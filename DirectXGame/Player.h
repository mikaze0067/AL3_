#include <WorldTransform.h>
#include <Model.h>
#include <Vector3.h>
#include <numbers>
#include <Input.h>
#include <MathUtilityForText.h>
#include <algorithm>

class MapChipField;

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

	const WorldTransform& GetWorldTransform() const { return worldTransform_; }

	const Vector3& GetVelocity() const { return velocity_; }

	void SetMapChipField(MapChipField* mapChipField) { mapChipField_ = mapChipField; }

	

	void inputMove();

	

	//角
	enum Corner {
		kRightBottom, //右下
		kLeftBottom,  //左下
		kRightTop,    //右上
		kLeftTop,     //左上

		kNumCorner    //要素数
	};

	

	void AnimateTurn();

	Vector3 CornerPosition(const Vector3& center, Corner corner);


	private:
	// ワールドトランスフォーム
	WorldTransform worldTransform_;
	// 3Dモデル
	Model* model_ = nullptr;
	// テクスチャハンドル
	uint32_t textureHandle_ = 0u;

	ViewProjection* viewProjection_ = nullptr;

	//マップチップによるフィールド
	MapChipField* mapChipField_ = nullptr;

	static inline const float kWidth = 0.8f;
	static inline const float kHeight = 0.8f;

	Vector3 velocity_ = {};
	// 接地状態フラグ
	bool onGround_ = true;
	//重力加速度（下方向）
	static inline const float kGravityAccleration = 0.098f;
	//最大落下速度
	static inline const float kLimitFallSpeed = 0.1f;
	//ジャンプ初速（上方向）
	static inline const float kJumpAcceleration = 0.6f;
	//着地時の速度減衰率
	static inline const float kAttenuationLanding = 0.01f;

	// 左右
	enum class LRDirection {
		kRight,
		kLeft,
	};

	struct CollisionMapInfo {
		bool ceiling = false; // 天井
		bool landing = false; // 着陸
		bool hitWall = false; // 壁
		Vector3 move;
	};

	void ChecMapCollision(CollisionMapInfo& info);

	void ChecMapCollisionUp(CollisionMapInfo& info);
	void ChecMapCollisionDown(CollisionMapInfo& info);
	void ChecMapCollisionRight(CollisionMapInfo& info);
	void ChecMapCollisionLeft(CollisionMapInfo& info);

	void CheckMapMove(const CollisionMapInfo& info);

	void CheckMapCelling(const CollisionMapInfo& info);

	void CheckMapLanding(const CollisionMapInfo& info);
	
	void CheckMapHItWall(const CollisionMapInfo& info);

	static inline const float kAttenuationWall = 0.2f;


	//旋回開始時の角度
	float turnFirstRotationY_ = 0.0f;
	//旋回タイマー
	float turnTimer_ = 0.0f;
	//旋回時間<秒>
	static inline const float kTimeTurn = 0.3f;

	static inline const float kAcceleration = 0.01f;
	static inline const float kAttenuation = 0.1f;
	static inline const float kLimitRunSpeed = 0.1f;
	
	LRDirection lrDirection_ = LRDirection::kRight;

	static inline const float kGroundSearchHeight = 0.2f;

	static inline const float kBlank = 1.0f;

	

};