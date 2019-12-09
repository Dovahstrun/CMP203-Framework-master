#include "ProceduralGeneration.h"

ProceduralGeneration::ProceduralGeneration()
{
}

void ProceduralGeneration::RenderDisk(int sides)
{
	float interval = (2 * M_PI) / sides;
	float angle = 0.0f;

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < sides; i++)
	{
		//texture vertex
		glTexCoord2f(0.5, -0.5);
		glNormal3f(0.0f, 0.0f, 1.0f);
		//center vertice
		glVertex3f(0, 0, 0);

		//texture vertex		
		glTexCoord2f(cos(angle) / 2 + 0.5, -(sin(angle) / 2 + 0.5));
		glNormal3f(0.0f, 0.0f, 1.0f);
		//first outer vertex
		glVertex3f(cos(angle), sin(angle), 0);

		//texture vertex
		glTexCoord2f(cos(angle + interval) / 2 + 0.5, -(sin(angle + interval) / 2 + 0.5));
		glNormal3f(0.0f, 0.0f, 1.0f);
		//create other vertex based on angle
		glVertex3f(cos(angle + interval), sin(angle + interval), 0);

		angle += interval;
	}
	//create final vertex
	glVertex3f(cos(0), sin(0), 0);
	glEnd();
}

void ProceduralGeneration::RenderSphere(int sides)
{
	float X = 0;
	float Y = 0;
	float Z = 0;
	float theta = (2 * M_PI) / sides; //latangle
	float delta = M_PI / sides;//lonangle

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < sides; i++)//this is longitude
	{
		for (int j = 0; j < sides; j++) //this is lattitute 
		{
			//texture vertex
			glTexCoord2f(cos(j*theta)*sin(i *delta), -cos(i * delta));
			//create vertex for 1st triangle
			glVertex3f(cos(j*theta)*sin(i *delta)				 //X value for 1st vertice
				, cos(i * delta)								 //Y value for 1st vertice
				, sin(j*theta) * sin(i *delta));				 //Z value for 1st vertice

																 //texture vertex
			glTexCoord2f(cos((1 + j)*theta)*sin(i *delta), -cos(i * delta));

			glVertex3f(cos((1 + j)*theta)*sin(i *delta)	     //X value for 2nd vertice
				, cos(i * delta)							 //Y value for 2nd vertice
				, sin((1 + j) * theta) * sin(i *delta));	 //Z value for 2nd vertice

															 //texture vertex
			glTexCoord2f(cos((1 + j)*theta)*sin((1 + i) *delta), -cos((1 + i) * delta));

			glVertex3f(cos((1 + j)*theta)*sin((1 + i) *delta)  //X value for 3rd vertice
				, cos((1 + i) * delta)						 //Y value for 3rd vertice
				, sin((1 + j) * theta) * sin((1 + i) *delta)); //Z value for 3rd vertice

															   //texture vertex
			glTexCoord2f(cos((1 + j)*theta)*sin((1 + i) *delta), -cos((1 + i) * delta));

			//2nd triangle
			glVertex3f(cos((1 + j)*theta)*sin((1 + i) *delta) //X value for 1st vertice
				, cos((1 + i) * delta)						  //Y value for 1st vertice
				, sin((1 + j) * theta) * sin((1 + i) *delta));//Z value for 1st vertice

															  //texture vertex
			glTexCoord2f(cos(j*theta)*sin((1 + i) *delta), -cos((1 + i) * delta));

			glVertex3f(cos(j*theta)*sin((1 + i) *delta)		 //X value for 2nd vertice
				, cos((1 + i) * delta)						 //Y value for 2nd vertice
				, sin(j * theta) * sin((1 + i) *delta));	 //Z value for 2nd vertice

															 //texture vertex
			glTexCoord2f(cos(j*theta)*sin(i *delta), -cos(i * delta));

			glVertex3f(cos(j*theta)*sin(i *delta)			 //X value for 3rd vertice
				, cos(i * delta)						     //Y value for 3rd vertice
				, sin(j*theta) * sin(i *delta));		     //Z value for 3rd vertice
		}
	}
	glEnd();
}

void ProceduralGeneration::RenderCylinder(int sides, int height)
{
	float interval = (2 * M_PI) / sides;
	float angle = 0.0f;
	//create the bottom
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < sides; i++)
	{
		//texture vertex
		glTexCoord2f(0.5, -0.5);
		glNormal3f(0.0f, 1.0f, 0.0f);
		//create center vertice
		glVertex3f(0, 0, 0);

		//texture vertex		
		glTexCoord2f(cos(angle) / 2 + 0.5, -(sin(angle) / 2 + 0.5));
		glNormal3f(0.0f, 1.0f, 0.0f);
		//create first outer vertex
		glVertex3f(cos(angle), sin(angle), 0);

		//texture vertex
		glTexCoord2f(cos(angle + interval) / 2 + 0.5, -(sin(angle + interval) / 2 + 0.5));
		glNormal3f(0.0f, 1.0f, 0.0f);
		//based on angle create other vertex
		glVertex3f(cos(angle + interval), sin(angle + interval), 0);

		angle += interval;
	}
	//texture Final vertex
	//create final vertex
	glVertex3f(cos(0), sin(0), 0);
	glEnd();

	float theta = (2 * M_PI) / sides; //latangle

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < height; i++)
	{
		angle = 0.0f; //reset angle for each layer
		for (int j = 0; j < sides; j++)
		{

			//texture vertex
			glTexCoord2f(j / sides, i / height);
			//create first outer vertex
			glVertex3f(cos(angle), sin(angle), i);

			//texture vertex
			glTexCoord2f((j + 1) / sides, i / height);
			//based on angle create other vertex
			glVertex3f(cos(angle + interval), sin(angle + interval), i);

			//texture vertex
			glTexCoord2f((j + 1) / sides, (i + 1) / height);
			glVertex3f(cos(angle + interval), sin(angle + interval), i + 1);

			//new triangle
			//texture vertex
			glTexCoord2f((j + 1) / sides, (i + 1) / height);
			glVertex3f(cos(angle + interval), sin(angle + interval), i + 1);

			//texture vertex
			glTexCoord2f(j / sides, (i + 1) / height);
			glVertex3f(cos(angle), sin(angle), i + 1);

			//texture vertex
			glTexCoord2f(j / sides, i / height);
			glVertex3f(cos(angle), sin(angle), i);

			angle += interval;

		}
	}
	glEnd();


	//create the top
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < sides; i++)
	{
		//texture vertex
		glTexCoord2f(0.5, -0.5);
		glNormal3f(0.0f, 1.0f, 0.0f);
		//create center vertice
		glVertex3f(0, 0, height);

		//texture vertex		
		glTexCoord2f(cos(angle) / 2 + 0.5, -(sin(angle) / 2 + 0.5));
		glNormal3f(0.0f, 1.0f, 0.0f);
		//create first outer vertex
		glVertex3f(cos(angle), sin(angle), height);

		//texture vertex
		glTexCoord2f(cos(angle + interval) / 2 + 0.5, -(sin(angle + interval) / 2 + 0.5));
		glNormal3f(0.0f, 1.0f, 0.0f);
		//based on angle create other vertex
		glVertex3f(cos(angle + interval), sin(angle + interval), height);

		angle += interval;
	}
	//texture Final vertex
	//create final vertex
	glVertex3f(cos(0), sin(0), 0);
	glEnd();
}
