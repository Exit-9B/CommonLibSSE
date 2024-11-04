#include "RE/B/BSFurnitureMarkerNode.h"

namespace RE
{
	BSFurnitureMarkerNode* BSFurnitureMarkerNode::FindBSFurnitureMarkerNode(NiObjectNET* a_object)
	{
		using func_t = decltype(&BSFurnitureMarkerNode::FindBSFurnitureMarkerNode);
		REL::Relocation<func_t> func{ STATIC_OFFSET(BSFurnitureMarkerNode::FindBSFurnitureMarkerNode) };
		return func(a_object);
	}

	std::uint32_t BSFurnitureMarkerNode::GetNumFurnitureMarkers(NiObjectNET* a_object)
	{
		const auto markerNode = FindBSFurnitureMarkerNode(a_object);
		return markerNode ? markerNode->markers.size() : 0;
	}
}
