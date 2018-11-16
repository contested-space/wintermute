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
  virtual void morph_into(tessStaticPoint *sp, float dur);
  int center_x;
  int center_y;
  int radius;
  float exp;

  private:
  tessStaticPoint *start_state;
  tessStaticPoint *end_state;
  uint64_t start_time;
  uint64_t end_time;
  bool morphing;

};



#endif

