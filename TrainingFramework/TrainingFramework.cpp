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
//#include"ResourceManager.h"
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
Texture* myTexture = new Texture();
Model* myModel = new Model();
Object* myObject = new Object();
Camera* myCamera = new Camera();
Matrix a;
GLfloat agle = 0.0f;

int Init(ESContext* esContext)
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	myTexture->initTexture("../Texture/Woman1.tga");
	myModel->initNFG("../Model/Woman1.nfg");
	myObject->InitObject();
	myObject->Ry.SetRotationY(agle);
	//myRM->initRM();
	myCamera->initCMR();
	myCamera->setWorldMatrixCMR();
	myCamera->setViewMatrixCMR();
	char* vs = "../Resources/Shaders/TriangleShaderVS.vs";
	//creation of shaders and program 
	return myShaders.Init(vs, "../Resources/Shaders/TriangleShaderFS.fs");
}

void Draw(ESContext* esContext)
{
	glEnable(GL_DEPTH_TEST);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(myShaders.program);

	glUniformMatrix4fv(myShaders.u_projection, 1, GL_FALSE, (const GLfloat*)myCamera->PCMR.m);
	glUniformMatrix4fv(myShaders.u_view, 1, GL_FALSE, (const GLfloat*)myCamera->VCMR.m);
	// 
	glBindTexture(GL_TEXTURE_2D, myTexture->TextureId);
	glBindBuffer(GL_ARRAY_BUFFER, myModel->m_vboId);
	if (myShaders.positionAttribute != -1)
	{
		glVertexAttribPointer(myShaders.positionAttribute, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
		glEnableVertexAttribArray(myShaders.positionAttribute);
	}
	if (myShaders.uvLoc != -1)
	{
		glUniform1i(myShaders.textureUniform, 0);
		glVertexAttribPointer(myShaders.uvLoc, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(Vector3)));
		glEnableVertexAttribArray(myShaders.uvLoc);
	}


	glUniformMatrix4fv(myShaders.u_transLoc, 1, GL_FALSE, (const GLfloat*)myObject->wordl.m);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, myModel->m_iboID);
	glDrawElements(GL_TRIANGLES, myModel->numberOfIndice, GL_UNSIGNED_INT, 0);


	//đóng cổng
	glBindTexture(GL_TEXTURE_2D, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


	eglSwapBuffers(esContext->eglDisplay, esContext->eglSurface);
}

void Update(ESContext* esContext, float deltaTime)
{
	if (keyPressed & ROTATE_X) {
		myCamera->RotationAroundX(deltaTime);
	}

	if (keyPressed & ROTATE_Y) {
		myCamera->RotationAroundY(deltaTime);
	}
	if (keyPressed & ROTATE_Z) {
		myCamera->RotationAroundZ(deltaTime);
	}
	if (keyPressed & ROTATE_X_NEG) {
		myCamera->RotationAroundX(-deltaTime);
	}

	if (keyPressed & ROTATE_Y_NEG) {
		myCamera->RotationAroundY(-deltaTime);
	}
	if (keyPressed & ROTATE_Z_NEG) {
		myCamera->RotationAroundZ(-deltaTime);
	}
	if (keyPressed & MOVE_FORWARD) {
		myCamera->MoveForward(deltaTime);
	}

	if (keyPressed & MOVE_BACKWARD) {
		myCamera->MoveBackward(deltaTime);
	}

	if (keyPressed & MOVE_LEFT) {
		myCamera->MoveLeft(deltaTime);
	}

	if (keyPressed & MOVE_RIGHT) {
		myCamera->MoveRight(deltaTime);
	}
	myCamera->updateCMR();
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

