#include "cube.hpp"

cube::cube(std::string& input)
{
  int i = 0;
  red_count = 0; 
  blue_count = 0; 
  green_count = 0; 
  yellow_count = 0; 
  white_count = 0; 
  orange_count = 0;  

  back.top_left = get_square(input, i);
  back.top = get_square(input, i);
  back.top_right = get_square(input, i);
  back.center_left = get_square(input, i);
  back.center = get_square(input, i);
  back.center_right = get_square(input, i);
  back.bottom_left = get_square(input, i);
  back.bottom = get_square(input, i);
  back.bottom_right = get_square(input, i); 
  
  up.top_left = get_square(input, i);
  up.top = get_square(input, i);
  up.top_right = get_square(input, i);
  up.center_left = get_square(input, i);
  up.center = get_square(input, i);
  up.center_right = get_square(input, i);
  up.bottom_left = get_square(input, i);
  up.bottom = get_square(input, i);
  up.bottom_right = get_square(input, i);   
 
  left.top_left = get_square(input, i);
  left.top = get_square(input, i);
  left.top_right = get_square(input, i);
  front.top_left = get_square(input, i);
  front.top = get_square(input, i);
  front.top_right = get_square(input, i); 
  right.top_left = get_square(input, i);
  right.top = get_square(input, i);
  right.top_right = get_square(input, i);
  left.center_left = get_square(input, i);
  left.center = get_square(input, i);
  left.center_right = get_square(input, i);
  front.center_left = get_square(input, i);
  front.center = get_square(input, i);
  front.center_right = get_square(input, i);
  right.center_left = get_square(input, i);
  right.center = get_square(input, i);
  right.center_right = get_square(input, i);
  left.bottom_left = get_square(input, i);
  left.bottom = get_square(input, i);
  left.bottom_right = get_square(input, i);
  front.bottom_left = get_square(input, i);
  front.bottom = get_square(input, i);
  front.bottom_right = get_square(input, i);
  right.bottom_left = get_square(input, i);
  right.bottom = get_square(input, i);
  right.bottom_right = get_square(input, i);
  
  down.top_left = get_square(input, i);
  down.top = get_square(input, i);
  down.top_right = get_square(input, i);
  down.center_left = get_square(input, i);
  down.center = get_square(input, i);
  down.center_right = get_square(input, i);
  down.bottom_left = get_square(input, i); 
  down.bottom = get_square(input, i);
  down.bottom_right = get_square(input, i);  
}

std::string cube::color(char* in)
{
  std::string out; 
  if(in[0] == 'r')
    out = "\e[1;3;31mr1\e[0m\0";
  else if(in[0] == 'g')
    out = "\e[1;3;32mr1\e[0m\0";
  else if(in[0] == 'y')
    out = "\e[1;3;93mr1\e[0m\0";
  else if(in[0] == 'b')
    out = "\e[1;3;34mr1\e[0m\0";
  else if(in[0] == 'o')
    out = "\e[1;3;33mr1\e[0m\0";
  else if(in[0] == 'w')
    return std::string(in);
    
  out[9] = in[0]; 
  out[10] = in[1];
  return out;
}

char* cube::get_square(std::string& input, int& i)
{  
  char* s = new char[3];
  std::string temp; 
  s[2] = '\0';
  while(!isalpha(input[i]))
    i++;

  s[0] = input[i];
 
  switch(input[i])
  {
  case 'r':
    temp = std::to_string(++red_count);
    s[1] = temp[0];
    break;     
  case 'b':
    temp = std::to_string(++blue_count);
    s[1] = temp[0];
    break; 
  case 'g':
    temp = std::to_string(++green_count);
    s[1] = temp[0];
    break; 
  case 'y':
    temp = std::to_string(++yellow_count);
    s[1] = temp[0];
    break;
  case 'w':
    temp = std::to_string(++white_count);
    s[1] = temp[0];
    break; 
  case 'o':
    temp = std::to_string(++orange_count);
    s[1] = temp[0];
    break; 
  }
  i++; 
  return s;
}

