#include "myWindow.h"
#include <iostream>
#include <string>
#define NOMINMAX

myWindow::myWindow()
{
	// initialize the GLFW windowing system
	if (!glfwInit())
		std::cout << "ERROR: GLFW failed to initialize, TERMINATING" << std::endl;

	glfwSetErrorCallback(ErrorCallback);

	// attempt to create a window with an OpenGL 4.1 core profile context
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	int width = 1000, height = 1000;
	window = glfwCreateWindow(width, height, "CPSC 453 OpenGL Boilerplate", 0, 0);
	if (!window) {
		std::cout << "Program failed to create GLFW window, TERMINATING" << std::endl;
		glfwTerminate();
	}

	// Really hard to find error when missing this...
	glfwMakeContextCurrent(window);

	// Intialize GLAD
	if (!gladLoadGL())
		std::cout << "GLAD init failed" << std::endl;

	// query and print out information about our OpenGL environment
	QueryGLVersion();
}

GLFWwindow* myWindow::GetWindowID() 
{
	return window;
}

void myWindow::QueryGLVersion()
{
	// query opengl version and renderer information

	std::string version = reinterpret_cast<const char *>(glGetString(GL_VERSION));
	std::string glslver = reinterpret_cast<const char *>(glGetString(GL_SHADING_LANGUAGE_VERSION));
	std::string renderer = reinterpret_cast<const char *>(glGetString(GL_RENDERER));

	std::cout << "OpenGL [ " << version << " ] "
		<< "with GLSL [ " << glslver << " ] "
		<< "on renderer [ " << renderer << " ]" << std::endl;
}

void myWindow::ErrorCallback(int error, const char * description)
{
	std::cout << "GLFW ERROR " << error << ":" << std::endl;
	std::cout << description << std::endl;
}