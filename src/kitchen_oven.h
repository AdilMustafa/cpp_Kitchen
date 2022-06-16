#pragma once
#include "ofMain.h"
class kitchen_oven
{

public:
	kitchen_oven();
	~kitchen_oven();
	
	void update();
	void draw();
	void setPosition(float x, float y, float z);
	//void rotationOn();
	//void rotationOff();
	
	
private:

	float posX, posY, posZ;

	ofBoxPrimitive	body, top, front, front2;

	ofCylinderPrimitive dial1, dial2, dial3, dial4, dial5;

	ofTexture front_texture, top_texture, body_texture, dial_texture;

	ofMaterial front_material, top_material;

	bool rotate;



};