void cube::print()
{
  //back
  for(int i = 0; i < 14; i++)
    std::cout << ' '; 
  std::cout << color(back.top_left) << "  " 
     << color(back.top) << "  "
     << color(back.top_right) << '\n';
  for(int i = 0; i < 14; i++)
    std::cout << ' '; 
  std::cout << color(back.center_left) << "  " 
     << color(back.center) << "  "
     << color(back.center_right) << '\n';
  for(int i  = 0; i < 14; i++)
    std::cout << ' '; 
  std::cout << color(back.bottom_left) << "  " 
     << color(back.bottom) << "  " 
     << color(back.bottom_right) << "\n\n"; 

  //up
  for(int i = 0; i < 14; i++)
    std::cout << ' '; 
  std::cout << color(up.top_left) << "  "
     << color(up.top) << "  " 
     << color(up.top_right) << '\n';
  for(int i = 0; i < 14; i++)
    std::cout << ' '; 
  std::cout << color(up.center_left) << "  "
     << color(up.center) << "  " 
     << color(up.center_right) << '\n';
  for(int i = 0; i < 14; i++)
    std::cout << ' '; 
  std::cout << color(up.bottom_left) << "  " 
     << color(up.bottom) << "  " 
     << color(up.bottom_right) << "\n\n";

  //left front right
 std::cout << color(left.top_left) << "  "
     << color(left.top) << "  " 
     << color(left.top_right) << "    "
     << color(front.top_left) << "  " 
     << color(front.top) << "  " 
     << color(front.top_right) << "    " 
     << color(right.top_left) << "  " 
     << color(right.top) << "  " 
     << color(right.top_right) << '\n'; 
  std::cout << color(left.center_left) << "  " 
     << color(left.center) << "  "
     << color(left.center_right) << "    " 
     << color(front.center_left) << "  " 
     << color(front.center) << "  "
     << color(front.center_right) << "    " 
     << color(right.center_left) << "  " 
     << color(right.center) << "  " 
     << color(right.center_right) << '\n';  
  std::cout << color(left.bottom_left) << "  " 
     << color(left.bottom) << "  " 
     << color(left.bottom_right) << "    " 
     << color(front.bottom_left) << "  " 
     << color(front.bottom) << "  " 
     << color(front.bottom_right) << "    " 
     << color(right.bottom_left) << "  " 
     << color(right.bottom) << "  " 
     << color(right.bottom_right) << "\n\n"; 

  //down
  for(int i = 0; i < 14; i++)
    std::cout << ' ';
  std::cout << color(down.top_left) << "  " 
     << color(down.top) << "  " 
     << color(down.top_right) << '\n';
  for(int i = 0; i < 14; i++)
    std::cout << ' ';
  std::cout << color(down.center_left) << "  " 
     << color(down.center) << "  " 
     << color(down.center_right) << '\n';
  for(int i = 0; i < 14; i++)
    std::cout << ' '; 
  std::cout << color(down.bottom_left) << "  " 
     << color(down.bottom) << "  " 
     << color(down.bottom_right) << "\n";
}

void cube::move_right()
{
  cube temp = *this; 

  this->right.top_left = temp.right.bottom_left; 
  this->right.top = temp.right.center_left; 
  this->right.top_right = temp.right.top_left; 
  this->right.center_left = temp.right.bottom; 
  this->right.center_right = temp.right.top; 
  this->right.bottom_left = temp.right.bottom_right; 
  this->right.bottom = temp.right.center_right; 
  this->right.bottom_right = temp.right.top_right; 

  this->up.bottom_right = temp.front.bottom_right; 
  this->up.center_right = temp.front.center_right;
  this->up.top_right = temp.front.top_right; 
  
  this->front.bottom_right = temp.down.bottom_right;
  this->front.center_right = temp.down.center_right; 
  this->front.top_right = temp.down.top_right; 

  this->back.bottom_right = temp.up.bottom_right; 
  this->back.center_right = temp.up.center_right; 
  this->back.top_right = temp.up.top_right; 
  
  this->down.top_right = temp.back.top_right; 
  this->down.center_right = temp.back.center_right; 
  this->down.bottom_right = temp.back.bottom_right; 
}


