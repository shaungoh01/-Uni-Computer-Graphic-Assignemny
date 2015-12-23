#include "Mesh.hpp"
#include "ObjReader.hpp"
#include <cstdint>
#include <cstring>
#include <iostream>

static const vec3 DEFAULT_COLOR = {.5,.5,.5};

Mesh::Mesh() :
    isVertexColor(false),
    isFlatColor(true),
    isVisible(true),
    name("Default Mesh Name")
{
    resetTransformations();
}

Mesh::Mesh(std::string path) : Mesh()
{
    ObjReader::loadOBJIndexed(path.c_str(),
                              vertices,
                              uvs,
                              normals,
                              indices);
}

Mesh::~Mesh()
{
}

void Mesh::draw()
{
    if (!isVisible) return;

    glPushMatrix();

    glRotatef(rotateX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotateY, 0.0f, 1.0f, 0.0f);
    glRotatef(rotateZ, 0.0f, 0.0f, 1.0f);
    glTranslatef(translateX, translateY, translateZ);
    glScalef(scale, scale, scale);

    if (isFlatColor) glColor3fv(&flat_color[0]);

    glBegin(GL_TRIANGLES);
    for (int j = 0; j < indices.size(); j++) {
        GLushort i = indices[j];
        if (isVertexColor) {
            glColor3fv(&colors[i][0]);
        }
        glNormal3fv(&normals[i][0]);
        glVertex3fv(&vertices[i][0]);
    }
    glEnd();

    glPopMatrix();

    glColor3fv(&DEFAULT_COLOR[0]);
}

void Mesh::resetTransformations()
{
    rotateX
        = rotateY
          = rotateZ
            = translateX
              = translateY
                = translateZ = 0;
    scale = 1;
}

bool Mesh::getVisibility() const
{
    return isVisible;
}

void Mesh::setVisibility(bool value)
{
    isVisible = value;
}

std::string Mesh::getName() const
{
    return name;
}

void Mesh::setName(const std::string &value)
{
    name = value;
}

GLuint Mesh::getNumIndices() const
{
    return indices.size();
}

GLuint Mesh::getNumVertices() const
{
    return vertices.size();
}

GLfloat Mesh::getScale() const
{
    return scale;
}

void Mesh::setScale(const GLfloat &value)
{
    scale = value;
}

GLfloat Mesh::getRotateX() const
{
    return rotateX;
}

void Mesh::setRotateX(const GLfloat &value)
{
    rotateX = value;

}
GLfloat Mesh::getRotateY() const
{
    return rotateY;
}

void Mesh::setRotateY(const GLfloat &value)
{
    rotateY = value;

}
GLfloat Mesh::getRotateZ() const
{
    return rotateZ;
}

void Mesh::setRotateZ(const GLfloat &value)
{
    rotateZ = value;
}

void Mesh::setTranslate(const vec3 &t)
{
    translateX = t[0];
    translateY = t[1];
    translateZ = t[2];
}

GLfloat Mesh::getTranslateX() const
{
    return translateX;
}

void Mesh::setTranslateX(const GLfloat &value)
{
    translateX = value;

}

GLfloat Mesh::getTranslateY() const
{
    return translateY;
}

void Mesh::setTranslateY(const GLfloat &value)
{
    translateY = value;

}
GLfloat Mesh::getTranslateZ() const
{
    return translateZ;
}

void Mesh::setTranslateZ(const GLfloat &value)
{
    translateZ = value;
}

void Mesh::enableVertexColor()
{
    isVertexColor = true;
}

void Mesh::disableVertexColor()
{
    isVertexColor = false;
}

bool Mesh::hasVertexColor() const
{
    return isVertexColor;
}

void Mesh::enableFlatColor()
{
    isFlatColor = true;
}

void Mesh::disableFlatColor()
{
    isFlatColor = false;
}

bool Mesh::hasFlatColor() const
{
    return isFlatColor;
}

void Mesh::setFlatColor(const vec3 &color)
{
    std::memcpy(&flat_color, &color, sizeof flat_color);
}

bool Mesh::hasUv() const
{
    return !uvs.empty();
}
