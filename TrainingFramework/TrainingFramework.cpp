﻿// TrainingFramework.cpp : Defines the entry point for the console application.
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
#include<iostream>

Shaders myShaders;
Texture *myTexture = new Texture();
Model *myModel = new Model();
Object* myObject = new Object();
Camera* myCamera = new Camera();
Matrix a;
GLfloat agle=0.0f;

int Init ( ESContext *esContext )
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	myTexture->initTexture("../Texture/Woman1.tga");
	myModel->initNFG("../Model/Woman1.nfg");
	myObject->InitObject();
	myObject->Ry.SetRotationY(agle);
	myCamera->initCMR();
	myCamera->setWorldMatrixCMR();
	myCamera->setViewMatrixCMR();
	//creation of shaders and program 
	return myShaders.Init("../Resources/Shaders/TriangleShaderVS.vs", "../Resources/Shaders/TriangleShaderFS.fs");
}

void Draw ( ESContext *esContext )
{
	glEnable(GL_DEPTH_TEST);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(myShaders.program);

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
	
	glUniformMatrix4fv(myShaders.u_projection, 1, GL_FALSE, (const GLfloat*)myCamera->PCMR.m);
	glUniformMatrix4fv(myShaders.u_view, 1, GL_FALSE, (const GLfloat*)myCamera->VCMR.m);
	glUniformMatrix4fv(myShaders.u_transLoc, 1, GL_FALSE, (const GLfloat*)myObject->wordl.m);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, myModel->m_iboID);
	glDrawElements(GL_TRIANGLES, myModel->numberOfIndice, GL_UNSIGNED_INT, 0);
		
	
	//đóng cổng
	glBindTexture(GL_TEXTURE_2D, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	

	eglSwapBuffers(esContext->eglDisplay, esContext->eglSurface);
}

void Update ( ESContext *esContext, float deltaTime )
{
	myCamera->updateCMR(deltaTime);
}

void Key ( ESContext *esContext, unsigned char key, bool bIsPressed)
{	
	float deltaTime = 0.5;
	if (bIsPressed == true) {
		myCamera->isPressKeyEvent(key, deltaTime);
	}
}

void CleanUp()
{
	
}

int _tmain(int argc, _TCHAR* argv[])
{
	ESContext esContext;

    esInitContext ( &esContext );

	esCreateWindow ( &esContext, "Hello Triangle", Globals::screenWidth, Globals::screenHeight, ES_WINDOW_RGB | ES_WINDOW_DEPTH);

	if ( Init ( &esContext ) != 0 )
		return 0;

	esRegisterDrawFunc ( &esContext, Draw );
	esRegisterUpdateFunc ( &esContext, Update );
	esRegisterKeyFunc ( &esContext, Key);

	esMainLoop ( &esContext );

	//releasing OpenGL resources
	CleanUp();

	//identifying memory leaks
	MemoryDump();
	printf("Press any key...\n");
	_getch();

	return 0;
}

