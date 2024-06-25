#include "erm_context.h"
using namespace nlohmann;
using namespace erm;

json CompactionContext::to_json() const {
	json res;
	res["level_info"] = {};
	res["level_info"]["from"] = from_level;
	res["level_info"]["to"] = to_level;

	return res;
}

std::unique_ptr<IContext> CompactionContext::clone() const {
	return std::make_unique<CompactionContext>(from_level, to_level);	
}
