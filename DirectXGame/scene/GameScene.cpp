#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>
#include <Affine.h>

GameScene::GameScene() {}

GameScene::~GameScene() {
	delete modelBlock_;
	//delete viewProjection_;
	//for (std::vector<WorldTransform*>& worldTransformBlockLine : worldTransformBlocks_) {
		for (WorldTransform* worldTransformBlock : worldTransformBlocks_) {
			delete worldTransformBlock;
		}
	//}
	worldTransformBlocks_.clear();
}

void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();

	textureHandle_ = TextureManager::Load("cube.jpg");

	modelBlock_ = Model::Create();
	// 要素数
	const uint32_t kNumBlockHorizontal = 20;
	// ブロック1個分の横幅
	const float kBlockWidth = 2.0f;
	// 要素数を変更する
	worldTransformBlocks_.resize(kNumBlockHorizontal);

	// キューブの生成
	for (uint32_t i = 0; i < kNumBlockHorizontal; ++i) {
		worldTransformBlocks_[i] = new WorldTransform();
		worldTransformBlocks_[i]->Initialize();
		worldTransformBlocks_[i]->translation_.x = kBlockWidth * 1;
		worldTransformBlocks_[i]->translation_.y = 0.0f;
	}

	//modelBlock_ = Model::Create();
	// ビュープロジェクションの初期化
	viewProjection_.Initialize();
	////要素数
	//const uint32_t kNumBlockVirtical = 10;
	//const uint32_t kNumBlockHorizontal = 20; 
	//// ブロック1個分の横幅
	//const float kBlockWidth = 2.0f;
	//const float kBlockHeight = 2.0f;
	//// 要素数を変更する
	//worldTransformBlocks_.resize(kNumBlockVirtical);
	//for (uint32_t i = 0; i < kNumBlockVirtical; ++i) {
	//	//
	//	worldTransformBlocks_[i].resize(kNumBlockHorizontal);
	//}
	
	// キューブの生成
	/*for (uint32_t i = 0; i < kNumBlockVirtical; ++i)
	{
		for (uint32_t j = 0; j < kNumBlockHorizontal; ++j)
		{
			worldTransformBlocks_[i][j] = new WorldTransform();
			worldTransformBlocks_[i][j]->Initialize();
			worldTransformBlocks_[i][j]->translation_.x = kBlockWidth * j;
			worldTransformBlocks_[i][j]->translation_.y = kBlockHeight * i;
		}
	}*/
}

void GameScene::Update() {
	//ブロックの更新
	//for (std::vector<WorldTransform*> worldTransformBlockTate : worldTransformBlocks_) {
	for (WorldTransform* worldTransformBlockYoko : /* worldTransformBlockTate*/ worldTransformBlocks_) {
			worldTransformBlockYoko->UpdateMatrix();
		}
	//}
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

	//ブロックの描画
	//for (std::vector<WorldTransform*> worldTransformBlockTate : worldTransformBlocks_) {
		for (WorldTransform* worldTransformBlockYoko : worldTransformBlocks_) {
			modelBlock_->Draw(*worldTransformBlockYoko, viewProjection_,textureHandle_);
		}
	//}
	

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}