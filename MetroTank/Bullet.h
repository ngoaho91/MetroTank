#pragma once

#include "BaseModel.h"
class Bullet
{
private:
	float m_Velocity;
	float m_Angle;
	int m_X;
	int m_Y;
	int m_Type;
	BaseModel* m_BulletModel;
public:
	Bullet(int type);
	void Update();
	void Render(SpriteBatch* spriteBatch);
	void SetPosition(int x, int y){ m_X = x; m_Y = y; m_BulletModel->SetPosition(x,y);}
	void SetVelocity(float v){ m_Velocity = v;}
	void SetAngle(float a){ m_Angle = a; m_BulletModel->SetRotation(a-3.14f/2);}
	int GetPositionX(){ return m_X;}
	int GetPositionY(){ return m_Y;}
	float GetAngle(){ return m_Angle;}
	float GetVelocity(){ return m_Velocity;}
	bool OffScreen();
};