#include "BezierCurve.h"
#include <cassert>
#include "type_ptr.hpp"
#include <iostream>

BezierCurve::BezierCurve(const std::vector<float>& vertices, bool cubic)
	:
	offset(0.0f,0.0f)
{
	SetVertices(vertices);
	isCubic = cubic;
}


void BezierCurve::InitializeGeometry(const std::vector<float>& vertices)
{
	assert(vertices.size() > 0);

	glGenBuffers(1, &geometry.VBO);

	glGenVertexArrays(1, &geometry.VAO);
	glBindVertexArray(geometry.VAO);

	glBindBuffer(GL_ARRAY_BUFFER, geometry.VBO);
	glVertexAttribPointer(
		0,					//Attribute index 
		2, 					//# of components
		GL_FLOAT, 			//Type of component
		GL_FALSE, 			//Should be normalized?
		sizeof(glm::vec2),	//Stride - can use 0 if tightly packed
		0);					//Offset to first element
	glEnableVertexAttribArray(0);

	// unbind our buffers, resetting to default state
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	// create an array buffer object for storing our vertices
	glBindBuffer(GL_ARRAY_BUFFER, geometry.VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2)*vertices.size(), vertices.data(), GL_STATIC_DRAW);

	//Unbind buffer to reset to default state
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void BezierCurve::InitializePointGeometry()
{
	assert(vertices.size() > 0);

	float hh = 0.05f;
	std::vector<glm::vec2> point_verts;
	std::vector<glm::vec3> colors;

	for (int i = 0; i < vertices.size(); i += 2)
	{
		// should have used vec2
		point_verts.emplace_back(vertices[i], vertices[i + 1] + hh);
		point_verts.emplace_back(vertices[i] + hh, vertices[i + 1] - hh);
		point_verts.emplace_back(vertices[i] - hh, vertices[i + 1] - hh);
	}

	int npoints = isCubic ? 3 : 2;
	for (int i = 0; i < point_verts.size() / 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i % npoints == 0)
				colors.emplace_back(1.0f, 0.0f, 0.0f);
			else
				colors.emplace_back(0.0f, 0.0f, 0.0f);
		}
	}

	std::cout << std::endl << colors.size() << std::endl << point_verts.size();
	
	glGenBuffers(1, &pointGeometry.VBO);
	glGenBuffers(1, &pointGeometry.CB);

	glGenVertexArrays(1, &pointGeometry.VAO);
	glBindVertexArray(pointGeometry.VAO);

	glBindBuffer(GL_ARRAY_BUFFER, pointGeometry.VBO);
	glVertexAttribPointer(
		0,					//Attribute index 
		2, 					//# of components
		GL_FLOAT, 			//Type of component
		GL_FALSE, 			//Should be normalized?
		sizeof(glm::vec2),	//Stride - can use 0 if tightly packed
		0);					//Offset to first element
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, pointGeometry.CB);
	glVertexAttribPointer(
		1,					//Attribute index 
		3, 					//# of components
		GL_FLOAT, 			//Type of component
		GL_FALSE, 			//Should be normalized?
		sizeof(glm::vec3),	//Stride - can use 0 if tightly packed
		0);					//Offset to first element
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, pointGeometry.VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2)*point_verts.size(), point_verts.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, pointGeometry.CB);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*colors.size(), colors.data(), GL_STATIC_DRAW);


	std::cout << std::endl << point_verts.size() << std::endl;
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
}

glm::mat4 BezierCurve::CreateTransMatrix() const
{
	glm::mat4  s = {
		scale		  ,  0             ,  0, 0,
		0             ,  scale		   ,  0, 0,
		0             ,  0             ,  1, 0,
		0             ,  0             ,  0, 1
	};
	glm::mat4  t = {
		1,  0,  0,  offset.x,
		0,  1,  0,  offset.y,
		0,  0,  1,  0,
		0,  0,  0,  1
	};
	return s*t;
}

void BezierCurve::Draw(const GLuint& program, const GLuint& simpleProgram) const
{
	assert(vertices.size() > 0);

	glUseProgram(program);

	float* fsrt = (float*)glm::value_ptr(CreateTransMatrix());
	glUniformMatrix4fv(glGetUniformLocation(program, "srt"), 1, false, fsrt);
	glUniform3f(glGetUniformLocation(program, "scolor"), 1.0f, 0.0f, 0.0f);

	if (isCubic)
		glPatchParameteri(GL_PATCH_VERTICES, 4);
	else
		glPatchParameteri(GL_PATCH_VERTICES, 3);

	glBindVertexArray(geometry.VAO);
	glBindBuffer(GL_ARRAY_BUFFER, geometry.VBO);
	glDrawArrays(GL_PATCHES, 0, vertices.size() / 2);
	
	glUseProgram(simpleProgram);
	glUniformMatrix4fv(glGetUniformLocation(simpleProgram, "srt"), 1, false, fsrt);
	glUniform3f(glGetUniformLocation(simpleProgram, "scolor"), 0.0f, 0.0f, 1.0f);

	glBindVertexArray(pointGeometry.VAO);
	glDrawArrays(GL_TRIANGLES, 0, vertices.size() / 2 * 3 );

	glBindVertexArray(0);
}

void BezierCurve::SetVertices(const std::vector<float>& vertices, bool cubic)
{
	isCubic = cubic;
	this->vertices = vertices;
	InitializeGeometry(vertices);
	InitializePointGeometry();
}

void BezierCurve::SetScale(float newScale)
{
	scale = newScale;
}

void BezierCurve::SetOffset(const glm::vec2& newOffset)
{
	offset = newOffset;
}


