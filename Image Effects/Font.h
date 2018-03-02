#pragma once
#include <vector>
#include "GlyphExtractor.h"
#include <cassert>

class Font
{
public:
	Font(const std::string& filename);
	const MyGlyph& GetGlyph(int i) const;
private:
	std::vector<MyGlyph> characters;
	GlyphExtractor glyph_extractor;
};