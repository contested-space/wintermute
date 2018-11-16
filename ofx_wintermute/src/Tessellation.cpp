#include "Tessellation.h"
//#include "TileMatrix.h"

Tessellation::Tessellation(){

}

void Tessellation::update(Tile** tm, int matrix_width, int matrix_height){

}

tessStaticPoint::tessStaticPoint(){

}

void tessStaticPoint::update(Tile** tm, int matrix_width, int matrix_height){
  if (!morphing){
    //cout << "update!" << endl;
    //std::cout << center_x << "static_point " << center_y <<  " radius: " << radius << endl;
    int minWidth = ((center_x - radius >= 0) ? center_x - radius  : 0 );
    //std::cout << minWidth << endl;
    int maxWidth = ((center_x + radius < matrix_width) ? center_x + radius : matrix_width - 1);
    //std::cout << maxWidth << endl;
    int minHeight = ((center_x - radius >= 0) ? center_y - radius  : 0);
    //std::cout << minHeight << endl;
    int maxHeight = ((center_x + radius < matrix_height) ? center_y + radius : matrix_height - 1);
    //std::cout << minHeight << endl;
    for (int i = minWidth; i<matrix_width; i++){
      // step through vertically
      for (int j=minHeight; j<maxHeight; j++ ){
	float delta = sqrt(pow(i - center_x, 2.0) + pow(j - center_y, 2.0));
	if (delta < radius){
	  //       	tm[i][j].switch_to_target_probability *= pow(delta/(float) radius, exp);
	  float previous_prob = tm[i][j].switch_to_target_probability;
	  tm[i][j].switch_to_target_probability = ofLerp(1.0, previous_prob, delta);
	  tm[i][j].switch_from_target_probability = 0.2;	  
	  //       	matrix[i][j].switchProbability *= (delta / radius);
	  //matrix[i][j].switchProbability *= (delta / radius);
	  //	std::cout << matrix[i][j].switchProbability<< endl;
	  //	std::cout << delta / radius << endl;
	  //std::cout << matrix[i][j].switchProbability << endl;
	}
      }
    }
  }
  else {
    float delta =((float) (ofGetElapsedTimeMillis() - start_time)) /((float) (end_time - start_time));
    int new_center_x = (int) ofLerp(start_state->center_x, end_state->center_x, delta);
    int new_center_y = (int) ofLerp(start_state->center_y, end_state->center_y, delta);
    int new_radius = (int) ofLerp(start_state->radius, end_state->radius, delta);
    float new_exp = ofLerp(start_state->exp, end_state->exp, delta);
      
    int minWidth = ((new_center_x - new_radius >= 0) ? new_center_x - new_radius  : 0 );
    //std::cout << minWidth << endl;
    int maxWidth = ((new_center_x + new_radius < matrix_width) ? new_center_x + new_radius : matrix_width - 1);
    //std::cout << maxWidth << endl;
    int minHeight = ((new_center_x - new_radius >= 0) ? new_center_y - new_radius  : 0);
    //std::cout << minHeight << endl;
    int maxHeight = ((new_center_x + new_radius < matrix_height) ? new_center_y + new_radius : matrix_height - 1);
    //std::cout << minHeight << endl;
    for (int i = minWidth; i<matrix_width; i++){
      // step through vertically
      for (int j=minHeight; j<maxHeight; j++ ){
	float delta = sqrt(pow(i - new_center_x, 2.0) + pow(j - new_center_y, 2.0));
	if (delta < new_radius){
	  //       	tm[i][j].switch_to_target_probability *= pow(delta/(float) radius, exp);
	  //tm[i][j].switch_to_target_probability = 1;
	  float previous_prob = tm[i][j].switch_to_target_probability;
	  tm[i][j].switch_to_target_probability = ofLerp(previous_prob, 1.0, delta);
	  tm[i][j].switch_from_target_probability = 0.2;	  
	  //       	matrix[i][j].switchProbability *= (delta / radius);
	  //matrix[i][j].switchProbability *= (delta / radius);
	  //	std::cout << matrix[i][j].switchProbability<< endl;
	  //	std::cout << delta / radius << endl;
	  //std::cout << matrix[i][j].switchProbability << endl;
	}
      }
    }
    if (ofGetElapsedTimeMillis() > end_time){
      morphing = false;
    }
  }
  
}

void tessStaticPoint::morph_into(tessStaticPoint *sp, float dur){
  morphing = true;
  start_time = ofGetElapsedTimeMillis();
  end_time = start_time + (int) round(dur * 1000);
  start_state = new tessStaticPoint();
  start_state->setup(center_x, center_y, radius, exp);
  end_state = sp;
}

void Tessellation::setup(){
}

void tessStaticPoint::setup(int coord_x, int coord_y, int _radius, float _exp){
  //cout << "static point setup" << endl;
  center_x = coord_x;
  center_y = coord_y;
  radius = _radius;
  exp = _exp;
  
}
