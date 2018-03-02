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
	window(window),
	s2f1(sanspro, s, "John Ferguson"),
	s2f2(lora, s, "John Ferguson"),
	s2f3(db, s, "John Ferguson"),
	s3f1(alex, s, "The quick brown fox jumps over the lazy dog."),
	s3f2(incon, s, "The quick brown fox jumps over the lazy dog."),
	s3f3(ack, s, "The quick brown fox jumps over the lazy dog.")
{
	// not sure what this stuff does
	glfwWindowHint(GLFW_SAMPLES, 1);
	glPointSize(1);

	std::vector<float> s1a_vert = {
		1.0f, 1.0f, 2.0f, -1.0f, 0.0f, -1.0f,
		0.0f, -1.0f, -2.0f, -1.0f, -1.0f, 1.0f,
		-1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f,
		1.2f, 0.5f, 2.5f, 1.0f, 1.3f, -0.4f 
	};

	scene1a.SetVertices(s1a_vert);
	scene1a.SetScale(0.6f);
	scene1a.SetOffset(glm::vec2(-0.15f, 0.0f));

	std::vector<float> s1b_vert = {
		1.0f, 1.0f, 4.0f, 0.0f, 6.0f, 2.0f, 9.0f, 1.0f,
		8.0f, 2.0f, 0.0f, 8.0f, 0.0f, -2.0f, 8.0f, 4.0f,
		5.0f, 3.0f, 3.0f, 2.0f, 3.0f, 3.0f, 5.0f, 2.0f,
		3.0f, 2.2f, 3.5f, 2.7f, 3.5f, 3.3f, 3.0f, 3.8f,
		2.8f, 3.5f, 2.4f, 3.8f, 2.4f, 3.2f, 2.8f, 3.5f
	};

	scene1b.SetVertices(s1b_vert, true);
	scene1b.SetScale(0.23f);
	scene1b.SetOffset(glm::vec2(-1.15f, -0.5f));

	// scene 2
	s2f1.SetPosition(glm::vec2{ -0.98f, -0.0f });
	s2f1.SetScale(0.3f);
	s2f1.SetColor({ 1.0f, 0.0f, 0.0f });

	s2f2.SetPosition(glm::vec2{ -0.98f, 0.0f });
	s2f2.SetScale(0.29f);
	s2f2.SetColor({ 0.0f, 1.0f, 0.0f });
	
	s2f3.SetPosition(glm::vec2{ -0.98f, 0.0f });
	s2f3.SetScale(0.17f);
	s2f3.SetColor({ 0.0f, 0.0f, 1.0f });

	// scene 3
	s3f1.SetPosition(glm::vec2{ -0.98f, 0.0f });
	s3f1.SetScale(0.5f);
	s3f1.SetColor({ 1.0f, 0.0f, 0.0f });

	s3f2.SetPosition(glm::vec2{ -0.98f, 0.0f });
	s3f2.SetScale(0.5f);
	s3f2.SetColor({ 0.0f, 1.0f, 0.0f });

	s3f3.SetPosition(glm::vec2{ -0.98f, 0.0f });
	s3f3.SetScale(0.5f);
	s3f3.SetColor({ 0.0f, 0.0f, 1.0f });
}



void Scene::Render()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	if (Keyboard::curScene == 0)
		scene1a.Draw(s.shaders[1].program, s.shaders[0].program);
	else if (Keyboard::curScene == 1)
		scene1b.Draw(s.shaders[2].program, s.shaders[0].program);
	else if (Keyboard::curScene == 2)
	{
		if (Keyboard::fontNumber == 0)
			s2f1.Draw();
		if (Keyboard::fontNumber == 1)
			s2f2.Draw();
		if (Keyboard::fontNumber == 2)
			s2f3.Draw();
	}
	else if (Keyboard::curScene == 3)
	{
		if (Keyboard::fontNumber == 0)
			s3f1.Draw();
		if (Keyboard::fontNumber == 1)
			s3f2.Draw();
		if (Keyboard::fontNumber == 2)
			s3f3.Draw();
	}

}

