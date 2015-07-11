#ifndef PLANE
#define PLANE

#include "stdafx.h"

using namespace glm;

namespace Geometry
{
	class Plane
	{
	protected:
		double distance;
		vec3 normal;

	public:
		Plane();
		Plane(double d){ distance = d; }
		Plane(vec3 n){ normal = n; }
		Plane(vec3 n, double d){ distance = d; normal = n; }
		Plane(double d, vec3 n){ this->distance = d; normal = n; }
		~Plane();

		///<summary>
		///This function set the distance used to determine the position of the plane
		///</summary>
		void SetDistance(double d){ distance = d; }


		///<summary>
		///This function set the normal used to determine the direction of the plane
		///</summary>
		void SetNormal(vec3 n){ normal = n; }


		///<summary>
		///This function return the distance used to determine the position of the plane
		///</summary>
		double GetDistance() const { return distance; }

		///<summary>
		///This function return the normal used to determine the direction of the plane
		///</summary>
		vec3 GetNormal() const { return normal; }
	};

}
#endif