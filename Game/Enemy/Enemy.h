#pragma once
#include "Vector2.h"

class Enemy
{
public:
	Enemy() = default;
	~Enemy() = default;

	void Initialize();
	void Update();
	void Draw();

public:
	Vector2 GetPos() { return pos_; }
	Vector2 GetSize() { return size_; }

private:
	Vector2 pos_ = { 640.0f,100.0f };
	Vector2 velocity_ = { 1.0f,0.0f };
	Vector2 size_ = { 50.0f,50.0f };
	const float kSpeed_ = 5.0f;

private:
	void MoveUpdate();
	void MoveLimit();

};
