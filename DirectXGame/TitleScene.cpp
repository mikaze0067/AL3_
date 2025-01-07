#include "TitleScene.h"
#include"Input.h"
#include<cmath>
#include<numbers>
#include"DirectXCommon.h"


TitleScene::~TitleScene() {
	delete model_;
	delete sprite_;
}

void TitleScene::Initialize() {
	//model_ = Model::CreateFromOBJ("");
	// ビュープロジェクションの初期化
	viewProjection_.Initialize();
	finished_ = false;
	textureHandle_ = TextureManager::Load("Title.png");
	sprite_ = Sprite::Create(textureHandle_, {0, 0});

}

void TitleScene::Update() { 

	if (Input::GetInstance()->PushKey(DIK_SPACE)) {
		finished_ = true;
	}
	
	
}

void TitleScene::Draw() {
	DirectXCommon* dxCommon_ = DirectXCommon::GetInstance();
	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

	Sprite::PreDraw(commandList);
	sprite_->Draw();

	Sprite::PostDraw();
	dxCommon_->ClearDepthBuffer();
}
