#include "pch.h"
#include "Block.h"

Block::Block()
{
	x = 0;
	y = 0;
	m_number = 0;
	check = 1;
	p_Head = nullptr;
	p_Up = nullptr;
	p_Down = nullptr;
	p_Left = nullptr;
	p_Right = nullptr;
}
Block::~Block()
{
}