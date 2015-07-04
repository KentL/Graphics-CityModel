#pragma once
#include "Collider.h"
class AABBCollider :public Collider
{
protected:
	double length;
	double width;
	double height;
public:
	AABBCollider();
	AABBCollider(vec3 pos){ position = pos; }	
	AABBCollider(double width, double length, double height){ this->length = length; this->width = width; this->height = height; }
	AABBCollider(vec3 pos, double width, double length, double height){ position = pos; this->width = width; this->length = length; this->height = height; }
	~AABBCollider();

	void setLength(double length){ this->length = length; }
	void setWidth(double width){ this->width = width; }
	void setHeight(double height){ this->height = height; }
	///<summary>
	///return width and height of AABBCollider in the form of size[]={width,length}.
	///</summary>
	double* getSize() const { double size[] = { width, length }; return size; }
	double  getWidth() const { return width; }
	double  getLength() const { return length; }
	double  getHeight() const { return height; }
};

