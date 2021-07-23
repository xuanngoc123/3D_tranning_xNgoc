// TrainingFramework.cpp : Defines the entry point for the console application.
//


#include "../Utilities/utilities.h" // if you use STL, please include this line AFTER all other include
#include "stdafx.h"
#include "Vertex.h"
#include "Shaders.h"
#include "Globals.h"
#include <conio.h>
#include "Texture.h"
#include "Model.h"
#include "Object.h"
#include"Camera.h"
#include"ResourceManager.h"
#include"SceneManager.h"
#include<iostream>

#define MOVE_FORWARD 1
#define MOVE_BACKWARD 1 << 1
#define MOVE_LEFT 1 << 2
#define MOVE_RIGHT 1 << 3
#define ROTATE_X 1 << 4
#define ROTATE_Y 1 << 5
#define ROTATE_Z 1 << 6
#define ROTATE_X_NEG 1 << 7
#define ROTATE_Y_NEG 1 << 8
#define ROTATE_Z_NEG 1 << 9

int keyPressed = 0;

Shaders myShaders;
//Texture* myTexture = new Texture();
//Model* myModel = new Model();
//Object* myObject = new Object();
ResourceManager* myRM = new ResourceManager();
SceneManager* mySM = new SceneManager();
//Camera* myCamera = new Camera();
Matrix a;
GLfloat agle = 0.0f;

int Init(ESContext* esContext)
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	//myTexture->initTexture("../Texture/Woman1.tga");
	//myModel->initNFG("../Model/Woman1.nfg");
	//myObject->InitObject("../Model/Woman1.nfg", "../Texture/Woman1.tga");
	//myObject->Ry.SetRotationY(agle);
	//myRM->initRM();
	myRM->initRM();
	mySM->initSM(myRM->listObj);
	//myCamera->initCMR();
	//myCamera->setWorldMatrixCMR();
	//myCamera->setViewMatrixCMR();
	char* vs = "../Resources/Shaders/TriangleShaderVS.vs";
	//creation of shaders and program 
	return myShaders.Init(vs, "../Resources/Shaders/TriangleShaderFS.fs");
}

void Draw(ESContext* esContext)
{
	glEnable(GL_DEPTH_TEST);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//for (int i = 0; i < myRM->listObj.size(); i++) {
	//	myRM->listObj.at(i)->draw(myCamera, myShaders);
	//}
	mySM->draw(myRM->listObj, myShaders);

	eglSwapBuffers(esContext->eglDisplay, esContext->eglSurface);
}

void Update(ESContext* esContext, float deltaTime)
{
	if (keyPressed & ROTATE_X) {
		mySM->s_camera->RotationAroundX(deltaTime);
	}

	if (keyPressed & ROTATE_Y) {
		mySM->s_camera->RotationAroundY(deltaTime);
	}
	if (keyPressed & ROTATE_Z) {
		mySM->s_camera->RotationAroundZ(deltaTime);
	}
	if (keyPressed & ROTATE_X_NEG) {
		mySM->s_camera->RotationAroundX(-deltaTime);
	}

	if (keyPressed & ROTATE_Y_NEG) {
		mySM->s_camera->RotationAroundY(-deltaTime);
	}
	if (keyPressed & ROTATE_Z_NEG) {
		mySM->s_camera->RotationAroundZ(-deltaTime);
	}
	if (keyPressed & MOVE_FORWARD) {
		mySM->s_camera->MoveForward(deltaTime);
	}

	if (keyPressed & MOVE_BACKWARD) {
		mySM->s_camera->MoveBackward(deltaTime);
	}

	if (keyPressed & MOVE_LEFT) {
		mySM->s_camera->MoveLeft(deltaTime);
	}

	if (keyPressed & MOVE_RIGHT) {
		mySM->s_camera->MoveRight(deltaTime);
	}
	mySM->s_camera->updateCMR();
}

