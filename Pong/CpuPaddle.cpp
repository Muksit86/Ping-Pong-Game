#include "CpuPaddle.h"

void CpuPaddle::Draw() const{
	DrawRectangle(pos_x, pos_y, width, height, GREEN);
}

void CpuPaddle::update(float ball_y) {
	if (pos_y + height / 2 > ball_y) {
		pos_y -= speed;
	}
	if (pos_y + height / 2 <= ball_y) {
		pos_y += speed;
	}

	LimiMovement();
}