#include "Scene.h"

// Scene constructor, initilises OpenGL
// You should add further variables to need initilised.
Scene::Scene(Input *in)
{
	// Store pointer for input class
	input = in;
		
	//OpenGL settings
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);				// Black Background
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

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);


	//Depth Test
	glEnable(GL_DEPTH_TEST); 
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_TEXTURE_2D);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);


	myTexture = SOIL_load_OGL_texture
	(
		"gfx/crate.png",
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

	grass = SOIL_load_OGL_texture
	(
		"gfx/grass_top.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	tpchecks = SOIL_load_OGL_texture
	(
		"gfx/transparentChecked.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	tpcrate = SOIL_load_OGL_texture
	(
		"gfx/transparentCrate.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	sky = SOIL_load_OGL_texture
	(
		"gfx/skybox.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	hoohTex = SOIL_load_OGL_texture
	(
		"models/Ho-oh/textures/houou_0_0.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT | SOIL_FLAG_INVERT_Y
	);

	shinyhoohTex = SOIL_load_OGL_texture
	(
		"models/Ho-oh/textures/houou_0_0S.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT | SOIL_FLAG_INVERT_Y
	);

	suicuneTex = SOIL_load_OGL_texture
	(
		"models/Suicune/BodyB1_0.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	enteiTex = SOIL_load_OGL_texture
	(
		"models/Entei/images/pm0244_00_BodyA1.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT | SOIL_FLAG_INVERT_Y
	);

	raikouTex = SOIL_load_OGL_texture
	(
		"models/Raikou/images/pm0243_00_BodyA1.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT | SOIL_FLAG_INVERT_Y
	);

	bellTex = SOIL_load_OGL_texture
	(
		"models/Japanese_Temple_Model/Textures/Japanese_Temple_Paint2_Japanese_Shrine_Mat_AlbedoTransparency.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	pokeballTex = SOIL_load_OGL_texture
	(
		"gfx/pokeball.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	shadowTex = SOIL_load_OGL_texture
	(
		"gfx/imposter.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	hooh.load("models/Ho-oh.obj", "models/Ho-oh/textures/houou_0_0.png");
	bell_Tower.load("models/Bell Tower/Japanese Shrine Tower/Bell Tower.obj", "models/Ho-oh/textures/houou_0_0.png");
	suicune.load("models/Suicune/suicunetri.obj", "models/Suicune/SuicuneTex.png");
	entei.load("models/entei.obj", "models/Ho-oh/textures/houou_0_0.png");
	raikou.load("models/raikou.obj", "models/Ho-oh/textures/houou_0_0.png");
	lightShine.load("models/LightShine.obj", "models/Ho-oh/textures/houou_0_0.png");

	cameraViews = MAIN; 

	hoohView.setPosition(Vector3(7.0f, 27.0f, 10.0f));
	hoohView.setYaw(-20);
	hoohView.setPitch(10);

	beastView.setPosition(Vector3(-6.0f, -2.0f, 15.0f));
	beastView.setYaw(15);
	beastView.setPitch(-20);

	overView.setPosition(Vector3(-2.0f, 20.0f, -14.0f));
	/*overView.setPosition(Vector3(0.0f, 0.0f, 0.0f));*/
	overView.setYaw(0);
	overView.setPitch(-15);
}


void Scene::handleInput(float dt)
{
	// Handle user input

	//////////////////////////////////////////////////////////////////////////////////////////////////////
	///WIREFRAME MODE
	//////////////////////////////////////////////////////////////////////////////////////////////////////
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
	///CAMERAS
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	if (input->isKeyDown('h'))
	{
		cameraViews = HOOH;
	}
	else if (input->isKeyDown('b'))
	{
		cameraViews = BEASTS;
	}
	else if (input->isKeyDown('o'))
	{
		cameraViews = OVER;
		if (input->isKeyDown('a'))
			overViewRotation += 20 * dt;
		else if (input->isKeyDown('d'))
			overViewRotation -= 20 * dt;
	}
	else
	{
		cameraViews = MAIN;
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////////
	///MOVEMENT
	//////////////////////////////////////////////////////////////////////////////////////////////////////

	//Forwards and back
	if (input->isKeyDown('w') && cameraViews == MAIN)
	{
		camera.moveForward(dt);//Forward
	}
	if (input->isKeyDown('s') && cameraViews == MAIN)
	{
		camera.moveBackward(dt);//Backward
	}

	//Up and down
	if (input->isKeyDown(' ') && cameraViews == MAIN)
	{
		camera.moveUp(dt);//Up
	}
	if (input->isKeyDown('f') && cameraViews == MAIN)
	{
		camera.moveDown(dt);//Down
	}

	//Left and right
	if (input->isKeyDown('a') && cameraViews == MAIN)
	{
		camera.moveLeft(dt);//Left
	}
	if (input->isKeyDown('d') && cameraViews == MAIN)
	{
		camera.moveRight(dt);//Right
	}

	//Rotation
	//if (input->isKeyDown('o') && cameraViews == MAIN)
	//{
	//	camera.rotateLeft();//Rotate left
	//}
	//if (input->isKeyDown('p') && cameraViews == MAIN)
	//{
	//	camera.rotateRight();//Rotate right
	//}

	//Mouse rotation
	if (input->getMouseX() != 0.0f && cameraViews == MAIN) //If mouse isn't in the centre
	{
		float xDistance = input->getMouseX() - width / 2; //Figure out how far (X) the mouse is from the centre
		camera.rotateYaw(xDistance, dt);//Turn camera by that distance horizontally
		//overView.rotateYaw(xDistance, dt);//Turn camera by that distance horizontally
	}
	if (input->getMouseY() != 0.0f && cameraViews == MAIN) //If mouse isn't in the centre
	{
		float yDistance = input->getMouseY() - height / 2;//Figure out how far (Y) the mouse is from the centre
		camera.rotatePitch(yDistance, dt);//turn camera by that distance vertically
		//overView.rotatePitch(yDistance, dt);//turn camera by that distance vertically
	}
	glutWarpPointer(width/2, height/2); //Set mouse to centre
	
}

void Scene::update(float dt)
{
	// update scene related variables.

	//Update camera
	camera.update(dt);
	hoohView.update(dt);
	beastView.update(dt);
	overView.update(dt);

	//overView.setLookAt(Vector3(-2.0f, 20.0f, -16.0f));

	//Update rotation
	rotation += 20 * dt;

	//Update overview camera's yaw
	overView.setYaw(overViewRotation);

	//Update spotlight position
	
	if (spotlightXTranslate <= -3.0f)
	{
		xIncrease = true;
	}
	else if (spotlightXTranslate >= 3.0f)
	{
		xIncrease = false;
	}

	if (xIncrease && input->isKeyDown('i'))
	{
		spotlightXTranslate += 2.0f * dt;
	}
	else if (!xIncrease && input->isKeyDown('i'))
	{
		spotlightXTranslate -= 2.0f * dt;
	}

	// Calculate FPS for output
	calculateFPS();
}

void Scene::render() {

	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	if (cameraViews == MAIN)
	{
		gluLookAt(camera.getPosition().x, camera.getPosition().y, camera.getPosition().z, camera.getLookAt().x, camera.getLookAt().y, camera.getLookAt().z, camera.getUp().x, camera.getUp().y, camera.getUp().z);
	}
	else if (cameraViews == HOOH)
	{
		gluLookAt(hoohView.getPosition().x, hoohView.getPosition().y, hoohView.getPosition().z, hoohView.getLookAt().x, hoohView.getLookAt().y, hoohView.getLookAt().z, hoohView.getUp().x, hoohView.getUp().y, hoohView.getUp().z);
	}
	else if (cameraViews == BEASTS)
	{
		gluLookAt(beastView.getPosition().x, beastView.getPosition().y, beastView.getPosition().z, beastView.getLookAt().x, beastView.getLookAt().y, beastView.getLookAt().z, beastView.getUp().x, beastView.getUp().y, beastView.getUp().z);
	}
	else if (cameraViews == OVER)
	{
		glTranslatef(0.0f, 250.0f, 0.0f);
		//renderSkyBox(overView);
		gluLookAt(overView.getPosition().x, overView.getPosition().y, overView.getPosition().z, overView.getLookAt().x, overView.getLookAt().y, overView.getLookAt().z, overView.getUp().x, overView.getUp().y, overView.getUp().z);
		glTranslatef(0.0f, -250.0f, 0.0f);
	}
	
	
	//Create skybox (needs to be done first as we disable the depth testing (inside the function))
	if (cameraViews == MAIN)
	{
		renderSkyBox(camera);
	}
	else if (cameraViews == HOOH)
	{
		renderSkyBox(hoohView);
	}
	else if (cameraViews == BEASTS)
	{
		renderSkyBox(beastView);
	}
	else if (cameraViews == OVER)
	{
		glPushMatrix();

		glRotatef(-overViewRotation, 0, 1, 0);
		glTranslatef(0, 8, 63);
		renderSkyBox(overView);

		glPopMatrix();
	}
	

	//Lighting--------
	glEnable(GL_LIGHTING);

	//set lighting variables
	GLfloat Light_Ambient[] = { 0.01f, 0.01f, 0.01f, 1.0f };
	GLfloat Light_AmbientSpotLight[] = { 0.3f, 0.3f, 0.3f, 1.0f };
	GLfloat Light_Diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	GLfloat Light_DiffuseSpotLight[] = { 1.0f, 0.83f, 0.0f, 1.0f };
	GLfloat Light_DiffuseHooh[] = { 1.0f, 0.83f, 0.0f, 1.0f };

	GLfloat Light_Specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

	GLfloat Light_PositionHooh[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat Light_Position[] = { 0.2f, 1.0f, -0.1f, 0.0f };
	GLfloat Light_PositionSpotLight[] = { -2.0f, -5.0f, -2.0f, 1.0f };

	GLfloat LightDirection[] = { 0.0f, -1.0, 0.0f, 1.0f };

	//Light 0 is for Ho-oh, it is a point light
	glPushMatrix();

		glTranslatef(-2.0f, 31.0f, -16.0f); //Translate to where Ho-oh is

		//Set up the attenuation values for Ho-oh's light
		glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0);
		glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.25);
		glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.01);

		//Set up the basic lighting for the point light
		glLightfv(GL_LIGHT0, GL_AMBIENT, Light_Ambient);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, Light_DiffuseHooh);
		glLightfv(GL_LIGHT0, GL_POSITION, Light_PositionHooh);
		glEnable(GL_LIGHT0);

	glPopMatrix();

	//Set up the world's directional light
	glLightfv(GL_LIGHT1, GL_AMBIENT, Light_Ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Light_Diffuse);
	glLightfv(GL_LIGHT1, GL_POSITION, Light_Position);
	glEnable(GL_LIGHT1);

	glPushMatrix();

		glTranslatef(spotlightXTranslate, 0.0f, 0.0f);

		glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 1.0);
		glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 0.0);
		glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 0.0);

		glLightfv(GL_LIGHT2, GL_AMBIENT, Light_AmbientSpotLight);
		glLightfv(GL_LIGHT2, GL_DIFFUSE, Light_DiffuseSpotLight);
		glLightfv(GL_LIGHT2, GL_POSITION, Light_PositionSpotLight);
		glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 50.0f); 
		glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, LightDirection);
		glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 50.0);
		glEnable(GL_LIGHT2);

	glPopMatrix();

	// Render geometry/scene here -------------------------------------

	//Render plane -------------------------------------
	for (double i = -10; i < 100; ++i)
	{
		for (double j = -10; j < 100; ++j)
		{
			renderPlane(i, 0.0f, j);
		}
	}

	///WEEK 10 STENCIL BUFFER -------------------------------------
		

	//Set up stencil stuff
	/*glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
	glEnable(GL_STENCIL_TEST);
	glStencilFunc(GL_ALWAYS, 1, 1);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
	glDisable(GL_DEPTH_TEST);

	//Render the window
	glBindTexture(GL_TEXTURE_2D, NULL);

	glPushMatrix();

		renderQuad(Vector3(-3, 0, 0), 6, 6, 0);

	glPopMatrix();

	//Set up more stencil stuff
	glEnable(GL_DEPTH_TEST);
	glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
	glStencilFunc(GL_EQUAL, 1, 1);
	glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);

	//Render the model in the stencil world
	glPushMatrix();
	
		glBindTexture(GL_TEXTURE_2D, rubiks);
		glScalef(1.0, 1.0, -1.0f);
		glTranslatef(0, 0, 3);
		glRotatef(rotation, 0, 1, 0);
		renderCube();
		
	glPopMatrix();

	//Generate a second model in the stencil world
	glPushMatrix();

		glBindTexture(GL_TEXTURE_2D, suicuneTex);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glScalef(0.01f, 0.01f, -0.01f);
		glTranslatef(0.0f, 0.0f, 800.0f);
		suicune.render();

	glPopMatrix();

	//De set up stencil things
	glDisable(GL_STENCIL_TEST);
	glEnable(GL_BLEND);
	glDisable(GL_LIGHTING);
	glColor4f(0.8f, 0.8f, 1.0f, 0.8f);

	//Generate the window again for reasons
	glBindTexture(GL_TEXTURE_2D, NULL);

	glPushMatrix();

		renderQuad(Vector3(-3, 0, 0), 6, 6, 0);

	glPopMatrix();

	//De-set up stencil things
	glEnable(GL_LIGHTING);
	glDisable(GL_BLEND);

	//Render the actual model
	glPushMatrix();

		glBindTexture(GL_TEXTURE_2D, rubiks);
		glTranslatef(0, 0, 3);
		glRotatef(rotation, 0, 1, 0);
		renderCube();
	glPopMatrix();

	//Render the second actual model
	glPushMatrix();

		glBindTexture(GL_TEXTURE_2D, suicuneTex);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glScalef(0.01f, 0.01f, 0.01f);
		glTranslatef(0.0f, 0.0f, 800.0f);
		suicune.render();

	glPopMatrix();*/

		
	///WEEK 10 STENCIL BUFFER -------------------------------------

	

	//Render plane -------------------------------------
	
	///WEEK 5 RUBIKS CUBE -------------------------------------
		/*rotation += 0.4f;
		glBindTexture(GL_TEXTURE_2D, rubiks);
		glTranslatef(5.0f, -2.0f, -3.0f);
		glRotatef(rotation, 0, 1, 0);
		renderCube();
		glRotatef(-rotation, 0, 1, 0);
		glTranslatef(-5.0f, 2.0f, 3.0f);*/
	///WEEK 5 RUBIKS CUBE -------------------------------------





	///WEEK 8 -------------------------------------
		
		glPushMatrix();

			glBindTexture(GL_TEXTURE_2D, pokeballTex);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glColor3f(1.0f, 1.0f, 1.0f);
			glTranslatef(-2.0f, -9.99f, 4.0f);
			glRotatef(-90, 1, 0, 0);
			generator.RenderDisk(20);

		glPopMatrix();

	///WEEK 8 -------------------------------------





	///ASSIGNMENT -------------------------------------

		

		//BELL TOWER
		glPushMatrix();
			glColor3f(1.0f, 1.0f, 1.0f);
			glBindTexture(GL_TEXTURE_2D, bellTex);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

			glTranslatef(-2.0f, -8.0f, -14.0f);
			bell_Tower.render();

			//HO-OH AND STENCIL TEST
			glPushMatrix();

				glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
				glEnable(GL_STENCIL_TEST);
				glStencilFunc(GL_ALWAYS, 1, 1);
				glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
				glDisable(GL_DEPTH_TEST);

				//Render the window
				glBindTexture(GL_TEXTURE_2D, NULL);

				glPushMatrix();

					glTranslatef(-6.0f, 35.0f, 20.0f);
					window.render2();

				glPopMatrix();

				//Set up more stencil stuff
				glEnable(GL_DEPTH_TEST);
				glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
				glStencilFunc(GL_EQUAL, 1, 1);
				glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);

				//Render the model in the stencil world
				glPushMatrix();

					glBindTexture(GL_TEXTURE_2D, shinyhoohTex);
					glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
					glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

					glTranslatef(0.0f, 35.0f, -2.0f);
					glScalef(0.03f, 0.03f, 0.03f);
					glColor3f(1.0f, 1.0f, 1.0f);

					hooh.render();

				glPopMatrix();

				glPushMatrix();

					glBindTexture(GL_TEXTURE_2D, NULL);
					glEnable(GL_BLEND);

					glTranslatef(0.0f, 39.0f, -1.0f);
					glRotatef(rotation, 1, 1, 1);
					glScalef(0.3f, 0.3f, 0.3f);
					glColor4f(1.0f, 1.0f, 0.0f, 0.1f);

					lightShine.render();

					glDisable(GL_BLEND);

				glPopMatrix();

				//De set up stencil things
				glDisable(GL_STENCIL_TEST);
				glEnable(GL_BLEND);
				glDisable(GL_LIGHTING);
				glColor4f(1.0f, 1.0f, 1.0f, 0.0f);

				//Generate the window again for reasons
				glBindTexture(GL_TEXTURE_2D, NULL);

				glPushMatrix();

					glTranslatef(-6.0f, 35.0f, 20.0f);
					window.render2();

				glPopMatrix();

				//De-set up stencil things
				glEnable(GL_LIGHTING);
				glDisable(GL_BLEND);

				//Render the actual model
				glPushMatrix();

					glBindTexture(GL_TEXTURE_2D, hoohTex);
					glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
					glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

					glTranslatef(0.0f, 35.0f, -2.0f);
					glScalef(0.03f, 0.03f, 0.03f);
					glColor3f(1.0f, 1.0f, 1.0f);

					hooh.render();

				glPopMatrix();

			//HO-OH AND STENCIL TEST

			glPopMatrix();


			//SUICUNE
			glPushMatrix();
				
				glBindTexture(GL_TEXTURE_2D, suicuneTex);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

				glTranslatef(0.0f, -2.0f, 12.0f);
				glScalef(0.02f, 0.02f, 0.02f);
				suicune.render();

				//Suicune's Shadow
				glPushMatrix();

					glBindTexture(GL_TEXTURE_2D, shadowTex);

					glDisable(GL_LIGHTING);
					glEnable(GL_BLEND);

					glScalef(50.0f, 50.0f, 50.0f);
					glColor4f(1.0f, 1.0f, 1.0f, 0.5f);
					glTranslatef(-4.0f, 0.1f, -4.0f);
					glRotatef(90, 1, 0, 0);
					renderQuad(Vector3(2, 2, 0), 4, 4, 0);

					glDisable(GL_BLEND);
					glEnable(GL_LIGHTING);

				glPopMatrix();

			glPopMatrix();


			//ENTEI
			glPushMatrix();

				glBindTexture(GL_TEXTURE_2D, enteiTex);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
				glTranslatef(3.0f, -2.0f, 12.0f);
				glScalef(0.8f, 0.8f, 0.8f);
				entei.render();

				//Entei's Shadow
				glPushMatrix();

					glBindTexture(GL_TEXTURE_2D, shadowTex);

					glDisable(GL_LIGHTING);
					glEnable(GL_BLEND);

					glScalef(1.25f, 1.25f, 1.25f);
					glColor4f(1.0f, 1.0f, 1.0f, 0.5f);
					glTranslatef(-4.0f, 0.12f, -4.0f);
					glRotatef(90, 1, 0, 0);
					renderQuad(Vector3(2, 2, 0), 4, 4, 0);

					glDisable(GL_BLEND);
					glEnable(GL_LIGHTING);

				glPopMatrix();

			glPopMatrix();

			//RAIKOU
			glPushMatrix();

				glBindTexture(GL_TEXTURE_2D, raikouTex);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
				
				glTranslatef(-3.0f, -2.0f, 12.0f);
				glScalef(0.8f, 0.8f, 0.8f);
				raikou.render();

				//Raikou's Shadow
				glPushMatrix();

					glBindTexture(GL_TEXTURE_2D, shadowTex);

					glDisable(GL_LIGHTING);
					glEnable(GL_BLEND);

					glScalef(1.25f, 1.25f, 1.25f);
					glColor4f(1.0f, 1.0f, 1.0f, 0.5f);
					glTranslatef(-4.0f, 0.11f, -4.0f);
					glRotatef(90, 1, 0, 0);
					renderQuad(Vector3(2, 2, 0), 4, 4, 0);

					glDisable(GL_BLEND);
					glEnable(GL_LIGHTING);

				glPopMatrix();

			glPopMatrix();

			//LIGHT CONES
			glPushMatrix();
				
				glBindTexture(GL_TEXTURE_2D, NULL);
				glEnable(GL_BLEND);
				
				glTranslatef(0.0f, 39.0f, -1.0f);
				glRotatef(rotation, 1, 1, 1);
				glScalef(0.3f, 0.3f, 0.3f);
				glColor4f(1.0f, 1.0f, 0.0f, 0.1f);

				lightShine.render();

				glDisable(GL_BLEND);

			glPopMatrix();

		glPopMatrix();
		
		
	///ASSIGNMENT -------------------------------------



	///WEEK 7 -------------------------------------

		//Checkered thing
	
		/*glEnable(GL_BLEND);

		glBindTexture(GL_TEXTURE_2D, tpchecks);

		glColor4f(1.0f, 1.0f, 1.0f, 1);

		renderQuad(Vector3(0.0f, 1.0f, 1.0f), 5.0f, 5.0f, 4.0f);

		glDisable(GL_BLEND);*/

	///WEEK 7 -------------------------------------
	



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

