#include <raylib.h>

#define WIDTH 800
#define HEIGHT 600

int main()
{
	InitWindow(WIDTH, HEIGHT, "nuts");
	float centerX = WIDTH / 2.0f;
	float centerY = HEIGHT / 2.0f;
	float radius = 50.0f;
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(BLACK);
		DrawCircle(centerX, centerY, radius, RAYWHITE);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
