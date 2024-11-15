#pragma once
#include<raylib.h>



class Ball {
public:
	int x, y;
	float speed_x, speed_y;
	float radius;
	int player_score;
	int cpu_score;

	void Draw() const;

	void update();

	void Reset();
};