void cube::move_right_prime()
{
  cube temp = *this; 

  //this->right.top_left = temp.right.bottom_left; 
  this->right.bottom_left = temp.right.top_left; 
  //this->right.top = temp.right.center_left; 
  this->right.center_left = right.top; 
  //this->right.top_right = temp.right.top_left; 
  this->right.top_left = temp.right.top_right; 
  //this->right.center_left = temp.right.bottom;
  this->right.bottom = temp.right.center_left;  
  //this->right.center_right = temp.right.top; 
  this->right.top = temp.right.center_right; 
  //this->right.bottom_left = temp.right.bottom_right; 
  this->right.bottom_right = temp.right.bottom_left; 
  //this->right.bottom = temp.right.center_right; 
  this->right.center_right = temp.right.bottom; 
  //this->right.bottom_right = temp.right.top_right;
  this->right.top_right = temp.right.bottom_right;  

  //this->up.bottom_right = temp.down.top_right; 
  this->front.bottom_right = temp.up.bottom_right; 
  //this->up.center_right = temp.front.center_right;
  this->front.center_right = temp.up.center_right; 
  //this->up.top_right = temp.front.top_right; 
  this->front.top_right = temp.up.top_right; 
  
  //this->front.bottom_right = temp.down.bottom_right;
  this->down.bottom_right = temp.front.bottom_right;
  //this->front.center_right = temp.down.center_right;
  this->down.center_right = temp.front.center_right;  
  //this->front.top_right = temp.down.top_right; 
  this->down.top_right = temp.front.top_right; 

  //this->back.bottom_right = temp.up.bottom_right;
  this->up.bottom_right = temp.back.bottom_right;  
  //this->back.center_right = temp.up.center_right;
  this->up.center_right = temp.back.center_right;  
  //this->back.top_right = temp.up.top_right; 
  this->up.top_right = temp.back.top_right; 
  
  //this->down.top_right = temp.back.top_right;
  this->back.top_right = temp.down.top_right;  
  //this->down.center_right = temp.back.center_right;
  this->back.center_right = temp.down.center_right;  
  this->back.bottom_right = temp.down.bottom_right;  
}

void cube::move_front()
{
  cube temp = *this; 
  this->front.top_left = temp.front.bottom_left; 
  this->front.top = temp.front.center_left; 
  this->front.top_right = temp.front.top_left; 
  this->front.center_left = temp.front.bottom;
  this->front.center_right = temp.front.top; 
  this->front.bottom_left = temp.front.bottom_right; 
  this->front.bottom = temp.front.center_right; 
  this->front.bottom_right = temp.front.top_right; 
                                                          
  this->up.bottom_left = temp.left.bottom_right; 
  this->up.bottom = temp.left.center_right; 
  this->up.bottom_right = temp.left.top_right;
  
  this->left.top_right = temp.down.top_left; 
  this->left.center_right = temp.down.top; 
  this->left.bottom_right = temp.down.top_right; 
 
  this->right.top_left = temp.up.bottom_left; 
  this->right.center_left = temp.up.bottom; 
  this->right.bottom_left = temp.up.bottom_right; 

  this->down.top_left = temp.right.bottom_left; 
  this->down.top = temp.right.center_left; 
  this->down.top_right = temp.right.top_left; 
}

void cube::move_front_prime()
{
  cube temp = *this; 
  //this->front.top_left = temp.front.bottom_left; 
  this->front.bottom_left = temp.front.top_left; 
  //this->front.top = temp.front.center_left; 
  this->front.center_left = temp.front.top; 
  //this->front.top_right = temp.front.top_left;
  this->front.top_left = temp.front.top_right;  
  //this->front.center_left = temp.front.bottom;
  this->front.bottom = temp.front.center_left; 
  //this->front.center_right = temp.front.top; 
  this->front.top = temp.front.center_right; 
  //this->front.bottom_left = temp.front.bottom_right;
  this->front.bottom_right = temp.front.bottom_left;  
  //this->front.bottom = temp.front.center_right; 
  this->front.center_right = temp.front.bottom;
  //this->front.bottom_right = temp.front.top_right;
  this->front.top_right = temp.front.bottom_right;  

  //this->up.bottom_left = temp.left.bottom_right; 
  this->left.bottom_right = temp.up.bottom_left; 
  //this->up.bottom = temp.left.center_right; 
  this->left.center_right = temp.up.bottom; 
  //this->up.bottom_right = temp.left.top_right;
  this->left.top_right = temp.up.bottom_right; 
  
  //this->left.top_right = temp.down.top_left; 
  this->down.top_left = temp.left.top_right; 
  //this->left.center_right = temp.down.top; 
  this->down.top = temp.left.center_right; 
  //this->left.bottom_right = temp.down.top_right; 
  this->down.top_right = temp.left.bottom_right; 
 
  //this->right.top_left = temp.up.bottom_left; 
  this->up.bottom_left = temp.right.top_left; 
  //this->right.center_left = temp.up.bottom; 
  this->up.bottom = temp.right.center_left; 
  //this->right.bottom_left = temp.up.bottom_right;
  this->up.bottom_right = temp.right.bottom_left;  

  //this->down.top_left = temp.right.bottom_left; 
  this->right.bottom_left = temp.down.top_left; 
  //this->down.top = temp.right.center_left; 
  this->right.center_left = temp.down.top;
  //this->down.top_right = temp.right.top_left;
  this->right.top_left = temp.down.top_right;  
}

