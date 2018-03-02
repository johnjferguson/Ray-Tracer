#include "TextField.h"
#include "glm.hpp"

TextField::TextField(const Font & font, const Shaders & shaders, const std::string & str)
	:
	font(font),
	shaders(shaders)
{
	for (const auto& c : str)
	{
		Character letter(c, font, { 1.0f,0.0f,1.0f }, shaders);
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

		left_position = new_pos;
		right_position = right_position + new_pos - left_position;
	}
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

void TextField::SetText(const std::string & str)
{
}

void TextField::Draw() const
{
	for (const auto& c : text)
		c.Draw();
}
