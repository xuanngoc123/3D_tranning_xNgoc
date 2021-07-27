
#include "stdafx.h"
#include"Texture.h"
#include<iostream>
using namespace std;

void Texture::initTexture(char* fileName, GLint wrap, GLint filter1, GLint filter2) {
	
	char* imgData = LoadTGA(fileName, &width, &height, &bpp);

	glGenTextures(1, &TextureId);
	glBindTexture(GL_TEXTURE_2D, TextureId);
	if (imgData)
	{
		std::cout << "load thanh cong" << std::endl;
		if(bpp == 24)
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, imgData);
		else
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imgData);
		
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter2);
	glBindTexture(GL_TEXTURE_2D, 0);
	delete imgData;
}
Texture::Texture() {

}
Texture::Texture(char* file, GLint wrap, GLint filter1, GLint filter2) {
	initTexture(file, wrap, filter1, filter2);
}
Texture::~Texture() {
	//glDeleteBuffers(1, &TextureId);
}