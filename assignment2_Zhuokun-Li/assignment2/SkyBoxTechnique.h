#ifndef SKYBOXTECHNIQUE
#define SKYBOXTECHNIQUE
#include "stdafx.h"

using namespace std;
using namespace glm;
class SkyBoxTechnique
{
private:
	string fsh;
	string vsh;
	mat4 mvp;

public:
	SkyBoxTechnique();
	~SkyBoxTechnique();
	
};

#endif