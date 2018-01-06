#include "stdafx.h"
#include "TopSpin.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

TopSpin::TopSpin(int size, int spinSize){
	if (size < 1) {
		std::cout << "Invalid parameter: size must be one or greater." << std::endl;
		return;
	}
	if (spinSize > size) {
		std::cout << "Invalid parameter: spin size must be less than or equal to board size." << std::endl;
		return;
	}

	for (int i = 1; i <= size; i++) {
		board.addData(i);
	}
	spinner = spinSize;
};

void TopSpin::shiftLeft() {
	board.decrementHead();
}

void TopSpin::shiftRight() {
	board.incrementHead();
}

void TopSpin::spin() {
	for (int i = 0; i < spinner / 2; i++) {
		board.swap(i, spinner - 1 - i);
	}
}

bool TopSpin::isSolved() {
	for (int i = 0; i < (board.getSize()-1); i++) {
		if (!((board[i] == board[i + 1] - 1) || (board[i] == board[i + 1] + 19))) {
			return false;
		}
		else return true;
	}
}

int TopSpin::valAt(unsigned i) {
	return board[i];
}

void TopSpin::random(unsigned times) {
	srand((unsigned)time(0));
	for (int i = 0; i < times; i++) {
		for (int i = 0; i < rand() % 19 + 1; i++) {
			shiftLeft();
		}
		spin();
	}
}

TopSpin::~TopSpin(){
}