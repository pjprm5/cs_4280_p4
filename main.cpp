// Paul Passiglia
// cs_4280 P3 - Static Semantics
// main.cpp


#include <iostream>
#include <string>
#include <fstream>
#include "parser.h"
#include "node.h"

using namespace std;

//main prints out the tree for parsing
int main(int argc, char* argv[])
{
  if(argc == 1)
  {
    node<std::string> root = parser(cin);
    root.statChecker();
  }
  else if(argc == 2) //check to see if the file has the proper extension
  {
    string fext, filename(""), filearg(argv[1]);
    int length = filearg.length();

    if(length > 2)
    {
      fext = filearg.substr(length-3, length);

      if(fext == ".fs")
      {
        filename = filearg;
      }
    }

    if(filename == "")
    {
      filename = filearg + ".fs";
    }

    ifstream fs(filename.c_str());

    if(fs)
    {
      node<std::string> root = parser(fs);
      root.statChecker();
    }
    else
    {
      cout << filename << ": cannot be opened.";
      return 1;
    }
  }
  else
  {
    cout << "Invalid # of arguments given.";
    return 2;
  }

  cout << "Program finished." << endl;
  return 0;
}
