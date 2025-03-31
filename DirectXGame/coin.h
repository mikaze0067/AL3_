#pragma once
#include "MathUtilityForText.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include <Model.h>

class Coin {
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(Model* model, uint32_t textureHandle);

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw(ViewProjection& viewProjection);

	/// <summary>
	/// 位置を設定
	/// </summary>
	void SetPosition(const Vector3& position);

	/// <summary>
	/// Y座標を取得
	/// </summary>
	float GetY() const;

private:
	// ワールドトランスフォーム
	WorldTransform worldTransform_;
	// 3Dモデル
	Model* model_ = nullptr;
	// テクスチャハンドル
	uint32_t textureHandle_ = 0u;
	// 落下速度
	Vector3 velocity_ = {0.0f, -0.1f, 0.0f}; // 下方向に落下
};
