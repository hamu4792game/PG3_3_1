#pragma once
#include "Vector2.h"
#include <list>

class Player
{
public:
	Player() = default;
	~Player() = default;

	void Initialize();
	void Update();
	void Draw();

public:
	Vector2 GetPos() { return pos_; }
	Vector2 GetSize() { return size_; }

private:
	Vector2 pos_ = { 640.0f,600.0f };
	Vector2 velocity_ = { 1.0f,0.0f };
	Vector2 size_ = { 50.0f,50.0f };
	const float kSpeed_ = 5.0f;
	
	struct BulletParameter {
		Vector2 pos_ = { 0.0f,0.0f };
		Vector2 size_ = { 25.0f,25.0f };
		const float kSpeed_ = 10.0f;
		bool isAlive = true;
	};
	std::list<BulletParameter> bullets_;

private:
	void MoveUpdate();
	void MoveLimit();

	void BulletUpdate();
public:
	bool EnemyColl(Vector2 enePos, Vector2 eneSize);

};

//	矩形の衝突判定処理
bool RectCollision(Vector2 pos1, Vector2 size1, Vector2 pos2, Vector2 size2);