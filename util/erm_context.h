#include <erm/generic_context.hpp>
#include <map>

class CompactionContext : public erm::IContext {
	public: 
		CompactionContext(int from, int to, int job_id,
						  std::map<int, int> input_quantity,
						  std::vector<std::map<uint64_t, uint64_t>> input_info, bool trivial_move) :
			from_level(from), 
 			to_level(to),
			job_id_(job_id),
			input_quantity_(input_quantity),
			input_info_(input_info),
			trivial_move_(trivial_move)
		{}

		CompactionContext(int from, int to, int job_id,
						  std::map<int, int> input_quantity,
						  std::vector<std::map<uint64_t, uint64_t>> input_info) :
			CompactionContext(from, to, job_id, input_quantity, input_info, false)
		{}

		CompactionContext(int from, int to, int job_id) :
			CompactionContext(from, to, job_id, std::map<int, int>(), std::vector<std::map<uint64_t, uint64_t>>(), true)
		{}

		nlohmann::json to_json() const;
		std::unique_ptr<erm::IContext> clone() const;
		int from_level;	
		int to_level;
		int job_id_;
		std::map<int, int> input_quantity_;
		std::vector<std::map<uint64_t, uint64_t>> input_info_;
		bool trivial_move_;
};

class FlushContext : public erm::IContext {
	public: 
		FlushContext(int num_memtables, int total_data_size, int job_id) : 
			num_memtables_(num_memtables),
			total_data_size_(total_data_size),
			job_id_(job_id)
		{}

		nlohmann::json to_json() const;
		std::unique_ptr<erm::IContext> clone() const;
		int num_memtables_;
		int total_data_size_;
		int job_id_;
};

