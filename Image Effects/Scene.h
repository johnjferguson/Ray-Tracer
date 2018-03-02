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
	Font lora = Font("fonts\\Lora-Regular.ttf");
	Font db = Font("fonts\\20db.otf");

	Font alex = Font("fonts\\AlexBrush-Regular.ttf");
	Font incon = Font("fonts\\Inconsolata.otf");
	Font ack = Font("fonts\\Acknowledgement.otf");

	

	TextField s2f1;
	TextField s2f2;
	TextField s2f3;

	TextField s3f1;
	TextField s3f2;
	TextField s3f3;

	BezierCurve scene1a;
	BezierCurve scene1b;

	std::vector <float*> smat;
	glm::vec2 curPos = { 0.0f, 0.0f };
	glm::vec2 delta;
};
