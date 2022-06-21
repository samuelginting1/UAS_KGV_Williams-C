#pragma once

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "Object.h"

class Trapezoid : public Object
{
public:
	static unsigned int vertexArray;
	static unsigned int vertexBuffer;
	static unsigned int indexBuffer;

	Trapezoid();
	void draw();

private:
	float vertices[8] = {
		-0.5, 1,
		0.5, 1,
		1, -1,
		-1, -1
	};

	unsigned indexArr[4] = {
		0, 1,
		2, 3,
	};
};

