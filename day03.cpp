#include <iostream>
#include <vector>
#include <string>

#include "utils.h"

int p1(std::vector<std::string> lines) {
	int gamma = 0;
	int epsilon = 0;
	for (int i = 0; i < lines[0].size(); i++) {
		int bitCnt = 0;
		for (auto l : lines) {
			(l[i] == '0') ? bitCnt-- : bitCnt++;
		}

		gamma = gamma << 1;
		epsilon = epsilon << 1;
		(bitCnt > 0) ? gamma += 1 : epsilon += 1;
	}
	return gamma * epsilon;
}

int p2(std::vector<std::string> lines) {
	std::vector<std::string> oxLines = lines;
	std::vector<std::string> co2Lines = lines;
	int oxygen = 0, co2 = 0;
	for (int i = 0; i < lines[0].size(); i++) {
		int bitCnt = 0;
		for (auto l : oxLines) {
			(l[i] == '0') ? bitCnt-- : bitCnt++;
		}
		char bit = (bitCnt >= 0) ? '1' : '0';
		std::vector<std::string> newOxLines;
		for (auto l : oxLines) {
			if (l[i] == bit)
				newOxLines.push_back(l);
		}
		oxLines = newOxLines;
		if (newOxLines.size() <= 1) {
			oxygen = std::stoi(newOxLines[0], 0, 2);
			break;
		}
	}

	for (int i = 0; i < lines[0].size(); i++) {
		int bitCnt = 0;
		for (auto l : co2Lines) {
			(l[i] == '0') ? bitCnt-- : bitCnt++;
		}
		char bit = (bitCnt >= 0) ? '0' : '1';
		std::vector<std::string> newCo2Lines;
		for (auto l : co2Lines) {
			if (l[i] == bit)
				newCo2Lines.push_back(l);
		}
		co2Lines = newCo2Lines;
		if (newCo2Lines.size() <= 1) {
			co2 = std::stoi(newCo2Lines[0], 0, 2);
			break;
		}
	}
	return oxygen * co2;
}

int main() {
	std::vector<std::string> lines = utils::readFile("./files/input03.txt");
	if (!lines.empty()) {
		std::cout << "part 1: " << p1(lines) << std::endl;
		std::cout << "part 2: " << p2(lines) << std::endl;
	}
}