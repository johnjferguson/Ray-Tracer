// John Ferguson
// id: 30032182
// CPSC 453 Assignment 1
#include "MyShader.h"
#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>

// load, compile, and link shaders, returning true if successful
bool InitializeShaders(MyShader *shader, const std::string& vs, const std::string& fs, const std::string& tc, const std::string& te)
{
	// load shader source from files
	std::string vertexSource = LoadSource(vs.c_str());
	std::string fragmentSource = LoadSource(fs.c_str());
	std::string tcsSource = LoadSource(tc.c_str());
	std::string tesSource = LoadSource(te.c_str());
	
	if (vertexSource.empty() || fragmentSource.empty()) return 0;

	// compile shader source into shader objects
	shader->vertex = CompileShader(GL_VERTEX_SHADER, vertexSource);
	shader->fragment = CompileShader(GL_FRAGMENT_SHADER, fragmentSource);
	shader->tcs = CompileShader(GL_TESS_CONTROL_SHADER, tcsSource);
	shader->tes = CompileShader(GL_TESS_EVALUATION_SHADER, tesSource);

	// link shader program
	shader->program = LinkProgram(shader->vertex, shader->fragment, shader->tcs, shader->tes);
	
	return CheckGLShaderErrors();
}

// deallocate shader-related objects
void DestroyShaders(MyShader *shader)
{
	// unbind any shader programs and destroy shader objects
	glUseProgram(0);
	glDeleteProgram(shader->program);
	glDeleteShader(shader->vertex);
	glDeleteShader(shader->fragment);
}

// reads a text file with the given name into a string
std::string LoadSource(const std::string &filename)
{
	std::string source;

	std::ifstream input(filename.c_str());
	if (input) {
		std::copy(std::istreambuf_iterator<char>(input),
			std::istreambuf_iterator<char>(),
			std::back_inserter(source));
		input.close();
	}
	else {
		std::cout << "ERROR: Could not load shader source from file "
			<< filename << std::endl;
	}

	return source;
}

// creates and returns a shader object compiled from the given source
GLuint CompileShader(GLenum shaderType, const std::string &source)
{
	glCreateShader(shaderType);
	// allocate shader object name
	GLuint shaderObject = glCreateShader(shaderType);

	// try compiling the source as a shader of the given type
	const GLchar *source_ptr = source.c_str();
	glShaderSource(shaderObject, 1, &source_ptr, 0);
	glCompileShader(shaderObject);

	// retrieve compile status
	GLint status;
	glGetShaderiv(shaderObject, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint length;
		glGetShaderiv(shaderObject, GL_INFO_LOG_LENGTH, &length);
		std::string info(length, ' ');
		glGetShaderInfoLog(shaderObject, info.length(), &length, &info[0]);
		std::cout << "ERROR compiling shader:" << std::endl << std::endl;
		std::cout << source << std::endl;
		std::cout << info << std::endl;
	}

	return shaderObject;
}

bool CheckGLShaderErrors()
{
	bool error = false;
	for (GLenum flag = glGetError(); flag != GL_NO_ERROR; flag = glGetError())
	{
		std::cout << "OpenGL ERROR:  ";
		switch (flag) {
		case GL_INVALID_ENUM:
			std::cout << "GL_INVALID_ENUM" << std::endl; break;
		case GL_INVALID_VALUE:
			std::cout << "GL_INVALID_VALUE" << std::endl; break;
		case GL_INVALID_OPERATION:
			std::cout << "GL_INVALID_OPERATION" << std::endl; break;
		case GL_INVALID_FRAMEBUFFER_OPERATION:
			std::cout << "GL_INVALID_FRAMEBUFFER_OPERATION" << std::endl; break;
		case GL_OUT_OF_MEMORY:
			std::cout << "GL_OUT_OF_MEMORY" << std::endl; break;
		default:
			std::cout << "[unknown error code]" << std::endl;
		}
		error = true;
	}
	return error;
}

// creates and returns a program object linked from vertex and fragment shaders
GLuint LinkProgram(GLuint vertexShader, GLuint fragmentShader, GLuint tcsShader, GLuint tesShader)
{
	// allocate program object name
	GLuint programObject = glCreateProgram();

	// attach provided shader objects to this program
	if (vertexShader)   glAttachShader(programObject, vertexShader);
	if (fragmentShader) glAttachShader(programObject, fragmentShader);
	if (tcsShader) glAttachShader(programObject, tcsShader);
	if (tesShader) glAttachShader(programObject, tesShader);

	// try linking the program with given attachments
	glLinkProgram(programObject);

	// retrieve link status
	GLint status;
	glGetProgramiv(programObject, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint length;
		glGetProgramiv(programObject, GL_INFO_LOG_LENGTH, &length);
		std::string info(length, ' ');
		glGetProgramInfoLog(programObject, info.length(), &length, &info[0]);
		std::cout << "ERROR linking shader program:" << std::endl;
		std::cout << info << std::endl;
	}

	return programObject;
}

MyShader::MyShader(const std::string & vertex_filename, const std::string & fragment_filename, const std::string& tc_filename, const std::string& te_filename)
	:
	vertex(0),
	fragment(0),
	tcs(0),
	tes(0),
	program(0)
{
	InitializeShaders(this, vertex_filename, fragment_filename, tc_filename, te_filename);
	std::cout << (int)program;
}

void MyShader::Clear()
{
	DestroyShaders(this);
}
