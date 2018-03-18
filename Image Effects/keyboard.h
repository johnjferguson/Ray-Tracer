#pragma once

#include "glad.h"
#include "glfw3.h"

class Keyboard
{
public:
	Keyboard() = default;
	Keyboard(GLFWwindow* window);
	void Update();

private:
	static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	
public:
	static int curScene;
	static int fontNumber;
	static float speed;
};
