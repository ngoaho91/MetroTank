#pragma once

#include <wrl.h>
#include <memory>

#include "Direct3DBase.h"
#include "SpriteBatch.h"
#include "Tank.h"

using namespace DirectX;
using namespace Windows::UI::Core;

ref class GameRenderer sealed : public Direct3DBase
{
public:
	// Direct3DBase methods.
	virtual void CreateDeviceResources() override;
	virtual void CreateWindowSizeDependentResources() override;
	virtual void Render() override;
	
	// Method for updating time-dependent objects.
	void Update(float timeTotal, float timeDelta);
	void UpdateMouseMoved(int x, int y);
	void UpdateMouseClicked(int x, int y);
	void UpdateKeyDown(CoreWindow^ window);
private:
	std::unique_ptr<DirectX::SpriteBatch> spriteBatch;
	Microsoft::WRL::ComPtr<ID3D11BlendState1> m_blendStateAlpha;
	Tank* m_Tank;
};
