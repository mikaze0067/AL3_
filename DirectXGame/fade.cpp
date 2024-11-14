#include "Fade.h"

void fade::Initialize(Sprite* sprite, uint32_t textureHandle) {
	textureHandle_ = textureHandle;

	// スプライトの生成
	sprite_ = sprite;
	// ワールド変換の初期化
	worldTransform_.Initialize();
	// シングルトンインスタンスを取得する
	input_ = Input::GetInstance();
}

void fade::Update() {}

void fade::Draw(ViewProjection& viewProjection) {}
