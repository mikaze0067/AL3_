#include "CoinManager.h"

void CoinManager::Initialize(Model* model, uint32_t textureHandle, int numCoins) {
	model_ = model;
	textureHandle_ = textureHandle;
	std::srand(static_cast<unsigned int>(std::time(nullptr))); // 乱数の初期化

	// 指定した枚数のコインを生成
	for (int i = 0; i < numCoins; ++i) {
		SpawnCoin();
	}
}

void CoinManager::Update() {
	for (auto it = coins_.begin(); it != coins_.end();) {
		it->Update();

		// 地面に落ちたら削除
		if (it->GetY() <= 0.0f) {
			it = coins_.erase(it);
		} else {
			++it;
		}
	}
}

void CoinManager::Draw(ViewProjection& viewProjection) {
	for (auto& coin : coins_) {
		coin.Draw(viewProjection);
	}
}

void CoinManager::SpawnCoin() {
	Coin newCoin;
	newCoin.Initialize(model_, textureHandle_);

	// コインの初期位置をランダムに設定
	float x = static_cast<float>(rand() % 10 - 5); // -5.0 ~ 4.0
	float y = 10.0f;                               // 高い位置から落とす
	float z = static_cast<float>(rand() % 10 - 5);

	newCoin.SetPosition({x, y, z});
	coins_.push_back(newCoin);
}
