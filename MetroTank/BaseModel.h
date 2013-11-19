#pragma once

#include "pch.h"
#include <DirectXMath.h>
#include <SpriteBatch.h>

using namespace DirectX;
class BaseModel
{
private:
	static ID3D11Device1* m_d3dDevice;
	static ID3D11DeviceContext1* m_d3dContext;
	ID3D11ShaderResourceView* m_Texture;
	ID3D11ShaderResourceView** m_Textures;
	int m_X;
	int m_Y;
	int m_OX;
	int m_OY;
	float m_Depth;
	int m_Width;
	int m_Height;

	float m_Scale;
	float m_Rotation;
public:
	BaseModel();
	static void Init(ID3D11Device1* d3dDevice, ID3D11DeviceContext1* d3dContext);
	void SetTexture(wchar_t* path);
	void SetAnimation(wchar_t* path, int frame);
	void Render(SpriteBatch* spriteBatch);

	void SetPosition(int x, int y){ m_X = x; m_Y = y;}
	void SetOriginal(int x, int y){ m_OX = x; m_OY = y;}
	void SetScale(float s){ m_Scale = s;}
	void SetRotation(float r){ m_Rotation = r;}
	int GetPositionX() { return m_X;}
	int GetPositionY() { return m_Y;}
	int GetOriginalX() { return m_OX;}
	int GetOriginalY() { return m_OY;}
	float GetDepth() { return m_Depth;}
	int GetWidth() { return m_Width;}
	int GetHeight() { return m_Height;}
};