#pragma once
#include <iostream>
#include <vector>
#include "Cube.h"

class Stack {
public:
	void push_back(const uiuc::Cube& cube);
	void pop_back();
	void pop_front();

	uiuc::Cube removeTop();
	uiuc::Cube& peekTop();
	unsigned size() const;

	// define operator overload for string insertion and string extraction 
	friend std::ostream& operator<<(std::ostream & os, const Stack & stack);
	friend std::istream& operator>>(std::istream& os, const Stack& stack);
private:
	std::vector<uiuc::Cube> cubes_;
};
