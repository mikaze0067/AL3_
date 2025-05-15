#pragma once

#include "MathUtilityForText.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include <Model.h>

class RightDoor {
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(Model* model, ViewProjection* viewProjection);

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private:
	// ワールドトランスフォーム
	WorldTransform worldTransform_;
	// ワールドトランスフォーム
	ViewProjection* viewProjection_;

	Model* model_ = nullptr;
	uint32_t textureHandle_ = 0u;
};