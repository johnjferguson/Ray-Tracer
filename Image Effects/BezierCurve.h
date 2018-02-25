#pragma once
#include <vector>
#include "MyGeometry.h"


class BezierCurve
{
public:
	BezierCurve() = default;
	BezierCurve(const std::vector<float>& vertices);
	void Draw(const GLuint& program) const;
	void SetVertices(const std::vector<float>& vertices);
	void SetIsCubic(bool tf);
private:
	void InitializeGeometry(const std::vector<float>& vertices);
	glm::mat4 CreateTransMatrix() const;
private:
	MyGeometry geometry;
	std::vector<float> vertices;
	bool isCubic = false;
	float scale = 0.5f;
};