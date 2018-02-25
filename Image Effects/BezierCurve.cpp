#include "BezierCurve.h"

BezierCurve::BezierCurve()
{
	vertices = {
		1.0f,	 1.0f,
		2.0f,	-1.0f,
		0.0f,	-1.0f,

		0.0f,	-1.0f,
		-2.0f,	-1.0f,
		-1.0f,	 1.0f,

		-1.0f,	 1.0f,
		0.0f,	 1.0f,
		1.0f,	 1.0f,

		1.2f,	 0.5f,
		2.5f,	 1.0f,
		1.3f,	-0.4f,
	};

	for (auto& i : vertices)
		i *= 0.4;

	glGenVertexArrays(1, &geometry.VAO);
	glGenBuffers(1, &geometry.VBO);

	glBindVertexArray(geometry.VAO);

	glBindBuffer(GL_ARRAY_BUFFER, geometry.VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(float), vertices.data(), GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// clean up
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}

void BezierCurve::Draw() const
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBindBuffer(GL_ARRAY_BUFFER, geometry.VBO);
	glBindVertexArray(geometry.VAO);
	glDrawArrays(GL_LINE_STRIP, 0, vertices.size() / 2);

}
