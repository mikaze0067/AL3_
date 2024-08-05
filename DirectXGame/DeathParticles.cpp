#include "DeathParticles.h"
#include <cassert>

void DeathParticles::Initialize(Model* model, ViewProjection* viewProjection, const Vector3& position) {
	// NULLポインタチェック
	assert(model);

	model_ = model;
	viewProjection_ = viewProjection;

	//ワールド変換の初期化
	for (auto& worldTransform : worldTransforms_) {
		worldTransform.Initialize();
		worldTransform.translation_ = position;
	}
}

void DeathParticles::Update() {}

void DeathParticles::Draw() {}
