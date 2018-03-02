
#pragma once
#include <string>
#include <vector>

#include "glad.h"
#include "glfw3.h"

struct MyShader
{
public:
	// OpenGL names for vertex and fragment shaders, shader program
	GLuint  vertex;
	GLuint  fragment;
	GLuint  program;
	GLuint  tcs;
	GLuint  tes;
	// initialize shader and program names to zero (OpenGL reserved value)
	MyShader(const std::string & vertex_filename, const std::string & fragment_filename, const std::string& tc_filename, const std::string& te_filename);
	MyShader(const std::string & vertex_filename, const std::string & fragment_filename);
	void Clear();
};

struct Shaders
{
	std::vector<MyShader> shaders = {
		MyShader("Shaders\\bc.vs", "Shaders\\bc.fs"),
		MyShader("Shaders\\bc.vs", "Shaders\\bc.fs", "Shaders\\tessControl.glsl", "Shaders\\tessEval.glsl"),
		MyShader("Shaders\\bc.vs", "Shaders\\bc.fs", "Shaders\\tessControlCubic.glsl", "Shaders\\tessEvalCubic.glsl")
	};
};

// load, compile, and link shaders, returning true if successful
bool InitializeShaders(MyShader *shader, const std::string& vs, const std::string& fs, const std::string& tc, const std::string& te);
bool InitializeShaders(MyShader *shader, const std::string& vs, const std::string& fs);

// deallocate shader-related objects
void DestroyShaders(MyShader *shader);

// reads a text file with the given name into a string
std::string LoadSource(const std::string &filename);

// creates and returns a shader object compiled from the given source
GLuint CompileShader(GLenum shaderType, const std::string &source);

bool CheckGLShaderErrors();

// creates and returns a program object linked from vertex and fragment shaders
GLuint LinkProgram(GLuint vertexShader, GLuint fragmentShader, GLuint tcsShader, GLuint tesShader);
GLuint LinkProgram(GLuint vertexShader, GLuint fragmentShader);
