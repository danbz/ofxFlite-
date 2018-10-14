#include "ofApp.h"

// Dan Buzzo 2018 - github.com/uwe-creative-technology/
// for UWE Bristol, Creative Technology MSc, Creative Technology Toolkit module 2018-19
// with modified portions from oF flite example;
// https://github.com/s373/ofxFlite-
// dependencies : requires poco libraries
// ofxFlite and  ofXPoco

//--------------------------------------------------------------

void ofApp::setup(){
    
    int sr = 44100; // specify the sample rate of the sound channel
    int bs = 512; // specify the bit rate of the sound channel
    float speed = 0.5f; // specify the speech speed
    float vol = 0.7; // specify the volume
    
    flite.setup(sr,bs,"Hello World.",speed,vol);
    sound.getDeviceList();
    sound.setDeviceID(1);
    sound.setup(this, 2, 0, sr, bs, 4);
    ofSetFrameRate(30);
    ofSetWindowTitle("ofxFlite~");
    
}

//--------------------------------------------------------------

void ofApp::update(){
    if(ofGetMousePressed(0)){
        float s = (float)ofGetMouseX() / (ofGetWidth()/2);
        flite.setSpeakSpeed(s);
    }
}

//--------------------------------------------------------------

void ofApp::draw(){
    
    ofSetColor(255);
    
    ofSetColor( 100, 200, 72);
    flite.draw(100, 400, 25);
    
    if(flite.isThreadRunning()){ // if there is a speech thread running
        ofSetColor(0,255,0); // draw in green
    }else {
        ofSetColor(255,0,0); // draw in red
    }
    
    ofDrawRectangle(50,10,25,25);
}

//--------------------------------------------------------------

void ofApp::audioOut(float * outpt, int bufferSize, int nChannels){
    float * audiosys = flite.processBuffer();
    
    for (int i = 0; i < bufferSize; i++){
        outpt[i*nChannels    ] = audiosys[i] ;
        outpt[i*nChannels + 1] =  audiosys[i] ;
    }
}

//--------------------------------------------------------------

void ofApp::keyPressed(int key){
    
    switch (key) {
        case '1':
            flite.setText("you suck, that jacket is not waterproof.");
            break;
            
        case '2':
            flite.setText("1 + 1 + 10000 + 7.34 + 16, that does work");
            break;
            
        case '3':
            flite.setText("sunshine");
            break;
            
        case '4':
            flite.setText("the time is " + ofToString( ofGetHours() ) + " hours " + ofToString(ofGetMinutes() ) + " minutes, and the day is the " + ofToString( ofGetDay() ) + " of the " + ofToString( ofGetMonth()) );
            break;
    }
}

//--------------------------------------------------------------



