#include <iostream>
#include <fstream>
#include "dataLoader.h"

#include <curl/curl.h>
#include <jsoncpp/json/json.h>

using namespace HACK;

int main()
{

  std::cout<<"\nAlbion\n"<<std::endl;

  dataLoader *dLoader = new dataLoader();
  
  dLoader->LoadData();

  return 0;
}