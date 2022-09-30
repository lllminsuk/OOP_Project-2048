#include "pch.h"
#include "Board.h"

Board::Board()
{
	srand((unsigned int)time(NULL));
	Block_Header = new Block;
	MakeBoard();
	RandomAdd();
}
Board::~Board()
{
}
Block* Board::GetBlock(int y, int x) // return blocks corresponding to coordinates
{
	Block* Cur = Block_Header->Get_p_Head();
	for (int i = 0; i < x; i++)
		Cur = Cur->Get_p_Right();
	for (int i = 0; i < y; i++)
		Cur = Cur->Get_p_Down();
	return Cur;
}
void Board::MakeBoard()
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			Block* NewBlock = new Block;
			if (x == 0 && y == 0)
			{
				GetHeader()->Set_p_Head(NewBlock);
				continue;
			}
			NewBlock->x = x;
			NewBlock->y = y;
			if (x != 0)
			{
				NewBlock->Set_p_Left(GetBlock(y, x - 1));
				NewBlock->Get_p_Left()->Set_p_Right(NewBlock);
			}
			if (y != 0)
			{
				NewBlock->Set_p_Up(GetBlock(y - 1, x));
				NewBlock->Get_p_Up()->Set_p_Down(NewBlock);
			}
		}
	}
}
void Board::RandomAdd()	// add 2
{
	int x, y;
	while (1)
	{
		x = rand() % 4; // random
		y = rand() % 4; // random
		if (CheckEmpty(y, x))
			break;
		else continue;
	}
	GetBlock(y, x)->Set_m_number(2);
}
bool Board::CheckEmpty(int y, int x)	// Return true if block is empty
{
	if (GetBlock(y, x)->Get_m_number() == 0)
		return true;
	else return false;
}

