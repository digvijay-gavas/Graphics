#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <business.objects.geometry/Point.h>
#include <business.objects.geometry/Vector.h>
#include <business.objects/Camera.h>

class InputHandler
{
private:
	static int button1Down, button2Down;
	static double dragX,dragY;
	static double rotateX;
	static double rotateY;
public:
	static void init() {
		button1Down = 0;
		button2Down = 0;
		glfwSetWindowSizeCallback(window, InputHandler::resizeCallback);
		glfwSetKeyCallback(window, InputHandler::keyCallback);
		glfwSetMouseButtonCallback(window, InputHandler::mouseClickCallback);
		glfwSetCursorPosCallback(window, InputHandler::cursorPosCallback);
		glfwSetScrollCallback(window, InputHandler::scrollCallback);
	};

	static GLFWwindow* window;
	static Camera camera;
	static void  resizeCallback(GLFWwindow* window, int w, int h);
	static void  keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void  mouseClickCallback(GLFWwindow* window, int button, int action, int mods);
	static void  cursorPosCallback(GLFWwindow* window, double x, double y);
	static void  scrollCallback(GLFWwindow* window, double xoffset, double yoffset);

	// derived event
	static void  panCallback(GLFWwindow* window, double xoffset, double yoffset);
	static void  rotateCallback(GLFWwindow* window, double xoffset, double yoffset);

};