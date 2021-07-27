#pragma once
#include"../Utilities/utilities.h"
#include<vector>
#include"Vertex.h"
#include<string>
using namespace std;
class Model {
public:
	int numberOfIndice;
	void initNFG(char* fileName);
	GLuint m_vboId;
	GLuint m_iboID;
	Model();
	Model(char* file);
	~Model();
};