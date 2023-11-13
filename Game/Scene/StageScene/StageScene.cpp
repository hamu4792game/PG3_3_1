#include "StageScene.h"
#include <Input.h>
#include <Novice.h>

StageScene::StageScene() {
	enemy_ = std::make_unique<Enemy>();
	player_ = std::make_unique<Player>();
}

void StageScene::Initialize() {
	enemy_->Initialize();
	player_->Initialize();
}

void StageScene::Update() {
	enemy_->Update();
	player_->Update();

	if (player_->EnemyColl(enemy_->GetPos(), enemy_->GetSize())) {
		sceneNo = CLEAR;
	}

}

void StageScene::Draw() {
	Novice::DrawBox(0, 0, 300, 20, 0.0f, 0x000000ff, kFillModeSolid);
	Novice::ScreenPrintf(0, 0, "GameScene = StageScene");

	enemy_->Draw();
	player_->Draw();
}
