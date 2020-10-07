
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <iostream>
#include <math.h> 


#include "business.objects/Camera.h"
#include "business.objects.geometry/Point.h"
#include "event.handlers/InputHandler.h"

#include <chrono>
#include <thread>
using namespace std::chrono_literals;

static int WIDTH = 1024;
static int HEIGHT = 768;
double PI = 3.1415;
double trans = 0;
float rotatex = 0, rotatey = 0, mouseX = 0, mouseY = 0;
bool dragging = false, panning = false;
float dragX = 0;
float dragY = 0;
int keyArr[350];

float x = 100, y = 100, dt = 0.001, M = 10000, c = 0.6, g = 0, distance = 100, r = 25, g1;
float px = 400, py = 400, vx = 1.2, vy = 1.3, ax, ay;
float px1 = 400, py1 = 400, vx1 = 1.5, vy1 = 0.3, ax1, ay1;
float  distance1;


int main(int argc, char** argv) {
	GLFWwindow* window;
	float zoom = 5;

	glfwInit();
	window = glfwCreateWindow(WIDTH, HEIGHT, argv[0], NULL, NULL);
	glfwMakeContextCurrent(window);

	Camera camera = Camera(WIDTH, HEIGHT);
	camera.setAt(Point(0, 0, 10));
	camera.lookAt(Point(0, 0, 0));
	//camera.zoom(zoom);

	InputHandler::window = window;
	InputHandler::camera = camera;
	InputHandler::init();
	

	glClearColor(0.0, 0.0, 0.2, 1.0);
	

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.0, 0.0, 0.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);

		glColor3f(1.0, 0.0, 0.0); // red x
		glBegin(GL_LINES);
		glVertex3f(-1.0, 0.0f, 0.0f); glVertex3f(1.0, 0.0f, 0.0f);// x aix
		glVertex3f(1.0, 0.0f, 0.0f);glVertex3f(0.3, 0.1f, 0.0f); glVertex3f(1.0, 0.0f, 0.0f); glVertex3f(0.3, -0.1f, 0.0f);// arrow
		glEnd();

		glColor3f(0.0, 1.0, 0.0); // green x
		glBegin(GL_LINES);
		glVertex3f(0.0, -1.0f, 0.0f); glVertex3f(0.0, 1.0f, 0.0f);// x aix
		glVertex3f(0.0f, 1.0, 0.0f); glVertex3f(0.1f,  0.3,  0.0f); glVertex3f(0.0f,  1.0,  0.0f); glVertex3f(-0.1f, 0.3, 0.0f);// arrow
		glEnd();

		glColor3f(0.0, 0.0, 1.0); // blue x
		glBegin(GL_LINES);
		glVertex3f( 0.0f, 0.0f, -1.0); glVertex3f( 0.0f, 0.0f, 1.0);// x aix
		glVertex3f( 0.0f, 0.0f, 1.0); glVertex3f( 0.1f, 0.0f, 0.3); glVertex3f(0.0f, 0.0f, 1.0); glVertex3f( -0.1f, 0.0f, 0.3);// arrow
		glEnd();
		
		glFlush();

		glfwSwapBuffers(window);
		glfwPollEvents();
		std::this_thread::sleep_for(10ms);
	}
	glfwDestroyWindow(window);
	return 0;
}