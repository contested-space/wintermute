#include "TileMatrix.h"
#include "ofApp.h"

void TileMatrix::setup(int matrix_width, int matrix_height){
  width = matrix_width;
  height = matrix_height;
  //Tile** matrix = new Tile[matrix_width][matrix_height];
  matrix = new Tile*[matrix_width];
  
  for (int i = 0; i < matrix_width; i++){
    matrix[i] = new Tile[matrix_height];
    /*
    for (int j = 0; j < matrix_height; j++){
      //matrix[i][j] = new Tile();
      matrix[i][j].setup(i, j, Tile::DEAD, Tile::ALIVE, 0.5, 0.5);
      //matrix[i][j].update();
    }
    */
  }
  
  
  //background = new tessBackground();
  //cout << "1.1" <<endl;
  tessBackground background;
  //cout << "1.1.1" <<endl;
  background.setup(matrix, width, height, 1);
  //cout << "1.2" <<endl;
  for (int i = 0; i<matrix_width; i++){
    for (int j = 0; j < matrix_height; j++){
      matrix[i][j].update();
    }
  }
  //cout << "1.3" <<endl;
  
}

//void TileMatrix::

Tile TileMatrix::get_tile(int x, int y){
  return matrix[x][y];
}

TileMatrix::TileMatrix(){

}

void TileMatrix::clear_tessellations(){
  tess_vector.clear();
}

void TileMatrix::add_tessellation(Tessellation *t){
  tess_vector.push_back(t);
  ////cout << "pushed!" <<endl;
}

void TileMatrix::update(){
  //replace with background.update()
  /*
  for (int i = 0; i < width; i++){
    matrix[i] = new Tile[height];
    for (int j = 0; j < height; j++){
      matrix[i][j].setup(i, j, Tile::DEAD, Tile::ALIVE, 0.5);
    }
  }
  */
  /*
  for ( int i=0; i<width; i++){
  // step through vertically
    for ( int j=0; j<height; j++ ){
      //tile_matrix[i][j].switchProbability(0.5);
      //matrix[i][j].previous_prob_to = matrix[i][j].switch_to_target_probability;
      //matrix[i][j].previous_prob_from = matrix[i][j].switch_from_target_probability;      
      //matrix[i][j].switch_to_target_probability = 0.5;
      //matrix[i][j].switch_from_target_probability = 0.5;
    }
  }
  */
  background.update(matrix, width, height);
  ////cout << "size: " << tess_vector.size() << endl;
  for (size_t i = 0; i < tess_vector.size(); i++){
    ////cout << "for once!" << endl;
    tess_vector[i]->update(matrix, width, height);
  }
  for (int i = 0; i<width; i++){
    for (int j = 0; j < height; j++){
      matrix[i][j].update();
    }
  }
  //reboucler a partir de la fin, retirer ceux qui sont terminés
  for (int i = tess_vector.size() - 1; i >= 0; i--){
    if (!tess_vector[i]->morphing){
      free(tess_vector[i]);
      tess_vector.erase(tess_vector.begin() + i);
      cout << "Element" << i << " erased" << endl;
    }
  }
  
}

