#include "Tessellation.h"
//#include "TileMatrix.h"

Tessellation::Tessellation(){

}

void Tessellation::update(Tile** tm, int matrix_width, int matrix_height){

}

void Tessellation::morph_into(){

}

tessStaticPoint::tessStaticPoint(){

}

tessBackground::tessBackground(){

}

void tessBackground::setup(Tile** tm, int matrix_width, int matrix_height, int pttrn){
  pattern = pttrn;
  target_state = Tile::DEAD;
  cout << "1.1.1.1" << endl;
  //cout << "1.1.1.1 w: " << matrix_width << endl;
  //cout << "1.1.1.1 h: " << matrix_height << endl;
  switch (pattern){
    case 0:
      for (int i = 0; i < matrix_width; i++){
	for (int j = 0; j < matrix_height; j++){
	  //cout << "1.1.1.2" << i << endl;
	  //cout << "1.1.1.3" << j << endl;
	  tm[i][j].setup(i, j, Tile::DONT_CARE, Tile::DONT_CARE, 0.5, 0.5);
	  //tm[i][j].set_target(Tile::DEAD, 1.0, 1.0);
	}
      }
      break;
    case 1:
      for (int i = 0; i < matrix_width; i++){
	for (int j = 0; j < matrix_height; j++){
	  //cout << "1.1.1.2" << i << endl;
	  //cout << "1.1.1.3" << j << endl;
	  tm[i][j].setup(i, j, Tile::DEAD, Tile::ALIVE, 0.5, 0.5);
	  //tm[i][j].set_target(Tile::ALIVE, 1.0, 1.0);
	}
      }
  }
}

