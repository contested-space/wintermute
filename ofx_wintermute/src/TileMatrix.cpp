#include "TileMatrix.h"

void TileMatrix::setup(int _width, int _height){
  width = _width;
  height = _height;
  matrix = new Tile*[width];
  for (int i = 0; i < width; i++){
    matrix[i] = new Tile[height];
    for (int j = 0; j < height; j++){
      matrix[i][j].setup(i, j, Tile::DEAD, Tile::ALIVE, 0.5);
    }
  }
  
}

//void TileMatrix::

Tile TileMatrix::get_tile(int x, int y){
  return matrix[x][y];
}

TileMatrix::TileMatrix(){

}

void TileMatrix::add_tessellation(Tessellation *t){
  tess_vector.push_back(t);
  //cout << "pushed!" <<endl;
}

void TileMatrix::update(){
  //replace with background.update()
  for ( int i=0; i<width; i++){
  // step through vertically
    for ( int j=0; j<height; j++ ){
      //tile_matrix[i][j].switchProbability(0.5);
      matrix[i][j].update();
    }
  }
  //cout << "size: " << tess_vector.size() << endl;
  for (size_t i = 0; i < tess_vector.size(); i++){
    //cout << "for once!" << endl;
    tess_vector[i]->update(matrix, width, height);
  }
  
}

