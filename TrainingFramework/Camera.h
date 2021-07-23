#pragma once
#include"../Utilities/utilities.h"
class Camera {
public:
	float speedCamera = 1.0f;
	float speedrotate = 1.0f;
	Vector3 position;
	Vector3 target;
	Vector3 up;
	Vector3 Wup;
	Vector3 right;

	GLfloat m_FOV;
	GLfloat m_near;
	GLfloat m_far;

	Matrix Rcm;
	Matrix Tcm;

	Matrix WCMR;
	Matrix VCMR;
	Matrix PCMR;
	Matrix WVP;

	Vector3 xasis;
	Vector3 yasis;
	Vector3 zasis;

	void initCMR();
	void updateCMR();
	void setRotationCMR();
	void setTranslationCMR();
	void setWorldMatrixCMR();
	void setViewMatrixCMR();
	void setPerspectiveMatrixCMR();


	void MoveForward(GLfloat deltaTime);
	void MoveBackward(GLfloat deltaTime);
	void MoveLeft(GLfloat deltaTime);
	void MoveRight(GLfloat deltaTime);

	void RotationAroundX(GLfloat deltaTime);
	void RotationAroundY(GLfloat deltaTime);
	void RotationAroundZ(GLfloat deltaTime);
	Camera();
	~Camera();
};