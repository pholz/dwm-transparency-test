#include "transparencyTest.h"


//--------------------------------------------------------------
void transparencyTest::setup(){

	angle = .0f;
	scale = 1.0f;
	ofSetSmoothLighting(true);
    pointLight.setDiffuseColor( ofFloatColor(.85, .85, .55) );
    pointLight.setSpecularColor( ofFloatColor(1.f, 1.f, 1.f));

	
	HWND wnd = GetActiveWindow();// WindowFromDC(wglGetCurrentDC()); 

	EnableBlurBehind(wnd);
}

HRESULT transparencyTest::EnableBlurBehind(HWND hwnd)
{
	DWORD style = ::GetWindowLong(hwnd, GWL_STYLE);
	style &= ~WS_OVERLAPPEDWINDOW;
	style |= WS_POPUP;
	::SetWindowLong(hwnd, GWL_STYLE, style);



    HRESULT hr = S_OK;

    // Create and populate the blur-behind structure.
    DWM_BLURBEHIND bb = {0};

	

    // Specify blur-behind and blur region.
	bb.dwFlags = DWM_BB_ENABLE | DWM_BB_BLURREGION;
    bb.fEnable = true;
	bb.hRgnBlur = CreateRectRgn(0, 0, 1, 1);


    // Enable blur-behind.
	
    hr = DwmEnableBlurBehindWindow(hwnd, &bb);
    if (SUCCEEDED(hr))
    {
        // ...
		int x = 0;
    }
    return hr;
}

//--------------------------------------------------------------
void transparencyTest::update(){

	pointLight.setPosition((ofGetWidth()*.5)+ cos(ofGetElapsedTimef()*.5)*(ofGetWidth()*.3), ofGetHeight()/2, 500);

	int mx = this->mouseX;
	int my = this->mouseY;

	angle = PI * static_cast<float>(mx) / 100.0f;
	scale = static_cast<float>(my) / 100.0f;
}

//--------------------------------------------------------------
void transparencyTest::draw(){
	ofEnableAlphaBlending();
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	ofEnableDepthTest();
	ofEnableLighting();
    pointLight.enable();

	ofClear(0,0);

	glColor3f(1.0f, .0f, .0f);

	ofPushMatrix();
	ofTranslate(ofPoint(ofGetWidth()/2, ofGetHeight()/2, 0.0f));
	ofRotateY(angle * RAD_TO_DEG);
	ofScale(scale, scale, scale);
	ofDrawBox(ofPoint(0), 100.0f);
	ofPopMatrix();

}

//--------------------------------------------------------------
void transparencyTest::keyPressed(int key){

}

//--------------------------------------------------------------
void transparencyTest::keyReleased(int key){

}

//--------------------------------------------------------------
void transparencyTest::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void transparencyTest::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void transparencyTest::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void transparencyTest::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void transparencyTest::windowResized(int w, int h){

}

//--------------------------------------------------------------
void transparencyTest::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void transparencyTest::dragEvent(ofDragInfo dragInfo){ 

}
