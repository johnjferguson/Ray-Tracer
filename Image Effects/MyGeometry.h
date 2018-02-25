// John Ferguson
// id: 30032182
// CPSC 453 Assignment 1
#pragma once
#include <iostream>
#include "glm.hpp"
#include "glad.h"
#include "glfw3.h"

// Functions to set up OpenGL buffers for storing geometry data
struct MyGeometry
{
	// OpenGL names for array buffer objects, vertex array object
	GLuint  VAO;
	GLuint  VBO;
	GLuint  EBO;
	GLuint	texture;
	
	// initialize object names to zero (OpenGL reserved value)
	MyGeometry() : VAO(0), EBO(0)
	{}
	void Clear();
};

// deallocate geometry-related objects
void DestroyGeometry(MyGeometry *geometry);

bool CheckGLErrors();