#ifndef PLANE
#define PLANE

#include "stdafx.h"

using namespace glm;

class Plane
{
protected:
	vec3 base_point;
	vec3 normal;

public:
	Plane();
	Plane(vec3 base, vec3 n){ base_point = base; normal = n; }
	~Plane();

	///<summary>
	///This function set the point used to determine the position of the plane
	///</summary>
	void SetPoint(vec3 p){ base_point = p; }


	///<summary>
	///This function set the normal used to determine the direction of the plane
	///</summary>
	void SetNormal(vec3 n){ normal = n; }


	///<summary>
	///This function return the point used to determine the position of the plane
	///</summary>
	vec3 GetPoint() const { return base_point; }


	///<summary>
	///This function return the normal used to determine the direction of the plane
	///</summary>
	vec3 GetNormal() const { return normal; }
};

#endif