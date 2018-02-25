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
	shaders.emplace_back("Shaders\\bc.vs", "Shaders\\bc.fs");
	
}


void Scene::Render()
{
	glUseProgram(shaders[0].program);
	bc.Draw();
}

