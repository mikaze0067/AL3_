#include "GameScene.h"
#include "TextureManager.h"
#include <AxisIndicator.h>
#include <ImGuiManager.h>
#include <PrimitiveDrawer.h>
#include <cassert>
#include <iostream>

GameScene::GameScene() {}

GameScene::~GameScene() {
	delete model_;
	delete player_;
	delete debugCamera_;
	delete blink_;
	delete blink2_;
	delete puchun_;
}

void GameScene::Initialize() {
	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();
	// ファイル名を指定してテクスチャを読み込む
	textureHandle_ = TextureManager::Load("mario.jpg");
	textureHandle2_ = TextureManager::Load("White.png");
	textureHandle3_ = TextureManager::Load("tyoiWhite.png");
	std::vector<uint32_t> puchunTextures =
	{TextureManager::Load("Puchun/Puchun1.png"), TextureManager::Load("Puchun/Puchun2.png"), TextureManager::Load("Puchun/Puchun3.png"), TextureManager::Load("Puchun/Puchun4.png"),
	 TextureManager::Load("Puchun/Puchun5.png"), TextureManager::Load("Puchun/Puchun6.png"), TextureManager::Load("Puchun/Puchun7.png")};

	// 3Dモデルの生成
	model_ = Model::Create();
	// ワールドトランスフォームの初期化
	worldTransform_.Initialize();
	// ビュープロジェクションの初期化
	viewProjection_.Initialize();

	// 自キャラの生成
	player_ = new Player();
	// 自キャラの初期化
	player_->Initialize(model_, textureHandle_);

	// デバッグカメラの生成
	debugCamera_ = new DebugCamera(1280, 720);

	blink_ = new Blink();
	blink_->Initialize(textureHandle2_);

	blink2_ = new Blink2();
	blink2_->Initialize(textureHandle3_, textureHandle2_);

	puchun_ = new Puchun();
	puchun_->Initialize(puchunTextures, audio_);

	// 軸方向表示の表示を有効にする
	AxisIndicator::GetInstance()->SetVisible(true);
	// 軸方向表示が参照するビュープロジェクションを指定する（アドレス渡し）
	AxisIndicator::GetInstance()->SetTargetViewProjection(&viewProjection_);
}

void GameScene::Update() {
	// 自キャラの更新
	player_->Update();

	blink_->Update();
	blink2_->Update();
	puchun_->Update();

#ifdef _DEBUG
	if (input_->TriggerKey(DIK_SPACE)) {
		isDebugCameraActive_ = true;
	}
#endif
	if (input_->TriggerKey(DIK_SPACE)) {
		puchun_->Start();
	}

	// カメラの処理
	if (isDebugCameraActive_) {
		// デバッグカメラの更新
		debugCamera_->Update();
		viewProjection_.matView = debugCamera_->GetViewProjection().matView;
		viewProjection_.matProjection = debugCamera_->GetViewProjection().matProjection;
		// ビュープロジェクション行列の転送
		viewProjection_.TransferMatrix();
	} else {
		// ビュープロジェクション行列の更新と転送
		viewProjection_.UpdateMatrix();
	}
}

void GameScene::Draw() {
	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	if (input_->TriggerKey(DIK_1)) {
	}
	// blink_->Draw();

	if (input_->TriggerKey(DIK_2)) {
	}
	// blink2_->Draw();

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>
	//blink3_->Draw(commandList);

	// 自キャラの描画
	player_->Draw(viewProjection_);

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>
	puchun_->Draw();

	// スプライト描画後処理
	Sprite::PostDraw();
#pragma endregion
}
