#include "../Utilities/utilities.h"
#include "Math.h"
#include"stdafx.h"
#include"Object.h"



Matrix Object::setRotation() {
	return Rz * Rx * Ry;
}

Matrix Object::setWordl() {
	return scale * rotation * trans;
}
Matrix Object::setView() {
	return trans.Inverst() * rotation.Inverst();
}
Matrix Object::setP() {
	return -1;
}
void Object::InitObject() {
	Rx.SetRotationX(0);
	Ry.SetRotationY(3.14);
	Rz.SetRotationZ(0);

	scale.SetScale(1, 1, 1);
	rotation = Rz * Rx * Ry;
	trans.SetTranslation(0.0, 0.0, 0.4);

	
	wordl = scale * rotation * trans;
	view = trans.Inverst() * rotation.Inverst();
}
Object::Object() {
	
}
Object::~Object() {

}