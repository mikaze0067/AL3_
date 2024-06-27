#define NOMINMAX
#include "Player.h"
#include <cassert>

void Player::Initialize(Model* model, ViewProjection* viewProjection, const Vector3& position) {
	// NULLポインタチェック
	assert(model);

	model_ = model;
	//textureHandle_ = textureHandle;
	// ワールド変換の初期化
	worldTransform_.Initialize();
	worldTransform_.translation_ = position;
	worldTransform_.rotation_.y = std::numbers::pi_v<float> / 2.0f;
	viewProjection_ = viewProjection;
}
void Player::Update() {
	//行列を定数バッファに転送
	worldTransform_.TransferMatrix();
	
	//移動入力
	if (onGround_) {
		// 左右移動
		if (Input::GetInstance()->PushKey(DIK_RIGHT) || Input::GetInstance()->PushKey(DIK_LEFT)) {
			// 旋回制御
			{
				if (turnTimer_ > 0.0f) {
					turnTimer_ -= 1.0f / 60.0f;

					// 左右の自キャラ角度テーブル
					float destinationRotationYtable[] = {std::numbers::pi_v<float> / 2.0f, std::numbers::pi_v<float> * 3.0f / 2.0f};
					// 状態に応じた角度を取得する
					float destinationRotationY = destinationRotationYtable[static_cast<uint32_t>(lrDirection_)];
					// 自キャラの角度を設定する
					worldTransform_.rotation_.y = EaseInOut(destinationRotationY, turnFirstRotationY_, turnTimer_ / kTimeTurn);
				}
			}
			// 左右加速
			Vector3 acceleration = {};
			if (Input::GetInstance()->PushKey(DIK_RIGHT)) {
				// 左移動中の右入力
				if (velocity_.x < 0.0f) {
					// 速度と逆方向に入力中は急ブレーキ
					velocity_.x *= (1.0f - kAttenuation);
				}
				acceleration.x += kAcceleration;
			    if (lrDirection_ != LRDirection::kRight) {
				    lrDirection_ = LRDirection::kRight;
				    turnFirstRotationY_ = worldTransform_.rotation_.y;
				    turnTimer_ = kTimeTurn;
			    }
			} else if (Input::GetInstance()->PushKey(DIK_LEFT)) {
				// 右移動中の左入力
				if (velocity_.x > 0.0f) {
					// 速度と逆方向に入力中は急ブレーキ
					velocity_.x *= (1.0f - kAttenuation);
				}
				acceleration.x -= kAcceleration;
				if (lrDirection_ != LRDirection::kLeft){
				    lrDirection_ = LRDirection::kLeft;
				    turnFirstRotationY_ = worldTransform_.rotation_.y;
				    turnTimer_ = kTimeTurn;
			    }
			}
			// 加速／減速
			velocity_ += acceleration;
			// 最大速度制限
			velocity_.x = std::clamp(velocity_.x, -kLimitRunSpeed, kLimitRunSpeed);
		} else {
			// 非入力時は移動減衰をかける
			velocity_.x *= (1.0f - kAttenuation);
		}
		if (Input::GetInstance()->PushKey(DIK_UP)) {
			//ジャンプ初速
			velocity_ += Vector3(0, kJumpAcceleration, 0);
		}
		//空中
	} else {
		//落下速度
		velocity_ += Vector3(0, -kGravityAccleration, 0);
		//落下速度制限
		velocity_.y = std::max(velocity_.y, -kLimitFallSpeed);
	}
	//移動
	worldTransform_.translation_ += velocity_;

	//行列計算
	worldTransform_.UpdateMatrix();

	// 着地フラグ
	bool landing = false;

	// 地面との当たり判定
	// 下降中？
	if (velocity_.y < 0) {
		// 座標が地面以下になったら着地
		if (worldTransform_.translation_.y <= 1.0f) {
			landing = true;
		}
	}

	// 接地判定
	if (onGround_) {
		// ジャンプ開始
		if (velocity_.y > 0.0f) {
			// 空中状態に移行
			onGround_ = false;
		}
	}else {
		// 着地
		if (landing) {
			// めり込み
			worldTransform_.translation_.y = 1.0f;
			// 摩擦で横方向速度が減衰する
			velocity_.x *= (1.0f - kAcceleration);
			// 下方向速度リセット
			velocity_.y = 0.0f;
			// 接地状態に移行
			onGround_ = true;
		}
	}
}

void Player::Draw() { 
	//3Dモデルを描画
	model_->Draw(worldTransform_, *viewProjection_, textureHandle_);
}