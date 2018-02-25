#include "BezierCurve.h"

BezierCurve::BezierCurve()
{
	glm::vec2 vertices[] = {
		glm::vec2(0, 0),
		glm::vec2(1, 0),
		glm::vec2(0.5, 0.5),
		glm::vec2(1.0, 0.5)
	};

	glm::vec3 colours[] = {
		glm::vec3(1.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f),
		glm::vec3(1.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f)
	};


	//Generate Vertex Buffer Objects
	// create an array buffer object for storing our vertices
	glGenBuffers(1, &geometry.VBO);

	// create another one for storing our colours
	glGenBuffers(1, &geometry.CB);

	//Set up Vertex Array Object
	// create a vertex array object encapsulating all our vertex attributes
	glGenVertexArrays(1, &geometry.VAO);
	glBindVertexArray(geometry.VAO);

	// associate the position array with the vertex array object
	glBindBuffer(GL_ARRAY_BUFFER, geometry.VBO);
	glVertexAttribPointer(
		0,					//Attribute index 
		2, 					//# of components
		GL_FLOAT, 			//Type of component
		GL_FALSE, 			//Should be normalized?
		sizeof(glm::vec2),		//Stride - can use 0 if tightly packed
		0);					//Offset to first element
	glEnableVertexAttribArray(0);

	// associate the colour array with the vertex array object
	glBindBuffer(GL_ARRAY_BUFFER, geometry.CB);
	glVertexAttribPointer(
		1,					//Attribute index 
		3, 					//# of components
		GL_FLOAT, 			//Type of component
		GL_FALSE, 			//Should be normalized?
		sizeof(glm::vec3), 	//Stride - can use 0 if tightly packed
		0);					//Offset to first element
	glEnableVertexAttribArray(1);

	// unbind our buffers, resetting to default state
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	// create an array buffer object for storing our vertices
	glBindBuffer(GL_ARRAY_BUFFER, geometry.VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2)*4, vertices, GL_STATIC_DRAW);

	// create another one for storing our colours
	glBindBuffer(GL_ARRAY_BUFFER, geometry.CB);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*4, colours, GL_STATIC_DRAW);

	//Unbind buffer to reset to default state
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void BezierCurve::Draw() const
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glPatchParameteri(GL_PATCH_VERTICES, 2);
	glBindVertexArray(geometry.VAO);
	glBindBuffer(GL_ARRAY_BUFFER, geometry.VBO);
	glDrawArrays(GL_PATCHES, 0, 4);

	glBindVertexArray(0);

}