void Scene::cameraOrbit(MyCamera _camera)
{
}

void Scene::renderPlane(double x, double y, double z)
{
	glColor3f(0.0f, 1.0f, 0.0f);
	glBindTexture(GL_TEXTURE_2D, grass);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTranslatef(-50.0f, -10.0f, -50.0f);

	glBegin(GL_QUADS);

		glColor3f(0.0f, 1.0f, 0.0f);
		//set normal
		glNormal3f(0.0f, 1.0f, 0.0f);
		//draw plane
		glTexCoord2f(x, y);
		glVertex3f(x, y, z - 1);

		glNormal3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(x + 1, y);
		glVertex3f(x, y, z);

		glNormal3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(x + 1, y + 1);
		glVertex3f(x + 1, y, z);

		glNormal3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(x, y + 1);
		glVertex3f(x + 1, y, z - 1);

	glEnd();

	

	glTranslatef(50.0f, 10.0f, 50.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
}

void Scene::renderCube()
{
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

	glColor3f(1.0f, 1.0f, 1.0f);
}

void Scene::renderSkyBox(MyCamera _currentCamera)
{
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, sky);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);//This removes one of the seams
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTranslatef(_currentCamera.getPosition().x, _currentCamera.getPosition().y, _currentCamera.getPosition().z);
		glColor3f(1.0f, 1.0f, 1.0f);
		glDisable(GL_DEPTH_TEST);
		renderBox();
		glEnable(GL_DEPTH_TEST);
	glPopMatrix();
}

