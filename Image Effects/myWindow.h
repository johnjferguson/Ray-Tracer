#pragma once
#include "glad.h"
#include "glfw3.h"

class myWindow
{
public:
	myWindow();
	GLFWwindow* GetWindowID();
private:
	void QueryGLVersion();
	static void ErrorCallback(int error, const char* description);
private:
	GLFWwindow* window = 0;
};