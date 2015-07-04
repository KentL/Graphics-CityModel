#include "stdafx.h"
#include "Collider.h"


using namespace std;
using namespace glm;
class SphereCollider:public Collider
{
protected:
	double radius;
public:
	//constructors and destructor
	SphereCollider();
	SphereCollider(vec3 pos){ position = pos; }
	SphereCollider(double r){ radius = r; }
	SphereCollider(vec3 pos, double r){ position = pos; radius = r; }
	~SphereCollider();

	void setRadius(double r){ radius = r; }
	double getRadius()const{ return radius; }
};

