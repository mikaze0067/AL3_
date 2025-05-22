#include "Pachinko.h"

void Pachinko::Initialize(Model* model, ViewProjection* viewProjection, Input* input) {
	worldTransform_.Initialize();
	audio_ = Audio::GetInstance();
	dxCommon_ = DirectXCommon::GetInstance();



	model_ = model;
	viewProjection_ = viewProjection;
	input_ = input; // ←追加

	worldTransform_.scale_ = {2.5f, 2.5f, 2.5f};
	worldTransform_.translation_ = {0.0f, -3.0f, 0.0f};
	// 白円テクスチャ読み込み
	fadeCircleTextureHandle_ = TextureManager::Load("white_circle.png");
	// スプライト作成（中央に配置したいのでアンカーポイントを中心に）
	fadeCircleSprite_ = Sprite::Create(fadeCircleTextureHandle_, {640.0f, 360.0f});
	fadeCircleSprite_->SetAnchorPoint({0.5f, 0.5f}); // 中心基準
}


void Pachinko::Update() {
	// スペースが押された「瞬間」に移動開始
	if (input_->TriggerKey(DIK_SPACE)) {
		isMoving_ = true;
		isFading_ = true; // フェード開始
	}

	 // 移動処理
	if (isMoving_) {
		Move();

		// Z座標が -33.0f 以下になったら移動停止
		if (worldTransform_.translation_.z <= -33.0f) {
			isMoving_ = false;
		}
	}

	if (isFading_) {
		fadeScale_ += 0.05f; // 拡大速度

		if (fadeScale_ > 4.0f) {
			fadeScale_ = 4.0f;
		}

		fadeCircleSprite_->SetSize({256.0f * fadeScale_, 256.0f * fadeScale_});
	}

	worldTransform_.matWorld_ = MakeAffineMatrix(worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);
	worldTransform_.TransferMatrix();

	
}

void Pachinko::Draw() {
	model_->Draw(worldTransform_, *viewProjection_);

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

	 // 2D描画開始
	Sprite::PreDraw(commandList);

	// 白円フェード描画
	if (isFading_ && fadeCircleSprite_) {
		fadeCircleSprite_->Draw();
	}

	// 2D描画終了
	Sprite::PostDraw();

}

void Pachinko::Move() {
	// 移動量の調整
	worldTransform_.translation_ += {0.0f, 0.01f, -0.2f};
}