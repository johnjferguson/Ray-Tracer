#pragma once
#include "vec3.hpp"

// abstract class
class Object
{
public:
	Object();
	virtual bool HasIntersection(const glm::vec3& origin, const glm::vec3& dir) = 0;
	virtual glm::vec3 NearestIntersection(const glm::vec3& origin, const glm::vec3& dir) = 0;
private:
	glm::vec3 color;
};

class Circle : public Object
{
public:
	Circle(float radius, const glm::vec3& center);
	bool HasIntersection(const glm::vec3& origin, const glm::vec3& dir);
	glm::vec3 NearestIntersection(const glm::vec3& origin, const glm::vec3& dir);
private:
	float radius;
	glm::vec3 center;
};

class Triangle : public Object
{
public:
	bool HasIntersection(const glm::vec3& origin, const glm::vec3& dir);
	glm::vec3 NearestIntersection(const glm::vec3& origin, const glm::vec3& dir);
private:
};

class Square : public Object
{
public:
	bool HasIntersection(const glm::vec3& origin, const glm::vec3& dir);
	glm::vec3 NearestIntersection(const glm::vec3& origin, const glm::vec3& dir);
private:
};