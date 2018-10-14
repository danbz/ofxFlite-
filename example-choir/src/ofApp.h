#pragma once

#include "ofMain.h"

#include "ofxFlite~.h"

#define NUMV 10


class ofApp : public ofBaseApp{
    
public:
    
    void setup();
    void update();
    void keyPressed(int key);
    void draw();
    void audioOut(float * outpt, int bufferSize, int nChannels);
    
    ofxFlite *flite[NUMV];
    ofSoundStream	soundStream;
    
};
