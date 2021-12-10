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
	int rows = lines.size();
	int cols = lines[0].size();
	int** grid = new int* [rows];
	for (int i = 0; i < rows; ++i)
		grid[i] = new int[cols];

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			int n = lines[i][j] - 48;
			grid[i][j] = n;
		}
	}

	int sum = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			bool lowest = true;
			int val = grid[i][j];
			if (i != 0 && val >= grid[i - 1][j]) {
				lowest = false;
			}
			if (i != rows - 1 && val >= grid[i + 1][j]) {
				lowest = false;
			}
			if (j != 0 && val >= grid[i][j - 1]) {
				lowest = false;
			}
			if (j != cols - 1 && val >= grid[i][j + 1]) {
				lowest = false;
			}
			if (lowest) {
				sum += (1 + val);
			}
		}
	}

	return sum;
}

// getting lazy here
std::vector<int> gridAddrs;

int calcBasinSize(int** grid, int i, int j, int rows, int cols, int dir, int depth) {
	int size = 1;
	int val = grid[i][j];

	if (dir == -1) {
		gridAddrs.push_back((int)&grid[i][j]);
	}

	if (dir != 3 && j != cols - 1 && grid[i][j + 1] != 9) {
		bool pursue = true;
		for (int n : gridAddrs)
			if (n == (unsigned int)&grid[i][j + 1])
				pursue = false;
		if (pursue) {
			gridAddrs.push_back((unsigned int)&grid[i][j + 1]);
			size += calcBasinSize(grid, i, j + 1, rows, cols, 1, depth + 1);
		}
	}
	if (dir != 4 && i != rows - 1 && grid[i + 1][j] != 9) {
		bool pursue = true;
		for (int n : gridAddrs)
			if (n == (unsigned int)&grid[i + 1][j])
				pursue = false;
		if (pursue) {
			gridAddrs.push_back((unsigned int)&grid[i + 1][j]);
			size += calcBasinSize(grid, i + 1, j, rows, cols, 2, depth + 1);
		}
	}
	if (dir != 1 && j != 0 && grid[i][j - 1] != 9) {
		bool pursue = true;
		for (int n : gridAddrs)
			if (n == (unsigned int)&grid[i][j - 1])
				pursue = false;
		if (pursue) {
			gridAddrs.push_back((unsigned int)&grid[i][j - 1]);
			size += calcBasinSize(grid, i, j - 1, rows, cols, 3, depth + 1);
		}
	}
	if (dir != 2 && i != 0 && grid[i - 1][j] != 9) {
		bool pursue = true;
		for (int n : gridAddrs)
			if (n == (unsigned int)&grid[i - 1][j])
				pursue = false;
		if (pursue) {
			gridAddrs.push_back((unsigned int)&grid[i - 1][j]);
			size += calcBasinSize(grid, i - 1, j, rows, cols, 4, depth + 1);
		}
	}
	return size;
}

long long p2(std::vector<std::string> lines) {
	int rows = lines.size();
	int cols = lines[0].size();
	int** grid = new int* [rows];
	for (int i = 0; i < rows; ++i)
		grid[i] = new int[cols];

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			int n = lines[i][j] - 48;
			grid[i][j] = n;
		}
	}

	std::vector<int> basinSizes;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			bool lowest = true;
			int val = grid[i][j];
			if (i != 0 && val >= grid[i - 1][j]) {
				lowest = false;
			}
			if (i != rows - 1 && val >= grid[i + 1][j]) {
				lowest = false;
			}
			if (j != 0 && val >= grid[i][j - 1]) {
				lowest = false;
			}
			if (j != cols - 1 && val >= grid[i][j + 1]) {
				lowest = false;
			}
			if (lowest) {
				int num = calcBasinSize(grid, i, j, rows, cols, -1, 0);
				basinSizes.push_back(num);
				gridAddrs.clear();
			}
		}
	}
	std::sort(basinSizes.begin(), basinSizes.end(), std::greater<int>());

	return basinSizes[0] * basinSizes[1] * basinSizes[2];
}

int main() {
	std::vector<std::string> lines = utils::readFile("./files/input09.txt");
	if (!lines.empty()) {
		std::cout << "part 1: " << p1(lines) << std::endl;
		std::cout << "part 2: " << p2(lines) << std::endl;
	}
}