// John Ferguson
// id: 30032182
// CPSC 453 Assignment 2
#pragma once
#include <vector>
#include "MyShader.h"
#include "Image.h"
#include "keyboard.h"
#include "BezierCurve.h"
//#include "GlyphExtractor.h"


class Scene
{
public:
	Scene() = default;
	~Scene();
	Scene(GLFWwindow* window);
	void Render();
private:
	GLFWwindow* window;
	std::vector<MyShader> shaders;
	std::vector<Image> images;
	std::vector<glm::vec4> grays;

	BezierCurve scene1a;
	BezierCurve scene1b;
	BezierCurve scene2a;

	//GlyphExtractor ge;

	std::vector <float*> smat;
	glm::vec2 curPos = { 0.0f, 0.0f };
	glm::vec2 delta;
};
