#pragma once
#include<raylib.h>
#include "Paddle.h"

class CpuPaddle : public Paddle {
public:
	void Draw() const;

	void update(float ball_y);
};
