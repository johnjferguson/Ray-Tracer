#include "Character.h"
#include "type_ptr.hpp"

Character::Character(int c, const Font & font, const glm::vec3 & color, const Shaders& shaders)
	:
	font(font),
	color(color),
	shaders(shaders)
{
	LoadGlyph(c, font.GetGlyph(c));
}

void Character::SetPosition(const glm::vec2 new_pos)
{
	pos = new_pos;
}

const glm::vec2 & Character::GetPosition() const
{
	return pos;
}

void Character::SetScale(float new_scale)
{
	scale = new_scale;
}

float Character::GetAdvance() const
{
	return advance*scale;
}

void Character::Draw() const
{
	glUseProgram(shaders.shaders[2].program);
	glPatchParameteri(GL_PATCH_VERTICES, 4);

	float* fsrt = (float*)glm::value_ptr(CreateTransMatrix(scale, pos));
	glUniformMatrix4fv(glGetUniformLocation(shaders.shaders[2].program, "srt"), 1, false, fsrt);
	glUniform3f(glGetUniformLocation(shaders.shaders[2].program, "scolor"), 0.0f, 1.0f, 0.0f);

	glBindVertexArray(cubic_geo.VAO);
	glBindBuffer(GL_ARRAY_BUFFER, cubic_geo.VBO);
	glDrawArrays(GL_PATCHES, 0, cubic_geo.elementCount);

	glUseProgram(shaders.shaders[0].program);

	glUniformMatrix4fv(glGetUniformLocation(shaders.shaders[0].program, "srt"), 1, false, fsrt);
	glUniform3f(glGetUniformLocation(shaders.shaders[0].program, "scolor"), 0.0f, 1.0f, 0.0f);

	glBindVertexArray(line_geo.VAO);
	glBindBuffer(GL_ARRAY_BUFFER, line_geo.VBO);
	glDrawArrays(GL_LINES, 0, line_geo.elementCount);
	
}

void Character::LoadGlyph(int c, const MyGlyph & glyph)
{
	advance = glyph.advance;

	std::vector<glm::vec2> lines, quad, cubic;

	for (const auto& contour : glyph.contours)
	{
		for (const auto& segment : contour)
		{
			int npoints = segment.degree + 1;
			for (int i = 0; i < npoints; i++)
			{
				if (npoints == 2)
					lines.emplace_back(segment.x[i], segment.y[i]);
				else if (npoints == 3)
					quad.emplace_back(segment.x[i], segment.y[i]);
				else if (npoints == 4)
					cubic.emplace_back(segment.x[i], segment.y[i]);
				else
					std::cout << "(Character.cpp)(LoadGlyph)" << std::endl;
			}
		}
	}
	InitializeVAO(&line_geo);
	LoadGeometry(&line_geo, lines, lines.size());

	InitializeVAO(&quad_geo);
	LoadGeometry(&quad_geo, quad, quad.size());

	InitializeVAO(&cubic_geo);
	LoadGeometry(&cubic_geo, cubic, cubic.size());

}

glm::mat4 CreateTransMatrix(float scale, glm::vec2 offset)
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
	return s * t;
}
