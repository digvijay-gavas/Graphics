#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <business.objects.geometry/Point.h>
#include <business.objects.geometry/Vector.h>

class Camera
{
private:
	GLFWwindow* window;
	Point eye, look;
	Vector up;

	void update();
	static void  resizeCallback(GLFWwindow* window, int w, int h);
	static void  keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void  mouseClickCallback(GLFWwindow* window, int button, int action, int mods);
	static void  cursorPosCallback(GLFWwindow* window, double x, double y);

public:
	Camera(GLFWwindow* window);
	void pan(GLdouble x, GLdouble y);
	void zoom(GLdouble angle);
	void setAt(GLdouble x, GLdouble y,GLdouble z);
	void setAt(Point eye);

	void lookAt(GLdouble x, GLdouble y,GLdouble z);
	void lookAt(Point look);

};