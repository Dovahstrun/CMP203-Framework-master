#pragma once

#include "Vector3.h"

class MyCamera
{
public:

	MyCamera();

	void update(float dt);
	Vector3 getPosition();
	Vector3 getLookAt();
	Vector3 getUp();

	void setPosition(Vector3 _position);
	void setYaw(float _newYaw);
	void setPitch(float _newPitch);
	void setRoll (float _newRoll);

	//Movement
	void moveForward(float dt);
	void moveBackward(float dt);
	void moveLeft(float dt);
	void moveRight(float dt);
	void moveUp(float dt);
	void moveDown(float dt);

	void rotateLeft();
	void rotateRight();

	void rotateYaw(float rotation, float dt);
	void rotatePitch(float rotation, float dt);


private:

	float Yaw;
	float Pitch;
	float Roll;

	Vector3 lookAt;

	Vector3 forward;
	Vector3 up;
	Vector3 position;
	Vector3 right;

};