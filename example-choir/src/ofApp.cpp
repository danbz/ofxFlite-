#include "ofApp.h"

// Dan Buzzo 2018 - github.com/uwe-creative-technology/
// for UWE Bristol, Creative Technology MSc, Creative Technology Toolkit module 2018-19
// with modified portions from oF flite example;
// https://github.com/s373/ofxFlite-
// dependencies : requires poco libraries
// ofxFlite and  ofXPoco

//--------------------------------------------------------------

void ofApp::setup(){
    
    int sampleRate = 44100;
    int bufferSize = 512;
    int numBuffers = 4;
    float speed = 0.5f;
    float volume = 0.27f;
    
    for(int i=0; i<NUMV;i++){
        flite[i] = new ofxFlite();
        flite[i]->setup(sampleRate,bufferSize,"..Hello There. Try. Try Pressing the L key, to Load the File onto Network Rom.",speed + ofRandom(-0.2,0.2),volume);
    }
    
    soundStream.getDeviceList();
    soundStream.setDeviceID(1); // alter this to suit your hardware, sound output device
    soundStream.setup(this, 2, 0, sampleRate, bufferSize, numBuffers);
    
    ofSetFrameRate(30);
    ofSetWindowTitle("ofxFlite~ choir");
    
}
//--------------------------------------------------------------

void ofApp::update(){
    
    if(ofGetMousePressed(0)){
        float s = (float)ofGetMouseX() / (ofGetWidth()/2);
        float locmin = (float) ofGetMouseX() / ofGetWidth();
        float locmax = locmin + (float) ofGetMouseY() / ofGetHeight();
        
        for(int i=0; i<NUMV;i++){
            flite[i]->setSpeakSpeed( s +ofRandom(s) )->setMinMaxBufferLoc(locmin,locmax)   ;
        }
        
    }
    
    // wave voices volumes
    for(int i=0; i<NUMV;i++){
        float v = cosf(ofGetElapsedTimef()*0.25 + i*TWO_PI/10.0f) * 0.5 + 0.5;
        flite[i]->setVolume( v);
    }
    
}

//--------------------------------------------------------------

void ofApp::keyPressed(int key){
    
    if(key=='l'){
        
        for(int i=0; i<NUMV;i++){
            flite[i]->loadFile("cyberspace.txt")  ;
        }
    }
}
//--------------------------------------------------------------

void ofApp::draw(){
    
    ofSetColor(255);
    
    for(int i=0; i<NUMV; i++){
        
        ofSetColor( 100, 200, 72);
        flite[i]->draw(100, 400 + i*12, 100);
        
        if(flite[i]->isThreadRunning()){
            ofSetColor(0,255,0);
        }else {
            ofSetColor(255,0,0);
        }
        ofDrawRectangle(50,10 + i * 27,25,25);
        
    }
}
//--------------------------------------------------------------

void ofApp::audioOut(float * outpt, int bufferSize, int nChannels){
    float * audiosys[NUMV];
    
    for (int i = 0; i < bufferSize; i++){
        outpt[i*nChannels    ] = 0.0f ;
        outpt[i*nChannels + 1] =  0.0f ;
    }
    
    for(int k=0; k<NUMV;k++){
        audiosys[k] = flite[k]->processBuffer();
        
        for (int i = 0; i < bufferSize; i++){
            outpt[i*nChannels    ] += audiosys[k][i] ;
            outpt[i*nChannels + 1] +=  audiosys[k][i] ;
        }
    }
}
