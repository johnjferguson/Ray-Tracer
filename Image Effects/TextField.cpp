#include "TextField.h"
#include "glm.hpp"

TextField::TextField(const Font & font, const Shaders & shaders, const std::string & str)
	:
	font(font),
	shaders(shaders)
{
	for (const auto& c : str)
	{
		Character letter(c, font, color, shaders);
		letter.SetPosition(right_position);
		letter.SetScale(scale);
		right_position = right_position + glm::vec2(letter.GetAdvance(), 0.0f);
		text.push_back(letter);
	}
}

void TextField::SetPosition(const glm::vec2& new_pos)
{
	if (new_pos != left_position)
	{
		for (auto& t : text)
		{
			t.SetPosition(t.GetPosition() + new_pos - left_position);
		}

		right_position = right_position + new_pos - left_position;
		left_position = new_pos;
	}
}

const glm::vec2& TextField::GetPosition() const
{
	return left_position;
}

float TextField::GetWidth() const
{
	return right_position.x - left_position.x;
}

void TextField::SetScale(float new_scale)
{
	if (new_scale != scale)
	{
		right_position = left_position;
		for (auto& t : text)
		{
			t.SetPosition(right_position);
			t.SetScale(new_scale);
			right_position = right_position + glm::vec2(t.GetAdvance(), 0.0f);
		}
	}
}

void TextField::SetColor(const glm::vec3 & new_color)
{
	color = new_color;

	for (auto& c : text)
		c.SetColor(new_color);
}

void TextField::SetText(const std::string & str)
{
}

void TextField::Draw() const
{
	for (const auto& c : text)
		c.Draw();
}