void Scene::renderBox()
{

	//Front face
	glBegin(GL_QUADS); //Begin drawing state

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 0.25f);
		glVertex3f(-1.0f, 1.0f, 1.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 0.5f);
		glVertex3f(-1.0f, -1.0f, 1.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.25f, 0.5f);		
		glVertex3f(1.0f, -1.0f, 1.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.25f, 0.25f);
		glVertex3f(1.0f, 1.0f, 1.0f);

	glEnd(); //end drawing

	//Right face
	glBegin(GL_QUADS); //Begin drawing state
		
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.25f, 0.25f);
		glVertex3f(1.0f, 1.0f, 1.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.25f, 0.5f);
		glVertex3f(1.0f, -1.0f, 1.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.5f, 0.5f);
		glVertex3f(1.0f, -1.0f, -1.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.5f, 0.25f);
		glVertex3f(1.0f, 1.0f, -1.0f);

	glEnd(); //end drawing

	//Left face
	glBegin(GL_QUADS); //Begin drawing state

		//Inverted texture coords. Either the vertexes or tcoords has to be inverted so the texture wraps correctly
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(1.0f, 0.25f);
		glVertex3f(-1.0f, 1.0f, 1.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(1.0f, 0.5f);
		glVertex3f(-1.0f, -1.0f, 1.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.75f, 0.5f);
		glVertex3f(-1.0f, -1.0f, -1.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.75f, 0.25f);
		glVertex3f(-1.0f, 1.0f, -1.0f);

	glEnd(); //end drawing

	//Top face
	glBegin(GL_QUADS); //Begin drawing state

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.5f, 0.001f); //Odd textCoord.y so that there isn't a seam
		glVertex3f(-1.0f, 1.0f, -1.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.25f, 0.001f);//Odd textCoord.y so that there isn't a seam
		glVertex3f(-1.0f, 1.0f, 1.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.25f, 0.25f);
		glVertex3f(1.0f, 1.0f, 1.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.5f, 0.25f);
		glVertex3f(1.0f, 1.0f, -1.0f);

	glEnd(); //end drawing

	//Bottom face
	glBegin(GL_QUADS); //Begin drawing state

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.5f, 0.75f);
		glVertex3f(-1.0f, -1.0f, -1.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.25f, 0.75f);
		glVertex3f(-1.0f, -1.0f, 1.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.25f, 0.5f);
		glVertex3f(1.0f, -1.0f, 1.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.5f, 0.5f);
		glVertex3f(1.0f, -1.0f, -1.0f);

	glEnd(); //end drawing

	//Back face
	glBegin(GL_QUADS); //Begin drawing state

		//Inverted texture coords. Either the vertexes or tcoords has to be inverted so the texture wraps correctly
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.75f, 0.25f);
		glVertex3f(-1.0f, 1.0f, -1.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.75f, 0.5f);
		glVertex3f(-1.0f, -1.0f, -1.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.5f, 0.5f);
		glVertex3f(1.0f, -1.0f, -1.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.5f, 0.25f);
		glVertex3f(1.0f, 1.0f, -1.0f);

	glEnd(); //end drawing
}

void Scene::renderQuad(Vector3 startVertex, double xLength, double yLength, double zLength)
{
	glBegin(GL_QUADS); //Begin drawing state (draw each vertex in anti-clockwise. Start at top left.)
		
		//Top Left Vertex
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(startVertex.x, startVertex.y, startVertex.z + zLength);

		//Bottom Left
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(startVertex.x, startVertex.y + yLength, startVertex.z + zLength);

		//Bottom Right
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(startVertex.x + xLength, startVertex.y + yLength, startVertex.z + zLength);

		//Top right
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(startVertex.x + xLength, startVertex.y, startVertex.z + zLength);

	glEnd(); //end drawing

	
}
