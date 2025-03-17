#include "Blink2.h"

void Blink2::Initialize(uint32_t textureHandle1, uint32_t textureHandle2) {
	// 2つのスプライトを初期化
	sprite_1 = Sprite::Create(textureHandle1, {0, 0});
	sprite_2 = Sprite::Create(textureHandle2, {0, 0}); // 位置は適宜調整
}

void Blink2::Update() {
	time += 0.1f;                           // 点滅速度
	isVisible = (fmod(time, 0.5f) < 0.25f); // 0.25秒ごとに切り替え
}

void Blink2::Draw() {
	if (isVisible) {
		sprite_1->Draw();
	} else {
		sprite_2->Draw();
	}
}
