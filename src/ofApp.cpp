#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    animRate = 10;
    x = y =0;
    width = height = 50;
}

//--------------------------------------------------------------
void ofApp::update(){
    float now = ofGetElapsedTimef();
    float time_difference = now - lastUpdate;
    lastUpdate = now;
    frequency = ofMap(mouseX, 0, ofGetWidth(), -10, 10);
    
    phase += time_difference*frequency;
    
    animRate =phase *ofGetElapsedTimef();

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor::gray, ofColor::black);
    ofDrawBitmapString("Freq=" + ofToString(frequency), 20, 20);
    
    
    //phase += time_difference * frequency
    //signal = sin(phase)
    
    //Draw background lines
    ofSetColor(255);
    for (int i =0; i<ofGetHeight(); i=i+100){
        ofDrawBitmapString("Y=" + ofToString(i), 20, i);
        ofLine(0, i, ofGetWidth(), i);
    }
    
    
    //#1-------------
    ofDrawBitmapString("Translate", 50, 50);
    ofPushMatrix();
        ofTranslate(50, 100);
        drawSpecialRect(x, y, width, height, 1);
    ofPopMatrix();
    
    //#2-------------
    ofSetColor(255);
        ofDrawBitmapString("Translate", 150, 50);
        ofDrawBitmapString("Rotate X", 150, 65);
        ofPushMatrix();
        ofTranslate(150, 100); //Initial translate
        ofRotateX(animRate); //Rotate
        drawSpecialRect(x, y, width, height, 2);
    ofPopMatrix();
    
    //#3-------------
    ofSetColor(255);
    ofDrawBitmapString("Translate", 250, 50);
    ofDrawBitmapString("Rotate X", 250, 65);
    ofDrawBitmapString("Translate", 250, 80);
    ofPushMatrix();
        ofTranslate(300, 100); //Initial translate
        ofRotateX(animRate); //Rotate
        ofTranslate(-25,-25); //offset to get center
            drawSpecialRect(x, y, width, height, 3);
    ofPopMatrix();
    
    //#4--------------
    ofSetColor(255);
    ofDrawBitmapString("Translate", 425, 50);
    ofDrawBitmapString("Rotate Y", 425, 65);
    ofPushMatrix();
        ofTranslate(450, 100);
        ofRotateY(animRate);
            drawSpecialRect(x, y, width, height, 4);
    ofPopMatrix();
    
    //#5---------------
    ofSetColor(255);
    ofDrawBitmapString("Translate", 600, 50);
    ofDrawBitmapString("Rotate Y", 600, 65);
    ofDrawBitmapString("Translate", 600, 80);
    //Translate and then rotate along Y Axis
    ofPushMatrix();
        ofTranslate(600, 100);
        ofRotateY(animRate);
        ofTranslate(-25,-25); 
            drawSpecialRect(x, y, width, height, 5);
    ofPopMatrix();
    
    //#6---------------
    ofSetColor(255);
    ofDrawBitmapString("Translate", 800, 50);
    ofDrawBitmapString("Rotate Z", 800, 65);
    ofPushMatrix();
        ofTranslate(800, 100);
        ofRotateZ(animRate);
            drawSpecialRect(x, y, width, height, 6);
    ofPopMatrix();
    
    //#7---------------
    ofSetColor(255);
    ofDrawBitmapString("Translate", 950, 50);
    ofDrawBitmapString("Rotate Z", 950, 65);
    ofDrawBitmapString("Translate", 950, 80);
    ofPushMatrix();
        ofTranslate(950, 100);
        ofRotateZ(animRate);
        ofTranslate(-25,-25); 
            drawSpecialRect(x, y, width, height, 7);
    ofPopMatrix();
    //300-----------------------------------------------
    
    //#8---------------
    //What happens if you put rotate before translate
    ofPushMatrix();
        ofRotateZ(animRate); //rotates around 0,0
        ofTranslate(50, 300);
            drawSpecialRect(x, y, width, height, 8);
    ofPopMatrix();
    
    //#9----------------
    ofSetColor(255);
    ofDrawBitmapString("Translate", 200, 230);
    ofDrawBitmapString("Rotate Y", 200, 245);
    ofDrawBitmapString("Push", 200, 260);
    ofDrawBitmapString("Translate", 200, 275);
    ofDrawBitmapString("Rotate Y", 200, 290);
    //Translate and then rotate along Y Axis
    ofPushMatrix();
        ofTranslate(200, 300);
        ofRotateY(animRate);
            drawSpecialRect(x, y, width, height, 9);
        ofPushMatrix();
            ofRotateY(animRate);
            ofTranslate(70,0);
            drawSpecialRect(x, y, width, height, 9);
        ofPopMatrix();
    ofPopMatrix();
    
    //#10----------------
    ofSetColor(255);
    ofDrawBitmapString("Translate", 500, 230);
    ofDrawBitmapString("Rotate Y", 500, 245);
    ofDrawBitmapString("Push", 500, 260);
    ofDrawBitmapString("Translate", 500, 275);
    //Translate and then rotate along Y Axis
    ofPushMatrix();
        ofTranslate(500, 300);
        ofRotateY(animRate);
            drawSpecialRect(x, y, width, height, 10);
        ofPushMatrix();
            ofTranslate(70,0);
            drawSpecialRect(x, y, width, height, 10);
        ofPopMatrix();
    ofPopMatrix();
    
    //#11-----------------
    ofSetColor(255);
    ofDrawBitmapString("Translate", 700, 230);
    ofDrawBitmapString("Rotate Y", 700, 245);
    ofDrawBitmapString("Push", 700, 260);
    ofDrawBitmapString("Translate", 700, 275);
    ofDrawBitmapString("Rotate X", 700, 290);
    //Translate and then rotate along Y Axis
    ofPushMatrix();
        ofTranslate(700, 300);
        ofRotateY(animRate);
            drawSpecialRect(x, y, width, height, 11);
        ofPushMatrix();
            ofTranslate(70,25);
            ofRotateX(-animRate);
            ofTranslate(0, -25);
            drawSpecialRect(x, y, width, height, 11);
        ofPopMatrix();
    ofPopMatrix();
    
    //600--------------------------------------
    //#12----------------
    ofSetColor(255);
    ofDrawBitmapString("Translate", 200, 530);
    ofDrawBitmapString("Rotate X", 200, 545);
    ofDrawBitmapString("Rotate Y", 200, 560);
    ofDrawBitmapString("Rotate Z", 200, 575);
    ofPushMatrix();
        ofTranslate(200, 600);
        ofRotateX(animRate);
        ofRotateY(animRate);
        ofRotateZ(animRate);
        ofTranslate(-25,-25); //compensates for rotate starting around 0,0
            drawSpecialRect(x, y, width, height, 12);
    ofPopMatrix();
    
    //#13-----------------
    ofSetColor(255);
    ofDrawBitmapString("Translate", 350, 530);
    ofDrawBitmapString("Rotate X", 350, 545);
    ofDrawBitmapString("Rotate Y", 350, 560);
    ofDrawBitmapString("Rotate Z", 350, 575);
    ofDrawBitmapString("Translate", 350, 590);
    ofDrawBitmapString("Push", 350, 605);
    ofDrawBitmapString("Translate", 350, 620);
    ofDrawBitmapString("Rotate X", 350, 635);
    ofDrawBitmapString("Rotate Y", 350, 650);
    ofDrawBitmapString("Rotate Z", 350, 665);
    
    ofPushMatrix();
        ofTranslate(350, 600);
        ofRotateX(animRate);
        ofRotateY(animRate);
        ofRotateZ(animRate);
        ofTranslate(-25,-25); //compensates for rotate starting around 0,0
            drawSpecialRect(x, y, width, height, 13);
        //Lets nest another one in here
        ofPushMatrix();
            ofTranslate(0, 50);
            ofRotateX(animRate);
            ofRotateY(animRate);
            ofRotateZ(animRate);
            drawSpecialRect(x, y, width, height, 13);
        ofPopMatrix();
    ofPopMatrix();
    
    //#14--------------
    ofSetColor(255);
    ofDrawBitmapString("Translate", 500, 530);
    ofDrawBitmapString("Rotate X", 500, 545);
    ofDrawBitmapString("Rotate Y", 500, 560);
    ofDrawBitmapString("Rotate Z", 500, 575);
    ofDrawBitmapString("Translate", 500, 590);
    ofDrawBitmapString("Push", 500, 605);
    ofDrawBitmapString("Translate", 500, 620);
    ofDrawBitmapString("-Rotate Z", 500, 635);
    ofDrawBitmapString("-Rotate Y", 500, 650);
    ofDrawBitmapString("-Rotate X", 500, 665);
    
    ofPushMatrix();
        ofTranslate(500, 600);
        ofRotateX(animRate);
        ofRotateY(animRate);
        ofRotateZ(animRate);
        
        ofTranslate(-25,-25); //compensates for rotate starting around 0,0
        drawSpecialRect(x, y, width, height, 14);
            ofPushMatrix();
                ofTranslate(0, 70);
                //If you want to counteract the rotation, you have to go backwards to nullify each one 
                //(ie the matrix above this goes X,Y,Z and then you can reverse that by going opposite rotation in Z,then Y then X.
                //
                ofRotateZ(-animRate);
                ofRotateY(-animRate);
                ofRotateX(-animRate);
                drawSpecialRect(x, y, width, height, 14);
            ofPopMatrix();
    ofPopMatrix();
    
    //#15---------------
    ofSetColor(255);
    ofDrawBitmapString("Translate", 700, 530);
    ofDrawBitmapString("Rotate X", 700, 545);
    ofDrawBitmapString("Rotate Y", 700, 560);
    ofDrawBitmapString("Rotate Z", 700, 575);
    ofDrawBitmapString("Translate", 700, 590);
    ofDrawBitmapString("Push", 700, 605);
    ofDrawBitmapString("Translate", 700, 620);
    ofDrawBitmapString("-Rotate Z", 700, 635);
    ofDrawBitmapString("-Rotate Y", 700, 650);
    ofDrawBitmapString("-Rotate X", 700, 665);
    ofDrawBitmapString("Push", 700, 680);
    ofDrawBitmapString("Translate", 700, 695);
    ofDrawBitmapString("Rotate X", 700, 710);
    ofDrawBitmapString("Rotate Z", 700, 725);
    ofPushMatrix();
        ofTranslate(700, 600);
        ofRotateX(animRate);
        ofRotateY(animRate);
        ofRotateZ(animRate);
        
        ofTranslate(-25,-25); //compensates for rotate starting around 0,0
        drawSpecialRect(x, y, width, height, 15);
        ofPushMatrix();
            ofTranslate(0, 70);
            //If you want to counteract the rotation of the "outer" matrix, you have to go backwards to nullify each one 
            //(ie the matrix above this goes X,Y,Z and then you can reverse that by going opposite rotation in Z,then Y then X.
            ofRotateZ(-animRate);
            ofRotateY(-animRate);
            ofRotateX(-animRate);
            drawSpecialRect(x, y, width, height, 15);
            ofPushMatrix();
                ofTranslate(70, 0);
                ofRotateX(animRate);
                ofRotateZ(animRate);
        drawSpecialRect(x, y, width/2, height/2, 15);
            ofPopMatrix();
        ofPopMatrix();
    ofPopMatrix();
}

void ofApp::drawSpecialRect(int x,int y, int w, int h, int iden){
    ofSetColor(255);
    ofRect(x, y, w, h);
    ofSetColor(0);
    ofLine(x,w/2,w/2,h/2);
    ofSetColor(255,0,0);
    ofLine(w/2,y,w/2,h/2);
    ofDrawBitmapString(ofToString(iden), width/2, height/2);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}