#pragma once
//#include "stdafx.h"
#include "../Utilities/utilities.h"
//#include "../Utilities/Math.h"
#include"Shaders.h"

//#include "Math.h"

class Object {
public:
	Matrix Rx;
	Matrix Ry;
	Matrix Rz;

	Matrix scale;
	Matrix rotation;
	Matrix trans;

	Matrix wordl;
	Matrix view;
	Matrix P;


	Matrix setRotation();

	Matrix setWordl();
	Matrix setView();
	Matrix setP();


	void InitObject();
	Object();
	~Object();



};