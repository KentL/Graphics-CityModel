#ifndef CAMERA
#define CAMERA
#include "stdafx.h"
#include "W_Common.h"
#include "Node.h"
#include "Frustum.h"
#include <wolf\W_VertexDeclaration.h>
#include "AABBCollider.h"


using namespace std;
using namespace glm;
using namespace Geometry;

class Camera:public Node
{
private:
	FrustumNode* frustum;
	float fov;
	float farPane, nearPane;
	float aspect;
	mat4 viewMatrix;
	mat4 projectionMatrix;
	vec4* vertices;
	vec4 lookatPoint;
	bool frustumCalculated;
	vector<Colliders::AABBCollider*>* aabbColliders;

	//camera movement parameters

	float turnLeftScale, turnUpScale;
	float leftDistance, forwDistance;
	float newx, newy, lastx, lasty;
	bool isfirsttime;


public:
	Camera();
	~Camera();
	void setPos(vec3 pos);
	void setFOV(float fov);
	void setFar(float far);
	void setNear(float near);
	void setAspect(float aspect);
	void SetAABBColliders(vector<Colliders::AABBCollider*>* aabbColliders);

	float getFar();
	float getNear();
	float getFOV();
	mat4 getViewMatrix();
	mat4 getProjectionMatrix();
	FrustumNode getFrustum();
	void calculateFrustum();
	vec4 getViewDirection();

	void cameraMove();

};

#endif