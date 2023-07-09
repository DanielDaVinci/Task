#pragma once

#include <string>

using namespace std;

class Color
{
private:

	char code[7];

public:

	Color(const char* colorCode = "#000000");
	Color(string& colorCode);

	float getR();
	float getG();
	float getB();
};

