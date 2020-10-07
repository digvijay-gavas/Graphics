#include "InputHandler.h"

int InputHandler::__init = InputHandler::init();

GLFWwindow* InputHandler::window;
Camera InputHandler::camera;

void InputHandler::resizeCallback(GLFWwindow* window, int w, int h)
{
	std::cout << "resizeCallback: w" << w << ", h " << h << std::endl;
}
void InputHandler::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	std::cout << "keyCallback: key" << key << ", scancode " << scancode << ", action " << action << ", mods " << mods << std::endl;
}
void InputHandler::mouseClickCallback(GLFWwindow* window, int button, int action, int mods)
{
	std::cout << "mouseClickCallback: button" << button << ", action " << action << ", mods " << mods << std::endl;
}
void InputHandler::cursorPosCallback(GLFWwindow* window, double x, double y)
{
	std::cout << "cursorPosCallback: x" << x << ", y " << y << std::endl;
}

void  InputHandler::scrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera.zoom(yoffset);
	std::cout << "scrollCallback: xoffset" << xoffset << ", yoffset " << yoffset << std::endl;
}