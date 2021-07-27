#include "stdafx.h"
#include "Shaders.h"

int Shaders::Init(char * fileVertexShader, char * fileFragmentShader)
{
	vertexShader = esLoadShader(GL_VERTEX_SHADER, fileVertexShader);

	if ( vertexShader == 0 )
		return -1;

	fragmentShader = esLoadShader(GL_FRAGMENT_SHADER, fileFragmentShader);

	if ( fragmentShader == 0 )
	{
		glDeleteShader( vertexShader );
		return -2;
	}

	program = esLoadProgram(vertexShader, fragmentShader);

	//finding location of uniforms / attributes
	positionAttribute = glGetAttribLocation(program, "a_posL");
	colorAttribute = glGetAttribLocation(program, "a_color");
	uvLoc = glGetAttribLocation(program, "a_uv");
	u_transLoc = glGetUniformLocation(program, "u_MVP");
	textureUniform = glGetUniformLocation(program, "u_texture");
	u_view = glGetUniformLocation(program, "u_view");
	u_projection = glGetUniformLocation(program, "u_projection");

	//cubeVertexLoc = glGetAttribLocation(program, "a_CubeVertexPos");
	cubeTextureLoc = glGetUniformLocation(program, "u_samplerCubeMap");
	return 0;
}

Shaders::~Shaders()
{
	glDeleteProgram(program);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}