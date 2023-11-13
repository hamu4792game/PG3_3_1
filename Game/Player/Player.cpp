#include "Player.h"
#include <Input.h>
#include <Novice.h>

void Player::Initialize() {
	pos_ = { 640.0f,600.0f };
	velocity_ = { kSpeed_,0.0f };
	size_ = { 50.0f,50.0f };
	bullets_.clear();
}

void Player::Update() {
	MoveUpdate();
	MoveLimit();
	BulletUpdate();
}

void Player::Draw() {
	Novice::DrawBox(static_cast<int>(pos_.x), static_cast<int>(pos_.y), 
		static_cast<int>(size_.x), static_cast<int>(size_.y), 0.0f, 0xbbbbbbff, kFillModeSolid);
	//	弾更新
	for (auto& i : bullets_) {
		if (i.isAlive) {
			Novice::DrawBox(static_cast<int>(i.pos_.x), static_cast<int>(i.pos_.y), 
				static_cast<int>(i.size_.x), static_cast<int>(i.size_.y), 0.0f, 0xbbbb00ff, kFillModeSolid);
		}
	}
}

void Player::MoveUpdate() {
	auto input = Input::GetInstance();
	velocity_ = { 0.0f,0.0f };
	if (input->PushKey(DIK_W)) {
		velocity_.y -= kSpeed_;
	}
	if (input->PushKey(DIK_S)) {
		velocity_.y += kSpeed_;
	}

	if (input->PushKey(DIK_A)) {
		velocity_.x -= kSpeed_;
	}
	if (input->PushKey(DIK_D)) {
		velocity_.x += kSpeed_;
	}

	pos_.x += velocity_.x;
	pos_.y += velocity_.y;

}

void Player::MoveLimit() {
	if (pos_.x + size_.x >= 1280.0f) {
		pos_.x = 1280.0f - size_.x;
	}
	else if (pos_.x - size_.x <= 0.0f) {
		pos_.x = 0.0f + size_.x;
	}

	if (pos_.y + size_.y >= 720.0f) {
		pos_.y = 720.0f - size_.y;
	}
	else if (pos_.y - size_.y <= 0.0f) {
		pos_.y = 0.0f + size_.y;
	}
}

void Player::BulletUpdate() {
	auto input = Input::GetInstance();

	//	デスフラグの立った弾を削除
	bullets_.remove_if([](BulletParameter& bullet) {
		return bullet.isAlive == false || bullet.pos_.y <= 0.0f;
		});

	//	弾生成
	if (input->TriggerKey(DIK_SPACE)) {
		float half = 1.0f / 2.0f;
		bullets_.push_back(BulletParameter());
		(*bullets_.rbegin()).pos_.x = pos_.x + (size_.x * half) - ((*bullets_.rbegin()).size_.x * half);
		(*bullets_.rbegin()).pos_.y = pos_.y;
		(*bullets_.rbegin()).isAlive = true;
	}

	for (auto& i : bullets_) {
		if (i.isAlive) {
			i.pos_.y -= i.kSpeed_;
		}
	}
}

bool Player::EnemyColl(Vector2 enePos, Vector2 eneSize) {
	for (auto& i : bullets_) {
		if (RectCollision(enePos, eneSize, i.pos_, i.size_)) {
			i.isAlive = false;
			return true;
		}
	}	
	return false;
}

bool RectCollision(Vector2 pos1, Vector2 size1, Vector2 pos2, Vector2 size2) {
	if (pos1.x <= pos2.x + size2.x && pos1.x + size1.x >= pos2.x && pos1.y <= pos2.y + pos2.y && pos1.y + size1.y >= pos2.y) {
		return true;
	}
	return false;
}
