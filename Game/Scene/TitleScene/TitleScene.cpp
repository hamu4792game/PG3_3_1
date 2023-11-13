#include "TitleScene.h"
#include <Input.h>
#include <Novice.h>

void TitleScene::Initialize() {
	color = 0xff0000ff;
}

void TitleScene::Update() {
	auto input = Input::GetInstance();

	if (input->TriggerKey(DIK_SPACE)) {
		sceneNo = STAGE;
	}
}

void TitleScene::Draw() {
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, color, kFillModeSolid);
	Novice::DrawBox(0, 0, 300, 20, 0.0f, 0x000000ff, kFillModeSolid);
	Novice::ScreenPrintf(0, 0, "GameScene = TitleScene");
}
