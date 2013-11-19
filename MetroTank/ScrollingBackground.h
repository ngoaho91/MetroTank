#pragma once
#include "SpriteBatch.h"
#include "BaseModel.h"
class ScrollingBackground
{
private:
	BaseModel* m_Sky;
	BaseModel* m_Near1;
	BaseModel* m_Near2;
	BaseModel* m_Near3;
	BaseModel* m_Far1;
	BaseModel* m_Far2;
	BaseModel* m_Far3;
	BaseModel* m_Ground1;
	BaseModel* m_Ground2;
	BaseModel* m_Ground3;

	int m_Speed;
	int m_Position;
	int m_EndPosition;
public:
	ScrollingBackground(wchar_t* name, int endPosition);
	void SetSpeed(int speed){ m_Speed = speed;}
};