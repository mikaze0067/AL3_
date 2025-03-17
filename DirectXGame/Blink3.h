#pragma once
#include "Sprite.h"
#include <d3d12.h>
#include <wrl.h>

class Blink3 {
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(uint32_t textureHandle, int screenWidth, int screenHeight);

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 画面全体のフラッシュ描画
	/// </summary>
	void Draw(ID3D12GraphicsCommandList* cmdList);

private:
	float alpha = 0.0f;
	float time = 0.0f;
	Sprite* overlay_ = nullptr;
};
