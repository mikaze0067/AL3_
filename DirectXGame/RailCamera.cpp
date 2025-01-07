#include "RailCamera.h"
#include <cmath>


struct Quaternion {
	float x, y, z, w;
};

Quaternion Conjugate(const Quaternion& quaternion) {

	Quaternion conjugate;
	conjugate.w = quaternion.w;
	conjugate.x = -quaternion.x; // x の符号を反転
	conjugate.y = -quaternion.y; // y の符号を反転
	conjugate.z = -quaternion.z; // z の符号を反転

	return conjugate;
}

float Norm(const Quaternion& quaternion) { return std::sqrt(quaternion.w * quaternion.w + quaternion.x * quaternion.x + quaternion.y * quaternion.y + quaternion.z * quaternion.z); }


Quaternion Inverse(const Quaternion& quaternion) {
	float normSquared = Norm(quaternion) * Norm(quaternion);
	if (normSquared == 0.0f) {
		return {0.0f, 0.0f, 0.0f, 0.0f};
	}
	Quaternion conjugate = Conjugate(quaternion);
	return {conjugate.x / normSquared, conjugate.y / normSquared, conjugate.z / normSquared, conjugate.w / normSquared};
}


void RailCamera::Initialize() {
	// ワールドトランスフォームの初期化
	 // 引数でワールド座標を受け取ってワールドトランスフォームに設定
    worldTransform_.translation_ = {0.0f, 0.0f, 0.0f}; // 位置を初期化

    // 引数で回転角（ラジアン）を受け取ってワールドトランスフォームに設定
    worldTransform_.rotation_ = {0.0f, 0.0f, 0.0f}; // 回転を初期化
	// ビュープロジェクションの初期化
	viewProjection_.Initialize();

}

void RailCamera::Update() {
	// ワールドトランスフォームの座標を加算して移動
    worldTransform_.translation_.z += 0.1f; // Z軸方向に前進

    // ワールドトランスフォームの角度を加算して回転
    worldTransform_.rotation_.y += 0.01f; // Y軸回転（ラジアン）

    // ワールドトランスフォームのワールド行列再計算
    worldTransform_.UpdateMatrix();
	//カメラオブジェクトのワールド行列からビュー行列を計算する
	viewProjection_.matView = Inverse(worldTransform_.matWorld_);
}
