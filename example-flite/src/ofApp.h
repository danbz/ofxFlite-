#pragma once
#include "ofMain.h"

#include "ofxFlite~.h"

// Dan Buzzo 2018 - github.com/uwe-creative-technology/
// for UWE Bristol, Creative Technology MSc, Creative Technology Toolkit module 2018-19
// with modified portions from oF flite example;
// https://github.com/s373/ofxFlite-
// dependencies : requires poco libraries
// ofxFlite and  ofXPoco

class ofApp : public ofBaseApp{
    
public:
    
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void audioOut(float * outpt, int bufferSize, int nChannels);
    
    ofxFlite flite;
    ofSoundStream sound;
    
};
   
