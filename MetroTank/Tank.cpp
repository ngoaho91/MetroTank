#include "pch.h"
#include "Tank.h"
#include "math.h"
Tank::Tank()
{
	m_TankModel = new BaseModel();
	m_TankModel->SetTexture(L"Images//tank.png");
	m_TankModel->SetOriginal(32,5);
	m_TankModel->SetPosition(700,600);
	m_BarrelModel = new BaseModel();
	m_BarrelModel->SetTexture(L"Images//barrel.png");
	m_BarrelModel->SetOriginal(16,32);
	m_BarrelModel->SetPosition(700,600);

	m_X = 700;
	m_Y = 600;
	m_Angle = 0;
	m_Follow = true;
}
void Tank::Track(int x, int y)
{
	m_TrackX = x;
	if(y > m_Y) y = m_Y - 1;
	m_TrackY = y;
}
void Tank::UpdateTrack()
{
	int opposite = m_Y - m_TrackY;
	int adjacent = m_X - m_TrackX;
	float hypotenuse = sqrt(opposite*opposite+adjacent*adjacent);
	float sin = opposite/hypotenuse;
	float cos = adjacent/hypotenuse;
	float angle = acos(cos);
	if(sin < 0) angle += 3.14f;

	m_Angle = angle;
	m_BarrelModel->SetRotation(angle - 3.14f/2);
	
	if(!m_Follow)
		return;

	if(abs(adjacent) < 20) return;
	if(m_X > m_TrackX) m_X -= abs(adjacent)/30;
	else m_X += abs(adjacent)/30;
	
	m_TankModel->SetPosition(m_X,m_Y);
	m_BarrelModel->SetPosition(m_X,m_Y);
}
void Tank::Fire()
{
	BulletManager::GetSingleton()->AddBullet(m_X-20*cos(m_Angle),m_Y-20*sin(m_Angle), m_Angle, 7);
}
void Tank::Render(SpriteBatch* spriteBatch)
{
	m_BarrelModel->Render(spriteBatch);
	m_TankModel->Render(spriteBatch);
}