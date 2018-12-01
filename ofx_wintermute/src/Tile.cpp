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

void Tile::set_target(char target, float sttp, float sftp){
  switch_to_target_probability = sttp;
  switch_from_target_probability = sftp;
  target_state = target;
}

void Tile::update(){
  if (target_state == DONT_CARE){
    roll_DONT_CARE();
  }
  else if (state == target_state){
    //cout << (int)state << " " << (int)target_state << endl;
    roll_switch_from_target();
  }
  else {
    roll_switch_to_target();
    //cout <<"from" << endl;
  }

  
  // if (state & target_state){
  //   roll_switch_from_target();
  // }
  // else {
  //   roll_switch_to_target();
}

void Tile::roll_DONT_CARE(){
  if (ofRandom(1.0) < (switch_from_target_probability < switch_to_target_probability ?
		       switch_from_target_probability :
		       switch_to_target_probability)){
    previous_state = state;
    state = ~state;
  }
}

void Tile::roll_switch_from_target(){
  //cout << "FROM()" << endl;
  if (ofRandom(1.0) < switch_from_target_probability) {
    previous_state = state;
    state = ~target_state;
  }
}

void Tile::roll_switch_to_target(){
  //cout << "TO()" << endl;
  if (ofRandom(1.0) < switch_to_target_probability) {
    previous_state = state;
    state = target_state;;
  }
}
  
void Tile::draw(int horizontal_step, int vertical_step){
  ofSetColor((state & ALIVE) ? ofColor(0, 0, 0) : ofColor(255, 255, 255));
  ofDrawRectangle(x * horizontal_step, y * vertical_step, horizontal_step, vertical_step  );
  
}
