#include "TitleScene.h"
#include"Input.h"
#include<cmath>
#include<numbers>
#include"DirectXCommon.h"


TitleScene::~TitleScene() { delete model_; }

void TitleScene::Initialize() {
	//model_ = Model::CreateFromOBJ("");
	// ビュープロジェクションの初期化
	viewProjection_.Initialize();
	finished_ = false;

	const float kPlayerScale = 10.0f;
	worldTransformPlayer_.Initialize();
	worldTransformPlayer_.scale_ = {kPlayerScale, kPlayerScale, kPlayerScale};
	worldTransformPlayer_.rotation_.y = 0.95f * std::numbers::pi_v<float>;
	worldTransformPlayer_.translation_.y = -9.0f;

}

void TitleScene::Update() { 

	if (Input::GetInstance()->PushKey(DIK_SPACE)) {
		finished_ = true;
	}
	counter_ += 1.0f / 60.0f;
	counter_ = std::fmod(counter_, kTimeTitleMove);

	float angle = counter_ / kTimeTitleMove * 2.0f * std::numbers::pi_v<float>;

	worldTransformTitle_.translation_.y = std::sin(angle) + 10.0f;

	viewProjection_.TransferMatrix();

	worldTransformPlayer_.UpdateMatrix();
	
}

void TitleScene::Draw() {
	DirectXCommon* dxCommon_ = DirectXCommon::GetInstance();
	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

	Model::PreDraw(commandList);
	//model_->Draw(worldTransformPlayer_, viewProjection_);
	Model::PostDraw();
}
