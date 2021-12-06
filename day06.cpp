#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <algorithm>
#include <cmath>
#include <unordered_map>

#include "utils.h"

long long p1(std::vector<std::string> lines) {
    std::unordered_map<long long, long long> fish;
    for (auto l : lines) {
        std::stringstream ss(l);
        for (int i; ss >> i;) {
            fish[i]++;
            if (ss.peek() == ',')
                ss.ignore();
        }
    }

    for (int i = 0; i < 80; i++) {
        std::unordered_map<long long, long long> newFish;
        for (int i = 0; i < 9; i++) {
            if (i - 1 == -1) {
                newFish[6] = fish[i];
                newFish[8] = fish[i];
            }
            else {
                newFish[i - 1] = newFish[i - 1] + fish[i];
            }
        }
        fish = newFish;
    }

    long long sum = 0;
    for (auto i = fish.begin(); i != fish.end(); i++) {
        sum += i->second;
    }

    return sum;
}

long long p2(std::vector<std::string> lines) {
    std::unordered_map<long long, long long> fish;
    for (auto l : lines) {
        std::stringstream ss(l);
        for (int i; ss >> i;) {
            fish[i]++;
            if (ss.peek() == ',')
                ss.ignore();
        }
    }

    for (int i = 0; i < 256; i++) {
        std::unordered_map<long long, long long> newFish;
        for (int i = 0; i < 9; i++) {
            if (i - 1 == -1) {
                newFish[6] = fish[i];
                newFish[8] = fish[i];
            }
            else {
                newFish[i - 1] = newFish[i - 1] + fish[i];
            }
        }
        fish = newFish;
    }

    long long sum = 0;
    for (auto i = fish.begin(); i != fish.end(); i++) {
        sum += i->second;
    }

    return sum;
}

int main() {
	std::vector<std::string> lines = utils::readFile("./files/input06.txt");
	if (!lines.empty()) {
		std::cout << "part 1: " << p1(lines) << std::endl;
		std::cout << "part 2: " << p2(lines) << std::endl;
	}
}