#include "../Utilities/utilities.h"
#include "Math.h"
#include"stdafx.h"
#include"Object.h"
#include"Camera.h"
#include"Shaders.h"


Matrix Object::setRotation(float x, float y, float z) {
	Rx.SetRotationX(x * 3.14 / 180);
	Ry.SetRotationY(y * 3.14 / 180);
	Rz.SetRotationZ(z * 3.14 / 180);
	return Rz * Rx * Ry;
}

Matrix Object::setWordl() {
	return scale * rotation * trans;
}
void Object::InitObject() {
	rotation = setRotation(o_rotation.x, o_rotation.y, o_rotation.z);
	scale.SetScale(o_scale.x, o_scale.y, o_scale.z);
	trans.SetTranslation(o_positon);
	wordl = setWordl();
}
void Object::draw(Shaders shader){
	InitObject();
	glUseProgram(shader.program);

	//glUniformMatrix4fv(shader.u_projection, 1, GL_FALSE, (const GLfloat*)cam->PCMR.m);
	//glUniformMatrix4fv(shader.u_view, 1, GL_FALSE, (const GLfloat*)cam->VCMR.m);
	// 
	glBindTexture(GL_TEXTURE_2D, texture->TextureId);
	glBindBuffer(GL_ARRAY_BUFFER, model->m_vboId);
	if (shader.positionAttribute != -1)
	{
		glVertexAttribPointer(shader.positionAttribute, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
		glEnableVertexAttribArray(shader.positionAttribute);
	}
	if (shader.uvLoc != -1)
	{
		glUniform1i(shader.textureUniform, 0);
		glVertexAttribPointer(shader.uvLoc, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(Vector3)));
		glEnableVertexAttribArray(shader.uvLoc);
	}


	glUniformMatrix4fv(shader.u_transLoc, 1, GL_FALSE, *wordl.m);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, model->m_iboID);
	glDrawElements(GL_TRIANGLES, model->numberOfIndice, GL_UNSIGNED_INT, 0);


	//đóng cổng
	glBindTexture(GL_TEXTURE_2D, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

Object::Object() {
	
}
Object::Object(Model* submodel, Texture* subtexture) {
	model = submodel;
	texture = subtexture;
	InitObject();
}
Object::~Object() {

}