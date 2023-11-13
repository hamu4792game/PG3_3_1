#include <Novice.h>
#include "Game/GameManager/GameManager.h"

const char kWindowTitle[] = "LE2A_20_マツイユウセイ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	auto game = GameManager::GetInstance();
	game->Run();

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
