#include <WorldTransform.h>
#include <Model.h>
#include <Vector3.h>
#include <numbers>
#include <Input.h>
#include <MathUtilityForText.h>
#include <algorithm>



/// <summary>
/// 自キャラ
/// </summary>
class Player{
public:
	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="model">モデル</param>
	/// <param name="textureHandle">テクスチャハンドル</param>
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
	// ワールドトランスフォーム
	WorldTransform worldTransform_;
	// 3Dモデル
	Model* model_ = nullptr;
	// テクスチャハンドル
	uint32_t textureHandle_ = 0u;

	ViewProjection* viewProjection_ = nullptr;

	Vector3 velocity_ = {};
	// 接地状態フラグ
	bool onGround_ = true;
	//重力加速度（下方向）
	static inline const float kGravityAccleration = 0.09f;
	//最大落下速度
	static inline const float kLimitFallSpeed = 1.0f;
	//ジャンプ初速（上方向）
	static inline const float kJumpAcceleration = 1.2f;
	// 左右
	enum class LRDirection {
		kRight,
		kLeft,
	};

	//旋回開始時の角度
	float turnFirstRotationY_ = 0.0f;
	//旋回タイマー
	float turnTimer_ = 0.0f;
	//旋回時間<秒>
	static inline const float kTimeTurn = 0.3f;

	static inline const float kAcceleration = 0.02f;
	static inline const float kAttenuation = 0.2f;
	static inline const float kLimitRunSpeed = 0.5f;
	
	LRDirection lrDirection_ = LRDirection::kRight;
};