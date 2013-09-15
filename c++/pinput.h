#include <string>
#include <utility>
#include <tuple>

namespace pinput{
	template<typename P, typename O, typename F, typename T>
	void parse(int argc, char* argv[], P& params, O& options, F& flags, const T& optional){

		std::string optionalParameterKey;
		bool isOptionalParameter = false;

		for(int n = 1; n < argc; ++n){
			std::string p = argv[n];
			if (p[0] == '-'){
				isOptionalParameter = false;
				if(p.size() > 1){
					if(p[1] == '-' || p.size() == 2){

						if(optional.count(p) > 0){
							options.emplace(std::piecewise_construct, std::forward_as_tuple(p), std::forward_as_tuple());
							optionalParameterKey = p;
							isOptionalParameter = true;
						}
						else{
							flags.insert(p);
						}
					}
					else{
						for(size_t i = 1; i < p.size(); ++i){
							flags.insert(std::string({'-', p[i]}));
						}
					}
				}
			}
			else if(isOptionalParameter){
				options.at(optionalParameterKey).push_back(p);
			}
			else{
				params.push_back(p);
			}
		}
	}
}
