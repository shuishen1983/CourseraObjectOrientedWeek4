#pragma once
#include "Stack.h"

class Game {
public:
	Game();
	void solve();

	bool isMoveLegal(int I1, int I2);

	void move(int I1, int I2);

	void moveCube(Stack& source, Stack& target);

	void recursiveMove(unsigned start, unsigned end, Stack & source, Stack & target, Stack & spare, unsigned depth);

	void recursiveSolve();

	friend std::ostream& operator<<(std::ostream& os, const Game& game);
private:
	std::vector<Stack> stacks_;
};