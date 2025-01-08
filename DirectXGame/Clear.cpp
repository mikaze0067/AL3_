#include "Clear.h"
#include <DirectXCommon.h>


ClearScene::~ClearScene() {}

void ClearScene::Initialize() {
	
	texture=TextureManager::Load("./Resources/Clear.png");
	sprite = Sprite::Create(texture, {-100, 0});
}

void ClearScene::Update() {
	time--;
	if (time==0) {
		finished_ = true;
	}
	//sprite = Sprite::Create(texture, { 0, 0 });


}

void ClearScene::Draw() {
	DirectXCommon* dxCommon_ = DirectXCommon::GetInstance();
	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

	Sprite::PreDraw(commandList);
	sprite->Draw();

	Sprite::PostDraw();
	dxCommon_->ClearDepthBuffer();
	
}
