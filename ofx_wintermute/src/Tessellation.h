#ifndef _TESSELLATION
#define _TESSELLATION

#include "ofMain.h"

class Tessellation {
  public:
  Tessellation();
  void setup();
  void update();

  private:
};

class tessBackground : public Tessellation {
  public:
  void set_state(char state);
};



#endif

