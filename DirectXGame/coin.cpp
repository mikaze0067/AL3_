#include "Coin.h"

void Coin::Initialize(Model* model, uint32_t textureHandle) {
	assert(model);

	model_ = model;
	textureHandle_ = textureHandle;
	worldTransform_.Initialize();
}

void Coin::Update() {
	// 落下処理
	worldTransform_.translation_.y += velocity_.y;
}

void Coin::Draw(ViewProjection& viewProjection) { model_->Draw(worldTransform_, viewProjection, textureHandle_); }

void Coin::SetPosition(const Vector3& position) { worldTransform_.translation_ = position; }

float Coin::GetY() const { return worldTransform_.translation_.y; }
