
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
void drawSphere(double r, int lats, int longs);


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
	//glEnable(GL_AUTO_NORMAL);
	//glClearDepth(1);
	//glEnable(GL_DEPTH_TEST);
	//glDepthFunc(GL_LEQUAL);
	//glShadeModel(GL_SMOOTH);
	//glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
	
	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);
	//glEnable(GL_LIGHT1);

	//glEnable(GL_LIGHT2);

	//glEnable(GL_NORMALIZE);
	//glMatrixMode(GL_MODELVIEW);

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.0, 0.0, 0.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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

		drawSphere(2,10,10);
		glfwSwapBuffers(window);
		glfwPollEvents();
		std::this_thread::sleep_for(10ms);
	}
	glfwDestroyWindow(window);
	return 0;
}



void drawSphere(double r, int lats, int longs) {
	int i, j;
	for (i = 0; i <= lats; i++) {
		double lat0 = PI * (-0.5 + (double)(i - 1) / lats);
		double z0 = sin(lat0);
		double zr0 = cos(lat0);

		double lat1 = PI * (-0.5 + (double)i / lats);
		double z1 = sin(lat1);
		double zr1 = cos(lat1);

		//glBegin(GL_QUAD_STRIP);
		glBegin(GL_LINES);
		for (j = 0; j <= longs; j++) {
			double lng = 2 * PI * (double)(j - 1) / longs;
			double x = cos(lng);
			double y = sin(lng);

			glNormal3f(x * zr0, y * zr0, z0);
			glVertex3f(r * x * zr0, r * y * zr0, r * z0);
			glNormal3f(x * zr1, y * zr1, z1);
			glVertex3f(r * x * zr1, r * y * zr1, r * z1);
		}
		glEnd();

		glBegin(GL_LINES);
		for (j = 0; j <= longs; j++) {
			double lng = 2 * PI * (double)(j - 1) / longs;
			double x = cos(lng);
			double y = sin(lng);

			glNormal3f(x * zr0, y * zr0, z0);
			glVertex3f(r * x * zr0, r * y * zr0, r * z0);
			glNormal3f(x * zr1, y * zr1, z1);
			glVertex3f(r * x * zr1, r * y * zr1, r * z1);
		}
		glEnd();
	}
}


/*void drawSphere(double radius, int alpha, int beta) {
	GLfloat x=0, y=0, z=0;// , alpha, beta; // Storage for coordinates and angles        
	//GLfloat radius = 60.0f;
	int gradation = 20;
	for (alpha = 0.0; alpha < PI; alpha += PI / gradation)
	{
		glBegin(GL_TRIANGLE_STRIP);
		for (beta = 0.0; beta < 2.01 * PI; beta += PI / gradation)
		{
			x = radius * cos(beta) * sin(alpha);
			y = radius * sin(beta) * sin(alpha);
			z = radius * cos(alpha);
			glVertex3f(x, y, z);
			x = radius * cos(beta) * sin(alpha + PI / gradation);
			y = radius * sin(beta) * sin(alpha + PI / gradation);
			z = radius * cos(alpha + PI / gradation);
			glVertex3f(x, y, z);
		}
		glEnd();
	}
}*/