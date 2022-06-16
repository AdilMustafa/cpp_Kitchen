#pragma once
#include "ofMain.h"
class kitchen
{

public:
	kitchen();
	~kitchen();
	
	void update();
	void draw();
	void setPosition(float x, float y, float z);

	
	
private:

	float posX, posY, posZ;

	//creates box primitives 
	ofBoxPrimitive	top, bottom, floor, wall, wall2, wall3, ceiling, cabinet, shelf1, shelf2, shelf3, vent1, vent2;

	//creates cylinder primitives
	ofCylinderPrimitive top_curve;

	//creates textures
	ofTexture top_texture, bottom_texture, wall3_texture, floor_texture, wall_texture, vent_texture;

	//creates materials
	ofMaterial top_material, bottom_material;





};

