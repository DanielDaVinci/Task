#pragma once
struct Transform
{
	double x, y, z;

	Transform(double x = 0, double y = 0, double z = 0);

	Transform operator + (Transform other);
	Transform operator - (Transform other);
	Transform operator * (double other);
	Transform operator / (double other);

	Transform& operator += (Transform other);
	Transform& operator -= (Transform other);
	Transform& operator *= (double other);
	Transform& operator /= (double other);
};

