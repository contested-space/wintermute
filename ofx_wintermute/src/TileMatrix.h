#ifndef _TILEMATRIX
#define _TILEMATRIX

#include "ofMain.h"
#include "Tessellation.h"
#include "Tile.h"

class TileMatrix {
  public:

  float switch_rate;
  void setup(int _width, int _height);
  void update();
  void draw();
  tessBackground background;
  vector<Tessellation> tess_vector;
  TileMatrix();
  Tile get_tile(int x, int y);

  private:
  Tile** matrix;
  int height;
  int width;  
  int switch_speed;

};

#endif
