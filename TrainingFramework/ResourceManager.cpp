#include"stdafx.h"
#include"ResourceManager.h"
#include<iostream>
#include"Texture.h"
#include"Model.h"
using namespace std;
void ResourceManager::initRM() {
	FILE* file;
	file = fopen("../Resources/RM.txt", "r");

	int NmOfModel, NmOftexture, NmOfShader, id;

	Shaders subShader;
	char filename2[30], filename1[30], wrap[10], filter1[15], filter2[15], vs[50], fs[50];


	fscanf(file, "#Models: %d\n", &NmOfModel);
	for (int i = 0; i < NmOfModel; i++) {
		fscanf(file, "ID %d\n", &id);
		fscanf(file, "FILE %s\n", &filename2);
		Model* submodel = new Model(filename2);
		listModel.push_back(submodel);
	}
	fscanf(file, "#2D Textures: %d\n", &NmOftexture);
	for (int i = 0; i < NmOftexture; i++) {
		GLint subWrap;
		GLint subFilter1, subfilter2;
		fscanf(file, "ID %d\n", &id);
		fscanf(file, "FILE %s\n", &filename1);
		fscanf(file, "WRAP %s\n", &wrap);
		if (strcmp(wrap, "REPEAT") == 0); subWrap = GL_REPEAT;
		fscanf(file, "FILTER %s %s\n", &filter1, &filter2);
		if (strcmp(filter1, "LINEAR") == 0); subFilter1 = GL_LINEAR;
		if (strcmp(filter2, "LINEAR") == 0); subfilter2 = GL_LINEAR;
		Texture* subTexture = new Texture(filename1, subWrap, subFilter1, subfilter2);
		listTexture.push_back(subTexture);
	}

	for (int i = 0; i < NmOfModel; i++) {
		Object* subObj= new Object(listModel.at(i), listTexture.at(i));
		listObj.push_back(subObj);
	}
}
ResourceManager::ResourceManager() {

}
ResourceManager::~ResourceManager() {

}