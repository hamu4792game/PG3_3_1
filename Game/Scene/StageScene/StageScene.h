#pragma once
#include "Game/Scene/IScene.h"
#include "Game/Player/Player.h"
#include "Game/Enemy/Enemy.h"
#include <memory>

class StageScene : public IScene {
public:
	StageScene();

	void Initialize() override;
	void Update() override;
	void Draw() override;

private:
	std::unique_ptr<Enemy> enemy_;
	std::unique_ptr<Player> player_;

};
