#include "kitchen.h"

kitchen::kitchen()
{
	//-------------------------- setting parrents ---------------------------\\
	
	//this section sets the their parent to "top" 
	top_curve.setParent(top);
	bottom.setParent(top);
	
	//this section sets the their parent to "floor" 
	wall.setParent(floor);
	wall2.setParent(floor);
	
	//this section sets the their parent to "wall"
	wall3.setParent(wall);
	cabinet.setParent(wall);
	shelf1.setParent(wall);
	shelf2.setParent(wall);
	shelf3.setParent(wall);
	vent1.setParent(wall);
	vent2.setParent(wall);


	//-------------------------- setting position ---------------------------\\
	
	//this section is setting the positions of each object 
	top.setPosition(0, 0, 0);
	top_curve.setPosition(0, -0.08, 22);
	bottom.setPosition(0, -30, 0);
	floor.setPosition(0, -60, 127);
	wall.setPosition(0, 100, -150);
	wall2.setPosition(150, 100, 0);
	wall3.setPosition(0, -14, 1);

	cabinet.setPosition(-55, 35, 15);

	shelf1.setPosition(28, 35, 5);
	shelf2.setPosition(28, 50, 5);
	shelf3.setPosition(28, 20, 5);
	
	vent1.setPosition(110, 55, 8);
	vent2.setPosition(110, 10, 8);



	//-------------------------- setting width, height, depth ---------------------------\\

	//this section is dedicated to setting the width, height and depth for each object 
	top.setWidth(165), top.setHeight(6), top.setDepth(45);
	bottom.setWidth(150), bottom.setHeight(60), bottom.setDepth(40);
	top_curve.setHeight(165), top_curve.setRadius(3), top_curve.setResolution(100, 100, 100), top_curve.rotateDeg(90, 0, 0, 1);
	floor.setWidth(300), floor.setHeight(2), floor.setDepth(300);
	wall.setWidth(300), wall.setHeight(200), wall.setDepth(2);
	wall2.setWidth(2), wall2.setHeight(200), wall2.setDepth(300);
	wall3.setWidth(160), wall3.setHeight(50), wall3.setDepth(2);

	cabinet.setWidth(45), cabinet.setHeight(35), cabinet.setDepth(30);
	shelf1.setWidth(105), shelf1.setHeight(5), shelf1.setDepth(10);
	shelf2.setWidth(105), shelf2.setHeight(5), shelf2.setDepth(10);
	shelf3.setWidth(105), shelf3.setHeight(5), shelf3.setDepth(10);

	vent1.setWidth(20), vent1.setHeight(90), vent1.setDepth(17);
	vent2.setWidth(35), vent2.setHeight(5), vent2.setDepth(17);
	
	//-------------------------- applying textures ---------------------------\\

	//this section is used to assign an image to each texture
	ofDisableArbTex();
	ofLoadImage(top_texture, "top.jpg");
	ofLoadImage(bottom_texture, "woodTexA.jpg");
	ofLoadImage(wall3_texture, "wall3.png");
	ofLoadImage(wall_texture, "wall.png");
	ofLoadImage(floor_texture, "floor.jpg");
	ofLoadImage(vent_texture, "oven_body.png");

	//-------------------------- applying materials ---------------------------\\

	//this section is used to alter each material's features 
	top_material.setDiffuseColor(ofFloatColor(1.0, 1.0, 1.0));
	top_material.setSpecularColor(ofFloatColor(0.7, 0.7, 0.7));
	top_material.setShininess(200.0);
	top_material.setAmbientColor(ofFloatColor(0.4, 0.4, 0.4));

	bottom_material.setDiffuseColor(ofFloatColor(1.0, 1.0, 1.0));
	bottom_material.setSpecularColor(ofFloatColor(0.7, 0.7, 0.7));
	bottom_material.setShininess(50.0);
	bottom_material.setAmbientColor(ofFloatColor(0.4, 0.4, 0.4));



}

kitchen::~kitchen()
{
	
}


//function is used to set the position inside the ofApp.cpp file
void kitchen::setPosition(float x, float y, float z)
{
	if (x < 5000 && x > 0) 
	
	posX = x;
	posY = y;
	posZ = z;

	top.setPosition(posX, posY, posZ);
}


void kitchen::update()
{

}

void kitchen::draw()
{
	//this section applies the top materials and draws the top and top_curve objects
	top_material.begin();
	top_texture.bind();
	top.draw();
	top_curve.draw();
	top_texture.unbind();
	top_material.end();

	//this section draws the bottom, cabinet and shelf objects and binds the bottom material and texture to them
	bottom_material.begin();
	bottom_texture.bind();
	bottom.draw();
	cabinet.draw();
	shelf1.draw();
	shelf2.draw();
	shelf3.draw();
	bottom_texture.unbind();
	bottom_material.end();

	//draws the floor and applies its tecture to it
	floor_texture.bind();
	floor.draw();
	floor_texture.unbind();

	//draws the first 2 walls and applies its tectures to them
	wall_texture.bind();
	wall.draw();
	wall2.draw();
	wall_texture.bind();

	//draw the third wall texture and applies its tecture to it 
	wall3_texture.bind();
	wall3.draw();
	wall3_texture.unbind();

	//draws the vent and applies its texture to it 
	vent_texture.bind();
	vent1.draw();
	vent2.draw();
	vent_texture.unbind();
}

