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
	uiuc::Cube c = cubes_[0];
	Stack::pop_back();
	return c;
};

uiuc::Cube& Stack::peekTop() {
	uiuc::Cube c = cubes_[0];
	return c;
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