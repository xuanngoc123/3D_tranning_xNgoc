#include"stdafx.h"
#include"SceneManager.h"
#include <stdio.h>
#include<iostream>
void SceneManager::initSM(vector<Object*> listObj) {
	FILE* file;
	file = fopen("../Resources/SM.txt", "r");
	int NmOfCam, NmOfObj, idObj, idTexture, NmOfTexture;
	int pos_Model, pos_Texture, pos_Shader, id, cubetexture;
	float x, y, z;
	fscanf(file, "#Cameras: %d\n", &NmOfCam);

	fscanf(file, "ID %d\n", &id);
	fscanf(file, "POSITION %f %f %f\n", &s_camera->position.x, &s_camera->position.y, &s_camera->position.z);
	fscanf(file, "TARGET %f %f %f\n", &s_camera->target.x, &s_camera->target.y, &s_camera->target.z);
	fscanf(file, "UP %f %f %f\n", &s_camera->up.x, &s_camera->up.y, &s_camera->up.z);
	fscanf(file, "FOVY %f\n", &s_camera->m_FOV);
	fscanf(file, "NEAR %f\n", &s_camera->m_near);
	fscanf(file, "FAR %f\n", &s_camera->m_far);
	fscanf(file, "MOVE_SPEED %f\n", &s_camera->speedCamera);
	fscanf(file, "ROTATE_SPEED %f\n", &s_camera->speedrotate);
	s_camera->updateCMR();

	fscanf(file, "#Objects: %d\n", &NmOfObj);
	for (int i = 0; i < NmOfObj; i++) {
		fscanf(file, "ID %d\n", &idObj);
		fscanf(file, "MODEL %d\n", &pos_Model);
		fscanf(file, "TEXTURES %d\n", &NmOfTexture);
		fscanf(file, "TEXTURE %d\n", &pos_Texture);
		fscanf(file, "CUBETEXTURES %d\n", &cubetexture);
		fscanf(file, "SHADER %d\n", &pos_Shader);
		fscanf(file, "POSITION %f %f %f\n", &x, &y, &z);
		listObj.at(i)->o_positon.x = x; listObj.at(i)->o_positon.y = y; listObj.at(i)->o_positon.z = z;
		fscanf(file, "ROTATION %f %f %f\n", &x, &y, &z);
		listObj.at(i)->o_rotation.x = x; listObj.at(i)->o_rotation.y = y; listObj.at(i)->o_rotation.z = z;
		fscanf(file, "SCALE %f %f %f\n", &x, &y, &z);
		listObj.at(i)->o_scale.x = x; listObj.at(i)->o_scale.y = y; listObj.at(i)->o_scale.z = z;
		listObj.at(i)->setWordl();
	}
}
void SceneManager::draw(vector<Object*> listObj, Shaders shader) {
	glUseProgram(shader.program);
	glUniformMatrix4fv(shader.u_projection, 1, GL_FALSE, (const GLfloat*)s_camera->PCMR.m);
	glUniformMatrix4fv(shader.u_view, 1, GL_FALSE, (const GLfloat*)s_camera->VCMR.m);
	for (int i = 0; i < listObj.size(); i++) {
		//cout << s_camera->position.x << endl; 
		//cout << listObj.at(i)->trans.m[3][0]  << " " << listObj.at(i)->trans.m[3][1] << " " << listObj.at(i)->trans.m[3][2] << endl;
		//listObj.at(i)->trans.SetTranslation(i, i, i);
		listObj.at(i)->draw(shader);
	}
}