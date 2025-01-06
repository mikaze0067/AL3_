#include "Clear.h"
#include <DirectXCommon.h>


ClearScene::~ClearScene() {}

void ClearScene::Initialize() {
	/*num[0] = TextureManager::Load("./Resources/0.png");
	num[1] = TextureManager::Load("./Resources/1.png");
	num[2] = TextureManager::Load("./Resources/2.png");
	num[3] = TextureManager::Load("./Resources/3.png");
	num[4] = TextureManager::Load("./Resources/4.png");
	num[5] = TextureManager::Load("./Resources/5.png");
	num[6] = TextureManager::Load("./Resources/6.png");
	num[7] = TextureManager::Load("./Resources/7.png");
	num[8] = TextureManager::Load("./Resources/8.png");
	num[9] = TextureManager::Load("./Resources/9.png");*/

	//texture=TextureManager::Load("./Resources/Clear.png");
}

void ClearScene::Update() {
	time--;
	if (time==0) {
		finished_ = true;
	}
	//sprite = Sprite::Create(texture, { 0, 0 });


}

void ClearScene::Draw() {
	//// 100の位のスコアを描画
	//if (scoreSprite100_ == nullptr) {
	//	scoreSprite100_ = Sprite::Create(num[score_100], { 100, 100 });
	//}
	//scoreSprite100_->Draw();

	//// 10の位のスコアを描画
	//if (scoreSprite10_ == nullptr) {
	//	scoreSprite10_ = Sprite::Create(num[score_10], { 150, 100 });
	//}
	//scoreSprite10_->Draw();

	//// 1の位のスコアを描画
	//if (scoreSprite1_ == nullptr) {
	//	scoreSprite1_ = Sprite::Create(num[score_1], { 200, 100 });
	//}
	//scoreSprite1_->Draw();

	////コマンドリストの取得
	//ID3D12GraphicsCommandList * commandList = dxCommon_->GetCommandList();
	//// 背景スプライト描画前処理
	//Sprite::PreDraw(commandList);
	//sprite->Draw();
	//// スプライト描画後処理
	//Sprite::PostDraw();
	//// 深度バッファクリア
	//dxCommon_->ClearDepthBuffer();
	
}

void ClearScene::SetScore(uint32_t score100, uint32_t score10, uint32_t score1)
{
	score_100 = score100;
	score_10 = score10;
	score_1 = score1;
}

