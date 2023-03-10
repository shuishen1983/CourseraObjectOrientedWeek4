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

bool Game::isMoveLegal(int I1, int I2) {
	// is legal moves possible, sequence may not matter
	// when stack is not empty no peek is even needed
	if (stacks_[I1].size() == 0 && stacks_[I2].size() > 0) {
		move(I2, I1);
		return true;
	}
	else if (stacks_[I1].size() > 0 && stacks_[I2].size() == 0) {
		move(I1, I2);
		return true;
	}
	else if (stacks_[I1].size() > 0 && stacks_[I2].size() > 0) {
		uiuc::Cube& c1(stacks_[I1].peekTop());
		double length1 = c1.getLength();
		uiuc::Cube& c2(stacks_[I2].peekTop());
		double length2 = c2.getLength();
		// when none of the cubes are of length0, in other words they are real cubes
		if (length1 < length2) {
			// this is legal to put cube 1 on top of cube 2
			move(I1, I2);
			return true;
		}
		else if (length1 > length2) {
			// this is still legal if we reverse to put cube 2 on top of cube 1
			move(I2, I1);
			return true;
		}
		else {
			// length of the cubes are equal it is not possible to place
			return false;
		}
	}
	else {
		return false;
	}
	/* peek first check empty second
	uiuc::Cube& c1(stacks_[I1].peekTop());
	double length1 = c1.getLength();
	//uiuc::HSLAPixel color1 = c1.getColor();
	uiuc::Cube& c2(stacks_[I2].peekTop());
	double length2 = c2.getLength();
	//uiuc::HSLAPixel color2 = c2.getColor();
	if (length1 == 0 || length2 == 0) {
		// when any of the cubes are of length 0, in other words empty
		if (length1 > 0 && length2 == 0) {
			//when cube 2 is empty, cube 1 is not empty it is legal to put cube 1 on top of cube 2 (empty)
			move(I1, I2);
			return true;
		}
		else if (length1 == 0 && length2 > 0) {
			//when cube 1 is empty, cube 2 is not empty it is legal to put cube 2 on top of cube 1 (empty)
			move(I2, I1);
			return true;
		}
		else {
			// both cubes are empty, it is not possible to move
			return false;
		}
	}
	else {
		// when none of the cubes are of length0, in other words they are real cubes
		if (length1 < length2) {
			// this is legal to put cube 1 on top of cube 2
			move(I1, I2);
			return true;
		}
		else if (length1 > length2) {
			// this is still legal if we reverse to put cube 2 on top of cube 1
			move(I2, I1);
			return true;
		}
		else {
			// length of the cubes are equal it is not possible to place
			return false;
		}

	}
	*/
};

void Game::move(int I1, int I2) {
	uiuc::Cube cRemoved = stacks_[I1].removeTop();
	stacks_[I2].push_back(cRemoved);
}

void Game::moveCube(Stack& source, Stack& target) {
	// move the top of source stack to target stack
	uiuc::Cube cRemoved = source.removeTop();
	target.push_back(cRemoved);
};

void Game::recursiveMove(unsigned start, unsigned end, Stack& source, Stack& target, Stack& spare, unsigned depth) {
	std::cout << "Planning (depth=" << depth++ << "):Move";
	// Check if we are only moving one cube
	if (start == end) {
		// If so, move it directly:
		moveCube(source, target);

	}
	else {
		// otherwise use recursive move strategy:
		recursiveMove(start + 1, end  , source, spare , target, depth);
		recursiveMove(start    , start, source, target, spare, depth);
		recursiveMove(start + 1, end  , spare, target, source, depth);
	}

}




void Game::solve() {
	while (stacks_[2].size() != 4) {
	//for (int i = 0; i < 3; i++) {
		isMoveLegal(0, 1);
		isMoveLegal(0, 2);
		isMoveLegal(1, 2);
		//std::cout << *this << std::endl;
	}
		
	//}
	
	/*
	* //move the first three cubes to the second stack
	bool IsMoveLegal1 = isMoveLegal(0, 1); // this is legal because stack 1 is empty
	uiuc::Cube cRemoved1 = stacks_[0].removeTop();
	stacks_[1].push_back(cRemoved1);
	bool IsMoveLegal2 = isMoveLegal(0, 1); // this is not legal because top of stack 1 is a cube smaller
	uiuc::Cube cRemoved2 = stacks_[0].removeTop();
	stacks_[1].push_back(cRemoved2); // this is not legal because top of the stack 1 is a cube smaller
	bool IsMoveLegal3 = isMoveLegal(0, 1);
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
	*/
	
};

void Game::recursiveSolve() {
	recursiveMove(0, 3, stacks_.at(0), stacks_.at(2), stacks_.at(1),0);
};