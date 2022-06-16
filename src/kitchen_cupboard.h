#pragma once
#include "ofMain.h"
class kitchen_cupboard
{

public:
	kitchen_cupboard();
	~kitchen_cupboard();
	
	void update();
	void draw();
	void setPosition(float x, float y, float z);

	
	
private:

	float posX, posY, posZ;

	//creates box primitives 
	ofBoxPrimitive	door, handle1, handle2,second_door, second_handle1, second_handle2;
	
	//creates cylinder primitives
	ofCylinderPrimitive handle3, second_handle3;

	//creates textures
	ofTexture door_texture, handle_texture;

	//creates materials
	ofMaterial door_material, handle_material;





};

