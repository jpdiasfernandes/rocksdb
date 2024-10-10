#include "erm_context.h"
using namespace nlohmann;
using namespace erm;

json CompactionContext::to_json() const {
	json res;
	res["level_info"] = {};
	res["level_info"]["from"] = from_level;
	res["level_info"]["to"] = to_level;
	res["job_id"] = job_id_;
	if (!trivial_move_) {
		json quantity_json;
		for (const auto &[level, quantity]: input_quantity_)
			quantity_json[std::to_string(level)] = quantity;
		res["quantity"] = quantity_json;

		json input_json = json::array();
		for (const auto &level_input: input_info_) {
			json info;
			for (const auto &[fd_number, size]: level_input)
				info[std::to_string(fd_number)] = size;
			input_json.emplace_back(info);
		}
		res["input"] = input_json;
	}

	return res;
}

std::unique_ptr<IContext> CompactionContext::clone() const {
	return std::make_unique<CompactionContext>(from_level, to_level, job_id_, input_quantity_, input_info_);
}

json FlushContext::to_json() const {
	json res;
	res["num_memtables"] = num_memtables_;
	res["total_data_size"] = total_data_size_;
	res["job_id"] = job_id_;


	return res;
}

std::unique_ptr<IContext> FlushContext::clone() const {
	return std::make_unique<FlushContext>(num_memtables_, total_data_size_, job_id_);
}
