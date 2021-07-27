#pragma once
#include "../Utilities/utilities.h"
#include<vector>
using namespace std;
class Cubetexture
{
public:
	int width = 0, height = 0, bpp = 0;
	vector<char*> listCube = {"../Textures/Skybox Textures/right.tga", "../Textures/Skybox Textures/left.tga", "../Textures/Skybox Textures/top.tga", "../Textures/Skybox Textures/bottom.tga", "../Textures/Skybox Textures/back.tga", "../Textures/Skybox Textures/front.tga"};
	GLuint CubeTextureId;
	void initTexture();
	Cubetexture();
	//Cubetexture(char* file, GLint wrap, GLint filter1, GLint filter2);
	~Cubetexture();
};