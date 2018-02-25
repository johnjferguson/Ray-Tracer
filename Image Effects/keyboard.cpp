// John Ferguson
// id: 30032182
// CPSC 453 Assignment 2
#include "keyboard.h"
#include <iostream>

int Keyboard::curScene = 0;

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
	
}

void Keyboard::scroll_callback(GLFWwindow * window, double xoffset, double yoffset)
{
}

void Keyboard::mouse_button_callback(GLFWwindow * window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
	}
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
	{
	}
}
