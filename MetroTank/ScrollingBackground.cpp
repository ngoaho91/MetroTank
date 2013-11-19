#include "pch.h"
 #include <wchar.h> 
#include "ScrollingBackground.h"

ScrollingBackground::ScrollingBackground(wchar_t* name, int endPosition)
{
	size_t len = wcslen(name);
	wchar_t* sky = wcsncat(name, L"_sky.jpg", 8);
	wchar_t* bgNear = wcsncat(name, L"_bg.png", 7);
	wchar_t* bgFar = wcsncat (name, L"_bg2.png", 8);
	wchar_t* ground = wcsncat(name, L"_ground.png", 11);

	m_Sky = new BaseModel();
	m_Sky->SetTexture(sky);
	m_Sky->SetPosition(0,0);

	m_Near1 = new BaseModel();
	m_Near1->SetTexture(bgNear);
	m_Near1->SetPosition(0,0);
	m_Near2 = new BaseModel();
	m_Near2->SetTexture(bgNear);
	m_Near2->SetPosition(0,0);
	m_Near3 = new BaseModel();
	m_Near3->SetTexture(bgNear);
	m_Near3->SetPosition(0,0);

	m_Far1 = new BaseModel();
	m_Far1->SetTexture(bgFar);
	m_Far1->SetPosition(0,0);
	m_Far2 = new BaseModel();
	m_Far2->SetTexture(bgFar);
	m_Far2->SetPosition(0,0);
	m_Far3 = new BaseModel();
	m_Far3->SetTexture(bgFar);
	m_Far3->SetPosition(0,0);

	m_Ground1 = new BaseModel();
	m_Ground1->SetTexture(ground);
	m_Ground1->SetPosition(0,0);
	m_Ground2 = new BaseModel();
	m_Ground2->SetTexture(ground);
	m_Ground2->SetPosition(0,0);
	m_Ground3 = new BaseModel();
	m_Ground3->SetTexture(ground);
	m_Ground3->SetPosition(0,0);
}