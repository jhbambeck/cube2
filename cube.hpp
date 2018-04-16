#pragma once
#include <string>
#include <iostream>
#include "side.hpp"

struct cube
{
  side front; 
  side back; 
  side up; 
  side down;
  side left; 
  side right; 

  int blue_count; 
  int red_count; 
  int orange_count; 
  int yellow_count; 
  int white_count; 
  int green_count; 
  
  cube(std::string&);
  char* get_square(std::string&, int&);
  void print();
  std::string color(char*);

  void move_right();
  void move_right_prime(); 
  void move_front(); 
  void move_front_prime(); 
  void move_up(); 
  void move_up_prime(); 
  void move_left(); 
  void move_left_prime(); 
  void move_back(); 
  void move_back_prime();
  void move_down();
  void move_down_prime(); 

  void move_x();  
  void move_x_prime();
  void move_y();  
};


