#pragma once
#include "ViewProjection.h"
#include "WorldTransform.h"
#include <Model.h>
#include <cstdlib>
#include <ctime>
#include <vector>


class Coin {
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

	void SetRandomRotation();

	void SetRandomPosition();

	void SetRandomBehavior();

	bool IsDead() const { return isDead_; }


private:
	// ワールドトランスフォーム
	WorldTransform worldTransform_;
	// ワールドトランスフォーム
	ViewProjection* viewProjection_;

	Vector3 velocity_ = {0.0f, 0.0f, 0.0f}; // 初速度
	float gravity_ = -0.015f; // 重力加速度（Y軸にマイナス）
	float bounceFactor_ = 0.2f;             // 跳ね返り係数（反発の強さ）
	bool grounded_ = false;                 // 地面に止まったかどうか

	Model* model_ = nullptr;
	uint32_t textureHandle_ = 0u;
	float timeOffset_ = 0.0f; // 浮遊アニメーション
	bool isDead_ = false;

};