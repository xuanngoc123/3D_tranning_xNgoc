#pragma once
#include "../Utilities/utilities.h"

class Shaders 
{
public:
	GLuint program, vertexShader, fragmentShader;
	char fileVS[260];
	char fileFS[260];
	GLint positionAttribute;
	GLint colorAttribute;
	
	GLint uvLoc;
	GLint u_transLoc;
	GLint textureUniform;
	GLint u_view;
	GLint u_projection;

	GLint cubeTextureLoc;
	GLint cubeVertexLoc;
	int Init(char * fileVertexShader, char * fileFragmentShader);
	~Shaders();
};