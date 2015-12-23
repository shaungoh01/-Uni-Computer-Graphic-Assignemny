#pragma once

#include "Typedefs.hpp"
#include <vector>
#include <string>
#include <GL/gl.h>

using std::vector;

class Mesh
{
public:
    Mesh();
    Mesh(std::string path);
    virtual ~Mesh();
    void draw();

    GLuint getNumIndices() const;
    GLuint getNumVertices() const;

    void enableVertexColor();
    void disableVertexColor();
    bool hasVertexColor() const;

    void enableFlatColor();
    void disableFlatColor();
    bool hasFlatColor() const;
    void setFlatColor(const vec3 &color);

    bool hasUv() const;

    // transformations:
    GLfloat getScale() const;
    GLfloat getRotateX() const;
    GLfloat getRotateY() const;
    GLfloat getRotateZ() const;
    GLfloat getTranslateX() const;
    GLfloat getTranslateY() const;
    GLfloat getTranslateZ() const;

    void setScale(const GLfloat &value);
    void setRotateX(const GLfloat &value);
    void setRotateY(const GLfloat &value);
    void setRotateZ(const GLfloat &value);
    void setTranslate(const vec3 &t);
    void setTranslateX(const GLfloat &value);
    void setTranslateY(const GLfloat &value);
    void setTranslateZ(const GLfloat &value);

    void resetTransformations();

    bool getVisibility() const;
    void setVisibility(bool value);

    std::string getName() const;
    void setName(const std::string &value);

protected:
    vector<vec3> vertices;
    vector<vec3> colors;
    vector<vec3> normals;
    vector<vec2> uvs;
    vector<GLushort> indices;

private:
    bool isVertexColor;
    bool isFlatColor;
    bool isVisible;
    std::string name;

    vec3 flat_color;

    GLfloat rotateX;
    GLfloat rotateY;
    GLfloat rotateZ;

    GLfloat translateX;
    GLfloat translateY;
    GLfloat translateZ;

    GLfloat scale;
};

