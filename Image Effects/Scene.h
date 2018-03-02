// John Ferguson
// id: 30032182
// CPSC 453 Assignment 2
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
	std::vector<Image> images;
	std::vector<glm::vec4> grays;
	
	Font sanspro = Font("fonts\\SourceSansPro-Bold.otf");
	Character char_a;

	TextField tf;

	BezierCurve scene1a;
	BezierCurve scene1b;

	std::vector <float*> smat;
	glm::vec2 curPos = { 0.0f, 0.0f };
	glm::vec2 delta;
};
