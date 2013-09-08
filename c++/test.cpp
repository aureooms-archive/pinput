#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "pinput.h"
#include "tools.h"

int main(int argc, char* argv[]){
	std::vector<std::string> params;
	std::unordered_map<std::string, std::vector<std::string>> options;
	std::unordered_set<std::string> flags;
	std::unordered_set<std::string> optional = {"--period", "--repair"};

	pinput::parse(argc, argv, params, options, flags, optional);

	std::cout << params << std::endl;
	std::cout << options << std::endl;
	std::cout << flags << std::endl;
	return 0;
}