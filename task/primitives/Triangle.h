#pragma once

#include "Primitive.h"

class Triangle : public Primitive
{
public:
	Triangle(double x = 0, double y = 0, double z = 0, double angle = 0, Color color = Color()) : 
		Primitive(x, y, z, angle, color, 3) {};
};

