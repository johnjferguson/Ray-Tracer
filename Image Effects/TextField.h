#pragma once
#include <vector>
#include "Character.h"

class TextField
{
public:
	TextField(const Font& font, const Shaders& shaders, const std::string& str = "");
	void SetPosition(const glm::vec2& new_pos);
	float GetWidth() const;
	void SetScale(float new_scale);
	void SetColor(const glm::vec3& new_color);
	void Draw() const;
private:
	void SetText(const std::string& str);
	std::vector<Character> text;
	
	const Font& font;
	const Shaders& shaders;
	
	glm::vec2 left_position = { -1.0f, 0.0f };
	glm::vec2 right_position = { -1.0f, 0.0f };

	float scale = 1.0f;
	glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f);
};