void cube::move_up()
{
  cube temp = *this;
  
  this->up.top_left = temp.up.bottom_left; 
  this->up.top = temp.up.center_left; 
  this->up.top_right = temp.up.top_left; 
  this->up.center_left = temp.up.bottom; 
  this->up.center_right = temp.up.top; 
  this->up.bottom_left = temp.up.bottom_right; 
  this->up.bottom = temp.up.center_right; 
  this->up.bottom_right = temp.up.top_right; 
 
  this->front.top_left = temp.right.top_left; 
  this->front.top = temp.right.top; 
  this->front.top_right = temp.right.top_right;

  this->right.top_left = temp.back.bottom_right; 
  this->right.top = temp.back.bottom; 
  this->right.top_right =temp.back.bottom_left; 

  this->left.top_left = temp.front.top_left; 
  this->left.top = temp.front.top; 
  this->left.top_right = temp.front.top_right;
 
  this->back.bottom_left = temp.left.top_right; 
  this->back.bottom = temp.left.top; 
  this->back.bottom_right = temp.left.top_left;     
}                                                     

void cube::move_up_prime()
{
  cube temp = *this;
  
  //this->up.top_left = temp.up.bottom_left; 
  this->up.bottom_left = temp.up.top_left; 
  //this->up.top = temp.up.center_left; 
  this->up.center_left = temp.up.top; 
  //this->up.top_right = temp.up.top_left;
  this->up.top_left = temp.up.top_right;  
  //this->up.center_left = temp.up.bottom;
  this->up.bottom = temp.up.center_left;  
  //this->up.center_right = temp.up.top; 
  this->up.top = temp.up.center_right; 
  //this->up.bottom_left = temp.up.bottom_right;
  this->up.bottom_right = temp.up.bottom_left;  
  //this->up.bottom = temp.up.center_right; 
  this->up.center_right = temp.up.bottom; 
  //this->up.bottom_right = temp.up.top_right;
  this->up.top_right = temp.up.bottom_right;  
 
  //this->front.top_left = temp.right.top_left; 
  this->right.top_left = temp.front.top_left; 
  //this->front.top = temp.right.top; 
  this->right.top = temp.front.top; 
  //this->front.top_right = temp.right.top_right;
  this->right.top_right = temp.front.top_right; 

  //this->right.top_left = temp.back.bottom_right;
  this->back.bottom_right = temp.right.top_left;  
  //this->right.top = temp.back.bottom; 
  this->back.bottom = temp.right.top; 
  //this->right.top_right =temp.back.bottom_left; 
  this->back.bottom_left = temp.right.top_right; 

  //this->left.top_left = temp.front.top_left; 
  this->front.top_left = temp.left.top_left; 
  //this->left.top = temp.front.top; 
  this->front.top = temp.left.top; 
  //this->left.top_right = temp.front.top_right;
  this->front.top_right = temp.left.top_right; 
 
  //this->back.bottom_left = temp.left.top_right;
  this->left.top_right = temp.back.bottom_left;  
  //this->back.bottom = temp.left.top; 
  this->left.top = temp.back.bottom; 
  //this->back.bottom_right = temp.left.top_left; 
  this->left.top_left = temp.back.bottom_right;     
}                                                     
                                                                                void cube::move_left()
{
  cube temp = *this; 
 
  this->left.top_left = temp.left.bottom_left; 
  this->left.top = temp.left.center_left; 
  this->left.top_right = temp.left.top_left; 
  this->left.center_left = temp.left.bottom; 
  this->left.center_right = temp.left.top; 
  this->left.bottom_left = temp.left.bottom_right;
  this->left.bottom = temp.left.center_right; 
  this->left.bottom_right = temp.left.top_right; 

  this->up.top_left = temp.back.top_left; 
  this->up.center_left = temp.back.center_left; 
  this->up.bottom_left = temp.back.bottom_left; 
  
  this->front.top_left = temp.up.top_left; 
  this->front.center_left = temp.up.center_left; 
  this->front.bottom_left = temp.up.bottom_left; 
  
  this->down.top_left = temp.front.top_left; 
  this->down.center_left = temp.front.center_left; 
  this->down.bottom_left = temp.front.bottom_left; 
  
  this->back.top_left = temp.down.top_left;
  this->back.center_left = temp.down.center_left; 
  this->back.bottom_left = temp.down.bottom_left;  
}                                                      

