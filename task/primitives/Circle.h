#pragma once

#include "Primitive.h"

class Circle final : public Primitive
{
public:
	Circle(double x = 0, double y = 0, double z = 0, double angle = 0, Color color = Color()) :
		Primitive(x, y, z, angle, color, 1000) {};
};

