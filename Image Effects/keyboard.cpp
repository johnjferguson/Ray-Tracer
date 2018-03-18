// John Ferguson
// id: 30032182
// CPSC 453 Assignment 3
#include "keyboard.h"
#include <iostream>

int Keyboard::curScene = 0;
int Keyboard::fontNumber = 0;
float Keyboard::speed = 0.5f;


Keyboard::Keyboard(GLFWwindow * window)
{
	glfwSetKeyCallback(window, KeyCallback);
	glfwSetScrollCallback(window, scroll_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);
}

void Keyboard::Update()
{
	glfwPollEvents();
}

void Keyboard::KeyCallback(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	//if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)

	if (key == GLFW_KEY_1 && action == GLFW_PRESS)
		Keyboard::curScene = 0;
	if (key == GLFW_KEY_2 && action == GLFW_PRESS)
		Keyboard::curScene = 1;
	if (key == GLFW_KEY_3 && action == GLFW_PRESS)
		Keyboard::curScene = 2;
	if (key == GLFW_KEY_4 && action == GLFW_PRESS)
		Keyboard::curScene = 3;
	
}

void Keyboard::scroll_callback(GLFWwindow * window, double xoffset, double yoffset)
{
	Keyboard::speed += yoffset * 0.1f;

	if (Keyboard::speed < 0.0f)
		Keyboard::speed = 0.0f;
	if (Keyboard::speed > 4.0f)
		Keyboard::speed = 4.0f;
}

void Keyboard::mouse_button_callback(GLFWwindow * window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		Keyboard::fontNumber = (Keyboard::fontNumber + 1) % 3;
	}
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
	{
	}
}
