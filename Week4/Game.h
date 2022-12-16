#pragma once
#include "Stack.h"

class Game {
public:
	Game();
	void solve();

	friend std::ostream& operator<<(std::ostream& os, const Game& game);
private:
	std::vector<Stack> stacks_;
};