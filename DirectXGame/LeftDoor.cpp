#include "LeftDoor.h"

void LeftDoor::Initialize(Model* model, ViewProjection* viewProjection) {
	// ワールド変換の初期化
	worldTransform_.Initialize();

	model_ = model;
	viewProjection_ = viewProjection;
	worldTransform_.scale_ = {
	    2.5f,
	    2.5f,
	    2.5f,
	};
	worldTransform_.translation_ = {0.0f, -5.0f, 0.5f};
}

void LeftDoor::Update() {
	// アフィン変換行列の作成
	//(MakeAffineMatrix：自分で作った数学系関数)
	worldTransform_.matWorld_ = MakeAffineMatrix(worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);

	// 定数バッファに転送
	worldTransform_.TransferMatrix();


	if (worldTransform_.translation_.x >= -12.0f) {
		worldTransform_.translation_.x -= 0.1f;
	}

}

void LeftDoor::Draw() {
	// 3Dモデルを描画
	model_->Draw(worldTransform_, *viewProjection_);
}
