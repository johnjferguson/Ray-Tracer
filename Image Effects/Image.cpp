#include "Image.h"
#include <iostream>

Image::Image(const std::string& filename)
{
	InitializeTexture(&texture, filename.c_str(), GL_TEXTURE_2D);
	Initialize();
}

void Image::Draw() const
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture.textureID);

	glBindBuffer(GL_ARRAY_BUFFER, geometry.VBO);
	glBindVertexArray(geometry.VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Image::DestroyImage()
{
	geometry.Destroy();
	texture.Destroy();
}

void Image::Initialize()
{
	float wr, hr;
	if (texture.width > texture.height)
	{
		wr = 1.0f;
		hr = float(texture.height) / float(texture.width);
	}
	else
	{
		hr = 1.0f;
		wr = float(texture.width) / float(texture.height);
	}
	std::cout << "this is the with and height" << texture.width << texture.height << std::endl;

	float vertices[] = {
		// positions             // texture coords
		wr,  hr, 0.0f,      1.0f, 1.0f, // top right
		wr, -hr, 0.0f,      1.0f, 0.0f, // bottom right
		-wr, -hr, 0.0f,     0.0f, 0.0f, // bottom left
		-wr,  hr, 0.0f,     0.0f, 1.0f  // top left 
	};
	unsigned int indices[] = {
		0, 1, 3, // first triangle
		1, 2, 3  // second triangle
	};
	glGenVertexArrays(1, &geometry.VAO);
	glGenBuffers(1, &geometry.VBO);
	glGenBuffers(1, &geometry.EBO);

	glBindVertexArray(geometry.VAO);

	glBindBuffer(GL_ARRAY_BUFFER, geometry.VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, geometry.EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// texture coord attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// clean up
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}

