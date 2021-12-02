#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "utils.h"

int p1(std::vector<std::string> lines) {
	int depth = 0;
	int horizontal = 0;
	for (auto l : lines) {
		std::stringstream ss(l);
		std::string instruction;
		int val;
		ss >> instruction;
		ss >> val;
		switch (instruction[0]) {
		case 'd':
			depth += val;
			break;
		case 'u':
			depth -= val;
			break;
		case 'f':
			horizontal += val;
			break;
		}
	}
	return depth * horizontal;
}

int p2(std::vector<std::string> lines) {
	int depth = 0;
	int horizontal = 0;
	int aim = 0;
	for (auto l : lines) {
		std::stringstream ss(l);
		std::string instruction;
		int val;
		ss >> instruction;
		ss >> val;
		switch (instruction[0]) {
		case 'd':
			aim += val;
			break;
		case 'u':
			aim -= val;
			break;
		case 'f':
			horizontal += val;
			depth += aim * val;
			break;
		}
	}
	return depth * horizontal;
}

int main() {
	std::vector<std::string> lines = utils::readFile("./files/input02.txt");
	if (!lines.empty()) {
		std::cout << "part 1: " << p1(lines) << std::endl;
		std::cout << "part 2: " << p2(lines) << std::endl;
	}
}