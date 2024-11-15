#include "Paddle.h"

void Paddle::LimiMovement() {
	if (pos_y <= 0) pos_y = 0;
	if (pos_y + height >= GetScreenHeight()) {
		pos_y = GetScreenHeight() - height;
	}
}

void Paddle::Draw() const {
	DrawRectangle(pos_x, pos_y, width, height, WHITE);
}

void Paddle::update() {
	if (IsKeyDown(KEY_UP)) pos_y -= speed * GetFrameTime() * 60;
	if (IsKeyDown(KEY_DOWN)) pos_y += speed * GetFrameTime() * 60;

	LimiMovement();
}