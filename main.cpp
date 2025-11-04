#include <raylib.h>
#include <vector>

#define WIDTH 800
#define HEIGHT 600

int main()
{
	InitWindow(WIDTH, HEIGHT, "nuts");
	SetTargetFPS(60);

	float centerX = WIDTH / 2.0f;
	float centerY = HEIGHT / 2.0f;
	float radius = 50.0f;

	std::vector<float> position = { 400.0f, 300.0f };
	std::vector<float> velocity = { 0.0f, 0.0f };

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(BLACK);
		DrawCircle(position[0], position[1], radius, RAYWHITE);
		position[0] += velocity[0];
		position[1] += velocity[1];
		velocity[1] += 9.81 / 20.0f;
		velocity[0] += 9.81 / 20.0f;
		if (position[1] - radius < 0 || position[1] + radius > HEIGHT) {
			velocity[1] *= -0.95f;
		}
		if (position[0] - radius < 0 || position[0] + radius > WIDTH) {
			velocity[0] *= -0.95f;
		}
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
