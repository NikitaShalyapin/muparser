#include <iostream>
#include <unordered_map>

#include "muParser.h"

int main(int argc, char* argv[])
{
  using namespace mu;

  try
  {
    Parser p;
    std::string str;
    std::string strtmp;
    std::string strtmpval;
    std::unordered_map<std::string, double> umap;

    std::cout << "<< Enter the mathematical expression:" << std::endl;
    std::cout << ">>";
    getline(std::cin,str);
    p.SetExpr(str);

    std::cout << "<< OK" << std::endl;
    str.clear();

    while(1)
    {
      int i = 0;

      std::cout << "<< Enter the value of the variables (x=value) or the command: -calculate -quit:" << std::endl;
      std::cout << ">>";
      getline(std::cin,str);

      if(str == "calculate"){
        std::cout << "<< " << p.Eval()<< std::endl;
        break;
      }

      else if(str == "quit")
        break;

      else {
        while (str[i] != '=') {
          strtmp += str[i];
          i++;
        }
        i++;

        while (str[i] != '\0') {
          strtmpval += str[i];
          i++;
        }

        std::cout << "strtmp =" << strtmp << " " << "strtmpval =" << strtmpval << std::endl;
        umap.insert(std::pair<std::string, double>(strtmp, atol(strtmpval.c_str())));
        p.DefineVar(strtmp, &umap.at(strtmp));
        std::cout << "<< OK" << std::endl;

        strtmp.clear();
        strtmpval.clear();
        str.clear();

      }
    }
  }
  catch (Parser::exception_type &e)
  {
    std::cout << e.GetMsg() << std::endl;
  }
  return 0;
}