#ifndef COLLIDER
#define COLLIDER

#include "stdafx.h"

using namespace glm;

enum ColliderType
{
	Sphere,
	AABB
};

class Collider
{
protected:
	ColliderType collider_type;
	vec3 position;
public:
	Collider();
	~Collider();
	void setPosition(vec3 pos){ position = pos; }
	vec3 getPosition() const{ return position; }
};


#endif