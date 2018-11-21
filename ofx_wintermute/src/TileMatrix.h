#ifndef _TILEMATRIX
#define _TILEMATRIX

#include "ofMain.h"
#include "Tessellation.h"
#include "Tile.h"

class TileMatrix {
  public:

  float switch_rate;
  void setup(int, int);
  void update();
  void draw();
  
  
  TileMatrix();
  Tile get_tile(int x, int y);
  void add_tessellation(Tessellation *t);

  private:
  Tile** matrix;
  int height;
  int width;  
  int switch_speed;
  vector<Tessellation*> tess_vector;
  tessBackground background;
  
};

#endif
