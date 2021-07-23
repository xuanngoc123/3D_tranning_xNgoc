#pragma once

#include"Object.h"
#include"Camera.h"
#include<vector>

using namespace std;
class SceneManager {
public:
	Camera* s_camera = new Camera();

	void initSM(vector<Object*> listObj);

	void draw(vector<Object*> listObj, Shaders shader);

};