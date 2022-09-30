#pragma once
class Block
{
private:
	int m_number;
	Block* p_Head;
	Block* p_Up;
	Block* p_Down;
	Block* p_Left;
	Block* p_Right;
public:
	Block();
	~Block();

	int x, y, check;
	Block* Get_p_Head() { return p_Head; }
	Block* Get_p_Up() { return p_Up; }
	Block* Get_p_Down() { return p_Down; }
	Block* Get_p_Left() { return p_Left; }
	Block* Get_p_Right() { return p_Right; }
	int Get_m_number() { return m_number; }
	void Set_p_Head(Block* temp) { p_Head = temp; }
	void Set_p_Up(Block* temp) { p_Up = temp; }
	void Set_p_Down(Block* temp) { p_Down = temp; }
	void Set_p_Left(Block* temp) { p_Left = temp; }
	void Set_p_Right(Block* temp) { p_Right = temp; }
	void Set_m_number(int num) { m_number = num; }
};