// John Ferguson
// id: 30032182
// CPSC 453 Assignment 2
#include "keyboard.h"
#include <iostream>

int Keyboard::curImage = 0;
int Keyboard::curEffect = 0;
float Keyboard::theta = 0.0f;
double Keyboard::x = 0.5f;
double Keyboard::y = 0.5f;
float Keyboard::zoom = 1.0f;
bool Keyboard::leftClickHold = false;

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

	if (key == GLFW_KEY_UP && action == GLFW_PRESS && Keyboard::curImage < 5)
		Keyboard::curImage++;
	if (key == GLFW_KEY_DOWN && action == GLFW_PRESS && Keyboard::curImage > 0)
		Keyboard::curImage--;
	if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS && Keyboard::curEffect < 11)
		Keyboard::curEffect++;
	if (key == GLFW_KEY_LEFT && action == GLFW_PRESS && Keyboard::curEffect > 0)
		Keyboard::curEffect--;
	
	if (key == GLFW_KEY_Q && action == GLFW_PRESS )
		Keyboard::theta += 3.1415f / 8.0f;
	if (key == GLFW_KEY_E && action == GLFW_PRESS)
		Keyboard::theta -= 3.1415f / 8.0f;
}

void Keyboard::scroll_callback(GLFWwindow * window, double xoffset, double yoffset)
{
	Keyboard::zoom += yoffset * 0.02f;

	if (Keyboard::zoom < 0.02f)
		Keyboard::zoom = 0.04f;
	if (Keyboard::zoom > 3.0f)
		Keyboard::zoom = 3.0f;
}

void Keyboard::mouse_button_callback(GLFWwindow * window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		Keyboard::leftClickHold = true;
		glfwGetCursorPos(window, &Keyboard::x, &Keyboard::y);
	}
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
	{
		Keyboard::leftClickHold = false;
	}
}
