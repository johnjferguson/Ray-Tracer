// John Ferguson
// id: 30032182
// CPSC 453 Assignment 3
#include "Scene.h"
#include <iostream>
#include "type_ptr.hpp"

Scene::~Scene()
{

}

Scene::Scene(GLFWwindow* window)
{
	ib.Initialize();
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			ib.SetPixel(100 + i, 100 + j, glm::vec3(0.0f, 0.0f, 1.0f));
}



void Scene::Render()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	ib.Render();
	
}

