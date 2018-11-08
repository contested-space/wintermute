#include "ofApp.h"
#include "Tile.h"

//const int matrixWidth = 320;
//const int matrixHeight= 180;

const int matrixWidth = 160;
const int matrixHeight= 90;


typedef struct pixelInfo{
  float switchProbability = 0;
  float weight = 0;
  int range = 0;
  int state = 0;
} pixelInfo;



ofColor color_matrix[matrixWidth][matrixHeight];
//pixelInfo info_matrix[matrixWidth][matrixHeight];

Tile tile_matrix[matrixWidth][matrixHeight];



int horizontal_step;
int vertical_step;




//--------------------------------------------------------------
void ofApp::setup(){
  int maxVal = matrixWidth * matrixHeight;
  
  horizontal_step = ofGetWindowWidth()/matrixWidth;
  vertical_step = ofGetWindowHeight()/matrixHeight;

  for ( int i=0; i<matrixWidth; i++){
    // step through vertically
    for ( int j=0; j<matrixHeight; j++ ){
      //pixelInfo p;
      //Tile t = new Tile(i, j, Tile::DEAD, Tile::ALIVE, 0.5);
      // t.switchProbability = ((float) i  / matrixWidth);
      //p.switchProbability = ((i * j) % 2 == 0 ? 0.0 : ((float) (i * j)/maxVal));
      //p.switchProbability = 0.5;
      //tile_matrix[i][j] = t;
      tile_matrix[i][j].setup(i, j, Tile::DEAD, Tile::ALIVE, 0.999);
    }
  }  
  
  
  //ofBackground(255,255,255);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
  ofSetWindowTitle("Wintermute");
    
    //ofSetRectMode(OF_RECTMODE_CENTER);
    
  ofSetFrameRate(60); // if vertical sync is off, we can go a bit fast... this caps the framerate at 60fps.
    
    // initialise member variables to the centre of the screen
    //mouseXPercent = 0.5f;
    //mouseYPercent = 0.5f;

}

/*
void matrix_iterator(pixelInfo *matrix, void * funPtr){
  for (int i = 0; i<matrixWidth; i++){
    for (int j=0; j<matrixHeight; j++){
      matrix[i][j] = fun(i, j);
    }
  }
}
*/

void static_point(pixelInfo matrix[][matrixHeight],
		  int center_x, int center_y,
		  int radius, float exp){
  //std::cout << center_x << "static_point " << center_y <<  " radius: " << radius << endl;
  int minWidth = ((center_x - radius >= 0) ? center_x - radius  : 0 );
  //std::cout << minWidth << endl;
  int maxWidth = ((center_x + radius < matrixWidth) ? center_x + radius : matrixWidth - 1);
  //std::cout << maxWidth << endl;
  int minHeight = ((center_x - radius >= 0) ? center_y - radius  : 0);
  //std::cout << minHeight << endl;
  int maxHeight = ((center_x + radius < matrixHeight) ? center_y + radius : matrixHeight - 1);
  //std::cout << minHeight << endl;
  for (int i = minWidth; i<matrixWidth; i++){
  // step through vertically
    for (int j=minHeight; j<maxHeight; j++ ){
      float delta = sqrt(pow(i - center_x, 2.0) + pow(j - center_y, 2.0));
      if (delta < radius){
       	matrix[i][j].switchProbability *= pow(delta/(float) radius, exp);
	//       	matrix[i][j].switchProbability *= (delta / radius);
	//matrix[i][j].switchProbability *= (delta / radius);
	//	std::cout << matrix[i][j].switchProbability<< endl;
	//	std::cout << delta / radius << endl;
	//std::cout << matrix[i][j].switchProbability << endl;
      }
    }
  }
}

//--------------------------------------------------------------
void ofApp::update(){
  int maxVal = matrixWidth * matrixHeight;
  
  for ( int i=0; i<matrixWidth; i++){
  // step through vertically
    for ( int j=0; j<matrixHeight; j++ ){
      //tile_matrix[i][j].switchProbability(0.5);
      tile_matrix[i][j].update();
    }
  }
  
  //static_point(info_matrix, 80, 45, 12, 1.0);
  //static_point(info_matrix, 10, 45, 25, 2.0);
  //static_point(info_matrix, 90, 69, 10, 5.0);
  //static_point(info_matrix, 100, 50, 5, 10.0);

}

ofColor select_color(pixelInfo p){
  ofColor c;
  if (rand()%100 < p.switchProbability * 100){
    if (p.state != 0){
      p.state = 1;
      c.r = 0;
      c.g = 0;
      c.b = 0;
    }
    else {
      p.state = 0;
      c.r = 255;
      c.g = 255;
      c.b = 255;
    }
  }
  else {
    if (p.state != 0){
      //p.state = DEAD;
      c.r = 255;
      c.g = 255;
      c.b = 255;
    }
    else {
      //p.state = ALIVE
      c.r = 0;
      c.g = 0;
      c.b = 0;
    }    
  }
  return c;
}

//--------------------------------------------------------------
void ofApp::draw(){

    // step through horizontally
  for ( int i=0; i<matrixWidth; i++){
    // step through vertically
    for ( int j=0; j<matrixHeight; j++ ){
      tile_matrix[i][j].draw(horizontal_step, vertical_step);
      
    }
  
  }
}


//void 

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased  (int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    // update mouse x and y percent when the mouse moves
    mouseXPercent = float(x) / ofGetWidth();
    mouseYPercent = float(y) / ofGetHeight();
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
