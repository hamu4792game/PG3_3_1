#include "Enemy.h"
#include <Novice.h>

void Enemy::Initialize() {
	pos_ = { 640.0f,100.0f };
	velocity_ = { kSpeed_,0.0f };
	size_ = { 50.0f,50.0f };
}

void Enemy::Update() {
	MoveUpdate();
	MoveLimit();
}

void Enemy::Draw() {
	Novice::DrawBox(static_cast<int>(pos_.x), static_cast<int>(pos_.y), static_cast<int>(size_.x), static_cast<int>(size_.y), 0.0f, 0xbb0000ff, kFillModeSolid);
}

void Enemy::MoveUpdate() {
	pos_.x += velocity_.x;
}

void Enemy::MoveLimit() {
	if (pos_.x + size_.x >= 1280.0f) {
		velocity_.x = -kSpeed_;
		pos_.x = 1280.0f - size_.x;
	}
	else if (pos_.x - size_.x <= 0.0f) {
		velocity_.x = kSpeed_;
		pos_.x = 0.0f + size_.x;
	}
}
