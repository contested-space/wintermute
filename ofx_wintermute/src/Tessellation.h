#ifndef _TESSELLATION
#define _TESSELLATION

#include "ofMain.h"
//#include "TileMatrix.h"
#include "Tile.h"


char state_lerp(char, char, float);

class Tessellation {
  public:
  Tessellation();
  virtual void setup();
  virtual void update(Tile** tm, int matrix_width, int matrix_height);
  virtual void morph_into();
  char target_state;
  bool morphing;
  
};

class tessBackground : public Tessellation {
  public:
  tessBackground();
  void setup(Tile** tm, int matrix_width, int matrix_height, int pttrn);
  void update(Tile** tm, int width, int height);
  int pattern;
  //char target_state;
  float switch_to_target;
  float switch_from_target;
  void setup_snow(char target, float stt, float sft);
  void morph_into();
  //char state;
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

};

class tessStaticLine : public Tessellation {
  public:
  tessStaticLine();
  virtual void update(Tile** tm, int matrix_width, int matrix_height);
  virtual void setup(int coordX_0, int coordY_0,
		     int coordX_1, int coordY_1,
		     int _width,
		     char _state,
		     float _to,
		     float _from,
		     float _exp);
  void morph_into(tessStaticLine *st, float dur);
  int x_0;
  int y_0;
  int x_1;
  int y_1;
  int width;
  char state;
  float switch_to_target_state;
  float switch_from_target_state;
  float exp;

  private:
  tessStaticLine *start_state;
  tessStaticLine *end_state;

  uint64_t start_time;
  uint64_t end_time;

};

float distance_from_center(int x, int y, int center_x, int center_y);
float distance_from_line(int x, int y, int line_x0, int line_x1, int line_y0, int line_y1);

#endif
