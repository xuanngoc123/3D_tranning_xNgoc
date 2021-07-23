#pragma once
#include "stdafx.h"
#include "../Utilities/utilities.h"
//#include "../Utilities/Math.h"
#include"Shaders.h"
#include<vector>
#include"Model.h"
#include"Texture.h"
#include"Camera.h"
using namespace std;
//#include "Math.h"

class Object {
public:
	Model* model;
	Texture* texture;

	Matrix Rx;
	Matrix Ry;
	Matrix Rz;

	Matrix scale;
	Matrix rotation;
	Matrix trans;

	Matrix wordl;
	
	Matrix WVP;


	Matrix setRotation(float x, float y, float z);

	Matrix setWordl();
	//Matrix setView();
	
	void draw(Shaders shader);

	Vector3 o_positon, o_rotation, o_scale;

	void InitObject();
	Object();
	Object(Model* submodel, Texture* subtexture);
	~Object();



};