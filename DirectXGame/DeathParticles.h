#pragma once
#include <Model.h>
#include <ViewProjection.h>
#include <array>
#include <WorldTransform.h>


class DeathParticles {
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(Model* model, ViewProjection* viewProjection, const Vector3& position);

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private:

	ViewProjection* viewProjection_ = nullptr;
	// ワールドトランスフォーム
	//WorldTransform worldTransform_;
	// 3Dモデル
	Model* model_ = nullptr;

	//パーティクルの個数
	static inline const uint32_t kNumParticles = 8;

	std::array<WorldTransform, kNumParticles> worldTransforms_;

};