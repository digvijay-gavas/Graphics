#include "InputHandler.h"


int InputHandler::button1Down;
GLFWwindow* InputHandler::window;
Camera InputHandler::camera;
double InputHandler::dragX;
double InputHandler::dragY;


void InputHandler::resizeCallback(GLFWwindow* window, int w, int h)
{
	camera.resize(w, h);
	std::cout << "resizeCallback: w" << w << ", h " << h << std::endl;
}
void InputHandler::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	std::cout << "keyCallback: key" << key << ", scancode " << scancode << ", action " << action << ", mods " << mods << std::endl;
}
void InputHandler::mouseClickCallback(GLFWwindow* window, int button, int action, int mods)
{
	switch (button) {
	case GLFW_MOUSE_BUTTON_1:
		button1Down = action;
		dragX = 0;
		dragY = 0;
	case GLFW_MOUSE_BUTTON_2:
		break;
	}
	std::cout << "mouseClickCallback: button" << button << ", action " << action << ", mods " << mods << std::endl;
}
void InputHandler::cursorPosCallback(GLFWwindow* window, double x, double y)
{
	if (button1Down==1) {		
		if (dragX == 0 && dragY == 0)
		{
			dragX = x;
			dragY = y;
		}
		panCallback(window, -(x - dragX), (y - dragY));
		dragX = x;
		dragY = y;
	}
	std::cout << "cursorPosCallback: x" << x << ", y " << y << std::endl;
}

void  InputHandler::scrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera.zoom(-yoffset);
	std::cout << "scrollCallback: xoffset" << xoffset << ", yoffset " << yoffset << std::endl;
}

void  InputHandler::panCallback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera.pan(xoffset, yoffset);
	std::cout << "panCallback: xoffset" << xoffset << ", yoffset " << yoffset << std::endl;
}