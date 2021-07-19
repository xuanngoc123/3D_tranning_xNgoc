#pragma once
#include"../Utilities/utilities.h"
class Camera {
public:
	Vector3 position;
	Vector3 target;
	Vector3 up = (0, 1, 0);
	GLfloat m_FOV = 60;
	GLfloat m_near;
	GLfloat m_far;
	Matrix Rcm;
	Matrix Tcm;

	Vector3 xasis;
	Vector3 yasis;
	Vector3 zasis;
	void initCMR();

	void setRotationCMR();
	void setTranslationCMR();
	Matrix getWorldMatrixCMR();
	Matrix getViewMatrixCMR();
	Matrix getPerspectiveMatrixCMR();


};