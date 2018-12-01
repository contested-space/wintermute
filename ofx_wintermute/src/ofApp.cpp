#include "ofApp.h"
#include "Tile.h"
#include "TileMatrix.h"
#include "Tessellation.h"

//const int matrix_width = 320;
//const int matrix_height= 180;

const int matrix_width = 160;
const int matrix_height= 90;

int loop = 0;

TileMatrix tile_matrix;

int horizontal_step;
int vertical_step;


//--------------------------------------------------------------
void ofApp::setup(){
  //cout << "1"<< endl;
  tile_matrix.setup(matrix_width, matrix_height);
    //cout << "2"<< endl;
  tessStaticPoint *sp = new tessStaticPoint();
    //cout << "3"<< endl;
  sp->setup(30, 45, 40, Tile::DEAD, 0.1, 0.0, 0.5);
    //cout << "4"<< endl;
  //tessStaticPoint *sp2 = new tessStaticPoint();
  //sp2->setup(240, 45, 20, 1.0);
  tessStaticPoint *np = new tessStaticPoint();
  np->setup(130, 45, 40, Tile::DEAD, 0.1, 0.0, 0.5);
  sp->morph_into(np, 20.0);
  tile_matrix.add_tessellation(sp);
  // //tile_matrix.add_tessellation(sp2);

  // tessStaticPoint *sp1 = new tessStaticPoint();
  // sp1->setup(80, 45, 20, Tile::ALIVE, 0.01, 0.001, 1.0);
  // //tessStaticPoint *sp2 = new tessStaticPoint();
  // //sp2->setup(240, 45, 20, 1.0);
  // tessStaticPoint *np1 = new tessStaticPoint();
  // np1->setup(145, 45, 10, Tile::ALIVE, 0.1, 0.1, 0.7);
  // sp1->morph_into(np1, 5.0);
  // tile_matrix.add_tessellation(sp1);

  // tessStaticPoint *sp2 = new tessStaticPoint();
  // sp2->setup(15, 45, 10, Tile::ALIVE, 0.00, 0.0, 0.0);
  // //tessStaticPoint *sp2 = new tessStaticPoint();
  // //sp2->setup(240, 45, 20, 1.0);
  // tessStaticPoint *np2 = new tessStaticPoint();
  // np2->setup(15, 80, 10, Tile::ALIVE, 0.1, 0.1, 1.0);
  // sp2->morph_into(np2, 20.0);
  // tile_matrix.add_tessellation(sp2);

  // tessStaticPoint *sp3 = new tessStaticPoint();
  // sp3->setup(15, 45, 10, Tile::ALIVE, 0.1, 0.001, 1.0);
  // //tessStaticPoint *sp2 = new tessStaticPoint();
  // //sp2->setup(240, 45, 20, 1.0);
  // tessStaticPoint *np3 = new tessStaticPoint();
  // np3->setup(15, 10, 10, Tile::ALIVE, 0.3, 0.1, 0.0);
  // sp3->morph_into(np3, 20.0);
  // tile_matrix.add_tessellation(sp3);


  // tessStaticPoint *sp4 = new tessStaticPoint();
  // sp4->setup(80, 45, 10, Tile::ALIVE, 0.0, 0.0, 1.0);
  // //tessStaticPoint *sp2 = new tessStaticPoint();
  // //sp2->setup(240, 45, 20, 1.0);
  // tessStaticPoint *np4 = new tessStaticPoint();
  // np4->setup(80, 45, 45, Tile::ALIVE, 0.003, 0.001, 0.5);
  // sp4->morph_into(np4, 45.0);
  // tile_matrix.add_tessellation(sp4);


  
  horizontal_step = ofGetWindowWidth()/matrix_width;
  vertical_step = ofGetWindowHeight()/matrix_height;

  ofEnableSmoothing();
  ofEnableAlphaBlending();
  ofSetWindowTitle("Wintermute");
    
    //ofSetRectMode(OF_RECTMODE_CENTER);
    
  ofSetFrameRate(24);
  
}

