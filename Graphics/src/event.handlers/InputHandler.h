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
public:
	static int init() {
		glfwSetWindowSizeCallback(window, InputHandler::resizeCallback);
		glfwSetKeyCallback(window, InputHandler::keyCallback);
		glfwSetMouseButtonCallback(window, InputHandler::mouseClickCallback);
		glfwSetCursorPosCallback(window, InputHandler::cursorPosCallback);
		glfwSetScrollCallback(window, InputHandler::scrollCallback);
		return 0;
	};

	static GLFWwindow* window;
	static Camera camera;
	static int __init;
	static void  resizeCallback(GLFWwindow* window, int w, int h);
	static void  keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void  mouseClickCallback(GLFWwindow* window, int button, int action, int mods);
	static void  cursorPosCallback(GLFWwindow* window, double x, double y);
	static void  scrollCallback(GLFWwindow* window, double xoffset, double yoffset);

};