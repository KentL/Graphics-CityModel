#ifndef SKYBOX
#define SKYBOX

#include "struct.h"
#include "CubemapTexture.h"

class SkyBox
{
private:
	CubemapTexture* m_cube_texture;
	Vertex1 m_vertices[36];
	vec3 m_position;
	vec3 m_scale;

public:
	SkyBox(string p_texture_name);
	~SkyBox();
	void Render();
	void SetPositon(vec3 pos);
	void SetScale(vec3 scale);

};

#endif // SKYBOX


