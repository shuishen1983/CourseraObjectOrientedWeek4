#include"Stack.h"
/*
* Stack::Stack() {
	std::vector<uiuc::Cube> c;
	cubes_ = c;
}
*/
void Stack::push_back(const uiuc::Cube& cube) {
	cubes_.push_back(cube);
}

void Stack::pop_back() {
	cubes_.pop_back();
};

void Stack::pop_front() {
	// this is a customized pop_front which erase the first element in std vector
	cubes_.erase(cubes_.begin());
};

uiuc::Cube Stack::removeTop() {
	// removeTop function will first return the top of the stack as return value and then remove the top from the stack.
	if (cubes_.size() > 0) {
		// if stack is not empty return the top and pop the top
		int IdxTop = cubes_.size() - 1;
		uiuc::Cube c(cubes_[IdxTop]);
		Stack::pop_back();
		return c;
	}
	else
	{
		// if stack is empty return unisize white cube
		uiuc::Cube c(0,uiuc::WHITE);
		return c;
	}
	
};

uiuc::Cube& Stack::peekTop() {
	if (cubes_.size()) {
		// if stack is not empty return the top
		int IdxTop = cubes_.size() - 1;
		uiuc::Cube& cRef = cubes_.at(IdxTop);
		uiuc::Cube c(cubes_[IdxTop]);
		return cRef;
	}
	else
	{
		// if stack is empty return unisize white cube
		uiuc::Cube c(0, uiuc::WHITE);
		return c;
	}
	
	
}

unsigned Stack::size() const {
	return cubes_.size();
}

std::ostream& operator<<(std::
	ostream& os, const Stack& stack) {
	int SizeInt = (int)stack.size();

	os << "The length of cubes in this stack are:" << std::endl;
	for (int i=0; i < SizeInt; i++) {
		os << stack.cubes_[i].getLength() <<"m ";
	}
	os << std::endl;

	return os;
};

std::istream& operator>>(std::istream& os, const Stack& stack) {
	return os;
};