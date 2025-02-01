#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr test;
  test.push_back("2");
  test.push_back("3");
  test.push_front("1");
  std:: cout<< test.front()<<std::endl;
  std:: cout<< test.back()<<std::endl;
  test.pop_back();
  test.pop_front();
  std:: cout<<test.size()<<std::endl;
  
  return 0;


}
