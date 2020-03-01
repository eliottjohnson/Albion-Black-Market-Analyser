#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "dataLoader.h"
#include<unistd.h> //for usleep
#define _s 1000000 // used for usleep
#include <curl/curl.h>
#include <jsoncpp/json/json.h>
#include <ctime>



using namespace HACK;

int main()
{

  // current date/time based on current system
  time_t now = time(0);
  tm *gmtm = gmtime(&now);

  std::cout<<std::endl;
  std::cout<<" █████╗ ██╗     ██████╗ ██╗ ██████╗ ███╗   ██╗██╗  ██╗ █████╗  ██████╗██╗  ██╗"<<std::endl;
  std::cout<<"██╔══██╗██║     ██╔══██╗██║██╔═══██╗████╗  ██║██║  ██║██╔══██╗██╔════╝██║ ██╔╝"<<std::endl;
  std::cout<<"███████║██║     ██████╔╝██║██║   ██║██╔██╗ ██║███████║███████║██║     █████╔╝ "<<std::endl;
  std::cout<<"██╔══██║██║     ██╔══██╗██║██║   ██║██║╚██╗██║██╔══██║██╔══██║██║     ██╔═██╗ "<<std::endl;
  std::cout<<"██║  ██║███████╗██████╔╝██║╚██████╔╝██║ ╚████║██║  ██║██║  ██║╚██████╗██║  ██╗"<<std::endl;
  std::cout<<"╚═╝  ╚═╝╚══════╝╚═════╝ ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝"<<std::endl;
  std::cout<<gmtm->tm_mday<<"/"<<1 + gmtm->tm_mon<<"/"<<1900 + gmtm->tm_year<<"  UTC: "<<gmtm->tm_hour<<":"<<gmtm->tm_min<<":"<<gmtm->tm_sec
           <<"                                       by Eliottlerouge\n"<<std::endl;



  dataLoader *dLoader = new dataLoader();
  
  while (true){
  dLoader->multiLoad();
  usleep(120*_s); //refresh every x seconds
  std::cout<<"REFRESH"<<std::endl;
  
  }
  
  return 0;
}
