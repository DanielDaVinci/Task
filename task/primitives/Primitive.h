#pragma once

#include "GLM/glm.hpp"
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtc/type_ptr.hpp>

#include "../common/Transform.h"
#include "../common/Color.h"
#include "../task/Shader.h"

#include <vector>

using namespace std;

class Primitive
{
protected:

	Transform transform;
	double angle;
	Color color;

private:

	unsigned vertices = 0;

	Shader shader = Shader("Data/Shaders/shader.vs", "Data/Shaders/shader.frag");
	GLuint VBO, VAO;

public:

	Primitive(double x = 0, double y = 0, double z = 0, double angle = 0, Color color = Color(), unsigned vertices = 0);
	virtual ~Primitive();

	void Translate(Transform transform);
	void Translate(double x, double y, double z);
	void Rotate(double angle);

	void setColor(Color color);

	void Draw();

private:

	vector<GLfloat> getVertices(unsigned count);

};