/*
void static_point(pixelInfo matrix[][matrix_height],
		  int center_x, int center_y,
		  int radius, float exp){
  //std:://cout << center_x << "static_point " << center_y <<  " radius: " << radius << endl;
  int minWidth = ((center_x - radius >= 0) ? center_x - radius  : 0 );
  //std:://cout << minWidth << endl;
  int maxWidth = ((center_x + radius < matrix_width) ? center_x + radius : matrix_width - 1);
  //std:://cout << maxWidth << endl;
  int minHeight = ((center_x - radius >= 0) ? center_y - radius  : 0);
  //std:://cout << minHeight << endl;
  int maxHeight = ((center_x + radius < matrix_height) ? center_y + radius : matrix_height - 1);
  //std:://cout << minHeight << endl;
  for (int i = minWidth; i<matrix_width; i++){
  // step through vertically
    for (int j=minHeight; j<maxHeight; j++ ){
      float delta = sqrt(pow(i - center_x, 2.0) + pow(j - center_y, 2.0));
      if (delta < radius){
       	matrix[i][j].switchProbability *= pow(delta/(float) radius, exp);
	//       	matrix[i][j].switchProbability *= (delta / radius);
	//matrix[i][j].switchProbability *= (delta / radius);
	//	std:://cout << matrix[i][j].switchProbability<< endl;
	//	std:://cout << delta / radius << endl;
	//std:://cout << matrix[i][j].switchProbability << endl;
      }
    }
  }
}
*/
//--------------------------------------------------------------
void ofApp::update(){
  tile_matrix.update();
  //int maxVal = matrix_width * matrix_height;

  //static_point(info_matrix, 80, 45, 12, 1.0);
  //static_point(info_matrix, 10, 45, 25, 2.0);
  //static_point(info_matrix, 90, 69, 10, 5.0);
  //static_point(info_matrix, 100, 50, 5, 10.0);

}

//--------------------------------------------------------------
void ofApp::draw(){

    // step through horizontally
  for ( int i=0; i<matrix_width; i++){
    // step through vertically
    for ( int j=0; j<matrix_height; j++ ){
      tile_matrix.get_tile(i, j).draw(horizontal_step, vertical_step);
      
    }
  
  }
}


//void 

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
  if (loop == 0){
    tile_matrix.background.pattern = 0;
    tile_matrix.clear_tessellations();
    tessStaticPoint *sp1 = new tessStaticPoint();
    sp1->setup(145, 45, 20, Tile::ALIVE , 0.01, 0.01, 1.0);
    //tessStaticPoint *sp2 = new tessStaticPoint();
    //sp2->setup(240, 45, 20, 1.0);
    tessStaticPoint *np1 = new tessStaticPoint();
    np1->setup(80 , 45, 10, Tile::ALIVE , 0.001, 0.1, 0.7);
    sp1->morph_into(np1, 7.0);
    tile_matrix.add_tessellation(sp1);

    tessStaticPoint *sp2 = new tessStaticPoint();
    sp2->setup(15, 45, 10, Tile::ALIVE , 0.01, 0.1, 0.0);
    //tessStaticPoint *sp2 = new tessStaticPoint();
    //sp2->setup(240, 45, 20, 1.0);
    tessStaticPoint *np2 = new tessStaticPoint();
    np2->setup(80, 45, 10, Tile::ALIVE , 0.01, 0.1, 1.0);
    sp2->morph_into(np2, 7.0);
    tile_matrix.add_tessellation(sp2);

    tessStaticPoint *sp3 = new tessStaticPoint();
    sp3->setup(80, 45, 0, Tile::ALIVE , 0.01, 0.1, 0.0);
    //tessStaticPoint *sp2 = new tessStaticPoint();
    //sp2->setup(240, 45, 20, 1.0);
    tessStaticPoint *np3 = new tessStaticPoint();
    np3->setup(80, 45, 45, Tile::ALIVE , 0.5, 0.5, 1.0);
    sp3->morph_into(np3, 15.0);
    tile_matrix.add_tessellation(sp3);

    
    loop = 1;
  }
  else {
    tile_matrix.clear_tessellations();
  }
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
