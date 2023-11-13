#pragma once

// シーン名を列挙型で定義
enum Scene { 
	TITLE, 
	STAGE, 
	CLEAR,
	SceneMaxNum, // シーンの最大数
};

class IScene {
public:
	IScene() = default;
	virtual ~IScene();

protected:
	// シーン番号を管理する変数
	static int sceneNo;
public:
	// 継承先で実装される関数
	// 抽象クラスなので、純粋仮想関数とする
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	// シーン番号のゲッター
	int GetSceneNo();
};
