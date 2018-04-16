#include "shell.hpp"

void shell::menu()
{
  bool cont = true; 
  std::string comm, alg;
  while(cont)
  {
    std::cout << "vc: ";
    std::cin >> comm;
    
    if(comm == "print")
    {
      c.print(); 
    }
    else if(comm == "algo")
    {
      std::cin >> alg; 
      vec = parse_execute_emplace(alg);
    } 
    else if(comm == "exit") cont = false; 
    else std::cout << "Invalid command.\n";
  }
}

std::vector<move> shell::parse_execute_emplace(std::string& alg)
{
  std::vector<move> v; 
  const char* ptr = alg.data(); 
  while(*ptr != '\0')
  {
    switch(*ptr)
    {
    case 'r': 
      if(*(ptr + 1) == '\'')
      {
        v.emplace_back(RIGHT_PRIME);
        ptr += 2; 
      }
      else 
      {
        v.emplace_back(RIGHT);
        ++ptr; 
      }
      break; 
    case 'l':
      if(*(ptr + 1) == '\'')
      {
        v.emplace_back(LEFT_PRIME);
        ptr += 2; 
      }
      else
      {
        v.emplace_back(LEFT);
        ++ptr;
      }
      break; 
    case 'f': 
      if(*(ptr + 1) == '\'')
      {
        v.emplace_back(FRONT_PRIME);
        ptr += 2; 
      }
      else 
      {
        v.emplace_back(FRONT);
        ++ptr; 
      }
      break; 
    case 'b': 
      if(*(ptr + 1) == '\'')
      {
        v.emplace_back(BACK_PRIME);
        ptr += 2; 
      }
      else 
      {
        v.emplace_back(BACK);
        ++ptr; 
      }
      break; 
    case 'u':
      if(*(ptr + 1) == '\'')
      {
        v.emplace_back(UP_PRIME);
        ptr += 2;  
      }
      else 
      {
        v.emplace_back(UP);
        ++ptr; 
      }
      break;
    case 'd':
      if(*(ptr + 1) == '\'')
      {
        v.emplace_back(DOWN_PRIME);
        ptr += 2; 
      } 
      else 
      {
        v.emplace_back(DOWN);
        ++ptr; 
      }
      break;
    case 'x': 
      if(*(ptr + 1) == '\'')
      {
        v.emplace_back(X_PRIME);
        ptr += 2; 
      }
      else
      {
        v.emplace_back(X);
        ++ptr; 
      } 
      break; 
    default:
      std::cout << "Invalid algorithm.\n";
      return vec; 
      break; 
    }//switch 
  }//while
  
  execute(v);
  return v; 
}

void shell::execute(std::vector<move> v) 
{
  c.print();
  std::cout << "------------------------------------------\n"; 
  for(std::vector<move>::iterator it = v.begin(); it != v.end(); ++it)
  {
    switch(*it)
    {
      case RIGHT: 
        c.move_right();
        break; 
      case RIGHT_PRIME: 
        c.move_right_prime(); 
        break; 
      case LEFT: 
        c.move_left(); 
        break; 
      case LEFT_PRIME: 
        c.move_left_prime(); 
        break; 
      case UP: 
        c.move_up(); 
        break; 
      case UP_PRIME: 
        c.move_up_prime(); 
        break; 
      case DOWN: 
        c.move_down(); 
        break; 
      case DOWN_PRIME: 
        c.move_down_prime(); 
        break; 
      case FRONT: 
        c.move_front(); 
        break; 
      case FRONT_PRIME: 
        c.move_front_prime(); 
        break;
      case BACK: 
        c.move_back(); 
        break;
      case BACK_PRIME: 
        c.move_back_prime(); 
        break; 
      case X: 
        c.move_x(); 
        break; 
      case X_PRIME: 
        c.move_x_prime();
        break;  
    }
    c.print(); 
    if(it != v.end() - 1)
      std::cout << "------------------------------------------\n";
  }
}
