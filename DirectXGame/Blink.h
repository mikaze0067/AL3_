#pragma once
#include <d3d12.h>
#include <wrl.h>
#include "Sprite.h"

class Blink {
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(uint32_t textureHandle); 

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private:
#pragma region チカチカ

	 float alpha = 0.0f;
	float time = 0.0f;
	Sprite* sprite_ = nullptr;
#pragma endregion
};
