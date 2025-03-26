#pragma once

#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include <DebugCamera.h>
#include <Player.h>
#include "MathUtilityForText.h"
#include "LightGroup.h" 
#include <Blink.h>
#include <Blink2.h>
#include <Puchun.h>

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {

public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	// 3Dモデル
	Model* model_ = nullptr;
	// ワールドトランスフォーム
	WorldTransform worldTransform_;
	// ビュープロジェクション
	ViewProjection viewProjection_;

private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;
	// テクスチャハンドル
	uint32_t textureHandle_ = 0;
	uint32_t textureHandle2_ = 0;
	uint32_t textureHandle3_ = 0;

	//自キャラ
	Player* player_ = nullptr;
	//デバッグカメラ有効
	bool isDebugCameraActive_ = false;

	DebugCamera* debugCamera_ = nullptr;

	Blink* blink_ = nullptr; // ライトグループ

	Blink2* blink2_ = nullptr; // ライトグループ

	Puchun* puchun_ = nullptr;
	uint32_t pichunSound_ = 0;


	/// <summary>
	/// ゲームシーン用
	/// </summary>
};
