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
void Game::solve() {
	//move the first three cubes to the second stack
	uiuc::Cube cRemoved1 = stacks_[0].removeTop();
	stacks_[1].push_back(cRemoved1);
	uiuc::Cube cRemoved2 = stacks_[0].removeTop();
	stacks_[1].push_back(cRemoved2);
	uiuc::Cube cRemoved3 = stacks_[0].removeTop();
	stacks_[1].push_back(cRemoved3);
	//move the last cube to the last stack
	uiuc::Cube cRemoved4 = stacks_[0].removeTop();
	stacks_[2].push_back(cRemoved4);
	//Move the cubes on the second stack to the last stack
	uiuc::Cube cRemoved5 = stacks_[1].removeTop();
	stacks_[2].push_back(cRemoved5);
	uiuc::Cube cRemoved6 = stacks_[1].removeTop();
	stacks_[2].push_back(cRemoved6);
	uiuc::Cube cRemoved7 = stacks_[1].removeTop();
	stacks_[2].push_back(cRemoved7);
};