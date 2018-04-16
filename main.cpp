#include <iostream>
#include <fstream>
#include <string>
#include "cube.hpp"
#include "shell.hpp"

int main()
{
  std::ifstream ifs("cube.txt");
  std::string line, input; 
  while(!ifs.eof())
  {
    getline(ifs, line);
    input.append(line);
  }
  shell s(input);
  s.menu(); 
  //c.print();
  //c.move_x();
  //std::cout << "----------------------------------------\n"; 
  //c.print();
  //std::cout << "----------------------------------------\n";
  //c.move_down_prime(); 
  //c.print(); 
}
