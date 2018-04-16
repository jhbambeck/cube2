#pragma once
#include <string>
#include <vector>
#include "cube.hpp"

enum move 
{
  RIGHT, 
  RIGHT_PRIME,
  LEFT,
  LEFT_PRIME,
  UP,
  UP_PRIME,
  DOWN, 
  DOWN_PRIME,
  FRONT, 
  FRONT_PRIME,
  BACK,
  BACK_PRIME,
  X, 
  X_PRIME,
};

struct shell
{
  cube c; 
  std::vector<move> vec; 

  shell(std::string& input) : c(input)
    { }
  void menu();
  std::vector<move> parse_execute_emplace(std::string&);  
  void execute(std::vector<move>);
};
