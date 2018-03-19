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

	bool b = circle.HasIntersection({ 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, -4.0f });
	glm::vec3 inter = circle.NearestIntersection({ 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, -4.0f });

	if (b == true)
		std::cout << "hasIntersection might be working" << std::endl;
	else
		std::cout << "hasIntersection not working" << std::endl;

	printf("x: %6.2f   y: %6.2f   z: %6.2f", inter.x, inter.y, inter.z);
}



void Scene::Render()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	ib.Render();
	
}

