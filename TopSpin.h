#pragma once
#include "TopSpinADT.h"
#include "CDLL.h"
#include <iostream>

class TopSpin : public TopSpinADT {
public:
	//declares topSpin obj of integer size and spinsize 
	TopSpin(int, int);
	//use increment/decrement head to shift the focus left/right
	void shiftLeft();
	void shiftRight();
	void spin();
	bool isSolved();
	int valAt(unsigned);
	void random(unsigned);
	~TopSpin();
private:
	CDLL<int> board;
	int spinner;
};
/*
std::ostream & operator<<(std::ostream& os, const CDLL<int>& brd) {
	os << brd << std::endl;	
	return os;
}
*/

//for some reasaon attempting to override the ostream operators was causing linker errors I was unable to work around so I'm fine with just taking lost marks 