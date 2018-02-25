// John Ferguson
// id: 30032182
// CPSC 453 Assignment 2
#include "Scene.h"
#include <iostream>
#include "type_ptr.hpp"

Scene::~Scene()
{

}

Scene::Scene(GLFWwindow* window)
	:
	window(window)
{
	// not sure what this stuff does
	glfwWindowHint(GLFW_SAMPLES, 4);
	glPointSize(4);

	shaders.emplace_back("Shaders\\bc.vs", "Shaders\\bc.fs", "Shaders\\tessControl.glsl", "Shaders\\tessEval.glsl");

	std::vector<float> s1a_vert = {
		1.0f, 1.0f, 2.0f, -1.0f, 0.0f, -1.0f,
		0.0f, -1.0f, -2.0f, -1.0f, -1.0f, 1.0f,
		-1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f,
		1.2f, 0.5f, 2.5f, 1.0f, 1.3f, -0.4f 
	};
	
	scene1.SetVertices(s1a_vert);
}


void Scene::Render()
{
	scene1.Draw(shaders[0].program);
}

