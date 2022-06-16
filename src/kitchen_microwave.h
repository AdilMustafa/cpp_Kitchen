#pragma once
#include "ofMain.h"
class kitchen_microwave
{

public:
	kitchen_microwave();
	~kitchen_microwave();
	
	void update();
	void draw();
	void setPosition(float x, float y, float z);
	//void rotationOn();
	//void rotationOff();
	
	
private:

	float posX, posY, posZ;

	ofBoxPrimitive	body, timer, buttons, eject, front;

	ofCylinderPrimitive dial1;

	ofTexture front_texture, body_texture, buttons_texture, timer_texture;

	ofMaterial front_material, body_material;

	bool rotate;



};

