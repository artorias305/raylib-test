#include <raylib.h>
#include <vector>

#define WIDTH 800
#define HEIGHT 600

class Object {
    public:
	std::vector<float> position;
	std::vector<float> velocity;
	float radius;
	float mass;

	Object(std::vector<float> position, std::vector<float> velocity,
	       float mass, float radius = 15.0f)
	{
		this->position = position;
		this->velocity = velocity;
		this->radius = radius;
		this->mass = mass;
	}

	void accelerate(float x, float y)
	{
		this->velocity[0] += x;
		this->velocity[1] += y;
	}

	void updatePos()
	{
		this->position[0] += velocity[0] / 1000.0f;
		this->position[1] += velocity[1] / 1000.0f;
	}
	void Draw()
	{
		DrawCircle(this->position[0], this->position[1], this->radius, RAYWHITE);
	}
};

int main()
{
	InitWindow(WIDTH, HEIGHT, "a");
	SetTargetFPS(60);

	float centerX = WIDTH / 2.0f;
	float centerY = HEIGHT / 2.0f;
	float radius = 50.0f;

	std::vector<Object> objs = {
		Object(std::vector<float>{200.0f, 300.0f}, std::vector<float>{0.0f, 0.0f}, 0),
		Object(std::vector<float>{700.0f, 300.0f}, std::vector<float>{0.0f, 0.0f}, 0)
	};

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(BLACK);
		for (auto& obj : objs) {
			obj.accelerate(5.0f, 9.81);
			obj.updatePos();
			obj.Draw();
			if (obj.position[1] - radius < 0 || obj.position[1] + radius > HEIGHT) {
				obj.velocity[1] *= -0.95;
			}
			if (obj.position[0] - obj.radius < 0 || obj.position[0] + obj.radius > WIDTH) {
				obj.velocity[0] *= -0.95;
			}
		}
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
