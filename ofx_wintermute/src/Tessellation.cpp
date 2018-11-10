#include "Tessellation.h"
//#include "TileMatrix.h"

Tessellation::Tessellation(){

}

void Tessellation::update(Tile** tm, int matrix_width, int matrix_height){

}

tessStaticPoint::tessStaticPoint(){

}

void tessStaticPoint::update(Tile** tm, int matrix_width, int matrix_height){
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
       	tm[i][j].switch_to_target_probability = 1;	
	//       	matrix[i][j].switchProbability *= (delta / radius);
	//matrix[i][j].switchProbability *= (delta / radius);
	//	std::cout << matrix[i][j].switchProbability<< endl;
	//	std::cout << delta / radius << endl;
	//std::cout << matrix[i][j].switchProbability << endl;
      }
    }
  }
  
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
