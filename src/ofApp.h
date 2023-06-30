#pragma once

#include "ofMain.h"
#include "ofxAravis.h"
#include "ofxSyphon.h"

struct AravisSyphonPair {
    ofxSyphonServer syphon;
    ofxAravis::Grabber aravis;
    int idx;
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
        vector<AravisSyphonPair *> cameras;
        int total;
        int columnWidth = 250;
        int columnHeight = columnWidth * 0.75;
};
