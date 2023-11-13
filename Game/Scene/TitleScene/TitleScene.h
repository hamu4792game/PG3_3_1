#pragma once
#include "Game/Scene/IScene.h"

class TitleScene : public IScene {
public:
	void Initialize() override;
	void Update() override;
	void Draw() override;

private:
	int color = 0;

};
