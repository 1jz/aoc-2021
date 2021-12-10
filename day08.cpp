#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <algorithm>
#include <cmath>
#include <deque>
#include <unordered_map>

#include "utils.h"

int p1(std::vector<std::string> lines) {
	std::unordered_map<int, int> numbers;
	for (auto l : lines) {
		l = l.substr(l.find('|')+2);
		std::stringstream ss(l);

		for (std::string num; ss >> num;) {
			switch (num.size()) {
				case 2:
					numbers[1]++;
					break;
				case 3:
					numbers[7]++;
					break;
				case 4:
					numbers[4]++;
					break;
				case 7:
					numbers[8]++;
					break;
			}
		}
	}

	int sum = 0;
	for (auto i = numbers.begin(); i != numbers.end(); i++) {
		sum += i->second;
	}

	return sum;
}

long long p2(std::vector<std::string> lines) {
	int sum = 0;
	for (auto l : lines) {
		std::stringstream ss(l);
		std::vector<std::string> numbers;
		std::unordered_map<int, std::string> numPatterns;
		for (std::string num; ss >> num;) {
			std::sort(num.begin(), num.end());
			if (num[0] == '|')
				break;
			numbers.push_back(num);
		}

		std::vector<std::string> hardNums;

		for(auto pattern : numbers) {
			switch (pattern.size()) {
			case 2:
				numPatterns[1] = pattern;
				break;
			case 3:
				numPatterns[7] = pattern;
				break;
			case 4:
				numPatterns[4] = pattern;
				break;
			case 7:
				numPatterns[8] = pattern;
				break;
			default:
				hardNums.push_back(pattern);
			}
		}

		for (auto pattern : hardNums) {
			if (pattern.size() == 5) {
				int total = 0;
				// decode #3
				if (numPatterns.find(3) == numPatterns.end()){
					for (char c : numPatterns[7]) {
						if (pattern.find(c) != -1)
							total++;
						if (total == 3) {
							numPatterns[3] = pattern;
							break;
						}
					}
				}
				if (total != 3) {
					total = 0;
					//decode #2, #5
					for (char c : numPatterns[4]) {
						if (pattern.find(c) != -1)
							total++;
					}

					if (total == 2) {
						numPatterns[2] = pattern;
					} 
					else if (total == 3) {
						numPatterns[5] = pattern;
					}
				}
			}
			else if (pattern.size() == 6) {
				int total = 0;
				//decode #9
				if (numPatterns.find(9) == numPatterns.end()) {
					for (char c : numPatterns[4]) {
						if (pattern.find(c) != -1)
							total++;
						if (total == 4) {
							numPatterns[9] = pattern;
							break;
						}
					}
				}

				if (total != 4) {
					total = 0;
					//decode #0, #6
					for (char c : numPatterns[7]) {
						if (pattern.find(c) != -1)
							total++;
					}

					if (total == 3) {
						numPatterns[0] = pattern;
					}
					else if (total == 2) {
						numPatterns[6] = pattern;
					}
				}
			}
		}

		std::unordered_map<std::string, int> values;
		for (auto i = numPatterns.begin(); i != numPatterns.end(); i++) {
			values[i->second] = i->first;
		}

		std::string decodedValue;
		for (std::string num; ss >> num;) {
			std::sort(num.begin(), num.end());
			decodedValue += std::to_string(values[num]);
		}
		sum += std::stoi(decodedValue);
	}

	return sum;
}

/*
ab dab eafb cdfbe gcdfa fbcad cefabd cdfgeb cagedb acedgfb

ab: 1
dab: 7
eafb: 4
acedgfb: 8

 cdfbe: missing 1 letter  from 4 (5)
 gcdfa: missing 2 letters from 4 (2)
 fbcad: 1, 7 (3)
cefabd: 1, 7, 4 (9)
cdfgeb: (6)
cagedb: 1, 7 (0)
*/

int main() {
	std::vector<std::string> lines = utils::readFile("./files/input08.txt");
	if (!lines.empty()) {
		std::cout << "part 1: " << p1(lines) << std::endl;
		std::cout << "part 2: " << p2(lines) << std::endl;
	}
}