void Key(ESContext* esContext, unsigned char key, bool bIsPressed)
{
	if (bIsPressed) {
		if (key == VK_UP) {
			keyPressed = keyPressed | ROTATE_X;
			return;
		}

		if (key == VK_DOWN) {
			keyPressed = keyPressed | ROTATE_X_NEG;
			return;
		}

		if (key == VK_LEFT) {
			keyPressed = keyPressed | ROTATE_Y;
			return;
		}
		if (key == VK_RIGHT) {
			keyPressed = keyPressed | ROTATE_Y_NEG;
			return;
		}
		if (key == 'a' || key == 'A') {
			keyPressed = keyPressed | MOVE_LEFT;
			return;
		}
		if (key == 'w' || key == 'W') {
			keyPressed = keyPressed | MOVE_FORWARD;
			return;
		}
		if (key == 's' || key == 'S') {
			keyPressed = keyPressed | MOVE_BACKWARD;
			return;
		}
		if (key == 'd' || key == 'D') {
			keyPressed = keyPressed | MOVE_RIGHT;
			return;
		}
		if (key == 'z' || key == 'Z') {
			keyPressed = keyPressed | ROTATE_Z;
			return;
		}
		if (key == 'v' || key == 'V') {
			keyPressed = keyPressed | ROTATE_Z_NEG;
			return;
		}
		if (key == 'y' || key == 'Y') {
			keyPressed = keyPressed | ROTATE_Y;
			return;
		}
		if (key == 'h' || key == 'H') {
			keyPressed = keyPressed | ROTATE_Y_NEG;
			return;
		}
		if (key == 'X' || key == 'x') {
			keyPressed = keyPressed | ROTATE_X;
			return;
		}
		if (key == 'c' || key == 'C') {
			keyPressed = keyPressed | ROTATE_X_NEG;
			return;
		}
	}
	else {
		if (key == VK_UP) {
			keyPressed = keyPressed ^ ROTATE_X;
			return;
		}

		if (key == VK_DOWN) {
			keyPressed = keyPressed ^ ROTATE_X_NEG;
			return;
		}

		if (key == VK_LEFT) {
			keyPressed = keyPressed ^ ROTATE_Y;
			return;
		}
		if (key == VK_RIGHT) {
			keyPressed = keyPressed ^ ROTATE_Y_NEG;
			return;
		}
		if (key == 'a' || key == 'A') {
			keyPressed = keyPressed ^ MOVE_LEFT;
			return;
		}
		if (key == 'w' || key == 'W') {
			keyPressed = keyPressed ^ MOVE_FORWARD;
			return;
		}
		if (key == 's' || key == 'S') {
			keyPressed = keyPressed ^ MOVE_BACKWARD;
			return;
		}
		if (key == 'd' || key == 'D') {
			keyPressed = keyPressed ^ MOVE_RIGHT;
			return;
		}
		if (key == 'z' || key == 'Z') {
			keyPressed = keyPressed ^ ROTATE_Z;
			return;
		}
		if (key == 'v' || key == 'V') {
			keyPressed = keyPressed ^ ROTATE_Z_NEG;
			return;
		}
		if (key == 'y' || key == 'Y') {
			keyPressed = keyPressed ^ ROTATE_Y;
			return;
		}
		if (key == 'h' || key == 'H') {
			keyPressed = keyPressed ^ ROTATE_Y_NEG;
			return;
		}
		if (key == 'X' || key == 'x') {
			keyPressed = keyPressed ^ ROTATE_X;
			return;
		}
		if (key == 'c' || key == 'C') {
			keyPressed = keyPressed ^ ROTATE_X_NEG;
			return;
		}
	}
}

void CleanUp()
{
	//delete myCamera;
	//delete myModel;
	//delete myTexture;
	//delete myObject;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ESContext esContext;

	esInitContext(&esContext);

	esCreateWindow(&esContext, "Hello Triangle", Globals::screenWidth, Globals::screenHeight, ES_WINDOW_RGB | ES_WINDOW_DEPTH);

	if (Init(&esContext) != 0)
		return 0;

	esRegisterDrawFunc(&esContext, Draw);
	esRegisterUpdateFunc(&esContext, Update);
	esRegisterKeyFunc(&esContext, Key);
	esMainLoop(&esContext);

	//releasing OpenGL resources
	CleanUp();

	//identifying memory leaks
	MemoryDump();
	printf("Press any key...\n");
	_getch();

	return 0;
}

