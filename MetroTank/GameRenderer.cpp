#include "pch.h"
#include "GameRenderer.h"
#include "WICTextureLoader.h"

using namespace Microsoft::WRL;
using namespace Windows::Foundation;
using namespace Windows::System;


void GameRenderer::CreateDeviceResources()
{
	Direct3DBase::CreateDeviceResources();

	D3D11_BLEND_DESC1 blendDesc;
    ZeroMemory(&blendDesc, sizeof(blendDesc));
    blendDesc.AlphaToCoverageEnable = false;
    blendDesc.IndependentBlendEnable = false;
    blendDesc.RenderTarget[0].BlendEnable = true;
    blendDesc.RenderTarget[0].LogicOpEnable = false;
    blendDesc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
    blendDesc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
    blendDesc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
    blendDesc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
    blendDesc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ONE;
    blendDesc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
    blendDesc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
    DX::ThrowIfFailed(
        m_d3dDevice->CreateBlendState1(
            &blendDesc,
            &m_blendStateAlpha
            )
        );
	spriteBatch = std::unique_ptr<DirectX::SpriteBatch>(
		new DirectX::SpriteBatch(m_d3dContext.Get()));
	BaseModel::Init(m_d3dDevice.Get(), m_d3dContext.Get());
	m_Tank = new Tank();
}

void GameRenderer::CreateWindowSizeDependentResources()
{
	Direct3DBase::CreateWindowSizeDependentResources();

}

void GameRenderer::Update(float timeTotal, float timeDelta)
{
	m_Tank->UpdateTrack();
	BulletManager::GetSingleton()->Update();
}

void GameRenderer::UpdateMouseMoved(int x, int y)
{
	m_Tank->Track(x,y);
}
void GameRenderer::UpdateMouseClicked(int x, int y)
{
	m_Tank->Fire();
}

void GameRenderer::UpdateKeyDown(CoreWindow^ window)
{
	CoreVirtualKeyStates zKeyState = window->GetAsyncKeyState(VirtualKey::Z);
	if( zKeyState == CoreVirtualKeyStates::Down)
	{
		m_Tank->SetFollow(false);
	}
	else if ( zKeyState == CoreVirtualKeyStates::None)
	{
		m_Tank->SetFollow(true);
	}
}


void GameRenderer::Render()
{
	m_d3dContext->OMSetRenderTargets(
        1,
        m_renderTargetView.GetAddressOf(),
        m_depthStencilView.Get()
        );
 
    const float lightBlue[] = { 0.705f, 0.705f, 1.000f, 1.000f };
    m_d3dContext->ClearRenderTargetView(
        m_renderTargetView.Get(),
        lightBlue
        );
 
    m_d3dContext->ClearDepthStencilView(
        m_depthStencilView.Get(),
        D3D11_CLEAR_DEPTH,
        1.0f,
        0
        );
	
	spriteBatch->Begin(SpriteSortMode_Deferred,m_blendStateAlpha.Get());
	
	m_Tank->Render(spriteBatch.get());
	BulletManager::GetSingleton()->Render(spriteBatch.get());

	spriteBatch->End();
}
