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
	void SetPosition(const glm::vec2 new_pos);
	const glm::vec2& GetPosition() const;
	void SetScale(float new_scale);
	void SetColor(glm::vec3 new_color);
	float GetAdvance() const;
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

	float advance;
	float scale = 1.0f;
	glm::vec2 pos = { 0.0f, 0.0f };
};

glm::mat4 CreateTransMatrix(float scale, glm::vec2 offset);