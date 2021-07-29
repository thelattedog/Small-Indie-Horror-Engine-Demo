#pragma once
#include <ctime>

struct GLFWwindow;

class Game
{
public:
	Game();
	~Game();
	bool Initialize();

	void Input();
	
	bool window_should_close();
	void Update(double dt);
	void Render();
private:

	// helper functions

	// variables
	GLFWwindow* m_window;
};

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

