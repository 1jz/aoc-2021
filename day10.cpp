#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <algorithm>
#include <cmath>
#include <stack>
#include <unordered_map>

#include "utils.h"

int p1(std::vector<std::string> lines) {
	int value = 0;
	for (auto l : lines) {
		std::stack<char> brackets;
		bool corrupted = false;
		for (auto c : l) {
			if (c == '[' || c == '{' || c == '(' || c == '<') {
				brackets.push(c);
				continue;
			}
			char bracket = brackets.top();
			switch (c) {
			case ']':
				brackets.pop();
				if (bracket != '[') {
					value += 57;
					corrupted = true;
				}
				break;
			case '}':
				brackets.pop();
				if (bracket != '{') {
					value += 1197;
					corrupted = true;
				}
				break;
			case ')':
				brackets.pop();
				if (bracket != '(') {
					value += 3;
					corrupted = true;
				}
				break;
			case '>':
				brackets.pop();
				if (bracket != '<') {
					value += 25137;
					corrupted = true;
				}
				break;
			}

			if (corrupted)
				break;
		}
	}
	return value;
}

long long p2(std::vector<std::string> lines) {
	std::vector<long long> values;
	for (auto l : lines) {
		long long value = 0;
		std::stack<char> brackets;
		bool corrupted = false;
		for (auto c : l) {
			if (c == '[' || c == '{' || c == '(' || c == '<') {
				brackets.push(c);
				continue;
			}
			char bracket = brackets.top();
			switch (c) {
			case ']':
				brackets.pop();
				if (bracket != '[') {
					corrupted = true;
				}
				break;
			case '}':
				brackets.pop();
				if (bracket != '{') {
					corrupted = true;
				}
				break;
			case ')':
				brackets.pop();
				if (bracket != '(') {
					corrupted = true;
				}
				break;
			case '>':
				brackets.pop();
				if (bracket != '<') {
					corrupted = true;
				}
				break;
			}
		}

		if (!corrupted) {
			for (; !brackets.empty();brackets.pop()) {
				value *= 5;
				switch (brackets.top()) {
				case '[':
					value += 2;
					break;
				case '{':
					value += 3;
					break;
				case '(':
					value += 1;
					break;
				case '<':
					value += 4;
					break;
				}
			}
			values.push_back(value);
		}
	}

	std::sort(values.begin(), values.end());

	return values[values.size()/2];
}

int main() {
	std::vector<std::string> lines = utils::readFile("./files/input10.txt");
	if (!lines.empty()) {
		std::cout << "part 1: " << p1(lines) << std::endl;
		std::cout << "part 2: " << p2(lines) << std::endl;
	}
}