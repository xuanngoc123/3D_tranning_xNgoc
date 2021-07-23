#pragma once
#include "../Utilities/utilities.h"
class Texture
{
public:
	int width = 0, height = 0, bpp = 0;
	GLuint TextureId;
	void initTexture(char* fileName, GLint wrap, GLint filter, GLint filter2);
	Texture();
	Texture(char* file, GLint wrap, GLint filter1, GLint filter2);
	~Texture();
};