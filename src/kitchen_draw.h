#pragma once
#include "ofMain.h"
class kitchen_draw
{

public:
	kitchen_draw();
	~kitchen_draw();
	
	void update();
	void draw();
	void setPosition(float x, float y, float z);

	
	
private:

	float posX, posY, posZ;

	//creates box primitives 
	ofBoxPrimitive	door, handle1, handle2, board1, board2, board3, board4;
	
	//creates cylinder primitives
	ofCylinderPrimitive handle3;
	
	//creates textures
	ofTexture door_texture, handle_texture;

	//creates materials
	ofMaterial door_material, handle_material;





};

