

#include "stdafx.h"
#include "CDLL.h"
#include "TopSpin.h"
#include <iostream>

using namespace std;
//used to print the topspin grid 
void printTable(int size, int spinSize, TopSpin * ts) {
	cout << "|**";
	for (int i = 0; i < spinSize; i++) cout << "***";
	cout << "|" << endl << "|  ";
	for (int i = 0; i < spinSize; i++) {
		cout << ts->valAt(i);
		cout << " ";
		if (ts->valAt(i) < 9) cout << " ";
	}
	cout << "|" << " ";
	for (int i = spinSize; i < size; i++) {
		cout << ts->valAt(i);
		cout << " ";
		if (ts->valAt(i) < 9) cout << " ";
	}
	cout << endl;
	cout << "|**";
	for (int i = 0; i < spinSize; i++) cout << "***";
	cout << "|" << endl << endl << endl;

}

int main()
{
	TopSpin ts = TopSpin(20, 4);
	unsigned x;
	printTable(20, 4, &ts);
	cout << "how many random moves should be entered to mix the board?: ";
	cin >> x;
	ts.random(x);
	cout << "Begin Game!" << endl << endl;

	// the loop iterates indefinitely until a break is triggered by either winning or quitting
	while (true) {
		int action;
		printTable(20, 4, &ts);
		cout << "Please choose from the following options enter your choice by entering the corresponding number:"  << endl
			<< "1. Spin" << endl << "2. Shift" << endl << "3. Quit" << endl;
		
		//switch statement of possible inputs and their actions
		cin >> action;
		switch (action) {
		case 1:
			ts.spin();
			break;
		case 2:
			char dir;
			int dist;
			cout << "Which way? (L/R): ";
			cin >> dir; 
			cout << "How many spaces? ";
			cin >> dist;
			if (dir == 'l' || dir == 'L') {
				for (int i = 0; i < dist; i++) ts.shiftLeft();
			}
			if (dir == 'r' || dir == 'R') {
				for (int i = 0; i < dist; i++) ts.shiftRight();
			}
		case 3:
			break;
		}
		
		//if isSolved is true then the flow of control will leave the loop
		if (ts.isSolved()) {
			cout << "!*C*O*N*G*R*A*T*U*L*A*T*I*O*N*S*!" <<	endl;
			break;
		}
	}

	cout << "thanks for playing!" << endl;
	return 0;
}

