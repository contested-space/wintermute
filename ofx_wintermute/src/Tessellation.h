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
  tessBackground();
  void setup(Tile** tm, int matrix_width, int matrix_height, int pttrn);
  void update(Tile** tm, int width, int height);
  int pattern;
  char target_state;
  float switch_to_target;
  float switch_from_target;
  void setup_snow(char target, float stt, float sft);
  
  void set_state(char state);
};

class tessStaticPoint : public Tessellation {
  public:
  tessStaticPoint();
  virtual void setup(int coord_x,
		     int coord_y,
		     int _radius,
		     char _state,
		     float _to,
		     float _from,
		     float  _exp);
  virtual void update(Tile** tm, int matrix_width, int matrix_height);
  virtual void morph_into(tessStaticPoint *sp, float dur);
  int center_x;
  int center_y;
  int radius;
  float exp;
  char state;
  float switch_to_target_state;
  float switch_from_target_state;
  
  private:
  tessStaticPoint *start_state;
  tessStaticPoint *end_state;

  
  uint64_t start_time;
  uint64_t end_time;
  bool morphing;

};



#endif

