#include "BezierCurve.h"

BezierCurve::BezierCurve()
{
	vertices = {
		1.0f,	 1.0f,	1.0f, 0.0f, 0.0f,
		2.0f,	-1.0f,	1.0f, 0.0f, 0.0f,
		0.0f,	-1.0f,	1.0f, 0.0f, 0.0f,

		0.0f,	-1.0f,	1.0f, 0.0f, 0.0f,
		-2.0f,	-1.0f,	1.0f, 0.0f, 0.0f,
		-1.0f,	 1.0f,	1.0f, 0.0f, 0.0f,

		-1.0f,	 1.0f,	1.0f, 0.0f, 0.0f,
		0.0f,	 1.0f,	1.0f, 0.0f, 0.0f,
		1.0f,	 1.0f,	1.0f, 0.0f, 0.0f,

		1.2f,	 0.5f,	1.0f, 0.0f, 0.0f,
		2.5f,	 1.0f,	1.0f, 0.0f, 0.0f,
		1.3f,	-0.4f,	1.0f, 0.0f, 0.0f,
	};


	glGenVertexArrays(1, &geometry.VAO);
	glGenBuffers(1, &geometry.VBO);

	glBindVertexArray(geometry.VAO);

	glBindBuffer(GL_ARRAY_BUFFER, geometry.VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(float), vertices.data(), GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5*sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)2);
	glEnableVertexAttribArray(1);


}

void BezierCurve::Draw() const
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glPatchParameteri(GL_PATCH_VERTICES, 2);
	glBindBuffer(GL_ARRAY_BUFFER, geometry.VBO);
	glBindVertexArray(geometry.VAO);
	glDrawArrays(GL_PATCHES, 0, 4);

	glBindVertexArray(0);

}