void tessBackground::update(Tile** tm, int matrix_width, int matrix_height){
  //  cout <<"background update" << endl;
  //cout <<"pattern: " << pattern << endl;
  switch(pattern){
  case 0:
    //cout <<"pattern 0" << endl;
    for (int i = 0; i < matrix_width; i++){
      for (int j = 0; j < matrix_height; j++){
	//tm[i][j].target_state = target_state;
	tm[i][j].previous_prob_to = tm[i][j].switch_to_target_probability;
	tm[i][j].previous_prob_from = tm[i][j].switch_from_target_probability;
	tm[i][j].set_target(Tile::ALIVE, 0.0, 0.0);
	//tm[i][j].switch_to_target_probability = 1.0;
	//tm[i][j].switch_from_target_probability = 0.0;
      }
    }
    break;
  case 1:
    for (int i = 0; i < matrix_width; i++){
      for (int j = 0; j < matrix_height; j++){
	//tm[i][j].target_state = target_state;
	tm[i][j].previous_prob_to = tm[i][j].switch_to_target_probability;
	tm[i][j].previous_prob_from = tm[i][j].switch_from_target_probability;
	tm[i][j].set_target(Tile::ALIVE, 0.3, 0.3);
	//tm[i][j].switch_to_target_probability = 1.0;
	//tm[i][j].switch_from_target_probability = 0.0;
	//tm[i][j].target_state = Tile::ALIVE;
	////cout << "1.1.1.2" << i << endl;
	////cout << "1.1.1.3" << j << endl;
      }
    }
    break;

  case 2:
    for (int i = 0; i < matrix_width; i++){
      for (int j = 0; j < matrix_height; j++){
	//tm[i][j].target_state = target_state;
	tm[i][j].previous_prob_to = tm[i][j].switch_to_target_probability;
	tm[i][j].previous_prob_from = tm[i][j].switch_from_target_probability;
	if ((i + j) % 2 == 0) {
	  tm[i][j].set_target(Tile::ALIVE, 0.9, 0.0);
	}
	else {
	  tm[i][j].set_target(Tile::DEAD, 0.9, 0.0);
	}
      }
    }
    break;
  case 3:
    for (int i = 0; i < matrix_width; i++){
      for (int j = 0; j < matrix_height; j++){
	//tm[i][j].target_state = target_state;
	tm[i][j].previous_prob_to = tm[i][j].switch_to_target_probability;
	tm[i][j].previous_prob_from = tm[i][j].switch_from_target_probability;
	if (i  % 2 == 0) {
	  tm[i][j].set_target(Tile::ALIVE, 0.7, 0.0);
	}
	else {
	  tm[i][j].set_target(Tile::DEAD, 0.7, 0.0);
	}
	//tm[i][j].switch_to_target_probability = 1.0;
	//tm[i][j].switch_from_target_probability = 0.0;
	//tm[i][j].target_state = Tile::ALIVE;
	////cout << "1.1.1.2" << i << endl;
	////cout << "1.1.1.3" << j << endl;
      }
    }
    break;
  case 4:
    for (int i = 0; i < matrix_width; i++){
      for (int j = 0; j < matrix_height; j++){
	//tm[i][j].target_state = target_state;
	tm[i][j].previous_prob_to = tm[i][j].switch_to_target_probability;
	tm[i][j].previous_prob_from = tm[i][j].switch_from_target_probability;
	tm[i][j].set_target(Tile::ALIVE, 0.7, 0.0);
   
	//tm[i][j].switch_to_target_probability = 1.0;
	//tm[i][j].switch_from_target_probability = 0.0;
	//tm[i][j].target_state = Tile::ALIVE;
	////cout << "1.1.1.2" << i << endl;
	////cout << "1.1.1.3" << j << endl;
      }
    }
    break;
  case 5:
    for (int i = 0; i < matrix_width; i++){
      for (int j = 0; j < matrix_height; j++){
	//tm[i][j].target_state = target_state;
	tm[i][j].previous_prob_to = tm[i][j].switch_to_target_probability;
	tm[i][j].previous_prob_from = tm[i][j].switch_from_target_probability;
	tm[i][j].set_target(Tile::DEAD, 0.7, 0.0);

	//tm[i][j].switch_to_target_probability = 1.0;
	//tm[i][j].switch_from_target_probability = 0.0;
	//tm[i][j].target_state = Tile::ALIVE;
	////cout << "1.1.1.2" << i << endl;
	////cout << "1.1.1.3" << j << endl;
      }
    }
    break;
  case 6:
    for (int i = 0; i < matrix_width; i++){
      for (int j = 0; j < matrix_height; j++){
	//tm[i][j].target_state = target_state;
	tm[i][j].previous_prob_to = tm[i][j].switch_to_target_probability;
	tm[i][j].previous_prob_from = tm[i][j].switch_from_target_probability;
	tm[i][j].set_target(Tile::ALIVE, 0.7, 0.03);

	//tm[i][j].switch_to_target_probability = 1.0;
	//tm[i][j].switch_from_target_probability = 0.0;
	//tm[i][j].target_state = Tile::ALIVE;
	////cout << "1.1.1.2" << i << endl;
	////cout << "1.1.1.3" << j << endl;
      }
    }
    break;
  case 7:
    for (int i = 0; i < matrix_width; i++){
      for (int j = 0; j < matrix_height; j++){
	//tm[i][j].target_state = target_state;
	tm[i][j].previous_prob_to = tm[i][j].switch_to_target_probability;
	tm[i][j].previous_prob_from = tm[i][j].switch_from_target_probability;
	tm[i][j].set_target(Tile::DEAD, 0.7, 0.03);

	//tm[i][j].switch_to_target_probability = 1.0;
	//tm[i][j].switch_from_target_probability = 0.0;
	//tm[i][j].target_state = Tile::ALIVE;
	////cout << "1.1.1.2" << i << endl;
	////cout << "1.1.1.3" << j << endl;
      }
    }
    break;
  case 8:
    for (int i = 0; i < matrix_width; i++){
      for (int j = 0; j < matrix_height; j++){
	//tm[i][j].target_state = target_state;
	tm[i][j].previous_prob_to = tm[i][j].switch_to_target_probability;
	tm[i][j].previous_prob_from = tm[i][j].switch_from_target_probability;
	tm[i][j].set_target(Tile::DEAD, 1.0, 1.0);

	//tm[i][j].switch_to_target_probability = 1.0;
	//tm[i][j].switch_from_target_probability = 0.0;
	//tm[i][j].target_state = Tile::ALIVE;
	////cout << "1.1.1.2" << i << endl;
	////cout << "1.1.1.3" << j << endl;
      }
    }
    break;       
  }
}

void tessBackground::morph_into(){

}


