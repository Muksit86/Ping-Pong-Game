#include<raylib.h>
#include "Ball.h"
#include "Paddle.h"
#include "CpuPaddle.h"

Ball ball;
Paddle paddle;
CpuPaddle cpu;

int main() {
	const int screen_width = 1280;
	const int screen_height = 800;
	InitWindow(screen_width, screen_height, "My Pong Game!");
	SetTargetFPS(60);

	//Line variables
	int start_x = screen_width/2;
	int start_y = 0;

	int end_x = screen_width / 2;
	int end_y = screen_height;

	//Ball variables
	ball.radius = 20;
	ball.x = screen_width / 2;
	ball.y = screen_height / 2;
	ball.speed_x = GetRandomValue(10, 15);
	ball.speed_y = GetRandomValue(5, 10);

	//Paddle variables
	paddle.speed = 15;
	paddle.width = 20;
	paddle.height = 220;
	paddle.pos_x = 20;
	paddle.pos_y = screen_height / 2 - paddle.height/2;

	//Cpu Paddle
	cpu.speed = 14;
	cpu.width = 20;
	cpu.height = 220;
	cpu.pos_x = screen_width - 20 - cpu.width;
	cpu.pos_y = screen_height / 2 - paddle.height / 2;

	//Game Loop
	while (!WindowShouldClose())
	{
		//Updating
		ball.update();
		paddle.update();
		cpu.update(float(ball.y));

		if (CheckCollisionCircleRec({ float(ball.x), float(ball.y) }, ball.radius, { paddle.pos_x, paddle.pos_y, paddle.width, paddle.height })) {
			ball.speed_x *= -1.1f;
		}

		if (CheckCollisionCircleRec({ float(ball.x), float(ball.y) }, ball.radius, { cpu.pos_x, cpu.pos_y, cpu.width, cpu.height })) {
			ball.speed_x *= -1.1f;
		}

		BeginDrawing();
		ClearBackground(BLACK);

		//Drawing
		DrawLine(start_x, start_y, end_x, end_y, WHITE);
		ball.Draw();
		paddle.Draw();
		cpu.Draw();

		DrawText(TextFormat("Player: %i", ball.player_score), 50, 10, 20, WHITE);
		DrawText(TextFormat("CPU: %i", ball.cpu_score), 1180, 10, 20, WHITE);
		EndDrawing();
	}
	CloseWindow();
}
