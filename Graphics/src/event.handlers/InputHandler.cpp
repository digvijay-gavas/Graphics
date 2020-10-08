#include "InputHandler.h"


int InputHandler::button1Down;
int InputHandler::button2Down;
GLFWwindow* InputHandler::window;
Camera InputHandler::camera;
double InputHandler::dragX;
double InputHandler::dragY;

double InputHandler::rotateX;
double InputHandler::rotateY;


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
		rotateX = 0;
		rotateY = 0;
		std::cout << "mouseClickCallback: GLFW_MOUSE_BUTTON_1 button" << button << ", action " << action << ", mods " << mods << std::endl;
		break;
	case GLFW_MOUSE_BUTTON_2:
		button2Down = action;
		dragX = 0;
		dragY = 0;
		std::cout << "mouseClickCallback: GLFW_MOUSE_BUTTON_2 button" << button << ", action " << action << ", mods " << mods << std::endl;
		break;
	}
	
}
void InputHandler::cursorPosCallback(GLFWwindow* window, double x, double y)
{
	if (button2Down==1) {		
		if (dragX == 0 && dragY == 0)
		{
			dragX = x;
			dragY = y;
		}
		panCallback(window, -(x - dragX), (y - dragY));
		dragX = x;
		dragY = y;
	}
	else if (button1Down == 1) {
		if (rotateX == 0 && rotateY == 0)
		{
			rotateX = x;
			rotateY = y;
		}
		rotateCallback(window, -(x - rotateX), (y - rotateY));
		rotateX = x;
		rotateY = y;
	}
	//std::cout << "cursorPosCallback: x" << x << ", y " << y << std::endl;
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

void  InputHandler::rotateCallback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera.rotate(xoffset, yoffset);
	std::cout << "rotateCallback: xoffset" << xoffset << ", yoffset " << yoffset << std::endl;
}