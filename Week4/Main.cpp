#include <vector>
#include <iostream>
#include"Game.h"

int main() {
	std::vector<int> v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(5);

	std::cout << v[0] << std::endl;
	std::cout << v[1] << std::endl;
	std::cout << v[2] << std::endl;

	std::vector<int> v0;
	for (int i = 0; i < 100; i++)
	{
		v0.push_back(i * i);
	}
	std::cout << "Testing Cube:" << std::endl;
	uiuc::Cube c(2, uiuc::BLUE);
	std::cout << "Cube Length:" << c.getLength() << std::endl;

	std::cout << "Testing Stack:" << std::endl;
	Stack S;
	std::cout << "The size of stack is:" << S.size() << std::endl;
	std::cout << "Adding five cubes to a stack:" << S.size() << std::endl;
	for (int i = 0; i < 5; i++)
	{
		double newLength = (double)(i + 1);
		c.setLength(newLength);
		S.push_back(c);
		std::cout << "The size of stack is:" << S.size() << std::endl;
	}
	std::cout << S << std::endl;

	std::cout << "Removing one cubes from the back side of the stack:" << S.size() << std::endl;
	S.pop_back();
	std::cout << S << std::endl;
	std::cout << "The size of stack is:" << S.size() << std::endl;

	std::cout << "Removing one cubes from the front side of the stack:" << S.size() << std::endl;
	S.pop_front();
	std::cout << S << std::endl;
	std::cout << "The size of stack is:" << S.size() << std::endl;

	std::cout << "Removing one cubes from the front side of the stack and return it as object:" << S.size() << std::endl;
	uiuc::Cube cRemoved = S.removeTop();
	std::cout << S << std::endl;
	std::cout << "The size of stack is:" << S.size() << std::endl;

	uiuc::Cube& cPeak = S.peekTop();

	std::cout << "Testing Game:" << std::endl;
	Game GameHanoi;
	std::cout << "Initial game state: " << std::endl;
	std::cout << GameHanoi << std::endl;
	GameHanoi.solve();
	std::cout << "Terminal game state: " << std::endl;
	std::cout << GameHanoi << std::endl;
}