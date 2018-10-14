#include "ofApp.h"

// Dan Buzzo 2018 - github.com/uwe-creative-technology/
// for UWE Bristol, Creative Technology MSc, Creative Technology Toolkit module 2018-19
// with modified portions from oF flite example;
// https://github.com/s373/ofxFlite-
// dependencies : requires poco libraries
// ofxFlite and  ofXPoco

//--------------------------------------------------------------

void ofApp::setup(){
    
    int sr = 44100;
    int bs = 512;
    float speed = 0.5f;
    float vol = 0.7;
    
    flite.setup(sr,bs,"..Hello There. Try. Try Pressing the L key, to Load the File onto Network Rom.",speed,vol);
    
    sound.getDeviceList();
    sound.setDeviceID(1); // alter this to suit your hardware, sound output device
    sound.setup(this, 2, 0, sr, bs, 4);
    ofSetFrameRate(30);
    ofSetWindowTitle("ofxFlite~ cyberspace");
    
}
//--------------------------------------------------------------

void ofApp::update(){
    
    if(ofGetMousePressed(0)){
        float s = (float)ofGetMouseX() / (ofGetWidth()/2);
        flite.setSpeakSpeed(s);
    }
    
}
//--------------------------------------------------------------


void ofApp::keyPressed(int key){
    if(key=='1'){
        flite.setText("you stupid programmer, that does not work.");
    }
    
    if(key=='l'){
        flite.loadFile("cyberspace.txt");
    }
}

//--------------------------------------------------------------

void ofApp::draw(){
    
    ofSetColor(255);
    
    ofSetColor( 100, 200, 72);
    flite.draw(100, 400, 25);
    
    if(flite.isThreadRunning()){
        ofSetColor(0,255,0);
    }else {
        ofSetColor(255,0,0);
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
