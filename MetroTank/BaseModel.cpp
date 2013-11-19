#include "pch.h"
#include "BaseModel.h"
#include "WICTextureLoader.h"
#include "DirectXHelper.h"

BaseModel::BaseModel()
{
	m_X = 0;
	m_Y = 0;
	m_Depth = 0;
	m_Width = 1;
	m_Height = 1;
	m_Rotation = 0;
	m_Scale = 1;
}
ID3D11Device1* BaseModel::m_d3dDevice = NULL;
ID3D11DeviceContext1* BaseModel::m_d3dContext = NULL;
void BaseModel::Init(ID3D11Device1* d3dDevice, ID3D11DeviceContext1* d3dContext)
{
	m_d3dDevice = d3dDevice;
	m_d3dContext = d3dContext;
}

void BaseModel::SetTexture(wchar_t* path)
{
	DX::ThrowIfFailed(
        CreateWICTextureFromFile(m_d3dDevice,m_d3dContext,path,NULL,&m_Texture,NULL)
    );
	ID3D11Texture2D* texture2D;
	ID3D11Resource* resource;
	m_Texture->GetResource(&resource);
	texture2D = (ID3D11Texture2D*)resource;
	D3D11_TEXTURE2D_DESC desc;
	texture2D->GetDesc(&desc);
	m_Width = desc.Width;
	m_Height = desc.Height;
}
void BaseModel::SetAnimation(wchar_t* path, int frame)
{
}
void BaseModel::Render(SpriteBatch* spriteBatch)
{
	//void Draw(_In_ ID3D11ShaderResourceView* texture, FXMVECTOR position, _In_opt_ RECT const* sourceRectangle, FXMVECTOR color = Colors::White, float rotation = 0, FXMVECTOR origin = g_XMZero, float scale = 1, SpriteEffects effects = SpriteEffects_None, float layerDepth = 0);
	RECT rect;
	rect.left = 0;
	rect.top = 0;
	rect.right = m_Width;
	rect.bottom = m_Height;
	FXMVECTOR position = { m_X, m_Y};
	FXMVECTOR original = {m_OX, m_OY};
	
	spriteBatch->Draw(
		m_Texture, 
		position, 
		&rect, 
		Colors::White, 
		m_Rotation, 
		original, 
		m_Scale,
		SpriteEffects_None, 
		m_Depth
		);

}