#include "RE/T/TESDataHandler.h"

#include "RE/T/TESFile.h"
#include "RE/T/TESForm.h"
#include "SKSE/MergeMapper.h"

namespace RE
{
	TESFile* TESFileCollection::GetFileForID(std::uint32_t a_formID) const
	{
		const std::uint8_t normalIndex = a_formID >> 24;
		if (normalIndex == 0xFE) {
			const std::uint16_t smallIndex = (a_formID >> 12) & 0xFFF;
			return GetSmallFile(smallIndex);
		} else {
			return GetNormalFile(normalIndex);
		}
	}

	TESFile* TESFileCollection::GetNormalFile(std::uint32_t a_index) const
	{
		if (a_index < files.size()) {
			return files[a_index];
		}
		return nullptr;
	}

	TESFile* TESFileCollection::GetSmallFile(std::uint32_t a_index) const
	{
		if (a_index < smallFiles.size()) {
			return smallFiles[a_index];
		}
		return nullptr;
	}

	TESDataHandler* TESDataHandler::GetSingleton()
	{
		REL::Relocation<TESDataHandler**> singleton{ STATIC_OFFSET(TESDataHandler::Singleton) };
		return *singleton;
	}

	std::uint32_t TESDataHandler::LoadScripts()
	{
		using func_t = decltype(&TESDataHandler::LoadScripts);
		REL::Relocation<func_t> func{ STATIC_OFFSET(TESDataHandler::LoadScripts) };
		return func(this);
	}

	TESForm* TESDataHandler::LookupForm(FormID a_rawFormID, stl::zstring a_modName)
	{
		if (const auto mergeMapper = SKSE::GetMergeMapperInterface()) {
			std::tie(a_modName, a_rawFormID) = mergeMapper->GetNewFormID(a_modName.data(), a_rawFormID);
		}

		auto file = LookupModByName(a_modName);
		if (!file || file->compileIndex == 0xFF) {
			return nullptr;
		}

		FormID formID = file->compileIndex << 24;
		if (file->compileIndex == 0xFE && file->IsLight()) {
			formID += file->smallFileCompileIndex << 12;
		}
		formID += a_rawFormID;

		return TESForm::LookupByID(formID);
	}

	const TESFile* TESDataHandler::LookupModByName(stl::zstring a_modName)
	{
		for (auto& file : files) {
			if (_stricmp(file->fileName, a_modName.data()) == 0) {
				return file;
			}
		}
		return nullptr;
	}

	std::optional<std::uint8_t> TESDataHandler::GetModIndex(stl::zstring a_modName)
	{
		auto mod = LookupModByName(a_modName);
		return mod ? std::make_optional(mod->compileIndex) : std::nullopt;
	}

	const TESFile* TESDataHandler::LookupLoadedModByName(stl::zstring a_modName)
	{
		for (auto& file : QNormalFileList()) {
			if (_stricmp(file->fileName, a_modName.data()) == 0) {
				return file;
			}
		}
		return nullptr;
	}

	const TESFile* TESDataHandler::LookupLoadedModByIndex(std::uint8_t a_index)
	{
		if (const auto* const compiledFiles = QCompiledFiles()) {
			return compiledFiles->GetNormalFile(a_index);
		}
#ifndef SKYRIMVR
		return nullptr;
#else
		return loadedFiles[a_index];
#endif
	}

	std::optional<std::uint8_t> TESDataHandler::GetLoadedModIndex(stl::zstring a_modName)
	{
		auto mod = LookupLoadedModByName(a_modName);
		return mod ? std::make_optional(mod->compileIndex) : std::nullopt;
	}

	const TESFile* TESDataHandler::LookupLoadedLightModByName(stl::zstring a_modName)
	{
		for (auto& smallFile : QSmallFileList()) {
			if (_stricmp(smallFile->fileName, a_modName.data()) == 0) {
				return smallFile;
			}
		}
		return nullptr;
	}

	const TESFile* TESDataHandler::LookupLoadedLightModByIndex(std::uint16_t a_index)
	{
		if (const auto* const compiledFiles = QCompiledFiles()) {
			return compiledFiles->GetSmallFile(a_index);
		}
		return nullptr;
	}

	std::optional<std::uint16_t> TESDataHandler::GetLoadedLightModIndex(stl::zstring a_modName)
	{
		auto mod = LookupLoadedLightModByName(a_modName);
		return mod ? std::make_optional(mod->smallFileCompileIndex) : std::nullopt;
	}

	bool TESDataHandler::IsGeneratedID(FormID a_formID)
	{
		return a_formID >= 0xFF000000;
	}

	BSTArray<TESForm*>& TESDataHandler::GetFormArray(FormType a_formType)
	{
		return formArrays[stl::to_underlying(a_formType)];
	}

	const TESFileCollection* TESDataHandler::QCompiledFiles() const
	{
#ifndef SKYRIMVR
		const TESFileCollection* const compiledFiles = &compiledFileCollection;
		__assume(compiledFiles);
		return compiledFiles;
#else
		static const TESFileCollection* const compiledFiles = []() {
			const auto handle = WinAPI::GetModuleHandle("skyrimvresl");

			using GetCompiledFileCollection_t = const TESFileCollection*();
			const auto GetCompiledFileCollection = reinterpret_cast<GetCompiledFileCollection_t*>(WinAPI::GetProcAddress(handle, "GetCompiledFileCollectionExtern"));
			return GetCompiledFileCollection ? GetCompiledFileCollection() : nullptr;
		}();

		return compiledFiles;
#endif
	}

	std::span<const TESFile* const> TESDataHandler::QNormalFileList() const
	{
		if (const auto* const compiledFiles = QCompiledFiles()) {
			return compiledFiles->files;
		}
#ifndef SKYRIMVR
		return {};
#else
		return std::span(loadedFiles, loadedFileCount);
#endif
	}

	std::span<const TESFile* const> TESDataHandler::QSmallFileList() const
	{
		if (const auto* const compiledFiles = QCompiledFiles()) {
			return compiledFiles->smallFiles;
		}
		return {};
	}
}
