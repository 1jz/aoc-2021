#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <deque>
#include "utils.h"

int p1(std::vector<std::string> lines) {
	int depthIncreased = 0;
	int lastDepth = -1;

	for (std::string l : lines) {
		std::stringstream ss(l);
		int depth;
		ss >> depth;

		if (lastDepth == -1) {
			lastDepth = depth;
		}
		else if (depth > lastDepth) {
			depthIncreased++;
		}
		lastDepth = depth;
	}

	return depthIncreased;
}

int p2(std::vector<std::string> lines) {
	std::deque<int> window;
	int depthIncreased = 0;
	int lastDepthSum = -1;
	int windowSum = 0;

	for (std::string l : lines) {
		std::stringstream ss(l);
		int depth;
		ss >> depth;
		window.push_back(depth);
		windowSum += depth;
		if (window.size() == 3) {
			if (lastDepthSum != -1 && windowSum > lastDepthSum) {
				depthIncreased++;
			}
			lastDepthSum = windowSum;
			windowSum -= *window.begin();
			window.pop_front();
		}
	}

	return depthIncreased;
}

int main() {
	std::vector<std::string> lines = utils::readFile("./files/input01.txt");
	if (!lines.empty()) {
		std::cout << "part 1: " << p1(lines) << std::endl;
		std::cout << "part 2: " << p2(lines) << std::endl;
	}
}