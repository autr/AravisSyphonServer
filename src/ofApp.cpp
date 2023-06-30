#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofLog::setAutoSpace(true);
    total = ofxAravis::ListAllDevices().size();
    for (int i = 0; i < total; i++) {
        AravisSyphonPair * pair = new AravisSyphonPair();
        pair->aravis.setup(0);
        pair->syphon.setName(pair->aravis.getInfo().model);
        pair->idx = i;
        cameras.push_back(pair);
    }
    
    ofSetWindowShape(total * columnWidth, columnHeight + 140);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (auto & pair : cameras ) {
        pair->aravis.update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
        
    ofBackground(0);
    
    for (auto & pair : cameras ) {
        
        int x = columnWidth * pair->idx;
        int w = columnWidth;
        int h = (float(w) / pair->aravis.getSensorWidth()) * pair->aravis.getSensorHeight();
        
        ofLog() << x << w << h;
        if (pair->aravis.isInited()) {
            pair->aravis.draw(x,0,w,h);
            pair->syphon.publishTexture( &pair->aravis.getTexture() );
        }
        pair->aravis.drawInfo(x + 20, columnHeight);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
