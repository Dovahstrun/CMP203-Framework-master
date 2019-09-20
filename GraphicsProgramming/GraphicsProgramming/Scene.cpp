#include "Scene.h"

// Scene constructor, initilises OpenGL
// You should add further variables to need initilised.
Scene::Scene(Input *in)
{
	// Store pointer for input class
	input = in;
		
	//OpenGL settings
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glClearStencil(0);									// Clear stencil buffer
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, 1);

	// Other OpenGL / render setting should be applied here.
	

	// Initialise scene variables
	
}

void Scene::handleInput(float dt)
{
	// Handle user input
}

void Scene::update(float dt)
{
	// update scene related variables.

	// Calculate FPS for output
	calculateFPS();
}

void Scene::render() {

	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(0.0f, 0.0f, 6.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	
	// Render geometry/scene here -------------------------------------

	rotation -= 1.0f;

	// rotate matrix
	glTranslatef(-1.0f, 0.0f, 0.0f);//tilt our solar system slightly so it isn’t on the eye plane
	glRotatef(20, 1, 0, 0);
	glPushMatrix();// Remember where we are.  THE SUN

		// render the sun
		glColor3f(1.0f, 0.9f, 0.0f);
		gluSphere(gluNewQuadric(), 0.20, 20, 20);
		glPushMatrix();//render planet 1
			glRotatef(rotation * 4, 0, 1, 0);
			glTranslatef(1, 0, 0);
			glRotatef(rotation, 0, 1, 0);
			glScalef(0.1, 0.1, 0.1);
			glColor3f(0.8f, 0.1f, 0.1f);
			gluSphere(gluNewQuadric(), 0.20, 20, 20);
		glPopMatrix();//GO BACK TO SUN

		glPushMatrix(); // REMEMBER WHERE WE ARE
		// render planet 2
			glRotatef(rotation * 2, 0, 1, 0);
			glTranslatef(1.5, 0, 0);
			glRotatef(rotation, 0, 1, 0);
			glScalef(0.3, 0.3, 0.3);
			glColor3f(0.1f, 0.9f, 1.0f);
			gluSphere(gluNewQuadric(), 0.20, 20, 20);
	
			glPushMatrix(); // REMEMBER WHERE WE ARE
				// Render a moon around planet 2
				glRotatef((rotation*2*2.0), 0, 1, 0);
				glTranslatef(1, 0, 0);
				glScalef(0.3, 0.3, 0.3);
				glColor3f(0.8f, 0.8f, 0.8f);
				gluSphere(gluNewQuadric(), 0.20, 20, 20);

				glPushMatrix(); // REMEMBER WHERE WE ARE
								// Render a moon around planet 2's moon
				glRotatef((rotation * 2 * 2.0), 0, 1, 0);
				glTranslatef(1, 0, 0);
				glScalef(0.3, 0.3, 0.3);
				glColor3f(0.8f, 0.8f, 0.8f);
				gluSphere(gluNewQuadric(), 0.20, 20, 20);
				glPopMatrix();

			glPopMatrix();

		glPopMatrix();//GO BACK TO SUN

		glPushMatrix();//render planet 3
			glRotatef(-rotation * 0.7, 0, 1, 0);
			glTranslatef(3, 0, 0);
			glRotatef(rotation, 0, 1, 0);
			glScalef(0.7, 0.7, 0.7);
			glColor3f(0.9f, 0.3f, 0.1f);
			gluSphere(gluNewQuadric(), 0.20, 20, 20);

			glPushMatrix(); // REMEMBER WHERE WE ARE
							// Render a moon around planet 3
				glRotatef((rotation * 2 * 2.0), 0, 1, 0);
				glTranslatef(1, 0, 0);
				glScalef(0.3, 0.3, 0.3);
				glColor3f(0.8f, 0.8f, 0.8f);
				gluSphere(gluNewQuadric(), 0.20, 20, 20);
			glPopMatrix();

			glPushMatrix(); // REMEMBER WHERE WE ARE
							// Render another moon around planet 3
			glRotatef((rotation * 2 * 2.0), 0, 0, 1);
			glTranslatef(-1, 0, 0);
			glScalef(0.3, 0.3, 0.3);
			glColor3f(0.8f, 0.8f, 0.8f);
			gluSphere(gluNewQuadric(), 0.20, 20, 20);
			glPopMatrix();

		glPopMatrix();//GO BACK TO SUN
	glPopMatrix();
	
	// Notice the indentation, this helps keep track of all the pushes and pops
	
	/*glTranslatef(-2.0, 1.0, 0.0);*/
	//glScalef(2, 0.5, 0);

	/*if (input->isKeyDown('o'))
	{
		glRotatef(45, 0, 1, 0);
	}
	else if (input->isKeyDown('p'))
	{
		glRotatef(-60, 0, 1, 0);
	}*/

	/*rotation -= 5.0f;*/

	/*glTranslatef(2, 0, 0);
	glScalef(1, 1, 1);
	glRotatef(rotation, 0, 0, 1);*/
	
	/*glRotatef(rotation, 0, 0, 1);
	glScalef(1, 1, 1);
	glTranslatef(1, 0, 0);*/
	
	/*glBegin(GL_TRIANGLES);

	glColor3f(1.0, 0.0, 0.0);

	glVertex3f(0.0, 1.0, 0.0);
	glVertex3f(-1.0, 0.0, 0.0);
	glVertex3f(1.0, 0.0, 0.0);

	glEnd();*/

	/*glClear;*/

	/*glRotatef(rotation, 0, 0, 1);
	glScalef(0.5, 0.5, 0.5);
	glTranslatef(3, 0, 0);*/

	/*glBegin(GL_TRIANGLES);

	glColor3f(0.0, 0.0, 1.0);

	glVertex3f(0.0, 1.0, 0.0);
	glVertex3f(-1.0, 0.0, 0.0);
	glVertex3f(1.0, 0.0, 0.0);

	glEnd();*/

	glColor3f(1.0f, 1.0f, 1.0f);

	// End render geometry --------------------------------------

	// Render text, should be last object rendered.
	renderTextOutput();
	
	// Swap buffers, after all objects are rendered.
	glutSwapBuffers();
}

// Handles the resize of the window. If the window changes size the perspective matrix requires re-calculation to match new window size.
void Scene::resize(int w, int h) 
{
	width = w;
	height = h;
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;

	float ratio = (float)w / (float)h;
	fov = 45.0f;
	nearPlane = 0.1f;
	farPlane = 100.0f;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(fov, ratio, nearPlane, farPlane);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);

	
}

