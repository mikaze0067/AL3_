#pragma once
#include <Sprite.h>
#include <Input.h>
#include <WorldTransform.h>
#include <ViewProjection.h>

class fade {
public: // メンバ関数
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(Sprite* sprite, uint32_t textureHandle);

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw(ViewProjection& viewProjection);

private:

	// ワールドトランスフォーム
	WorldTransform worldTransform_;
	uint32_t textureHandle_ = 0;
	Sprite* sprite_ = nullptr;
	Input* input = nullptr;

	// 透明度制御用の変数
	float color = 1.0f;

	bool bossFrag = false; // ボスフラグ
	int timer = 0;         // カウントダウンタイマー
};