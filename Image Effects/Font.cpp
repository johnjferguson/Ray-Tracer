#include "Font.h"

Font::Font(const std::string& filename)
{
	glyph_extractor.LoadFontFile(filename);

	for (int i = 32; i < 127; i++)
	{
		MyGlyph glyph = glyph_extractor.ExtractGlyph(i);
		characters.push_back(glyph);
	}

}

const MyGlyph & Font::GetGlyph(int i) const
{
	assert(i >= 32 && i <= 126);
	return characters[i - 32];
}
