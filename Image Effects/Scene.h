// John Ferguson
// id: 30032182
// CPSC 453 Assignment 3
#pragma once
#include <vector>
#include "MyShader.h"
#include "Image.h"
#include "keyboard.h"
#include "FrameTimer.h"
#include "imagebuffer.h"
#include "object.h"



class Scene
{
public:
	Scene() = default;
	~Scene();
	Scene(GLFWwindow* window);
	void Render();

private:
	GLFWwindow* window;
	Shaders s;

	ImageBuffer ib;
	Circle circle = Circle(1.0f, { 0.0f, 0.0f, -3.0f });

	FrameTimer ft;
};
