#include "kitchen_oven.h"

kitchen_oven::kitchen_oven()
{
	//-------------------------- setting parrents ---------------------------\\

	//this section sets the their parent to "body" 
	front.setParent(body);
	front2.setParent(body);
	top.setParent(body);
	dial1.setParent(body);
	dial2.setParent(body);
	dial3.setParent(body);
	dial4.setParent(body);
	dial5.setParent(body);

	//-------------------------- setting position ---------------------------\\
	
	//this section is setting the positions of each object 
	body.setPosition(110, -30, 0);
	front.setPosition(0, 10, 20);
	front2.setPosition(0, -15, 20);
	top.setPosition(0, 32, 0);

	dial1.setPosition(-20, 28, 18);
	dial2.setPosition(0, 2000, 18);
	dial3.setPosition(-7, 28, 18);
	dial4.setPosition(6, 28, 18);
	dial5.setPosition(19, 28, 18);

	//-------------------------- setting width, height, depth ---------------------------\\

	//this section is dedicated to setting the width, height and depth for each object 
	body.setWidth(50), body.setHeight(65), body.setDepth(40);
	front.setWidth(40), front.setHeight(18), front.setDepth(5);
	front2.setWidth(40), front2.setHeight(18), front2.setDepth(5);
	top.setWidth(40), top.setHeight(5), top.setDepth(35);

	dial1.setHeight(5), dial1.setRadius(3.5), dial1.setResolution(100, 100, 100), dial1.rotateDeg(90, 1, 0, 0);
	dial2.setHeight(5), dial2.setRadius(3.5), dial2.setResolution(100, 100, 100), dial2.rotateDeg(90, 1, 0, 0);
	dial3.setHeight(5), dial3.setRadius(3.5), dial3.setResolution(100, 100, 100), dial3.rotateDeg(90, 1, 0, 0);
	dial4.setHeight(5), dial4.setRadius(3.5), dial4.setResolution(100, 100, 100), dial4.rotateDeg(90, 1, 0, 0);
	dial5.setHeight(5), dial5.setRadius(3.5), dial5.setResolution(100, 100, 100), dial5.rotateDeg(90, 1, 0, 0);

	//-------------------------- applying textures ---------------------------\\

	//this section is used to assign an image to each texture
	ofDisableArbTex();
	ofLoadImage(body_texture, "oven_body.png");
	ofLoadImage(front_texture, "oven_front.png");
	ofLoadImage(top_texture, "oven_top.png");


	//-------------------------- applying materials ---------------------------\\
	
	//this section is used to alter each material's features 
	front_material.setDiffuseColor(ofFloatColor(1.0, 1.0, 1.0));
	front_material.setSpecularColor(ofFloatColor(0.7, 0.7, 0.7));
	front_material.setShininess(50.0);
	front_material.setAmbientColor(ofFloatColor(0.4, 0.4, 0.4));

}

kitchen_oven::~kitchen_oven()
{

}


//function is used to set the position inside the ofApp.cpp file
void kitchen_oven::setPosition(float x, float y, float z)
{
	if (x < 5000 && x > 0)

	posX = x;
	posY = y;
	posZ = z;

	body.setPosition(posX, posY, posZ);
}


void kitchen_oven::update()
{

}

void kitchen_oven::draw()
{
	//draws the two front windows and applies its texture and material to them
	front_material.begin();
	front_texture.bind();
	front.draw();
	front2.draw();
	front_texture.unbind();
	front_material.end();

	//draws the body and applies its texture to it
	body_texture.bind();
	body.draw();
	body_texture.unbind();

	//draws the dials
	dial1.draw();
	dial2.draw();
	dial3.draw();
	dial4.draw();
	dial5.draw();
	
	//draws the top and applies its texture to it
	top_texture.bind();
	top.draw();
	top_texture.unbind();



}