void tessStaticPoint::update(Tile** tm, int matrix_width, int matrix_height){
  if (!morphing){
    ////cout << "update!" << endl;
    //std:://cout << center_x << "static_point " << center_y <<  " radius: " << radius << endl;
    int minWidth = ((center_x - radius >= 0) ? center_x - radius  : 0 );
    //std:://cout << minWidth << endl;
    int maxWidth = ((center_x + radius < matrix_width) ? center_x + radius : matrix_width - 1);
    //std:://cout << maxWidth << endl;
    int minHeight = ((center_y - radius >= 0) ? center_y - radius  : 0);
    //std:://cout << minHeight << endl;
    int maxHeight = ((center_y + radius < matrix_height) ? center_y + radius : matrix_height - 1);
    //std:://cout << minHeight << endl;
    for (int i = minWidth; i<maxWidth; i++){
      // step through vertically
      for (int j=minHeight; j<maxHeight; j++ ){
	float delta = sqrt(pow(i - center_x, 2.0) + pow(j - center_y, 2.0));
	if (delta < radius){
	  //       	tm[i][j].switch_to_target_probability *= pow(delta/(float) radius, exp);
	  float previous_prob = tm[i][j].previous_prob_to;
	  float previous_prob_from = tm[i][j].previous_prob_from;
	  tm[i][j].switch_to_target_probability = ofLerp(switch_to_target_state,
							 ofLerp(switch_to_target_state,
								previous_prob,
								exp),
							 ((float)(delta))/radius);
	  tm[i][j].switch_from_target_probability = ofLerp(switch_from_target_state,
							 ofLerp(switch_from_target_state,
								previous_prob_from,
								exp),
							 ((float)(delta))/radius);
	  
	  //tm[i][j].switch_to_target_probability = ofLerp(1.0, previous_prob, delta);
	  //tm[i][j].switch_from_target_probability = 0.2;	  
	  //       	matrix[i][j].switchProbability *= (delta / radius);
	  //matrix[i][j].switchProbability *= (delta / radius);
	  //	std:://cout << matrix[i][j].switchProbability<< endl;
	  //	std:://cout << delta / radius << endl;
	  //std:://cout << matrix[i][j].switchProbability << endl;
	}
      }
    }
    
  }
  else {
    float ratio =((float) (ofGetElapsedTimeMillis() - start_time)) /((float) (end_time - start_time));
    int new_center_x = (int) ofLerp(start_state->center_x, end_state->center_x, ratio);
    int new_center_y = (int) ofLerp(start_state->center_y, end_state->center_y, ratio);
    int new_radius = (int) ofLerp(start_state->radius, end_state->radius, ratio);
    float new_to = ofLerp(start_state->switch_to_target_state,
			  end_state->switch_to_target_state,
			  ratio);
    float new_from = ofLerp(start_state->switch_from_target_state,
			    end_state->switch_from_target_state,
			    ratio);
    float new_exp = ofLerp(start_state->exp, end_state->exp, ratio);
      
    int minWidth = ((new_center_x - new_radius >= 0) ? new_center_x - new_radius  : 0 );
    //std:://cout << minWidth << endl;
    int maxWidth = ((new_center_x + new_radius < matrix_width) ? new_center_x + new_radius : matrix_width - 1);
    //std:://cout << maxWidth << endl;
    int minHeight = ((new_center_y - new_radius >= 0) ? new_center_y - new_radius  : 0);
    //std:://cout << minHeight << endl;
    int maxHeight = ((new_center_y + new_radius < matrix_height) ? new_center_y + new_radius : matrix_height - 1);
    //std:://cout << minHeight << endl;
    for (int i = minWidth; i<maxWidth; i++){
      // step through vertically
      for (int j=minHeight; j<maxHeight; j++ ){
	float delta = sqrt(pow(i - new_center_x, 2.0) + pow(j - new_center_y, 2.0));
	if (delta < new_radius){
	  //       	tm[i][j].switch_to_target_probability *= pow(delta/(float) radius, exp);
	  //tm[i][j].switch_to_target_probability = 1;
	  
	  float previous_prob = tm[i][j].switch_to_target_probability;
	  float previous_prob_from = tm[i][j].switch_from_target_probability;
	  tm[i][j].switch_to_target_probability = ofLerp(new_to,
							 ofLerp(new_to,
								previous_prob,
								new_exp),
							 ((float)(delta))/radius);
	  tm[i][j].switch_from_target_probability = ofLerp(new_from,
							 ofLerp(new_from,
								previous_prob_from,
								new_exp),
							 ((float)(delta))/radius);
	  tm[i][j].target_state = state_lerp(start_state->target_state, end_state->target_state,
					     ratio);
	  //tm[i][j].switch_to_target_probability = ofLerp(previous_prob, 1.0, delta);
	  //tm[i][j].switch_from_target_probability = 0.2;	  
	  //       	matrix[i][j].switchProbability *= (delta / radius);
	  //matrix[i][j].switchProbability *= (delta / radius);
	  //	std:://cout << matrix[i][j].switchProbability<< endl;
	  //	std:://cout << delta / radius << endl;
	  //std:://cout << matrix[i][j].switchProbability << endl;
	}
      }
    }
    if (ofGetElapsedTimeMillis() > end_time){
      //start_state = end_state;
      morphing = false;
    }
  }
  
}

