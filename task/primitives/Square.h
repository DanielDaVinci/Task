#pragma once

#include "Primitive.h"

class Square final : public Primitive
{
public:
	Square(double x = 0, double y = 0, double z = 0, double angle = 0, Color color = Color()) :
		Primitive(x, y, z, angle + 45, color, 4) {};
};

