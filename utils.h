#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

namespace utils {
	std::vector<std::string> readFile(std::string filename) {
		std::ifstream file(filename);
		auto lines = std::vector<std::string>();
		if (!file) {
			std::cerr << (std::string("Cannot open [") + filename + "]") << std::endl;
			return lines;
		}
		std::string line;
		while (std::getline(file, line)) {
			lines.push_back(line);
		}
		return lines;
	}
}