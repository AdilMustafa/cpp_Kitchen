#include "kitchen_draw.h"

kitchen_draw::kitchen_draw()
{
	//-------------------------- setting parrents ---------------------------\\
	
	//this section sets the their parent to "handle3" 
	handle1.setParent(handle3);
	handle2.setParent(handle3);
	
	//this section sets the their parent to "door" 
	handle3.setParent(door);
	board1.setParent(door);
	board2.setParent(door);
	board3.setParent(door);
	board4.setParent(door);

	//-------------------------- setting position ---------------------------\\
	
	//this section is setting the positions of each object 
	door.setPosition(-45, -10, 30);
	board1.setPosition(0, -4, -10);
	board2.setPosition(-14, 0, -10);
	board3.setPosition(14, 0, -10);
	board4.setPosition(0, 0, -19);
	handle1.setPosition(0, -7, -1);
	handle2.setPosition(0, 7, -1);
	handle3.setPosition(0, 0, 2);

	//-------------------------- setting width, height, depth ---------------------------\\

	//this section is dedicated to setting the width, height and depth for each object 
	door.setWidth(30), door.setHeight(10), door.setDepth(2);
	board1.setWidth(30), board1.setHeight(2), board1.setDepth(20);
	board2.setWidth(2), board2.setHeight(10), board2.setDepth(20);
	board3.setWidth(2), board3.setHeight(10), board3.setDepth(20);
	board4.setWidth(30), board4.setHeight(10), board4.setDepth(2);

	handle1.setWidth(0.8), handle1.setHeight(0.8), handle1.setDepth(2);
	handle2.setWidth(0.8), handle2.setHeight(0.8), handle2.setDepth(2);
	handle3.setHeight(15), handle3.setRadius(0.5), handle3.setResolution(100, 100, 100), handle3.rotateDeg(90, 0, 0, 1);

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

kitchen_draw::~kitchen_draw()
{

}


//function is used to set the position inside the ofApp.cpp file
void kitchen_draw::setPosition(float x, float y, float z)
{
	if (x < 5000 && x > 0)

	posX = x;
	posY = y;
	posZ = z;

	door.setPosition(posX, posY, posZ);
}


void kitchen_draw::update()
{

}

void kitchen_draw::draw()
{
	//this secion draws the door and boards and applies the door texture and material to them
	door_material.begin();
	door_texture.bind();
	door.draw();
	board1.draw();
	board2.draw();
	board3.draw();
	board4.draw();
	door_texture.unbind();
	door_material.end();

	//draws the handles and applies its material to them
	handle_material.begin();
	handle1.draw();
	handle2.draw();
	handle3.draw();
	handle_material.end();




}