bool Board::CheckBlockUp(Block* temp) // if block can move up, return true
{
	if (temp->y == 0) return false;
	else if (temp->Get_p_Up()->Get_m_number() == 0) return true;
	else if (temp->Get_m_number() != 0 && temp->Get_m_number() == temp->Get_p_Up()->Get_m_number()) return true;
	else return false;
}
bool Board::CheckBlockDown(Block* temp)// if block can move down, return true
{
	if (temp->y == 3) return false;
	else if (temp->Get_p_Down()->Get_m_number() == 0) return true;
	else if (temp->Get_m_number() != 0 && temp->Get_m_number() == temp->Get_p_Down()->Get_m_number()) return true;
	else return false;
}
bool Board::CheckBlockLeft(Block* temp) // if block can move left, return true
{
	if (temp->x == 0) return false;
	else if (temp->Get_p_Left()->Get_m_number() == 0) return true;
	else if (temp->Get_m_number() != 0 && temp->Get_m_number() == temp->Get_p_Left()->Get_m_number()) return true;
	else return false;
}
bool Board::CheckBlockRight(Block* temp) // if block can move right, return true
{
	if (temp->x == 3) return false;
	else if (temp->Get_p_Right()->Get_m_number() == 0) return true;
	else if (temp->Get_m_number() != 0 && temp->Get_m_number() == temp->Get_p_Right()->Get_m_number()) return true;
	else return false;
}
bool Board::CheckUp()	// if it can move up, return true
{
	for (int y = 1; y < 4; y++)
		for (int x = 0; x < 4; x++)
			if (GetBlock(y, x)->Get_m_number() != 0 && CheckBlockUp(GetBlock(y, x)))
				return true;
	return false;
}
bool Board::CheckDown()	// if it can move down, return true
{
	for (int y = 0; y < 3; y++)
		for (int x = 0; x < 4; x++)
			if (GetBlock(y, x)->Get_m_number() != 0 && CheckBlockDown(GetBlock(y, x)))
				return true;
	return false;
}
bool Board::CheckLeft()	// if it can move left, return true
{
	for (int y = 0; y < 4; y++)
		for (int x = 1; x < 4; x++)
			if (GetBlock(y, x)->Get_m_number() != 0 && CheckBlockLeft(GetBlock(y, x)))
				return true;
	return false;
}
bool Board::CheckRight()	// if it can move right, return true
{
	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 3; x++)
			if (GetBlock(y, x)->Get_m_number() != 0 && CheckBlockRight(GetBlock(y, x)))
				return true;
	return false;
}
void Board::GoUp(Block* temp) // go up
{
	if (CheckBlockUp(temp)) // if block can move up
	{
		if (temp->Get_p_Up()->check && temp->Get_m_number() == temp->Get_p_Up()->Get_m_number()) // if the number is the same as up
		{
			temp->Get_p_Up()->Set_m_number(temp->Get_m_number() * 2); // add two blocks
			temp->Set_m_number(0);
			temp->Get_p_Up()->check = 0;
		}
		else if (temp->Get_p_Up()->Get_m_number() == 0) //If up is empty
		{
			temp->Get_p_Up()->Set_m_number(temp->Get_m_number()); // move up
			temp->Set_m_number(0);
			int tempcheck = temp->Get_p_Up()->check;
			temp->Get_p_Up()->check = temp->check;
			temp->check = tempcheck;
			if (CheckBlockUp(temp->Get_p_Up())) // if block can move up
				GoUp(temp->Get_p_Up()); // go up
		}
	}
}
void Board::GoDown(Block* temp)// go down
{
	if (CheckBlockDown(temp)) //if block can move down
	{
		if (temp->Get_p_Down()->check && temp->Get_m_number() == temp->Get_p_Down()->Get_m_number()) // if the number is the same as down
		{
			temp->Get_p_Down()->Set_m_number(temp->Get_m_number() * 2); // add two blocks
			temp->Set_m_number(0);
			temp->Get_p_Down()->check = 0;
		}
		else if (temp->Get_p_Down()->Get_m_number() == 0) //If down is empty
		{
			temp->Get_p_Down()->Set_m_number(temp->Get_m_number()); // move down
			temp->Set_m_number(0);
			int tempcheck = temp->Get_p_Down()->check;
			temp->Get_p_Down()->check = temp->check;
			temp->check = tempcheck;
			if (CheckBlockDown(temp->Get_p_Down())) // if block can move down
				GoDown(temp->Get_p_Down()); // go down
		}
	}
}
void Board::GoLeft(Block* temp) // go left
{
	if (CheckBlockLeft(temp)) // if block can move left
	{
		if (temp->Get_p_Left()->check && temp->Get_m_number() == temp->Get_p_Left()->Get_m_number())// if the number is the same as left
		{
			temp->Get_p_Left()->Set_m_number(temp->Get_m_number() * 2); // add two blocks
			temp->Set_m_number(0);
			temp->Get_p_Left()->check = 0;
		}
		else if (temp->Get_p_Left()->Get_m_number() == 0) //If left is empty
		{
			temp->Get_p_Left()->Set_m_number(temp->Get_m_number()); // move left
			temp->Set_m_number(0);
			int tempcheck = temp->Get_p_Left()->check;
			temp->Get_p_Left()->check = temp->check;
			temp->check = tempcheck;
			if (CheckBlockLeft(temp->Get_p_Left())) // if block can move left
				GoLeft(temp->Get_p_Left()); // go left
		}
	}
}
void Board::GoRight(Block* temp) // go right
{
	if (CheckBlockRight(temp)) // if block can move right
	{
		if (temp->Get_p_Right()->check && temp->Get_m_number() == temp->Get_p_Right()->Get_m_number()) // if the number is the same as right
		{
			temp->Get_p_Right()->Set_m_number(temp->Get_m_number() * 2); // add two blocks
			temp->Set_m_number(0);
			temp->Get_p_Right()->check = 0;
		}
		else if (temp->Get_p_Right()->Get_m_number() == 0) // if right is empty
		{
			temp->Get_p_Right()->Set_m_number(temp->Get_m_number()); // move right
			temp->Set_m_number(0);
			int tempcheck = temp->Get_p_Right()->check;
			temp->Get_p_Right()->check = temp->check;
			temp->check = tempcheck;
			if (CheckBlockRight(temp->Get_p_Right())) // if block can move right
				GoRight(temp->Get_p_Right()); // go right
		}
	}
}
bool Board::Up()
{
	if (!CheckUp()) return false;	// if it can't move up, return false
	else
	{
		for (int x = 0; x < 4; x++)
			for (int y = 1; y < 4; y++)
				GoUp(GetBlock(y, x));
		return true;
	}
}
bool Board::Down()
{
	if (!CheckDown()) return false;	// if it can't move down, return false
	else
	{
		for (int x = 0; x < 4; x++)
			for (int y = 2; y >= 0; y--)
				GoDown(GetBlock(y, x));
		return true;
	}
}
bool Board::Left()
{
	if (!CheckLeft()) return false;	// if it can't move left, return false
	else
	{
		for (int y = 0; y < 4; y++)
			for (int x = 1; x < 4; x++)
				GoLeft(GetBlock(y, x));
		return true;
	}
}
bool Board::Right()
{
	if (!CheckRight()) return false; 	// if it can't move right, return false
	else
	{
		for (int y = 0; y < 4; y++)
			for (int x = 2; x >= 0; x--)
				GoRight(GetBlock(y, x));
		return true;
	}
}
void Board::ResetCheck()
{
	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
			GetBlock(y, x)->check = 1;
}
bool Board::CheckEnd()
{
	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
			if (GetBlock(y, x)->Get_m_number() == 2048)
				return true;
	return false;
}