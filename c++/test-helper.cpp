#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <unordered_map>
#include <unordered_set>
#include "tools.h"
#include "pinput/helper.hpp"

int main(int argc, char* argv[]){

	try {
		bool help, verbose;
		std::vector<long long> seed_v;
		std::string init;
		size_t max_steps(0);
		std::chrono::milliseconds max_time(0);
		double Td(0), Tp(0), sample_size_f(0);

		std::unordered_set<std::string> INIT {"random", "slack"};

		typedef std::vector<std::string> V;
		typedef std::vector<std::vector<std::string>> D;

		std::vector<std::string> params;
		std::unordered_map<std::string, std::vector<std::string>> options;
		std::unordered_set<std::string> flags;

		pinput::helper optparse;

		optparse.usage("pfsp-ig <filename> [options] [flags]")

		.flag("--help", "display help")
		.flag("--verbose", "verbose output")

		.alias("--help", "-h")
		.alias("--verbose", "-v")

		.option("--seed", "seed array for the random engine")
		.option("--init", "initial solution generator")
		.option("--max-steps", "step based termination criterion")
		.option("--max-time", "time (ms) based termination criterion")
		.option("--temperature-d", "delta used for the temperature")
		.option("--temperature-p", "probability used for the temperature")
		.option("--sample-size-f", "sample size (neighborhood size %)")

		.alias("--seed", "-s")
		.alias("--init", "-i")
		.alias("--max-steps", "-#")
		.alias("--max-time", "-t")
		.alias("--temperature-d", "--td")
		.alias("--temperature-p", "--tp")
		.alias("--sample-size-f", "--ss")

		.mandatory("--init")
		.mandatory(D({{"--max-steps"}, {"--max-time"}}))
		.mandatory("--temperature-d")
		.mandatory("--temperature-p")
		.mandatory("--sample-size-f")

		.odefault("--seed", {std::to_string(std::chrono::high_resolution_clock::now().time_since_epoch().count())})

		.condition("--init", [&]{return INIT.count(init) > 0;}, "in {slack, random}")
		.condition("--temperature-p", [&]{return Tp > 0.0;}, "> 0")
		.condition("--temperature-p", [&]{return Tp < 1.0;}, "< 1")
		.condition("--temperature-d", [&]{return Td > 0.0;}, "> 0")
		.condition("--max-time", [&]{return max_time.count() >= 0;}, ">= 0")
		.condition("--sample-size-f", [&]{return sample_size_f > 0.0;}, "> 0")
		.condition("--sample-size-f", [&]{return sample_size_f <= 1.0;}, "<= 1")

		.oassign("--init", [&](const V& v){init = v[0];})
		.oassign("--temperature-p", [&](const V& v){Tp = std::stod(v[0]);})
		.oassign("--temperature-d", [&](const V& v){Td = std::stod(v[0]);})
		.oassign("--max-time", [&](const V& v){max_time = std::chrono::milliseconds(std::stoul(v[0]));})
		.oassign("--max-steps", [&](const V& v){max_steps = std::stoul(v[0]);})
		.oassign("--sample-size-f", [&](const V& v){sample_size_f = std::stod(v[0]);})
		.oassign("--seed", [&](const V& v){
			for(const auto& e : v) seed_v.push_back(std::stoll(e));
		})

		.fassign("--help", [&](const bool v){help = v;})
		.fassign("--verbose", [&](const bool v){verbose = v;})


		.parse(argc, argv, params, options, flags);

		if (help) optparse.signature();
		else {
			if (params.size() == 0) throw pinput::exception("<filename> missing");
			optparse.validate(params, options, flags);

			std::cout << params << std::endl;
			std::cout << options << std::endl;
			std::cout << flags << std::endl;
		}

	}

	catch (std::exception& e) {
		std::cout << "error -> " << e.what() << std::endl;
		return 1;
	}
	
	return 0;
}