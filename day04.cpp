#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <algorithm>

#include "utils.h"

// man.
bool checkWin(std::vector <std::pair<int, bool>> board) {
	bool vert, hor;
	for (int i = 0; i < 5; i++) {
		vert = (board[i * 5].second == true && board[i * 5 + 1].second == true && board[i * 5 + 2].second == true && board[i * 5 + 3].second == true && board[i * 5 + 4].second == true);
		hor = (board[i].second == true && board[i+5].second == true && board[i + 10].second == true && board[i + 15].second == true && board[i + 20].second == true);
		if (hor || vert)
			break;
	}
	return (hor || vert);
}

int p1(std::vector<std::string> lines) {
	std::stringstream numbersStream; 
	std::vector<std::vector<std::pair<int, bool>>> boards;
	std::vector <std::pair<int, bool>> board;
	int row = 0;
	for (auto i = lines.begin(); i != lines.end(); i++) {
		if (i == lines.begin()) {
			numbersStream = std::stringstream(*i);
			continue;
		}

		if (!i->empty()) {
			std::stringstream ss(*i);
			for (int i = 0; i < 5; i++) {
				int number;
				ss >> number;
				board.push_back(std::pair<int, bool>(number, false));
			}
		}
		
		if (board.size() == 25) {
			boards.push_back(board);
			board = std::vector<std::pair<int, bool>>();
		}
	}

	std::vector<int> numbers;

	for (int i; numbersStream >> i;) {
		numbers.push_back(i);
		if (numbersStream.peek() == ',')
			numbersStream.ignore();
	}

	for (auto number : numbers) {
		for (auto &board : boards) {
			for (auto &pair : board) {
				if (pair.first == number) {
					pair.second = true;
				}
			}

			bool won = checkWin(board);
			if (won) {
				int sum = 0;
				for (auto pair : board) {
					if (pair.second == false)
						sum += pair.first;
				}
				return number * sum;
			}
		}
	}

	return -1;
}

int p2(std::vector<std::string> lines) {
	std::stringstream numbersStream;
	std::vector<std::vector<std::pair<int, bool>>> boards;
	std::vector <std::pair<int, bool>> board;
	int row = 0;
	for (auto i = lines.begin(); i != lines.end(); i++) {
		if (i == lines.begin()) {
			numbersStream = std::stringstream(*i);
			continue;
		}

		if (!i->empty()) {
			std::stringstream ss(*i);
			for (int i = 0; i < 5; i++) {
				int number;
				ss >> number;
				board.push_back(std::pair<int, bool>(number, false));
			}
		}

		if (board.size() == 25) {
			boards.push_back(board);
			board = std::vector<std::pair<int, bool>>();
		}
	}

	std::vector<int> numbers;

	for (int i; numbersStream >> i;) {
		numbers.push_back(i);
		if (numbersStream.peek() == ',')
			numbersStream.ignore();
	}

	std::vector<int> winningBoards;

	for (auto number : numbers) {
		for (auto& board : boards) {
			for (auto& pair : board) {
				if (pair.first == number) {
					pair.second = true;
				}
			}

			bool won = checkWin(board);
			if (won) {
				if (std::find(winningBoards.begin(), winningBoards.end(), (int)&board) == std::end(winningBoards)) {
					if (winningBoards.size() == boards.size() - 1) {
						int sum = 0;
						for (auto pair : board) {
							if (pair.second == false)
								sum += pair.first;
						}
						return number * sum;
					}
					winningBoards.push_back((int)&board);
				}
			}
		}
	}

	return -1;
}

int main() {
	std::vector<std::string> lines = utils::readFile("./files/input04.txt");
	if (!lines.empty()) {
		std::cout << "part 1: " << p1(lines) << std::endl;
		std::cout << "part 2: " << p2(lines) << std::endl;
	}
}