void tessStaticPoint::morph_into(tessStaticPoint *sp, float dur){
  morphing = true;
  start_time = ofGetElapsedTimeMillis();
  end_time = start_time + (int) round(dur * 1000);
  start_state = new tessStaticPoint();
  start_state->setup(center_x,
		     center_y,
		     radius,
		     target_state,
		     switch_to_target_state,
		     switch_from_target_state,
                     exp);
  end_state = sp;
}

void Tessellation::setup(){
}

void tessStaticPoint::setup(int coord_x,
			    int coord_y,
			    int _radius,
			    char _state,
			    float _to,
			    float _from,
			    float _exp){
  ////cout << "static point setup" << endl;
  center_x = coord_x;
  center_y = coord_y;
  radius = _radius;
  target_state = _state;
  switch_to_target_state = _to;
  switch_from_target_state = _from;
  exp = _exp;
  
}

tessStaticLine::tessStaticLine(){

}

void tessStaticLine::setup(int coordX_0,
			   int coordY_0,
			   int coordX_1,
			   int coordY_1,			   
			   int _width,
			   char _state,
			   float _to,
			   float _from,
			   float _exp){
  x_0 = coordX_0;
  y_0 = coordY_0;
  x_1 = coordX_1;
  y_1 = coordY_1;
  width = _width;
  state = _state;
  switch_from_target_state = _from;
  switch_to_target_state = _to;
  exp = _exp;
}

void tessStaticLine::update(Tile** tm, int matrix_width, int matrix_height){
  //cout << "tessStaticLine updating" << endl;
  if (!morphing){
    cout << "tessStaticLine not morphing" << endl;
    ////cout << "update!" << endl;
    //std:://cout << center_x << "static_point " << center_y <<  " radius: " << radius << endl;
    int minWidth = MIN(x_0, x_1);
    minWidth = (minWidth - width > 0 ? minWidth - width : 0);
    //std:://cout << minWidth << endl;
    int maxWidth = MAX(x_0, x_1);
    maxWidth = (maxWidth + width < matrix_width ? maxWidth + width : matrix_width);
    //std:://cout << maxWidth << endl;
    int minHeight = MIN(y_0, y_1);
    minHeight = (minHeight - width > 0 ? minHeight - width : 0);
    //std:://cout << minHeight << endl;
    int maxHeight = MAX(y_0, y_1);
    maxHeight = (maxHeight + width < matrix_height ? maxHeight + width : matrix_height);
    //std:://cout << minHeight << endl;
    for (int i = minWidth; i<maxWidth; i++){
      // step through vertically
      for (int j=minHeight; j<maxHeight; j++ ){
	float delta = distance_from_line(i, j, x_0, x_1, y_0, y_1);
	//cout << "delta; " << delta << endl;
	if (delta < width){
	  //       	tm[i][j].switch_to_target_probability *= pow(delta/(float) radius, exp);
	  float previous_prob = tm[i][j].previous_prob_to;
	  float previous_prob_from = tm[i][j].previous_prob_from;
	  tm[i][j].switch_to_target_probability = ofLerp(switch_to_target_state,
							 ofLerp(switch_to_target_state,
								previous_prob,
								exp),
							 delta/((float)width));
	  tm[i][j].switch_from_target_probability = ofLerp(switch_from_target_state,
							 ofLerp(switch_from_target_state,
								previous_prob_from,
								exp),
							   delta/((float)width));
	  
	  //tm[i][j].switch_to_target_probability = ofLerp(1.0, previous_prob, delta);
	  //tm[i][j].switch_from_target_probability = 0.2;	  
	  //       	matrix[i][j].switchProbability *= (delta / radius);
	  //matrix[i][j].switchProbability *= (delta / radius);
	  //	std:://cout << matrix[i][j].switchProbability<< endl;
	  //	std:://cout << delta / radius << endl;
	  //std:://cout << matrix[i][j].switchProbability << endl;
	}
      }
    }
    
  }
  else {
    //cout << "tessStaticLine morphing" << endl;
    //cout << "end time: " << end_time << endl;
    float ratio =((float) (ofGetElapsedTimeMillis() - start_time)) /((float) (end_time - start_time));
    //cout << "Ratio: " << ratio << endl;
    int new_x0 = (int) ofLerp(start_state->x_0, end_state->x_0, ratio);
    int new_y0 = (int) ofLerp(start_state->y_0, end_state->y_0, ratio);
    int new_x1 = (int) ofLerp(start_state->x_1, end_state->x_1, ratio);
    int new_y1 = (int) ofLerp(start_state->y_1, end_state->y_1, ratio);
    //std::cout << new_x0 << endl;
    //std::cout << new_y0 << endl;
    //std::cout << new_x1 << endl;
    //std::cout << new_y1 << endl;
 
    int new_width = (int) ofLerp(start_state->width, end_state->width, ratio);

    //cout << "new width:" << new_width << endl;
    
    float new_to = ofLerp(start_state->switch_to_target_state,
			  end_state->switch_to_target_state,
			  ratio);
    float new_from = ofLerp(start_state->switch_from_target_state,
			    end_state->switch_from_target_state,
			    ratio);
    float new_exp = ofLerp(start_state->exp, end_state->exp, ratio);

    int minWidth = MIN(new_x0, new_x1);
    minWidth = (minWidth - new_width > 0 ? minWidth - new_width : 0);
    //std::cout << minWidth << endl;
    int maxWidth = MAX(new_x0, new_x1);
    maxWidth = (maxWidth + new_width < matrix_width ? maxWidth + new_width : matrix_width);
    //std::cout << maxWidth << endl;
    int minHeight = MIN(new_y0, new_y1);
    minHeight = (minHeight - new_width > 0 ? minHeight - new_width : 0);
    //std::cout << minHeight << endl;
    int maxHeight = MAX(new_y0, new_y1);
    maxHeight = (maxHeight + new_width < matrix_height ? maxHeight + new_width : matrix_height);
    //std::cout << minHeight << endl;
    for (int i = minWidth; i<maxWidth; i++){
      // step through vertically
      for (int j=minHeight; j<maxHeight; j++ ){
	float delta = distance_from_line(i, j, new_x0, new_x1, new_y0, new_y1);
	//cout << "delta; " << delta << endl;
	if (delta < new_width){
	  //       	tm[i][j].switch_to_target_probability *= pow(delta/(float) radius, exp);
	  //tm[i][j].switch_to_target_probability = 1;
	  
	  float previous_prob = tm[i][j].switch_to_target_probability;
	  float previous_prob_from = tm[i][j].switch_from_target_probability;
	  tm[i][j].switch_to_target_probability = ofLerp(new_to,
							 ofLerp(new_to,
								previous_prob,
								new_exp),
							 ((float)(delta))/width);
	  tm[i][j].switch_from_target_probability = ofLerp(new_from,
							 ofLerp(new_from,
								previous_prob_from,
								new_exp),
							 ((float)(delta))/width);
	  tm[i][j].target_state = state_lerp(start_state->target_state, end_state->target_state,
					     ratio);
	  //tm[i][j].switch_to_target_probability = ofLerp(previous_prob, 1.0, delta);
	  //tm[i][j].switch_from_target_probability = 0.2;	  
	  //       	matrix[i][j].switchProbability *= (delta / radius);
	  //matrix[i][j].switchProbability *= (delta / radius);
	  //	std:://cout << matrix[i][j].switchProbability<< endl;
	  //	std:://cout << delta / radius << endl;
	  //std:://cout << matrix[i][j].switchProbability << endl;
	}
      }
    }
    if (ofGetElapsedTimeMillis() > end_time){
      //start_state = end_state;
      morphing = false;
    }
  }
  
}

