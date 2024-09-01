#include "Clear.h"


ClearScene::~ClearScene() {}

void ClearScene::Initialize() {}

void ClearScene::Update() {
	if (Input::GetInstance()->PushKey(DIK_SPACE)) {
		finished_ = true;
	}
}

void ClearScene::Draw() {}
