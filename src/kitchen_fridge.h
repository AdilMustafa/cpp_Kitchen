#pragma once
#include "ofMain.h"
class kitchen_fridge
{

public:
	kitchen_fridge();
	~kitchen_fridge();
	
	void update();
	void draw();
	void setPosition(float x, float y, float z);

	
	
private:

	float posX, posY, posZ;
	//creates box primitives 
	ofBoxPrimitive	door, handle1, handle2,second_door, second_handle1, second_handle2, body;
	
	//creates cylinder primitives
	ofCylinderPrimitive handle3, second_handle3;

	//creates textures
	ofTexture door_texture, handle_texture;
	
	//creates materials
	ofMaterial door_material, handle_material;

};