void tessStaticLine::morph_into(tessStaticLine *sl, float dur){
  morphing = true;
  start_time = ofGetElapsedTimeMillis();
  end_time = start_time + (int) round(dur * 1000);
  start_state = new tessStaticLine();
  start_state->setup(x_0,
		     y_0,
		     x_1,
		     y_1,
		     width,
		     target_state,
		     switch_to_target_state,
		     switch_from_target_state,
                     exp);
  end_state = sl;
}

//not a real lerp, transition from state_begin to state_end through DONT_CARE if they differ
char state_lerp(char state_begin, char state_end, float pos){
  //printf("state begin: %u\n state end: %u\n", state_begin, state_end);
  if (state_begin == state_end){
    return state_begin;
  }
  else if (state_begin != Tile::DONT_CARE && state_end !=Tile::DONT_CARE){
    if (pos < 0.33) return state_begin;
    if (pos < 0.67) return Tile::DONT_CARE;
    else return state_end;
  }
  else {
    if (pos < 0.5) return state_begin;
    else return state_end;
  }

}


float distance_from_center(int x, int y, int center_x, int center_y){
  float distance = 0;
  return distance;
}

float distance_from_line(int x, int y, int line_x0, int line_x1, int line_y0, int line_y1){
   float distance = fabs((line_y1 - line_y0) * x
			 - (line_x1 - line_x0) * y
			 + line_x1 * line_y0 - line_y1 * line_x0)
     /
     sqrt(pow((line_y1 - line_y0), 2.0) + pow((line_x1 - line_x0), 2.0));
  return distance;
}
