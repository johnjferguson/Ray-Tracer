// John Ferguson
// id: 30032182
// CPSC 453 Assignment 2
#include "program.h"
#include <iostream>
#include <string>

Program::Program()
	:
	scene(window.GetWindowID())
{
	// initalize keyboard
	kbd = Keyboard(window.GetWindowID());

}

void Program::Run()
{

	while (!glfwWindowShouldClose(window.GetWindowID()))
	{
		kbd.Update();
		scene.Render();

		glfwSwapBuffers(window.GetWindowID());
	}
}