// Calculates FPS
void Scene::calculateFPS()
{

	frame++;
	time = glutGet(GLUT_ELAPSED_TIME);

	if (time - timebase > 1000) {
		sprintf_s(fps, "FPS: %4.2f", frame*1000.0 / (time - timebase));
		timebase = time;
		frame = 0;
	}
}

// Compiles standard output text including FPS and current mouse position.
void Scene::renderTextOutput()
{
	// Render current mouse position and frames per second.
	sprintf_s(mouseText, "Mouse: %i, %i", input->getMouseX(), input->getMouseY());
	displayText(-1.f, 0.96f, 1.f, 0.f, 0.f, mouseText);
	displayText(-1.f, 0.90f, 1.f, 0.f, 0.f, fps);
}

// Renders text to screen. Must be called last in render function (before swap buffers)
void Scene::displayText(float x, float y, float r, float g, float b, char* string) {
	// Get Lenth of string
	int j = strlen(string);

	// Swap to 2D rendering
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 5, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// Orthographic lookAt (along the z-axis).
	gluLookAt(0.0f, 0.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	// Set text colour and position.
	glColor3f(r, g, b);
	glRasterPos2f(x, y);
	// Render text.
	for (int i = 0; i < j; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, string[i]);
	}
	// Reset colour to white.
	glColor3f(1.f, 1.f, 1.f);

	// Swap back to 3D rendering.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fov, ((float)width/(float)height), nearPlane, farPlane);
	glMatrixMode(GL_MODELVIEW);
}
