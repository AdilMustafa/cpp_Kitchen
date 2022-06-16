#pragma once

#include "ofMain.h"
#include "kitchen.h" //allows me to use the kitchen header file ive created
#include "kitchen_cupboard.h" //allows me to use the kitchen_cupboard header file ive created
#include "kitchen_draw.h" //allows me to use the kitchen_draw header file ive created
#include "kitchen_microwave.h" //allows me to use the kitchen_microwave header file ive created
#include "kitchen_oven.h" //allows me to use the kitchen_oven header file ive created
#include "kitchen_fridge.h" //allows me to use the kitchen_fridge header file ive created
#include "ofxGui.h" //allows me to add onscreen sliders to manipulate the lighting
using namespace glm;

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	void addQuadFacet(ofMesh &curMesh, vec3 v0, vec3 v1, vec3 v2, vec3 v3, vec2 tMin, vec2 tMax);
	ofVboMesh createCuboidMesh(float width, float height);

	ofEasyCam camera;
	ofLight keyLight;
	ofVboMesh teapotMesh, pedestalMesh;
	ofMaterial teapotMaterial, pedestalMaterial;
	ofImage woodTexture;

	kitchen room; //draws the room of the kitchen
	kitchen_cupboard cupboard, cupboard2, cupboard3; //draws the cupboards 
	kitchen_draw kit_draw, kit_draw2, kit_draw3, kit_draw4; //draws the kitchen draws
	kitchen_microwave micro; //draws the microwave
	kitchen_oven oven; //draws the oven #
	kitchen_fridge fridge; //draws the fridge

	ofxPanel gui; //draws the gui
	ofxFloatSlider light_red, light_blue, light_green; //creates sliders that uses float values

	ofxVec3Slider light_pos; //creates a slider that uses vec3 numbers
	

};
