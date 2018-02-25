#pragma once
#include <vector>
#include "MyGeometry.h"


class BezierCurve
{
public:
	BezierCurve();
	void Draw() const;
private:
	MyGeometry geometry;
	std::vector<float> vertices;
};