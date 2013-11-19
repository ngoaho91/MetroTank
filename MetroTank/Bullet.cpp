#include "pch.h"
#include "Bullet.h"
#include "math.h"
Bullet::Bullet(int type)
{
	m_BulletModel = new BaseModel();
	m_BulletModel->SetTexture(L"images\\bullet.png");
	m_BulletModel->SetOriginal(12,12);
	m_BulletModel->SetPosition(700,600);
	m_X = 700;
	m_Y = 600;
	m_Velocity = 0;
	m_Angle = 0;
	m_Type = type;
}
void Bullet::Render(SpriteBatch* spriteBatch)
{
	m_BulletModel->Render(spriteBatch);
}
void Bullet::Update()
{
	float c = cos(m_Angle);
	float s = sin(m_Angle);
	
	m_X += -c*m_Velocity;
	m_Y += -s*m_Velocity;
	m_BulletModel->SetPosition(m_X,m_Y);
}
bool Bullet::OffScreen()
{
	if((m_X+12<0 && m_Y+12<0) ||(m_X-12 > 1366 && m_Y-12 > 768)) return true;
	return false;
}