#pragma once
#include<raylib.h>

class Paddle {
protected:
	void LimiMovement();
public:
	float pos_x, pos_y;
	float width, height;
	float speed;

	void Draw() const;

	void update();
};
