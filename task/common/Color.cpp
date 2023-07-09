#include "Color.h"

Color::Color(const char* colorCode)
{
	strcpy(code, colorCode);
}

Color::Color(string& colorCode) : Color(colorCode.c_str())
{
}

float Color::getR()
{
	float value = (float)((code[1] - ((code[1] >= '0' && code[1] <= '9') ? '0' : 'a' - 10)) * 16 +
		(code[2] - ((code[2] >= '0' && code[2] <= '9') ? '0' : 'a'))) / 256.0f;
	return value;
}

float Color::getG()
{
	return (float)((code[3] - ((code[3] >= '0' && code[3] <= '9') ? '0' : 'a' - 10)) * 16 +
		(code[4] - ((code[4] >= '0' && code[4] <= '9') ? '0' : 'a'))) / 256.0f;
}

float Color::getB()
{
	return (float)((code[5] - ((code[5] >= '0' && code[5] <= '9') ? '0' : 'a' - 10)) * 16 +
		(code[6] - ((code[6] >= '0' && code[6] <= '9') ? '0' : 'a'))) / 256.0f;
}




