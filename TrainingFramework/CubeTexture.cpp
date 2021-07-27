
#include "stdafx.h"
#include"Cubetexture.h"
#include<iostream>
using namespace std;

void Cubetexture::initTexture() {
	glGenTextures(1, &CubeTextureId);
	glBindTexture(GL_TEXTURE_CUBE_MAP, CubeTextureId);
	for (int i = 0; i < listCube.size(); i++)
	{
		char* imgData = LoadTGA(listCube.at(i), &width, &height, &bpp);
		if (imgData)
		{
			std::cout << "load thanh cong" << std::endl;
			if (bpp == 24)
				glTexImage2D(
					GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
					0,
					GL_RGB,
					width,
					height,
					0,
					GL_RGB,
					GL_UNSIGNED_BYTE,
					imgData);
			else
				glTexImage2D(
					GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
					0,
					GL_RGBA,
					width,
					height,
					0,
					GL_RGBA,
					GL_UNSIGNED_BYTE,
					imgData);
		}
		else
		{
			std::cout << "Failed to load texture" << std::endl;
		}
		delete imgData;
	}
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
}
Cubetexture::Cubetexture() {
	initTexture();
}

Cubetexture::~Cubetexture() {
	glDeleteBuffers(1, &CubeTextureId);
}