#ifndef _TESSELLATION
#define _TESSELLATION

#include "ofMain.h"
//#include "TileMatrix.h"
#include "Tile.h"

class Tessellation {
  public:
  Tessellation();
  virtual void setup();
  virtual void update(Tile** tm, int matrix_width, int matrix_height);

  private:
};

class tessBackground : public Tessellation {
  public:
  void set_state(char state);
};

class tessStaticPoint : public Tessellation {
  public:
  tessStaticPoint();
  virtual void setup(int coord_x, int coord_y, int _radius, float  _exp);
  virtual void update(Tile** tm, int matrix_width, int matrix_height);

  private:
  int center_x;
  int center_y;
  int radius;
  float exp;
};



#endif

