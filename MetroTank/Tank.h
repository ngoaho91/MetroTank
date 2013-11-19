#pragma once

#include "SpriteBatch.h"
#include "BaseModel.h"
#include "BulletManager.h"

class Tank
{
private:
	int m_X;
	int m_Y;
	int m_TrackX;
	int m_TrackY;
	float m_Angle;
	bool m_Follow;

	BaseModel* m_TankModel;
	BaseModel* m_BarrelModel;
public:
	Tank();
	void Track(int x, int y);
	void UpdateTrack();
	void Fire();
	void Render(SpriteBatch* spriteBatch);

	void SetFollow(bool follow){ m_Follow = follow;}
	int GetPositionX(){ return m_X;}
	int GetPositionY(){ return m_Y;}
	float GetAngle(){ return m_Angle;}
};