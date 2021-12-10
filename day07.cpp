#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <algorithm>
#include <cmath>

#include "utils.h"

int fuelCost(int dist) {
	int fuel = 0;
	for (int i = 0; i < dist; i++) {
		fuel += (i + 1);
	}
	return fuel;
}

int p1(std::vector<std::string> lines) {
	std::vector<int> crabs;
	int sum = 0;
	for (auto l : lines) {
		std::stringstream ss(l);
		for (int i; ss >> i;) {
			crabs.push_back(i);
			if (ss.peek() == ',')
				ss.ignore();
		}

		std::sort(crabs.begin(), crabs.end());

		for (int location : crabs) {
			sum += std::abs(location - crabs[(int)crabs.size() / 2]);
		}
	}
	return sum;
}

long long p2(std::vector<std::string> lines) {
	std::vector<int> crabs;
	int sum = 0;
	unsigned int lowestFuel = -1;
	for (auto l : lines) {
		std::stringstream ss(l);
		for (int i; ss >> i;) {
			crabs.push_back(i);
			if (ss.peek() == ',')
				ss.ignore();
		}

		std::sort(crabs.begin(), crabs.end());

		for (int pos = 0; pos < crabs[crabs.size() - 1]; pos++) {
			int sum = 0;
			for (int location : crabs) {
				sum += fuelCost(std::abs(location - pos));
			}
			if (sum < lowestFuel) {
				std::cout << pos << std::endl;
				lowestFuel = sum;
			}
		}
	}
	return lowestFuel;
}

int main() {
	std::vector<std::string> lines = utils::readFile("./files/input07.txt");
	if (!lines.empty()) {
		std::cout << "part 1: " << p1(lines) << std::endl;
		std::cout << "part 2: " << p2(lines) << std::endl;
	}
}