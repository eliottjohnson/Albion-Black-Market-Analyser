#include <iostream>
#include <fstream>
#include "dataLoader.h"

#include <curl/curl.h>
#include <jsoncpp/json/json.h>

using namespace HACK;

int main()
{

  std::cout<<std::endl;
  std::cout<<"███████╗██╗     ██╗ ██████╗ ████████╗████████╗██╗     ███████╗██████╗  ██████╗ ██╗   ██╗ ██████╗ ███████╗"<<std::endl;
  std::cout<<"██╔════╝██║     ██║██╔═══██╗╚══██╔══╝╚══██╔══╝██║     ██╔════╝██╔══██╗██╔═══██╗██║   ██║██╔════╝ ██╔════╝"<<std::endl;
  std::cout<<"█████╗  ██║     ██║██║   ██║   ██║      ██║   ██║     █████╗  ██████╔╝██║   ██║██║   ██║██║  ███╗█████╗  "<<std::endl;
  std::cout<<"██╔══╝  ██║     ██║██║   ██║   ██║      ██║   ██║     ██╔══╝  ██╔══██╗██║   ██║██║   ██║██║   ██║██╔══╝  "<<std::endl;
  std::cout<<"███████╗███████╗██║╚██████╔╝   ██║      ██║   ███████╗███████╗██║  ██║╚██████╔╝╚██████╔╝╚██████╔╝███████╗"<<std::endl;
  std::cout<<"╚══════╝╚══════╝╚═╝ ╚═════╝    ╚═╝      ╚═╝   ╚══════╝╚══════╝╚═╝  ╚═╝ ╚═════╝  ╚═════╝  ╚═════╝ ╚══════╝"<<std::endl;
  std::cout<<"                                                                                                         "<<std::endl;

  dataLoader *dLoader = new dataLoader();
  
  std::ifstream is("../urls/urls.txt");
  std::string url;
  
  while(getline(is, url)){
    dLoader->LoadData(url);
  }


  return 0;
}
