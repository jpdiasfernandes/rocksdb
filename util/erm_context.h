#include <erm/generic_context.hpp>

class CompactionContext : public erm::IContext {
	public: 
		CompactionContext(int from, int to) :
			from_level(from), 
			to_level(to)
		{}


		nlohmann::json to_json() const;
		std::unique_ptr<erm::IContext> clone() const;
		int from_level;	
		int to_level;
};


