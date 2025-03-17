#include "Blink.h"
#include <cmath> // sin()
#include "Blink2.h"

void Blink::Initialize(uint32_t textureHandle) {
	// Sprite::Create(テクスチャ, 位置) を使用
	sprite_ = Sprite::Create(textureHandle, {0, 0}); // 適宜位置を調整
}

void Blink::Update() {
	time += 0.1f;                      // 点滅速度を調整
	alpha = (sin(time) + 1.0f) / 2.0f; // 0.0 ～ 1.0 の範囲
}

void Blink::Draw() {
	if (sprite_) {
		// 透明度を適用
		sprite_->SetColor({1.0f, 1.0f, 1.0f, alpha}); // RGBA (白 + 透明度)
		sprite_->Draw();
	}
}
