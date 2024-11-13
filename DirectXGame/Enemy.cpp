#include "Enemy.h"
#include <cassert>
#include "MathUtilityForText.h"


void Enemy::Initialize(Model* model, uint32_t textureHandle) {
	// NULLポインタチェック
	assert(model);

	model_ = model;
	textureHandle_ = textureHandle;
	// ワールド変換の初期化
	worldTransform_.Initialize();
}

void Enemy::Update() {
	
	// キャラクターの移動ベクトル
	Vector3 move = {0, 0, 0};

	// キャラクターの移動速さ
	const float kCharacterSpeed = 0.2f;

	//move.x -= kCharacterSpeed;
	//move.x += kCharacterSpeed;
	//move.y -= kCharacterSpeed;
	//move.y += kCharacterSpeed;
	//move.z -= kCharacterSpeed;
	//move.z += kCharacterSpeed;
	
	// 座標移動（ベクトルの加算）
	//worldTransform_.translation_ += move;

	// アフィン変換行列の作成
	//(MakeAffineMatrix：自分で作った数学系関数)
	worldTransform_.matWorld_ = MakeAffineMatrix(worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);

	const float kMoveLimitX = 34;
	const float kMoveLimitY = 18;

	worldTransform_.translation_.x = max(worldTransform_.translation_.x, -kMoveLimitX);
	worldTransform_.translation_.x = min(worldTransform_.translation_.x, +kMoveLimitX);
	worldTransform_.translation_.y = max(worldTransform_.translation_.y, -kMoveLimitY);
	worldTransform_.translation_.y = min(worldTransform_.translation_.y, +kMoveLimitY);

	// 行列を定数バッファに転送
	worldTransform_.TransferMatrix();

	switch (phase_) {
	case Phase::Approach:
	default:
		// 移動（ベクトルを加算）
		worldTransform_.translation_ += move;
		// 既定の位置に到達したら離脱
		if (worldTransform_.translation_.z < 0.0f) {
			phase_ = Phase::Leave;
		}
		break;
	case Phase::Leave:
		// 移動（ベクトルを加算）
		worldTransform_.translation_ += move;
	}
}

void Enemy::Draw(ViewProjection& viewProjection) {
	// 3Dモデルを描画
	model_->Draw(worldTransform_, viewProjection, textureHandle_);
}