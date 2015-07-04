#include <wolf\W_Texture.h>
class SurfaceMaterial
{
public:
	SurfaceMaterial() : m_diffuse(0, 0, 0, 0), m_specular(0, 0, 0, 0), m_ambient(0, 0, 0, 0) {};
	~SurfaceMaterial();
	void setAmbient(wolf::Color4 ambient){ m_ambient = ambient; }
	void setDiffuse(wolf::Color4 diffuse){ m_diffuse = diffuse; }
	void setSpecular(wolf::Color4 specular){ m_specular = specular; }
	wolf::Color4 getAmbient(){ return m_ambient; }
	wolf::Color4 getDiffuse(){ return m_diffuse; }
	wolf::Color4 getSpecular(){ return m_specular; }

private:
	wolf::Color4	m_ambient;
	wolf::Color4	m_diffuse;
	wolf::Color4	m_specular; // w stores the specular power
};


