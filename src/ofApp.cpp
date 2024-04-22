#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
    cam.setUpAxis({0,0,1});
    cam.setDistance(200);
    text.load("Fonts/fractalFont.otf",40);
    dataText.load("Fonts/fractalFont.otf",23);

    Fractals.push_back(new Circle("Circle Fractal", 2));
    Fractals.push_back(new Tree("Tree Fractal", 1));
    Fractals.push_back(new Triangle("Triangle Fractal", 2));
    Fractals.push_back(new Fern("Barnsley Fern", 10));
    Fractals.push_back(new SnowFlake("Koch SnowFlake", 2));
    Fractals.push_back(new Fractal3D("3D Fractal", 3, &cam));
}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackgroundGradient(ofColor(65), ofColor(0), OF_GRADIENT_BAR);

    ofNoFill();
        Fractals[index-1]->draw();
        Fractals[index-1]->update(); //instead of using static_cast to increase angle, we use an update method for it
        text.drawString(Fractals[index-1]->getName(),25,60);

    if(debug){
        // Levels of different shapes
       dataText.drawString("1.Circle Level: " + to_string(Fractals[0]->getLevel()),25,240); 
       dataText.drawString("2.Tree Level: " + to_string(Fractals[1]->getLevel()),25,300); 
       dataText.drawString("3.Triangle Level: " + to_string(Fractals[2]->getLevel()),25,360); 
       dataText.drawString("4.Barnsley Level: " + to_string(Fractals[3]->getLevel()),25,420); 
       dataText.drawString("5.SnowFlake Level: " + to_string(Fractals[4]->getLevel()),25,480); 
       dataText.drawString("6.3D Fractal Level: " + to_string(Fractals[5]->getLevel()),25,540); 
    	
       // Información de como subir los niveles
       dataText.drawString("Press Right Arrow to Level up the Recursion",950,60);
       dataText.drawString("Press Left Arrow to Level down the Recursion",957,120);
       
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key >= '1' && key <= '6'){
        mode = key;
        index = key - '0'; //Convertimos el character a int
    }
    //This will increase level
    if(key == OF_KEY_RIGHT){
        Fractals[index-1]->increaseLevel();            
    }
    //This will decrease level
    if(key == OF_KEY_LEFT){ 
        Fractals[index-1]->decreaseLevel(); 
    }
    if(tolower(key) == 'd'){
        debug = !debug;
    }
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