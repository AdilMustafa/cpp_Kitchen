#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	gui.setup(); //allows the gui to display
	gui.add(light_pos.setup("light Position", ofVec3f(120, 100, 120), ofVec3f(0, 0, 0), ofVec3f(300, 200, 300))); //allows the user to control the x, y, z, potion of the light 

	gui.add(light_red.setup("Red Value", 1, 0, 1)); //allows the user to increase/decrease the red colour value for the lighting
	gui.add(light_green.setup("Green Value", 1, 0, 1)); //allows the user to increase/decrease the green colour value for the lighting
	gui.add(light_blue.setup("Blue Value", 1, 0, 1)); //allows the user to increase/decrease the blue colour value for the lighting

	ofSetBackgroundColor(30);
	camera.setPosition(vec3(20.0, 70.0, 440.0));
	camera.setTarget(vec3(0.0, 0.0, 0.0));
	camera.setFov(35.0);
	camera.setAutoDistance(false);

	teapotMesh.load("teapot.ply");

	teapotMaterial.setDiffuseColor(ofFloatColor(1.0, 1.0, 1.0));
	teapotMaterial.setSpecularColor(ofFloatColor(0.7, 0.7, 0.7));
	teapotMaterial.setShininess(50.0);
	teapotMaterial.setAmbientColor(ofFloatColor(0.4, 0.4, 0.4));

	room.setPosition(0, 0, 0); //sets the room position
	cupboard2.setPosition(30, -35, 19); //sets the second pair of cupboards position 
	cupboard3.setPosition(-20, 20, 0); //sets the third pair of cupboards position 

	kit_draw2.setPosition(0, -10, 22); //sets the second draw's position 
	kit_draw3.setPosition(20, -10, 22); //sets the third draw's position 
	kit_draw4.setPosition(67, -10, 30); //sets the fourth draw's position 

	ofEnableNormalizedTexCoords();
	woodTexture.load("woodTexA.jpg");



}

//--------------------------------------------------------------
void ofApp::update() {

	//this has been moved into update in order to allow the user to change the lighting
	keyLight.setDiffuseColor(ofFloatColor(light_red, light_green, light_blue)); //links the colours to the slider values
	keyLight.setSpecularColor(keyLight.getDiffuseColor());
	keyLight.setPosition(vec3(light_pos->x, light_pos->y, light_pos->z)); //links the positions to the vec3 slider values
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofEnableDepthTest();
	camera.begin();
	ofEnableLighting();
	keyLight.enable();
	ofTranslate(0, -50); //moves everything down by 50px

	//this section draws the teapot and moves the teapot 10px up
	ofPushMatrix();
		ofTranslate(0, 10); 
		teapotMaterial.begin();
		teapotMesh.draw();
		teapotMaterial.end();
	ofPopMatrix();

	room.draw(); //draws the room

	//this section draws the cupboards and moves it 2px down and 10px to the left 
	ofPushMatrix();
		ofTranslate(-10, -2, 0);
		cupboard.draw();
		cupboard2.draw();


	kit_draw.draw(); //draws the first draw

	//this section draws the remaing 3 draws and positions them with translate
	ofPushMatrix();
		ofTranslate(-8, 0, 0);
		kit_draw2.draw();

		ofTranslate(18, 0, 0);
		kit_draw3.draw();

		ofTranslate(-130, 30, -140);
		fridge.draw();
		ofPopMatrix();

		kit_draw4.draw();
	ofPopMatrix();

	micro.draw(); //draws the microwave
	oven.draw(); //draws the oven 

	//this section disables everything associated with the camera and lighting
	keyLight.disable();
	ofDisableLighting();
	camera.end();
	ofDisableDepthTest();
	
	gui.draw(); //draws the gui 

	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

void ofApp::addQuadFacet(ofMesh &curMesh, vec3 v0, vec3 v1, vec3 v2, vec3 v3, vec2 tMin, vec2 tMax) {
	// Adds a quadrilateral facet based on positions of the 4 vertex positions and min and max
	// values for the texture coordinates. Automatically calculates the normal based on a CCW winding
	// order for the vertex positions.

	int baseIndex = curMesh.getNumVertices();

	curMesh.addVertex(v0);
	curMesh.addVertex(v1);
	curMesh.addVertex(v2);
	curMesh.addVertex(v3);

	vec3 n = normalize(cross(v1 - v0, v3 - v0));
	curMesh.addNormal(n);
	curMesh.addNormal(n);
	curMesh.addNormal(n);
	curMesh.addNormal(n);

	curMesh.addTexCoord(vec2(tMin.x, tMin.y));
	curMesh.addTexCoord(vec2(tMax.x, tMin.y));
	curMesh.addTexCoord(vec2(tMax.x, tMax.y));
	curMesh.addTexCoord(vec2(tMin.x, tMax.y));

	curMesh.addTriangle(baseIndex, baseIndex + 1, baseIndex + 2);
	curMesh.addTriangle(baseIndex, baseIndex + 2, baseIndex + 3);
}


ofVboMesh ofApp::createCuboidMesh(float width, float height) {
	ofVboMesh curMesh;

	curMesh.setMode(OF_PRIMITIVE_TRIANGLES);

	// Pedestal width and height values
	const float w = 0.5f * width;
	const float h = height;

	// Facets for the 4 sides
	addQuadFacet(curMesh, vec3(-w, 0, w), vec3(w, 0, w), vec3(w, h, w), vec3(-w, h, w), vec2(0.0, 0.0), vec2(0.25, 1.0));
	addQuadFacet(curMesh, vec3(w, 0, w), vec3(w, 0, -w), vec3(w, h, -w), vec3(w, h, w), vec2(0.25, 0.0), vec2(0.5, 1.0));
	addQuadFacet(curMesh, vec3(w, 0, -w), vec3(-w, 0, -w), vec3(-w, h, -w), vec3(w, h, -w), vec2(0.5, 0.0), vec2(0.75, 1.0));
	addQuadFacet(curMesh, vec3(-w, 0, -w), vec3(-w, 0, w), vec3(-w, h, w), vec3(-w, h, -w), vec2(0.75, 0.0), vec2(1.0, 1.0));

	// Facet for the top
	addQuadFacet(curMesh, vec3(-w, h, w), vec3(w, h, w), vec3(w, h, -w), vec3(-w, h, -w), vec2(0.0, 0.0), vec2(0.25, 0.25));

	// Facet for the bottom
	addQuadFacet(curMesh, vec3(-w, 0, w), vec3(-w, 0, -w), vec3(w, 0, -w), vec3(w, 0, w), vec2(0.25, 0.25), vec2(0.5, 0.5));

	return curMesh;
}
