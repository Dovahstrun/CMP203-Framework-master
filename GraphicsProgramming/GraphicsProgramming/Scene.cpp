#include "Scene.h"

// Scene constructor, initilises OpenGL
// You should add further variables to need initilised.
Scene::Scene(Input *in)
{
	// Store pointer for input class
	input = in;
		
	//OpenGL settings
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glClearStencil(0);									// Clear stencil buffer
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, 1);

	// Other OpenGL / render setting should be applied here.
	glutSetCursor(GLUT_CURSOR_NONE);

	// Initialise scene variables


	//Define lights

	//glEnable(GL_COLOR_MATERIAL);
	//glEnable(GL_LIGHTING);


	//Depth Test
	glEnable(GL_DEPTH_TEST); 
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_TEXTURE_2D);


	myTexture = SOIL_load_OGL_texture
	(
		"gfx/cratearrow.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	Omnitrix = SOIL_load_OGL_texture
	(
		"gfx/ben10.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	triangle = SOIL_load_OGL_texture
	(
		"gfx/bluered.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	rubiks = SOIL_load_OGL_texture
	(
		"gfx/rubiks.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	checks = SOIL_load_OGL_texture
	(
		"gfx/checked.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
}


void Scene::handleInput(float dt)
{
	// Handle user input
	if (input->isKeyDown('r'))
	{
		glGetIntegerv(GL_POLYGON_MODE, &polygonMode);
		if (polygonMode == GL_FILL)
		{
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		}
		else
		{
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		}
		input->SetKeyUp('r');
	}


	//////////////////////////////////////////////////////////////////////////////////////////////////////
	///MOVEMENT
	//////////////////////////////////////////////////////////////////////////////////////////////////////

	//Forwards and back
	if (input->isKeyDown('w'))
	{
		camera.moveForward(dt);//Forward
	}
	if (input->isKeyDown('s'))
	{
		camera.moveBackward(dt);//Backward
	}

	//Up and down
	if (input->isKeyDown(' '))
	{
		camera.moveUp(dt);//Up
	}
	if (input->isKeyDown('f'))
	{
		camera.moveDown(dt);//Down
	}

	//Left and right
	if (input->isKeyDown('a'))
	{
		camera.moveLeft(dt);//Left
	}
	if (input->isKeyDown('d'))
	{
		camera.moveRight(dt);//Right
	}


	if (input->isKeyDown('o'))
	{
		camera.rotateLeft();
	}
	if (input->isKeyDown('p'))
	{
		camera.rotateRight();
	}

	if (input->getMouseX() != 0.0f)
	{
		float xDistance = input->getMouseX() - width / 2;
		camera.rotateYaw(xDistance, dt);
	}
	if (input->getMouseY() != 0.0f)
	{
		float yDistance = input->getMouseY() - height / 2;
		camera.rotatePitch(yDistance, dt);
		input->setMouseY(height / 2);
	}
	glutWarpPointer(width/2, height/2);
	
}

void Scene::update(float dt)
{
	// update scene related variables.

	//Update camera
	camera.update(dt);

	// Calculate FPS for output
	calculateFPS();
}

void Scene::render() {

	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	//gluLookAt(0.0f, 0.0f, 6.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	gluLookAt(camera.getPosition().x, camera.getPosition().y, camera.getPosition().z, camera.getLookAt().x, camera.getLookAt().y, camera.getLookAt().z, camera.getUp().x, camera.getUp().y, camera.getUp().z);
	
	// Render geometry/scene here -------------------------------------

	rotation += 0.2f;
	glBindTexture(GL_TEXTURE_2D, rubiks);
	glRotatef(rotation, 1, 1, 0);

	//Front face
	glBegin(GL_QUADS); //Begin drawing state

		glColor3f(1.0f, 1.0f, 1.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);

	glEnd(); //end drawing

	//Right face
	glBegin(GL_QUADS); //Begin drawing state

		glColor3f(1.0f, 0.0f, 0.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);

	glEnd(); //end drawing

	//Left face
	glBegin(GL_QUADS); //Begin drawing state

		glColor3f(1.0f, 0.5f, 0.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);

	glEnd(); //end drawing

	//Top face
	glBegin(GL_QUADS); //Begin drawing state

		glColor3f(0.0f, 0.0f, 1.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);

	glEnd(); //end drawing

	//Bottom face
	glBegin(GL_QUADS); //Begin drawing state

		glColor3f(0.0f, 1.0f, 0.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);

	glEnd(); //end drawing

	//Back face
	glBegin(GL_QUADS); //Begin drawing state

		glColor3f(1.0f, 1.0f, 0.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);

	glEnd(); //end drawing

	glRotatef(-rotation, 1, 1, 0);

	//rotate the objects drawn after
	//glRotatef(25, 1.0f, 0.0f, 0.0f);

	//Render plane
	for (double i = -10; i < 10; i += 1)
	{
		for (double j = -10; j < 10; j += 1)
		{
			renderPlane(i, 0.0f, j);
		}
	}

	//glRotatef(-25, 1.0f, 0.0f, 0.0f);

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

void Scene::renderPlane(double x, double y, double z)
{
	glBegin(GL_QUADS);

	//glColor3f(0.0f, 1.0f, 0.0f);
	//set normal
	glNormal3f(0.0f, 1.0f, 0.0f);
	//draw plane
	glTexCoord2f(x, y);
	glVertex3f(x, y, z - 1);

	glTexCoord2f(x + 1, y);
	glVertex3f(x, y, z);

	glTexCoord2f(x + 1, y + 1);
	glVertex3f(x + 1, y, z);

	glTexCoord2f(x, y + 1);
	glVertex3f(x + 1, y, z - 1);


	glEnd();
}