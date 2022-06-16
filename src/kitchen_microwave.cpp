#include "kitchen_microwave.h"

kitchen_microwave::kitchen_microwave()
{
	//-------------------------- setting parrents ---------------------------\\

	//this section sets the their parent to "body" 
	front.setParent(body);
	timer.setParent(body);
	buttons.setParent(body);
	eject.setParent(body);



	//-------------------------- setting position ---------------------------\\
	
	//this section is setting the positions of each object 
	body.setPosition(-60, 13, -5);
	front.setPosition(-2, 0, 8.5);
	timer.setPosition(12, 6.5, 8.5);
	buttons.setPosition(12, 1, 8.5);
	eject.setPosition(12, -4, 8.5);



	//-------------------------- setting width, height, depth ---------------------------\\

	//this section is dedicated to setting the width, height and depth for each object 
	body.setWidth(30), body.setHeight(20), body.setDepth(20);
	front.setWidth(22), front.setHeight(15), front.setDepth(5);
	timer.setWidth(3), timer.setHeight(2), timer.setDepth(5);
	eject.setWidth(2), eject.setHeight(1), eject.setDepth(5);
	buttons.setWidth(3), buttons.setHeight(7), buttons.setDepth(5);



	//-------------------------- applying textures ---------------------------\\
	
	//this section is used to assign an image to each texture
	ofDisableArbTex();
	ofLoadImage(body_texture, "microwave_body.jfif");
	ofLoadImage(front_texture, "microwave_window.png");
	ofLoadImage(buttons_texture, "buttons.png");
	ofLoadImage(timer_texture, "timer.png");

	//-------------------------- applying materials ---------------------------\\

	//this section is used to alter each material's features 
	front_material.setDiffuseColor(ofFloatColor(1.0, 1.0, 1.0));
	front_material.setSpecularColor(ofFloatColor(0.7, 0.7, 0.7));
	front_material.setShininess(50.0);
	front_material.setAmbientColor(ofFloatColor(0.4, 0.4, 0.4));





}

kitchen_microwave::~kitchen_microwave()
{

}


//function is used to set the position inside the ofApp.cpp file
void kitchen_microwave::setPosition(float x, float y, float z)
{
	if (x < 5000 && x > 0)

	posX = x;
	posY = y;
	posZ = z;

	body.setPosition(posX, posY, posZ);
}


void kitchen_microwave::update()
{

}

void kitchen_microwave::draw()
{
	
	
	//draws the body and applies its texture and material to it
	front_material.begin();
	body_texture.bind();
	body.draw();
	body_texture.unbind();
	front_material.end();

	//draws the front and adds its texture to it
	front_texture.bind();
	front.draw();
	front_texture.unbind();

	//draws the timer and adds its texture to it
	timer_texture.bind();
	timer.draw();
	timer_texture.unbind();

	//draws the buttons and adds its texture to it
	buttons_texture.bind();
	buttons.draw();
	buttons_texture.unbind();

	//draws the eject button
	eject.draw();
	




}

