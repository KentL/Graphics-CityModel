#ifndef CITYMODELLER
#define CITYMODELLER
#include <vector>
#include "struct.h"
#include "AABBCollider.h"
#define SIZE            70

using namespace std;

class CityModeller
{
private:
	vector<building*>* buildingStore;
	vector<road*>*     roadStore;
	vector<Vertex2>*  city_vertices_data;
	vector<singlegrid*>* cross;
	vector<singlegrid*>* buildingBase;
	vector<singlegrid*>* space;
	vector<Colliders::AABBCollider*>* aabbCollidersCollection;
	public:	vector<Vertex1>* collider_vertex;//For debug

private:
	void loadBuffer();
	
public:
	CityModeller();
	~CityModeller();
	void generateCityLayoutData(bool firsttime);
	void render();
	std::vector<Vertex2>* getBuffer();
	std::vector<Colliders::AABBCollider*>* GetAABBColliders();
	void clearBuffer();
	
public:
	bool grids[SIZE][SIZE];
	int w, h, l; //width length height of a building
	int wMax, hMax, lMax;
	int row1, row2, column1, column2;
    float lastT = 0;
};
#endif