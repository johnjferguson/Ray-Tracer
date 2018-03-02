// John Ferguson
// id: 30032182
// CPSC 453 Assignment 1
#pragma once
#include <iostream>
#include <vector>
#include "glm.hpp"
#include "glad.h"
#include "glfw3.h"

// Functions to set up OpenGL buffers for storing geometry data
struct MyGeometry
{
	int elementCount;

	GLuint  VAO;
	GLuint  VBO;
	GLuint  EBO;
	GLuint  CB;
	GLuint	texture;
	
	// initialize object names to zero (OpenGL reserved value)
	MyGeometry() : VAO(0), EBO(0)
	{}
	void Destroy();
};

bool InitializeVAO(MyGeometry *geometry);

bool LoadGeometry(MyGeometry *geometry, const std::vector<glm::vec2>& vertices, int elementCount);

// deallocate geometry-related objects
void DestroyGeometry(MyGeometry *geometry);

bool CheckGLErrors();