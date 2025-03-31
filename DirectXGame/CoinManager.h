#pragma once
#include "Coin.h"
#include <cstdlib> // rand()
#include <ctime>   // time()
#include <vector>

class CoinManager {
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(Model* model, uint32_t textureHandle, int numCoins);

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw(ViewProjection& viewProjection);

private:
	/// <summary>
	/// コインを生成
	/// </summary>
	void SpawnCoin();

	std::vector<Coin> coins_;
	Model* model_;
	uint32_t textureHandle_;
};
