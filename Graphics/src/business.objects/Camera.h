#pragma once
#include <GL/glew.h>
class Camera
{

public:
	void pan(GLdouble x, GLdouble y);
	void zoom(GLdouble angle);
	void setAt(GLdouble x, GLdouble y,GLdouble z);
	void lookAt(GLdouble x, GLdouble y,GLdouble z);

};