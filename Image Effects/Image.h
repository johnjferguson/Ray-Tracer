#pragma once
#include <vector>
#include <string>
#include "glm.hpp"
#include "MyGeometry.h"
#include "texture.h"
#include "MyShader.h"

class Image
{
public:
	Image(const std::string& filename);
	void Draw() const;
	void DestroyImage();
private:
	void Initialize();
private:
	MyGeometry geometry;
	MyTexture texture;
};