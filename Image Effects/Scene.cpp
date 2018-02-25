// John Ferguson
// id: 30032182
// CPSC 453 Assignment 2
#include "Scene.h"
#include <iostream>
#include "type_ptr.hpp"

Scene::~Scene()
{
	for (auto& i : shaders)
		DestroyShaders(&i);
	for (auto& i : smat)
		delete[] i;
	for (auto& i : images)
		i.DestroyImage();
}

Scene::Scene(GLFWwindow* window)
	:
	window(window)
{
	shaders.emplace_back("Shaders\\normal.vs", "Shaders\\normal.fs");
	shaders.emplace_back("Shaders\\normal.vs", "Shaders\\gray.fs");
	shaders.emplace_back("Shaders\\normal.vs", "Shaders\\sepia.fs");
	shaders.emplace_back("Shaders\\normal.vs", "Shaders\\edge.fs");
	shaders.emplace_back("Shaders\\normal.vs", "Shaders\\gaussian.fs");


	glUseProgram(shaders[0].program);
	glUniform1i(glGetUniformLocation(shaders[0].program, "texture1"), 0);

	glUseProgram(shaders[1].program);
	glUniform1i(glGetUniformLocation(shaders[1].program, "texture1"), 0);

	glUseProgram(shaders[2].program);
	glUniform1i(glGetUniformLocation(shaders[2].program, "texture1"), 0);

	glUseProgram(shaders[3].program);
	glUniform1i(glGetUniformLocation(shaders[3].program, "texture1"), 0);

	glUseProgram(shaders[4].program);
	glUniform1i(glGetUniformLocation(shaders[4].program, "texture1"), 0);

	grays.emplace_back(0.333f, 0.333f, 0.333f, 0.000f);
	grays.emplace_back(0.299f, 0.587f, 0.114f, 0.000f);
	grays.emplace_back(0.213f, 0.715f, 0.072f, 0.000f);

	float* s0 = new float[9]{
		1.0f, 0.0f, -1.0f,
		2.0f, 0.0f, -2.0f,
		1.0f, 0.0f, -1.0f
	};

	float* s1 = new float[9]{
		-1, -2, -1,
		0,  0,  0,
		1,  2,  1
	};
	float* s2 = new float[9]{
		0, -1,  0,
		-1,  5, -1,
		0,  -1,  0
	};
	smat.push_back(s0);
	smat.push_back(s1);
	smat.push_back(s2);

	images.emplace_back("a2images\\image1-mandrill.png");
	images.emplace_back("a2images\\image2-uclogo.png");
	images.emplace_back("a2images\\image3-aerial.jpg");
	images.emplace_back("a2images\\image4-thirsk.jpg");
	images.emplace_back("a2images\\image5-pattern.png");
	images.emplace_back("a2images\\image6-monika.jpg");
}


void Scene::Render()
{
	// updating scale rotation and translation matrix
	
	glm::mat4  s = {
		Keyboard::zoom,  0             ,  0, 0,
		0             ,  Keyboard::zoom,  0, 0,
		0             ,  0             ,  1, 0,
		0             ,  0             ,  0, 1
	};

	glm::mat4  r = {
		cos(Keyboard::theta), -sin(Keyboard::theta), 0, 0,
		sin(Keyboard::theta),  cos(Keyboard::theta), 0, 0,
		0                   ,  0                   , 1, 0,
		0                   ,  0                   , 0, 1
	};

	if (Keyboard::leftClickHold)
	{
		double tempx, tempy;
		glfwGetCursorPos(window, &tempx, &tempy);
		delta = (glm::vec2((float)tempx, (float)tempy) - glm::vec2((float)Keyboard::x, (float)Keyboard::y)) / 500.0f;
	}

	glm::mat4  t = {
		1,  0,  0,  curPos[0] + delta[0],
		0,  1,  0,  curPos[1] - delta[1],
		0,  0,  1,  0,
		0,  0,  0,  1
	};

	if (!Keyboard::leftClickHold)
	{
		curPos[0] += delta[0];
		curPos[1] -= delta[1];
		delta = { 0.0f, 0.0f };
	};

	glm::mat4 srt = s * r * t;

	const float* fsrt = (const float*)glm::value_ptr(srt);

	for (int i = 0; i < 5; i++)
		glUniformMatrix4fv(glGetUniformLocation(shaders[i].program, "srt"), 1, false, fsrt);

	if (Keyboard::curEffect == 0)
	{
		glUseProgram(shaders[0].program);
	}
	else if (Keyboard::curEffect > 0 && Keyboard::curEffect < 4)
	{
		glUniform4f(glGetUniformLocation(shaders[1].program, "gray0"), 
			grays[Keyboard::curEffect - 1][0],
			grays[Keyboard::curEffect - 1][1],
			grays[Keyboard::curEffect - 1][2],
			grays[Keyboard::curEffect - 1][3]
		);
		glUseProgram(shaders[1].program);
	}
	else if (Keyboard::curEffect == 4)
	{
		glUseProgram(shaders[2].program);
	}
	else if (Keyboard::curEffect > 4 && Keyboard::curEffect < 8)
	{
		glUniformMatrix3fv(glGetUniformLocation(shaders[3].program, "sobel"), 1, false, smat[Keyboard::curEffect - 5]);
		glUseProgram(shaders[3].program);
	}
	else if (Keyboard::curEffect > 7 && Keyboard::curEffect < 11)
	{
		glUniform1i(glGetUniformLocation(shaders[4].program, "ngaus"), 2*(Keyboard::curEffect - 7) + 1);
		glUseProgram(shaders[4].program);
	}

	images[Keyboard::curImage].Draw();
}

