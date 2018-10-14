#pragma once

#include "ofMain.h"

#include "ofxFlite~.h"


class ofApp : public ofBaseApp{

	public:

    void setup();
    void update();
    void keyPressed(int key);
    void draw();
    void audioOut(float * outpt, int bufferSize, int nChannels);
    
		ofxFlite flite;
		ofSoundStream sound;

};
