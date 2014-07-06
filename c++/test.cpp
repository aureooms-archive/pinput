#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "tools.h"
#include "pinput.h"

int main(int argc, char* argv[]){
	std::vector<std::string> params;
	std::unordered_map<std::string, std::vector<std::string>> options;
	std::unordered_set<std::string> flags;
	std::unordered_set<std::string> option_set = {"--period", "--repair"};
	std::unordered_set<std::string> flag_set = {"--help"};

	pinput::parse(argc, argv, params, options, flags, option_set, flag_set);

	std::cout << params << std::endl;
	std::cout << options << std::endl;
	std::cout << flags << std::endl;
	return 0;
}