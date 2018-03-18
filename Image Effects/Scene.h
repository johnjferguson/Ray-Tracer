// John Ferguson
// id: 30032182
// CPSC 453 Assignment 3
#pragma once
#include <vector>
#include "MyShader.h"
#include "Image.h"
#include "keyboard.h"
#include "BezierCurve.h"
#include "GlyphExtractor.h"
#include "Font.h"
#include "Character.h"
#include "TextField.h"
#include "FrameTimer.h"


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

	FrameTimer ft;
};
