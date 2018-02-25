// John Ferguson
// id: 30032182
// CPSC 453 Assignment 2
#pragma once
#include "glad.h"
#include "glfw3.h"
#include "keyboard.h"
#include "Scene.h"
#include "myWindow.h"

class Program
{
public:
	Program();
	void Run();
private:
	myWindow window;
	Keyboard kbd;
	Scene scene;
};
