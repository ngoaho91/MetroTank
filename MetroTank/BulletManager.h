#pragma once

#include <vector>
#include "Bullet.h"
using namespace std;

class BulletManager
{
public:
	BulletManager();
	static void Init(ID3D11Device1* d3dDevice, ID3D11DeviceContext1* d3dContext);
	static BulletManager* GetSingleton();
	void AddBullet(int x, int y, float angle, float velocity, int type = 0);
	void Update();
	void Render(SpriteBatch* spriteBatch);
private:
	static BulletManager* m_Singleton;
	vector <Bullet*> m_Bullets;
	static ID3D11Device1* m_d3dDevice;
	static ID3D11DeviceContext1* m_d3dContext;

};