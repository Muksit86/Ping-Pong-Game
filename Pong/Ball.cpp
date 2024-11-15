#pragma once
#include "Ball.h"
#include<cmath>

void Ball::Draw() const{
	DrawCircle(x, y, radius, WHITE);
}

void Ball::update() {
	x += speed_x;
	y += speed_y;

	//Bounce off the wall
	if (y + radius >= GetScreenHeight() || y - radius <= 0) {
		speed_y *= -1;
	}

	if (x + radius >= GetScreenWidth()) {
		player_score++;
		Reset();
	}
	if (x - radius < 0) {
		cpu_score++;
		Reset();
		speed_x += 10;
	}
}

void Ball::Reset() {
	x = GetScreenWidth() / 2;
	y = GetScreenHeight() / 2;

	do {
		speed_x = GetRandomValue(10, 15) * (GetRandomValue(0, 1) ? -1 : 1);
		speed_y = GetRandomValue(5, 10) * (GetRandomValue(0, 1) ? -1 : 1);
	} while (abs(speed_x) == abs(speed_y)); // Ensure speeds are not identical
}