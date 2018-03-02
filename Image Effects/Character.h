#pragma once
#include "glm.hpp"
#include "Font.h"
#include "MyShader.h"
#include "GlyphExtractor.h"
#include "MyGeometry.h"

class Character
{
public:
	Character(int c, const Font& font, const glm::vec3& color, const Shaders& shaders);
	void Draw() const;
private:
	void LoadGlyph(int c, const MyGlyph& glyph);
private:
	MyGeometry line_geo;
	MyGeometry quad_geo;
	MyGeometry cubic_geo;

	glm::vec3 color;
	const Font& font;
	const Shaders& shaders;
};

glm::mat4 CreateTransMatrix(float scale, glm::vec2 offset);