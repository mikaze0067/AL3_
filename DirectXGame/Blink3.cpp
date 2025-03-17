#include "Blink3.h"
#include <cmath> // sin()

void Blink3::Initialize(uint32_t textureHandle, int screenWidth, int screenHeight) {
	// 画面全体を覆う白いスプライトを作成
	overlay_ = Sprite::Create(textureHandle, {0, 0}, {1.0f, 1.0f, 1.0f, 1.0f});
	overlay_->SetSize({static_cast<float>(screenWidth), static_cast<float>(screenHeight)});
}

void Blink3::Update() {
	time += 0.1f;
	alpha = (sin(time * 3.14f) + 1.0f) / 2.0f; // 0.0 ～ 1.0 の範囲で変化
}

void Blink3::Draw(ID3D12GraphicsCommandList* cmdList) {
	if (!overlay_) {
		return;
	}

	overlay_->SetColor({1.0f, 1.0f, 1.0f, alpha});     // 白色 + アルファ適用
	Sprite::PreDraw(cmdList, Sprite::BlendMode::kAdd); // 加算ブレンドを適用
	overlay_->Draw();
	Sprite::PostDraw();
}
