#include "object.h"
#include <algorithm>

Circle::Circle(float radius, const glm::vec3& center)
	:
	radius(radius),
	center(center),
	Object()
{
}

bool Circle::HasIntersection(const glm::vec3& origin, const glm::vec3& dir)
{
	// could streamline better to avoid doing these calculations twice

	float a = std::pow(dir.x, 2) + std::pow(dir.y, 2) + std::pow(dir.z, 2);
	float b = 2 * (dir.x*(origin.x - center.x) + dir.y*(origin.y - center.y) + dir.z*(origin.z - center.z));
	float c = std::pow(origin.x - center.x, 2) + std::pow(origin.y - center.y, 2) + std::pow(origin.z - center.z, 2) - std::pow(radius, 2);

	float sqr2ac = std::sqrt(std::pow(b, 2) - 4 * a * c) / (2 * a);
	float b2ac = -b / (2 * a);

	return std::pow(b, 2) - 4 * a * c >= 0.0f && ((b2ac - sqr2ac) >= 0.0f || (b2ac + sqr2ac) >= 0.0f);
}

glm::vec3 Circle::NearestIntersection(const glm::vec3& origin, const glm::vec3& dir)
{
	float a = std::pow(dir.x, 2) + std::pow(dir.y, 2) + std::pow(dir.z, 2);
	float b = 2*(dir.x*(origin.x - center.x) + dir.y*(origin.y - center.y) + dir.z*(origin.z - center.z));
	float c = std::pow(origin.x - center.x, 2) + std::pow(origin.y - center.y, 2) + std::pow(origin.z - center.z, 2) - std::pow(radius, 2);

	float sqr2ac = std::sqrt(std::pow(b, 2) - 4 * a * c) / (2 * a);
	float b2ac = -b / (2 * a);

	float t1 = b2ac + sqr2ac;
	float t2 = b2ac - sqr2ac;
	float t;

	if (t1 >= 0.0f && t2 >= 0.0f)
		t = std::min(t1, t2);
	else
		t = std::max(t1, t2);
	
	return origin + t * dir;
}

bool Triangle::HasIntersection(const glm::vec3& origin, const glm::vec3& dir)
{
	return false;
}

glm::vec3 Triangle::NearestIntersection(const glm::vec3& origin, const glm::vec3& dir)
{
	return glm::vec3();
}

bool Square::HasIntersection(const glm::vec3& origin, const glm::vec3& dir)
{
	return false;
}

glm::vec3 Square::NearestIntersection(const glm::vec3& origin, const glm::vec3& dir)
{
	return glm::vec3();
}

Object::Object()
	:
	color(1.0f, 0.0f, 0.0f)
{
}
