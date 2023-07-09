#include "Transform.h"

Transform::Transform(double x, double y, double z) : x(x), y(y), z(z)
{
}

Transform Transform::operator+(Transform other)
{
	return Transform(x + other.x, y + other.y, z + other.z);
}

Transform Transform::operator-(Transform other)
{
	return Transform(x - other.x, y - other.y, z - other.z);
}

Transform Transform::operator*(double other)
{
	return Transform(x * other, y * other, z * other);
}

Transform Transform::operator/(double other)
{
	return Transform(x / other, y / other, z / other);
}

Transform& Transform::operator+=(Transform other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	return *this;
}

Transform& Transform::operator-=(Transform other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
	return *this;
}

Transform& Transform::operator*=(double other)
{
	x *= other;
	y *= other;
	z *= other;
	return *this;
}

Transform& Transform::operator/=(double other)
{
	x /= other;
	y /= other;
	z /= other;
	return *this;
}