void cube::move_left_prime()
{
  cube temp = *this; 
 
  //this->left.top_left = temp.left.bottom_left;
  this->left.bottom_left = temp.left.top_left;  
  //this->left.top = temp.left.center_left; 
  this->left.center_left = temp.left.top; 
  //this->left.top_right = temp.left.top_left;
  this->left.top_left = temp.left.top_right;  
  //this->left.center_left = temp.left.bottom;
  this->left.bottom = temp.left.center_left; 
  //this->left.center_right = temp.left.top; 
  this->left.top = temp.left.center_right; 
  //this->left.bottom_left = temp.left.bottom_right;
  this->left.bottom_right = temp.left.bottom_left; 
  //this->left.bottom = temp.left.center_right; 
  this->left.center_right = temp.left.bottom; 
  //this->left.bottom_right = temp.left.top_right;
  this->left.top_right = temp.left.bottom_right; 

  //this->up.top_left = temp.back.top_left; 
  this->back.top_left = temp.up.top_left; 
  //this->up.center_left = temp.back.center_left;
  this->back.center_left = temp.up.center_left; 
  //this->up.bottom_left = temp.back.bottom_left;
  this->back.bottom_left = temp.up.bottom_left; 
  
  //this->front.top_left = temp.up.top_left; 
  this->up.top_left = temp.front.top_left; 
  //this->front.center_left = temp.up.center_left;
  this->up.center_left = temp.front.center_left; 
  //this->front.bottom_left = temp.up.bottom_left;
  this->up.bottom_left = temp.front.bottom_left; 
  
  //this->down.top_left = temp.front.top_left; 
  this->front.top_left = temp.down.top_left; 
  //this->down.center_left = temp.front.center_left;
  this->front.center_left = temp.down.center_left; 
  //this->down.bottom_left = temp.front.bottom_left;
  this->front.bottom_left = temp.down.bottom_left; 
  
  //this->back.top_left = temp.down.top_left;
  this->down.top_left = temp.back.top_left; 
  //this->back.center_left = temp.down.center_left;
  this->down.center_left = temp.back.center_left; 
  //this->back.bottom_left = temp.down.bottom_left;
  this->down.bottom_left = temp.back.bottom_left; 
}                                                     

void cube::move_back()
{
  cube temp = *this; 
  
  this->back.top_left = temp.back.bottom_left; 
  this->back.top = temp.back.center_left; 
  this->back.top_right = temp.back.top_left;
  this->back.center_left = temp.back.bottom; 
  this->back.center_right = temp.back.top; 
  this->back.bottom_left = temp.back.bottom_right; 
  this->back.bottom = temp.back.center_right; 
  this->back.bottom_right = temp.back.top_right; 
 
  this->up.top_left = temp.left.bottom_left; 
  this->up.top = temp.left.center_left; 
  this->up.top_right = temp.left.top_left; 

  this->left.top_left = temp.down.bottom_left; 
  this->left.center_left = temp.down.bottom; 
  this->left.bottom_left = temp.down.bottom_right; 

  this->right.top_right = temp.up.top_left; 
  this->right.center_right = temp.up.top; 
  this->right.bottom_right = temp.up.top_right; 

  this->down.bottom_left = temp.right.bottom_right; 
  this->down.bottom = temp.right.center_right; 
  this->down.bottom_right = temp.right.top_right;   
}

