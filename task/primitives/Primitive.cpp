#include "Primitive.h"

Primitive::Primitive(double x, double y, double z, double angle, Color color, unsigned vertices) : transform(Transform(x, y, z)), angle(angle), color(color), vertices(vertices)
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    vector<GLfloat> mVertices = getVertices(vertices);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices * 9 * sizeof(GLfloat), &mVertices[0], GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

Primitive::~Primitive()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Primitive::Translate(Transform transform)
{
    this->transform += transform;
}

void Primitive::Translate(double x, double y, double z)
{
    Translate(Transform(x, y, z));
}

void Primitive::Rotate(double angle)
{
    this->angle += angle;
}

void Primitive::setColor(Color color)
{
    this->color = color;
}

void Primitive::Draw()
{
    shader.setUniform("primColor", color.getR(), color.getG(), color.getB());

    shader.Use();

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, vertices * 3);
    glBindVertexArray(0);
}

vector<GLfloat> Primitive::getVertices(unsigned count)
{
    vector<float> vertices(count * 9);

    for (unsigned i = 0; i < count; i++)
    {
        vertices[i * 9] = 0.0f;
        vertices[i * 9 + 1] = 0.0f;
        vertices[i * 9 + 2] = 0.0f;

        float vAngle = 90.0f + (i * 360.0f / count);
        vertices[i * 9 + 3] = cos(vAngle * glm::pi<float>() / 180.0f);
        vertices[i * 9 + 4] = sin(vAngle * glm::pi<float>() / 180.0f);
        vertices[i * 9 + 5] = 0.0f;

        vAngle = 90.0f + ((i + 1) * 360.0f / count);
        vertices[i * 9 + 6] = cos(vAngle * glm::pi<float>() / 180.0f);
        vertices[i * 9 + 7] = sin(vAngle * glm::pi<float>() / 180.0f);
        vertices[i * 9 + 8] = 0.0f;
    }

    return vertices;
}
