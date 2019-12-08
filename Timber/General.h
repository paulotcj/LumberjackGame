#pragma once
#include <stdio.h>
#include <tchar.h>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1080;
const int NUM_BRANCHES = 6;


using namespace sf;
enum class side { LEFT, RIGHT, NONE };

Sprite branches[NUM_BRANCHES];
side branchPositions[NUM_BRANCHES];


//--------------------------------------------------------
// Function definition
void updateBranches(int seed)
{

	// Move all the branches down one place
	for (int i = NUM_BRANCHES - 1; i > 0; i--) {
		branchPositions[i] = branchPositions[i - 1];
	}

	// Spawn a new branch at position 0
	// LEFT, RIGHT or NONE
	srand((int)time(0) + seed);
	int r = (rand() % 5);

	switch (r) {
	case 0:
		branchPositions[0] = side::LEFT;
		break;

	case 1:
		branchPositions[0] = side::RIGHT;
		break;

	default:
		branchPositions[0] = side::NONE;
		break;
	}


}
//--------------------------------------------------------