#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <algorithm>
#include <cmath>

#include "utils.h"

struct Coord {
	int x, y;
};

int p1(std::vector<std::string> lines) {
	std::vector<std::pair<Coord, Coord>> lineCoords;
	int **grid = new int*[999]();
	for (int i = 0; i < 999; i++)
		grid[i] = new int[999]();
	for (auto l : lines) {
		std::stringstream ss(l);
		Coord coord1;
		Coord coord2;

		ss >> coord1.x;
		ss.ignore();
		ss >> coord1.y;
		ss.ignore(4);
		ss >> coord2.x;
		ss.ignore();
		ss >> coord2.y;

		lineCoords.push_back(std::pair<Coord, Coord>(coord1, coord2));
	}

	int inter = 0;
	for (auto line : lineCoords) {
		if (std::abs(line.first.x - line.second.x) && line.first.y - line.second.y == 0) {
			int x1 = std::min(line.first.x, line.second.x);
			int x2 = std::max(line.first.x, line.second.x);
			for (int i = x1; i <= x2; i++) {
				grid[line.first.y][i]++;
			}
		}
		else if (std::abs(line.first.y - line.second.y) && line.first.x - line.second.x == 0) {
			int y1 = std::min(line.first.y, line.second.y);
			int y2 = std::max(line.first.y, line.second.y);
			for (int i = y1; i <= y2; i++) {
				grid[i][line.first.x]++;
			}
		}
	}

	for (int i = 0; i < 999; i++)
		for (int j = 0; j < 999; j++)
			if (grid[i][j] > 1)
				inter++;

	return inter;
}

int p2(std::vector<std::string> lines) {
	std::vector<std::pair<Coord, Coord>> lineCoords;
	int** grid = new int* [999]();
	for (int i = 0; i < 999; i++)
		grid[i] = new int[999]();
	for (auto l : lines) {
		std::stringstream ss(l);
		Coord coord1;
		Coord coord2;

		ss >> coord1.x;
		ss.ignore();
		ss >> coord1.y;
		ss.ignore(4);
		ss >> coord2.x;
		ss.ignore();
		ss >> coord2.y;

		lineCoords.push_back(std::pair<Coord, Coord>(coord1, coord2));
	}

	int inter = 0;
	for (auto line : lineCoords) {
		if (std::abs(line.first.x - line.second.x) && line.first.y - line.second.y == 0) {
			int x1 = std::min(line.first.x, line.second.x);
			int x2 = std::max(line.first.x, line.second.x);
			for (int i = x1; i <= x2; i++) {
				grid[line.first.y][i]++;
			}
		}
		else if (std::abs(line.first.y - line.second.y) && line.first.x - line.second.x == 0) {
			int y1 = std::min(line.first.y, line.second.y);
			int y2 = std::max(line.first.y, line.second.y);
			for (int i = y1; i <= y2; i++) {
				grid[i][line.first.x]++;
			}
		}
		else {
			int x1 = line.first.x;
			int x2 = line.second.x;
			int y1 = line.first.y;
			int y2 = line.second.y;
			int i = y1, j = x1;
			for (; i != y2 && j != x2; (y1 < y2) ? i++ : i--, (x1 < x2) ? j++ : j--) {
				
				grid[i][j]++;
			}
			grid[i][j]++;
		}
	}

	for (int i = 0; i < 999; i++)
		for (int j = 0; j < 999; j++)
			if (grid[i][j] > 1)
				inter++;

	return inter;
}

int main() {
	std::vector<std::string> lines = utils::readFile("./files/input05.txt");
	if (!lines.empty()) {
		std::cout << "part 1: " << p1(lines) << std::endl;
		std::cout << "part 2: " << p2(lines) << std::endl;
	}
}