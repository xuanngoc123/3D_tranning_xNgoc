#include"stdafx.h"
#include"Camera.h"
#include "../Utilities/utilities.h"
#include"math.h"
#include"Globals.h"
void Camera::initCMR() {
	zasis = (position - target).Normalize();
	xasis = (up.Cross(zasis)).Normalize();
	yasis = (zasis.Cross(xasis)).Normalize();
}
void Camera::setRotationCMR() {
	Rcm.m[0][0] = xasis.x; Rcm.m[0][1] = xasis.y; Rcm.m[0][2] = xasis.z; Rcm.m[0][3] = 0;
	Rcm.m[1][0] = yasis.x; Rcm.m[1][1] = yasis.y; Rcm.m[1][2] = yasis.z; Rcm.m[1][3] = 0;
	Rcm.m[2][0] = zasis.x; Rcm.m[2][1] = zasis.y; Rcm.m[2][2] = zasis.z; Rcm.m[2][3] = 0;
	Rcm.m[3][0] = 0;	   Rcm.m[3][1] = 0;		  Rcm.m[3][2] = 0;		 Rcm.m[3][3] = 1;
}
void Camera::setTranslationCMR() {
	Tcm.m[0][0] = 1; Tcm.m[0][1] = 0; Tcm.m[0][2] = 0; Tcm.m[0][3] = 0;
	Tcm.m[1][0] = 0; Tcm.m[1][1] = 1; Tcm.m[1][2] = 0; Tcm.m[1][3] = 0;
	Tcm.m[2][0] = 0; Tcm.m[2][1] = 0; Tcm.m[2][2] = 1; Tcm.m[2][3] = 0;
	Tcm.m[3][0] = position.x; Tcm.m[3][1] = position.y; Tcm.m[3][2] = position.z; Tcm.m[3][3] = 1;
}
Matrix Camera::getWorldMatrixCMR() {
	return Rcm * Tcm;
}
Matrix Camera::getViewMatrixCMR() {
	Matrix tmp;
	tmp.m[0][0] = xasis.x; tmp.m[0][1] = yasis.x; tmp.m[0][2] = zasis.x; tmp.m[0][3] = 0;
	tmp.m[1][0] = xasis.y; tmp.m[1][1] = yasis.y; tmp.m[1][2] = zasis.y; tmp.m[1][3] = 0;
	tmp.m[2][0] = xasis.z; tmp.m[2][1] = yasis.z; tmp.m[2][2] = zasis.z; tmp.m[2][3] = 0;
	tmp.m[3][0] = -position.Dot(xasis); tmp.m[3][1] = -position.Dot(yasis); tmp.m[3][2] = -position.Dot(zasis); tmp.m[3][3] = 1;
	return tmp;
}
Matrix Camera::getPerspectiveMatrixCMR() {
	float aspect = (float)Globals::screenWidth / Globals::screenHeight;
	Matrix perspective;
	perspective.SetPerspective(m_FOV, aspect, m_near, m_far);
	return perspective;
}