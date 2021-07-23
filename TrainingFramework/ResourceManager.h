#pragma once
#include"stdafx.h"
#include<vector>
#include"Object.h"

using namespace std;
class ResourceManager {
public:
	vector<Object*> listObj;
	vector<Model*> listModel;
	vector<Texture*> listTexture;
	void initRM();
	ResourceManager();
	~ResourceManager();
};