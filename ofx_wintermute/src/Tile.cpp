#include "Tile.h"

void Tile::setup(int coord_x, int coord_y,
	   char init_state,
	   char init_target_state,
	   float sttprob,
	   float sftprob){
  x = coord_x;
  y = coord_y;
  state = init_state;
  target_state = init_target_state;
  switch_to_target_probability = sttprob;
  switch_from_target_probability = sftprob;
  
}

Tile::Tile(){

}

void Tile::update(){
  if (state & target_state){
    roll_switch_from_target();
  }
  else {
    roll_switch_to_target();
  }
}

void Tile::roll_switch_from_target(){
  if (ofRandom(1.0) < switch_from_target_probability) {
    previous_state = state;
    state = ~state;
  }
}

void Tile::roll_switch_to_target(){
  if (ofRandom(1.0) < switch_to_target_probability) {
    previous_state = state;
    state = ~state;
  }
}
  
void Tile::draw(int horizontal_step, int vertical_step){
  ofSetColor((state & ALIVE) ? ofColor(0, 0, 0) : ofColor(255, 255, 255));
  ofDrawRectangle(x * horizontal_step, y * vertical_step, horizontal_step, vertical_step  );
  
}
