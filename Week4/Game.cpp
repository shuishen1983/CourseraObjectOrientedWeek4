#include"Game.h"

Game::Game() {
	// Construction initialize the game
	// create three stacks each with initial no cubes on the stack
	for (int i = 0; i < 3; i++)
	{
		Stack stackOfCubes;
		stacks_.push_back(stackOfCubes);
	}

	// stack up from bottom to top blue orange, purple and yellow on the first stack with index 0
	uiuc::Cube blue(4,uiuc::HSLAPixel::BLUE);
	stacks_[0].push_back(blue);

	uiuc::Cube orange(3, uiuc::HSLAPixel::ORANGE);
	stacks_[0].push_back(orange);

	uiuc::Cube purple(2, uiuc::HSLAPixel::PURPLE);
	stacks_[0].push_back(purple);

	uiuc::Cube yellow(1, uiuc::HSLAPixel::YELLOW);
	stacks_[0].push_back(yellow);
}

std::ostream& operator<<(std::ostream& os, const Game& game) {
	//int SizeInt = (int)game.stacks_[0].size();
	for (Stack s : game.stacks_) //range based c
	{
		// range based for loop has no index
		os << s << std::endl;
	}
	/*
	* 	for (int i = 0; i < game.stacks_.size(); i++) {
		os << i;
		os << game.stacks_[i] << std::endl;
	}
	*/

	return os;
};
void solve() {

};