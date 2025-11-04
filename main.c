#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <raylib.h>

#define WIDTH 800
#define HEIGHT 600

struct Circle {
	float centerX, centerY;
	float radius;
	Color color;
};

void drawCircle(struct Circle circle)
{
	DrawCircle(circle.centerX, circle.centerY, circle.radius, circle.color);
}

void updatePos(struct Circle *circle, float newPosX, float newPosY)
{
	circle->centerX = newPosX;
	circle->centerY = newPosY;
}

bool checkCollision(struct Circle *circle1, struct Circle *circle2)
{
	int deltaX = abs((int)circle1->centerX - (int)circle2->centerX);
	int deltaY = abs((int)circle1->centerY - (int)circle2->centerY);
	int distSq = (deltaX * deltaX) + (deltaY * deltaY);
	int sumSq = (circle1->radius + circle2->radius) *
		    (circle1->radius + circle2->radius);
	return distSq <= sumSq;
}

void updateCircle(struct Circle *circle, float *velocityY, float dt,
		  float gravity, float damping, bool horizontal_movement)
{
	// gravity
	*velocityY += dt * gravity;
	circle->centerY += *velocityY * dt;

	// bounce off the floor
	if (circle->centerY + circle->radius >= HEIGHT) {
		circle->centerY = HEIGHT - circle->radius;

		if (fabs(*velocityY) < 10.0f) // small threshold
			*velocityY = 0;
		else
			*velocityY *= -damping;
	}
	// bounce off ceiling
	if (circle->centerY - circle->radius < 0) {
		circle->centerY = circle->radius;
		*velocityY *= -damping;
	}

	if (horizontal_movement) {
		// bounce off side walls
		if (circle->centerX + circle->radius > WIDTH) {
			circle->centerX = WIDTH - circle->radius;
		}
		if (circle->centerX - circle->radius < 0) {
			circle->centerX = circle->radius;
		}

		// move with keys
		float velocityX = 500.0f; // pixels per second
		if (IsKeyDown(KEY_D))
			circle->centerX += velocityX * dt;
		if (IsKeyDown(KEY_A))
			circle->centerX -= velocityX * dt;
	}
}

int main()
{
	InitWindow(WIDTH, HEIGHT, "ur mom");
	float centerX = (float)WIDTH / 2;
	float centerY = (float)HEIGHT / 2;
	struct Circle circle = { centerX, centerY, 50.0f, RED };
	struct Circle circle2 = { 50.0f, 50.0f, 50.0f, WHITE };
	float velocityY1 = 0.0f;
	float velocityY2 = 0.0f;
	float gravity = 727.0f; // pixels per second^2
	float damping = 0.8f; // energy kept after each bounce
	while (!WindowShouldClose()) {
		float dt = GetFrameTime();

		if (IsKeyPressed(KEY_SPACE)) {
			velocityY1 -= 300.0f;
			velocityY2 -= 300.0f;
		}

		updateCircle(&circle, &velocityY1, dt, gravity, damping, true);
		updateCircle(&circle2, &velocityY2, dt, gravity, damping,
			     false);

		if (checkCollision(&circle, &circle2)) {
			circle2.color = BLUE;
		}

		BeginDrawing();
		ClearBackground(BLACK);
		drawCircle(circle);
		drawCircle(circle2);
		EndDrawing();
	}
	return 0;
}