void cube::move_back_prime()
{
  cube temp = *this; 
  
  //this->back.top_left = temp.back.bottom_left;
  this->back.bottom_left = temp.back.top_left;  
  //this->back.top = temp.back.center_left; 
  this->back.center_left = temp.back.top; 
  //this->back.top_right = temp.back.top_left;
  this->back.top_left = temp.back.top_right; 
  //this->back.center_left = temp.back.bottom;
  this->back.bottom = temp.back.center_left;  
  //this->back.center_right = temp.back.top; 
  this->back.top = temp.back.center_right; 
  //this->back.bottom_left = temp.back.bottom_right; 
  this->back.bottom_right = temp.back.bottom_left; 
  //this->back.bottom = temp.back.center_right; 
  this->back.center_right = temp.back.bottom; 
  //this->back.bottom_right = temp.back.top_right;
  this->back.top_right = temp.back.bottom_right;  
                                                        
  //this->up.top_left = temp.left.bottom_left; 
  this->left.bottom_left = temp.up.top_left; 
  //this->up.top = temp.left.center_left; 
  this->left.center_left = temp.up.top;
  //this->up.top_right = temp.left.top_left;
  this->left.top_left = temp.up.top_right;  

  //this->left.top_left = temp.down.bottom_left;
  this->down.bottom_left = temp.left.top_left;  
  //this->left.center_left = temp.down.bottom; 
  this->down.bottom = temp.left.center_left; 
  //this->left.bottom_left = temp.down.bottom_right;
  this->down.bottom_right = temp.left.bottom_left;  

  //this->right.top_right = temp.up.top_left; 
  this->up.top_left = temp.right.top_right; 
  //this->right.center_right = temp.up.top; 
  this->up.top = temp.right.center_right; 
  //this->right.bottom_right = temp.up.top_right;
  this->up.top_right = temp.right.bottom_right;  

  //this->down.bottom_left = temp.right.bottom_right; 
  this->right.bottom_right = temp.down.bottom_left; 
  //this->down.bottom = temp.right.center_right; 
  this->right.center_right = temp.down.bottom; 
  //this->down.bottom_right = temp.right.top_right;
  this->right.top_right = temp.down.bottom_right;    
}


void cube::move_down()
{
  cube temp = *this; 
  
  this->down.top_left = temp.down.bottom_left; 
  this->down.top = temp.down.center_left; 
  this->down.top_right = temp.down.top_left; 
  this->down.center_left = temp.down.bottom; 
  this->down.center_right = temp.down.top; 
  this->down.bottom_left = temp.down.bottom_right; 
  this->down.bottom = temp.down.center_right; 
  this->down.bottom_right = temp.down.top_right; 
  
  this->front.bottom_left = temp.left.bottom_left; 
  this->front.bottom = temp.left.bottom; 
  this->front.bottom_right = temp.left.bottom_right; 
 
  this->left.bottom_left = temp.back.top_right; 
  this->left.bottom = temp.back.top; 
  this->left.bottom_right = temp.back.top_left; 

  this->right.bottom_left = temp.front.bottom_left; 
  this->right.bottom = temp.front.bottom; 
  this->right.bottom_right = temp.front.bottom_right; 

  this->back.top_left = temp.right.bottom_right; 
  this->back.top = temp.right.bottom; 
  this->back.top_right = temp.right.bottom_left; 
}

void cube::move_down_prime()
{
  cube temp = *this; 
  
  //this->down.top_left = temp.down.bottom_left; 
  this->down.bottom_left = temp.down.top_left; 
  //this->down.top = temp.down.center_left; 
  this->down.center_left = temp.down.top; 
  //this->down.top_right = temp.down.top_left;
  this->down.top_left = temp.down.top_right;  
  //this->down.center_left = temp.down.bottom;
  this->down.bottom = temp.down.center_left;  
  //this->down.center_right = temp.down.top; 
  this->down.top = temp.down.center_right; 
  //this->down.bottom_left = temp.down.bottom_right;
  this->down.bottom_right = temp.down.bottom_left;   
  //this->down.bottom = temp.down.center_right; 
  this->down.center_right = temp.down.bottom; 
  //this->down.bottom_right = temp.down.top_right;
  this->down.top_right = temp.down.bottom_right;  
  
  //this->front.bottom_left = temp.left.bottom_left;
  this->left.bottom_left = temp.front.bottom_left;  
  //this->front.bottom = temp.left.bottom; 
  this->left.bottom = temp.front.bottom; 
  //this->front.bottom_right = temp.left.bottom_right; 
  this->left.bottom_right = temp.front.bottom_right; 
 
  //this->left.bottom_left = temp.back.top_right; 
  this->back.top_right = temp.left.bottom_left; 
  //this->left.bottom = temp.back.top; 
  this->back.top = temp.left.bottom; 
  //this->left.bottom_right = temp.back.top_left; 
  this->back.top_left = temp.left.bottom_right; 

  //this->right.bottom_left = temp.front.bottom_left;
  this->front.bottom_left = temp.right.bottom_left;  
  //this->right.bottom = temp.front.bottom; 
  this->front.bottom = temp.right.bottom; 
  //this->right.bottom_right = temp.front.bottom_right;
  this->front.bottom_right = temp.right.bottom_right;  

  //this->back.top_left = temp.right.bottom_right; 
  this->right.bottom_right = temp.back.top_left; 
  //this->back.top = temp.right.bottom; 
  this->right.bottom = temp.back.top; 
  //this->back.top_right = temp.right.bottom_left; 
  this->right.bottom_left = temp.back.top_right; 
}
 
