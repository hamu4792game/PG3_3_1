#include "GameManager.h"
#include <Novice.h>
#include "Game/Scene/TitleScene/TitleScene.h"
#include "Game/Scene/StageScene/StageScene.h"
#include "Game/Scene/ClearScene/ClearScene.h"

GameManager::GameManager() {
	// 各シーンの配列
	sceneArr_[TITLE] = std::make_unique<TitleScene>();
	sceneArr_[STAGE] = std::make_unique<StageScene>();
	sceneArr_[CLEAR] = std::make_unique<ClearScene>();

	// 初期シーンの設定
	currentSceneNo_ = TITLE;
	sceneArr_[currentSceneNo_]->Initialize();
}

GameManager::~GameManager() {

}

GameManager* GameManager::GetInstance() {
	static GameManager instance;
	return &instance;
}

int GameManager::Run() {
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		// シーンのチェック
		prevSceneNo_ = currentSceneNo_;
		currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();

		// シーン変更チェック
		if (prevSceneNo_ != currentSceneNo_) {
			sceneArr_[currentSceneNo_]->Initialize();
		}

		// 更新処理
		sceneArr_[currentSceneNo_]->Update();

		// 描画処理
		sceneArr_[currentSceneNo_]->Draw();

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}
	return 0;
}
