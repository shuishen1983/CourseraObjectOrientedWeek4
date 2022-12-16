#pragma once


class Shape {
public:
	Shape() {
		length_ = 0;
	};
	Shape(double lengthIn) {
		length_ = lengthIn;
	}
private:
	double length_;
};