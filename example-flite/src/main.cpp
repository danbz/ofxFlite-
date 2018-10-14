#include "ofMain.h"
#include "ofApp.h"

#include "flite.h"
extern "C"
{ // c declares
    cst_voice* register_cmu_us_kal(); // you can change this to select a different voice
    cst_voice* register_cmu_us_kal16();// other voices available
    cst_voice* register_cmu_us_awb();
    cst_voice* register_cmu_us_rms();
    cst_voice* register_cmu_us_slt();
    
}

//========================================================================
int main( ){
    ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context
    
    // this kicks off the running of my app
    // can be OF_WINDOW or OF_FULLSCREEN
    // pass in width and height too:
    ofRunApp(new ofApp());
    
    cst_voice *v;
    flite_init();
    v=register_cmu_us_kal();
    flite_text_to_speech("hello world, how are you?",v,"play");
    return 0;
    
}
