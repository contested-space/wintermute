#ifndef _TILE
#define _TILE

#include"ofMain.h"



class Tile {
  public:
  
  static const char DEAD = 1;
  static const char ALIVE = 2;
  static const char DONT_CARE = 3;
  void setup(int, int, char, char, float);
  void update();
  void draw(int horizontal_step, int vertival_step);

  int x;
  int y;
  float switch_to_target_probability;
  char target_state;
  char state;
  

  Tile();

  private:
  //char next_state;
  void roll_switch_from_target();
  void roll_switch_to_target();
  //float switch_from_target_probability; //?

};
  
#endif
