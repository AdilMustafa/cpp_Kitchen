#include "kitchen_cupboard.h"

kitchen_cupboard::kitchen_cupboard()
{
	//-------------------------- setting parrents ---------------------------\\

	//this section sets the their parent to "handle3" 
	handle1.setParent(handle3);
	handle2.setParent(handle3);
	
	//this section sets the their parent to "door" 
	handle3.setParent(door);
	second_door.setParent(door);

	//this section sets the their parent to "second_handle3" 
	second_handle1.setParent(second_handle3);
	second_handle2.setParent(second_handle3);
	
	//sets second_handle3's parent to "second_door"
	second_handle3.setParent(second_door);


	//-------------------------- setting position ---------------------------\\
	
	//this section is setting the positions of each object 
	door.setPosition(-45, -35, 19);
	handle1.setPosition(0, -4, -1);
	handle2.setPosition(0, 4, -1);
	handle3.setPosition(10, 10, 4);	
	
	second_door.setPosition(37,0,0);
	second_handle1.setPosition(0, -4, -1);
	second_handle2.setPosition(0, 4, -1);
	second_handle3.setPosition(-10, 10, 4);

	//-------------------------- setting width, height, depth ---------------------------\\

	//this section is dedicated to setting the width, height and depth for each object 
	door.setWidth(30), door.setHeight(35), door.setDepth(5);
	handle1.setWidth(0.8), handle1.setHeight(0.8), handle1.setDepth(2);
	handle2.setWidth(0.8), handle2.setHeight(0.8), handle2.setDepth(2);
	handle3.setHeight(9), handle3.setRadius(0.5), handle3.setResolution(100, 100, 100);	
	
	second_door.setWidth(30), second_door.setHeight(35), second_door.setDepth(5);
	second_handle1.setWidth(0.8), second_handle1.setHeight(0.8), second_handle1.setDepth(2);
	second_handle2.setWidth(0.8), second_handle2.setHeight(0.8), second_handle2.setDepth(2);
	second_handle3.setHeight(9), second_handle3.setRadius(0.5), second_handle3.setResolution(100, 100, 100);
	
	//-------------------------- applying textures ---------------------------\\

	ofDisableArbTex();
	ofLoadImage(door_texture, "woodTexA.jpg");

	//-------------------------- applying materials ---------------------------\\
	
	//this section is used to alter each material's features 
	door_material.setDiffuseColor(ofFloatColor(1.0, 1.0, 1.0));
	door_material.setSpecularColor(ofFloatColor(0.7, 0.7, 0.7));
	door_material.setShininess(50.0);
	door_material.setAmbientColor(ofFloatColor(0.4, 0.4, 0.4));

	handle_material.setDiffuseColor(ofFloatColor(1.0, 1.0, 1.0));
	handle_material.setSpecularColor(ofFloatColor(0.7, 0.7, 0.7));
	handle_material.setShininess(50.0);
	handle_material.setAmbientColor(ofFloatColor(0.4, 0.4, 0.4));



}

kitchen_cupboard::~kitchen_cupboard()
{
	
}


//function is used to set the position inside the ofApp.cpp file
void kitchen_cupboard::setPosition(float x, float y, float z)
{
	if (x < 5000 && x > 0) 
	
	posX = x;
	posY = y;
	posZ = z;

	door.setPosition(posX, posY, posZ);

}


void kitchen_cupboard::update()
{

}

void kitchen_cupboard::draw()
{
	//this section draws the doors and applies its materials and texture to them
	door_material.begin();
	door_texture.bind();
	door.draw();	
	second_door.draw();
	door_texture.unbind();
	door_material.end();


	//draws the handles
	handle_material.begin();
	handle1.draw();
	handle2.draw();
	handle3.draw();	
	second_handle1.draw();
	second_handle2.draw();
	second_handle3.draw();
	handle_material.end();



	

}

