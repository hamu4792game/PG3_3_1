#pragma once
#include <memory>
#include "Game/Scene/IScene.h"

class GameManager {
public:
	GameManager();
	~GameManager();

	static GameManager* GetInstance();

private:
	// シーンを保持するメンバ変数
	std::unique_ptr<IScene> sceneArr_[SceneMaxNum];

	// どのステージを呼び出すかを管理する変数
	int currentSceneNo_; // 現在のシーン
	int prevSceneNo_; // 前のシーン

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };


public:
	// この関数でゲームループを呼び出す
	int Run();

};
