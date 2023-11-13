#include "ClearScene.h"
#include <Input.h>
#include <Novice.h>

void ClearScene::Initialize() {
	color = 0x0000ffff;
}

void ClearScene::Update() {
	auto input = Input::GetInstance();

	if (input->TriggerKey(DIK_SPACE)) {
		sceneNo = TITLE;
	}
}

void ClearScene::Draw() {
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, color, kFillModeSolid);
	Novice::DrawBox(0, 0, 300, 20, 0.0f, 0x000000ff, kFillModeSolid);
	Novice::ScreenPrintf(0, 0, "GameScene = ClearScene");
}