void cube::move_x()
{
  cube temp = *this; 

  this->front.top_left = temp.front.bottom_left; 
  this->front.top = temp.front.center_left; 
  this->front.top_right = temp.front.top_left; 
  this->front.center_left = temp.front.bottom;
  this->front.center_right = temp.front.top; 
  this->front.bottom_left = temp.front.bottom_right; 
  this->front.bottom = temp.front.center_right; 
  this->front.bottom_right = temp.front.top_right; 
 
  this->back.bottom_left = temp.back.top_left;   
  this->back.center_left = temp.back.top; 
  this->back.top_left = temp.back.top_right; 
  this->back.bottom = temp.back.center_left;   
  this->back.top = temp.back.center_right;  
  this->back.bottom_right = temp.back.bottom_left;  
  this->back.center_right = temp.back.bottom; 
  this->back.top_right = temp.back.bottom_right;  

  this->up.top_left = temp.left.bottom_left; 
  this->up.top = temp.left.center_left; 
  this->up.top_right = temp.left.top_left; 
  this->up.center_left = temp.left.bottom; 
  this->up.center = temp.left.center; 
  this->up.center_right = temp.left.top; 
  this->up.bottom_left = temp.left.bottom_right; 
  this->up.bottom = temp.left.center_right;
  this->up.bottom_right = temp.left.top_right; 

  this->right.top_left = temp.up.bottom_left; 
  this->right.top = temp.up.center_left; 
  this->right.top_right = temp.up.top_left; 
  this->right.center_left = temp.up.bottom; 
  this->right.center = temp.up.center; 
  this->right.center_right = temp.up.top;
  this->right.bottom_left = temp.up.bottom_right; 
  this->right.bottom = temp.up.center_right; 
  this->right.bottom_right = temp.up.top_right; 

  this->left.top_left = temp.down.bottom_left; 
  this->left.top = temp.down.center_left; 
  this->left.top_right = temp.down.top_left; 
  this->left.center_left = temp.down.bottom; 
  this->left.center = temp.down.center; 
  this->left.center_right = temp.down.top; 
  this->left.bottom_left = temp.down.bottom_right; 
  this->left.bottom = temp.down.center_right; 
  this->left.bottom_right = temp.down.top_right; 

  this->down.top_left = temp.right.bottom_left; 
  this->down.top = temp.right.center_left; 
  this->down.top_right = temp.right.top_left; 
  this->down.center_left = temp.right.bottom; 
  this->down.center = temp.right.center; 
  this->down.center_right = temp.right.top; 
  this->down.bottom_left = temp.right.bottom_right; 
  this->down.bottom = temp.right.center_right; 
  this->down.bottom_right = temp.right.top_right;
}

 
void cube::move_x_prime()
{
  cube temp = *this; 

  //this->front.top_left = temp.front.bottom_left; 
  this->front.bottom_left = temp.front.top_left; 
  //this->front.top = temp.front.center_left; 
  this->front.center_left = temp.front.top; 
  //this->front.top_right = temp.front.top_left;
  this->front.top_left = temp.front.top_right; 
  //this->front.center_left = temp.front.bottom;
  this->front.bottom = temp.front.center; 
  //this->front.center_right = temp.front.top;
  this->front.top = temp.front.center_right;  
  //this->front.bottom_left = temp.front.bottom_right; 
  this->front.bottom_right = temp.front.bottom_left; 
  //this->front.bottom = temp.front.center_right; 
  this->front.center_right = temp.front.bottom; 
  //this->front.bottom_right = temp.front.top_right;
  this->front.top_right = temp.front.bottom_right;  
 
  //this->back.bottom_left = temp.back.top_left;   
  this->back.top_left = temp.back.bottom_left; 
  //this->back.center_left = temp.back.top; 
  this->back.top = temp.back.center_left; 
  //this->back.top_left = temp.back.top_right;
  this->back.top_right = temp.back.top_left;  
  //this->back.bottom = temp.back.center_left;
  this->back.center_left = temp.back.bottom;    
  //this->back.top = temp.back.center_right; 
  this->back.center_right = temp.back.top;  
  //this->back.bottom_right = temp.back.bottom_left; 
  this->back.bottom_left = temp.back.bottom_right;  
  //this->back.center_right = temp.back.bottom; 
  this->back.bottom = temp.back.center_right;
  //this->back.top_right = temp.back.bottom_right;
  this->back.bottom_right = temp.back.top_right;   

  //this->up.top_left = temp.left.bottom_left; 
  this->left.bottom_left = temp.up.top_left; 
  //this->up.top = temp.left.center_left; 
  this->left.center_left = temp.up.top; 
  //this->up.top_right = temp.left.top_left;
  this->left.top_left = temp.up.top_right;  
  //this->up.center_left = temp.left.bottom;
  this->left.bottom = temp.up.center_left;  
  //this->up.center = temp.left.center; 
  this->left.center = temp.up.center; 
  //this->up.center_right = temp.left.top;
  this->left.top = temp.up.center_right;  
  //this->up.bottom_left = temp.left.bottom_right; 
  this->left.bottom_right = temp.up.bottom_left; 
  //this->up.bottom = temp.left.center_right;
  this->left.center_right = temp.up.bottom; 
  //this->up.bottom_right = temp.left.top_right;
  this->left.top_right = temp.up.bottom_right;  

  //this->right.top_left = temp.up.bottom_left;
  this->up.bottom_left = temp.right.top_left;  
  //this->right.top = temp.up.center_left; 
  this->up.center_left = temp.right.top; 
  //this->right.top_right = temp.up.top_left;
  this->up.top_left = temp.right.top_right;  
  //this->right.center_left = temp.up.bottom;
  this->up.bottom = temp.right.center_left;  
  //this->right.center = temp.up.center; 
  this->up.center = temp.right.center; 
  //this->right.center_right = temp.up.top;
  this->up.top = temp.right.center_right; 
  //this->right.bottom_left = temp.up.bottom_left; 
  this->up.bottom_right = temp.right.bottom_left; 
  //this->right.bottom = temp.up.center_right; 
  this->up.center_right = temp.right.bottom; 
  //this->right.bottom_right = temp.up.top_right;
  this->up.top_right = temp.right.bottom_right;  

  //this->left.top_left = temp.down.bottom_left;
  this->down.bottom_left = temp.left.top_left;  
  //this->left.top = temp.down.center_left; 
  this->down.center_left = temp.left.top; 
  //this->left.top_right = temp.down.top_left;
  this->down.top_left = temp.left.top_right;  
  //this->left.center_left = temp.down.bottom;
  this->down.bottom = temp.left.center_left;  
  //this->left.center = temp.down.center; 
  this->down.center = temp.left.center; 
  //this->left.center_right = temp.down.top;
  this->down.top = temp.left.center_right;  
  //this->left.bottom_left = temp.down.bottom_right;
  this->down.bottom_right = temp.left.bottom_left;  
  //this->left.bottom = temp.down.center_right; 
  this->down.center_right = temp.left.bottom; 
  //this->left.bottom_right = temp.down.top_right;
  this->down.top_right = temp.left.bottom_right;  

  //this->down.top_left = temp.right.bottom_left;
  this->right.bottom_left = temp.down.top_left;  
  //this->down.top = temp.right.center_left; 
  this->right.center_left = temp.down.top; 
  //this->down.top_right = temp.right.top_left;
  this->right.top_left = temp.down.top_right;  
  //this->down.center_left = temp.right.bottom;
  this->right.bottom = temp.down.center_left;  
  //this->down.center = temp.right.center; 
  this->right.center = temp.down.center; 
  //this->down.center_right = temp.right.top;
  this->right.top = temp.down.center_right;  
  //this->down.bottom_left = temp.right.bottom_right;
  this->right.bottom_right = temp.down.bottom_left;  
  //this->down.bottom = temp.right.center_right; 
  this->right.center_right = temp.down.bottom; 
  //this->down.bottom_right = temp.right.top_right;
  this->right.top_right = temp.down.bottom_right; 
}
                                                                                                                                                                                                                                                         
                                                                                                                                                                                                                                                                                                                                                                
