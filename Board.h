#pragma once
#include "Block.h"
#include <cstdlib> // for rand()
#include <ctime> // for time()

using namespace std;
class Board
{
private:
	Block* Block_Header;
public:
	Board();
	~Board();
	int filenum = 1;

	Block* GetHeader() { return Block_Header; }
	Block* GetBlock(int y, int x);
	void MakeBoard();
	void RandomAdd();
	bool CheckEmpty(int y, int x);
	bool CheckBlockUp(Block* temp);
	bool CheckBlockDown(Block* temp);
	bool CheckBlockLeft(Block* temp);
	bool CheckBlockRight(Block* temp);
	bool CheckUp();
	bool CheckDown();
	bool CheckLeft();
	bool CheckRight();
	void GoUp(Block* temp);
	void GoDown(Block* temp);
	void GoLeft(Block* temp);
	void GoRight(Block* temp);
	bool Up();
	bool Down();
	bool Left();
	bool Right();
	void ResetCheck();
	bool CheckEnd();
};