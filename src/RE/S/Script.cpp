#include "RE/S/Script.h"

#include "RE/M/MemoryManager.h"

namespace RE
{
	bool ScriptCompiler::CompilePartialScript(Script* a_script, TESObjectREFR* a_targetRef, COMPILER_NAME a_name, bool a_arg4)
	{
		using func_t = decltype(&ScriptCompiler::CompilePartialScript);
		REL::Relocation<func_t> func{ STATIC_OFFSET(ScriptCompiler::CompilePartialScript) };
		return func(this, a_script, a_targetRef, a_name, a_arg4);
	}

	void Script::ClearCommand()
	{
		if (text) {
			free(text);
			text = nullptr;
		}
	}

	void Script::CompileAndRun(TESObjectREFR* a_targetRef, COMPILER_NAME a_name)
	{
		ScriptCompiler compiler;
		CompileAndRun_Impl(&compiler, a_name, a_targetRef);
	}

	void Script::CompileAndRun(ScriptCompiler* a_compiler, TESObjectREFR* a_targetRef, COMPILER_NAME a_name)
	{
		CompileAndRun_Impl(a_compiler, a_name, a_targetRef);
	}

	BSSimpleList<SCRIPT_LOCAL*>* Script::CreateLocalList()
	{
		using func_t = decltype(&Script::CreateLocalList);
		REL::Relocation<func_t> func{ STATIC_OFFSET(Script::CreateLocalList) };
		return func(this);
	}

	std::string Script::GetCommand() const
	{
		return text ? text : "";
	}

	bool Script::Run(TESObjectREFR* a_targetRef, ScriptLocals* a_locals, TESObjectREFR* a_arg3, bool a_arg4)
	{
		using func_t = decltype(&Script::Run);
		REL::Relocation<func_t> func{ STATIC_OFFSET(Script::Run) };
		return func(this, a_targetRef, a_locals, a_arg3, a_arg4);
	}

	void Script::SetCommand(std::string_view a_command)
	{
		if (text) {
			free(text);
		}

		text = malloc<char>(a_command.length() + 1);
		std::memcpy(text, a_command.data(), a_command.length());
		text[a_command.length()] = '\0';
	}

	void Script::CompileAndRun_Impl(ScriptCompiler* a_compiler, COMPILER_NAME a_name, TESObjectREFR* a_targetRef)
	{
		using func_t = decltype(&Script::CompileAndRun_Impl);
		REL::Relocation<func_t> func{ STATIC_OFFSET(Script::CompileAndRun) };
		return func(this, a_compiler, a_name, a_targetRef);
	}
}
