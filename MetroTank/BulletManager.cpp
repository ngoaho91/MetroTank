#include "pch.h"
#include "BulletManager.h"

BulletManager* BulletManager::m_Singleton = NULL;
BulletManager* BulletManager::GetSingleton()
{
	if(m_Singleton == NULL)
	{
		m_Singleton = new BulletManager();
	}
	return m_Singleton;
}
BulletManager::BulletManager()
{
	
}
void BulletManager::Update()
{
	vector <Bullet*>::const_iterator iter = m_Bullets.begin();
	while(iter < m_Bullets.end())
	{
		(*iter)->Update();
		if((*iter)->OffScreen()) 
		{
			m_Bullets.erase(iter);
			break;
		}
		iter++;
	}
}
void BulletManager::Render(SpriteBatch* spriteBatch)
{
	vector <Bullet*>::const_iterator iter;
	for (iter = m_Bullets.begin(); iter < m_Bullets.end();iter++)
	{
		(*iter)->Render(spriteBatch);
	}
}
void BulletManager::AddBullet(int x, int y, float angle, float velocity, int type)
{
	Bullet* bullet = new Bullet(type);
	bullet->SetPosition(x,y);
	bullet->SetAngle(angle);
	bullet->SetVelocity(velocity);
	m_Bullets.push_back(bullet);
}
