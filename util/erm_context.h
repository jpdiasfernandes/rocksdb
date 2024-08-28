#include <erm/generic_context.hpp>

class CompactionContext : public erm::IContext {
	public: 
		CompactionContext(int from, int to, int job_id) :
			from_level(from), 
			to_level(to), 
			job_id_(job_id)
		{}


		nlohmann::json to_json() const;
		std::unique_ptr<erm::IContext> clone() const;
		int from_level;	
		int to_level;
		int job_id_;
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

