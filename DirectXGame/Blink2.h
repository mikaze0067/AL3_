#pragma once
#include <cmath> // fmod()
#include <Sprite.h>

class Blink2 {
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(uint32_t textureHandle1, uint32_t textureHandle2);

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private:
	float time = 0.0f;
	bool isVisible = true;
	Sprite* sprite_1 = nullptr;
	Sprite* sprite_2 = nullptr;
};

