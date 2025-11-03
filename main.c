#include <stdio.h>
#include <raylib.h>

#define WIDTH 800
#define HEIGHT 600

struct Circle {
	float centerX, centerY;
	float radius;
	Color color;
};

void drawCircle(struct Circle circle) {
	DrawCircle(circle.centerX, circle.centerY, circle.radius, circle.color);
}

int main()
{
	InitWindow(WIDTH, HEIGHT, "ur mom");
	struct Circle circ = {(float)WIDTH / 2, (float)HEIGHT / 2, 50.0f, RED};
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(BLACK);
		drawCircle(circ);
		EndDrawing();
	}
	return 0;
}
