#include <iostream>
#include <fstream>
#include "dataLoader.h"
#include<unistd.h> //for usleep
#define _ms 1000 // used for usleep
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
  
  std::ifstream is("../urls/urlsBagsCaerleon.txt");
  std::ifstream is2("../urls/urlsBagsBlackMarket.txt");
  std::string url,url2;

  Json::Value jsonDataCaerleon;
  Json::Value jsonDataBlackMarket;
  
  while(getline(is, url) && getline(is2, url2)){
    dLoader->LoadData(url,jsonDataCaerleon);
    dLoader->LoadData(url2,jsonDataBlackMarket);
    
    for (int i=0; i<jsonDataCaerleon.size(); i++){
      std::cout<<jsonDataCaerleon[i]["item_id"]<<"quality: "<<jsonDataCaerleon[i]["quality"]<<" "<<jsonDataCaerleon[i]["city"]<<"sell price min: "<<jsonDataCaerleon[i]["sell_price_min"]<<std::endl;
      std::cout<<jsonDataBlackMarket[i]["item_id"]<<"quality: "<<jsonDataBlackMarket[i]["quality"]<<" "<<jsonDataBlackMarket[i]["city"]<<" buy price min: "<<jsonDataBlackMarket[i]["buy_price_min"]<<std::endl;
    }
  }


  return 0;
}
