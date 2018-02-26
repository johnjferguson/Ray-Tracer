#include "BezierCurve.h"
#include <cassert>
#include "type_ptr.hpp"

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

	//glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	//glClear(GL_COLOR_BUFFER_BIT);

	float* fsrt = (float*)glm::value_ptr(CreateTransMatrix());
	glUniformMatrix4fv(glGetUniformLocation(program, "srt"), 1, false, fsrt);

	if (isCubic)
		glPatchParameteri(GL_PATCH_VERTICES, 4);
	else
		glPatchParameteri(GL_PATCH_VERTICES, 3);

	glBindVertexArray(geometry.VAO);
	glBindBuffer(GL_ARRAY_BUFFER, geometry.VBO);
	glDrawArrays(GL_PATCHES, 0, vertices.size() / 2);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glUseProgram(0);

}

void BezierCurve::SetVertices(const std::vector<float>& vertices, bool cubic)
{
	isCubic = cubic;
	this->vertices = vertices;
	InitializeGeometry(vertices);
}

void BezierCurve::SetScale(float newScale)
{
	scale = newScale;
}

void BezierCurve::SetOffset(const glm::vec2& newOffset)
{
	offset = newOffset;
}


