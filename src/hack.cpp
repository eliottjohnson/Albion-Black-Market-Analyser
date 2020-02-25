#include <iostream>
#include <fstream>
#include <iomanip>
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
  
  //std::ifstream is("../urls/SelectedUrlsCaerleon.txt");
  //std::ifstream is2("../urls/SelectedUrlsBlackMarket.txt");
  std::ifstream is("../urls/shortURLsCaerleon.txt");
  std::ifstream is2("../urls/shortURLsBlackMarket.txt");
  
  std::ofstream tempC,tempB;
  tempC.open("shortURLsCaerleon.txt");
  tempB.open("shortURLsBlackMarket.txt");
  
  
  std::string url,url2;

  Json::Value jsonDataCaerleon;
  Json::Value jsonDataBlackMarket;
  
  while(getline(is, url) && getline(is2, url2)){

    dLoader->LoadData(url,jsonDataCaerleon);
    dLoader->LoadData(url2,jsonDataBlackMarket);
    
    for (int i=0; i<jsonDataCaerleon.size(); i++){
      
      
      const std::size_t buy_price_min(jsonDataBlackMarket[i]["buy_price_min"].asUInt());
      const std::size_t sell_price_min(jsonDataCaerleon[i]["sell_price_min"].asUInt());
      
      int benefit = (buy_price_min-(3*buy_price_min/100))-sell_price_min;
      if (benefit>1000){
        std::cout<<jsonDataCaerleon[i]["item_id"]<<"quality: "<<jsonDataCaerleon[i]["quality"]<<" "<<jsonDataCaerleon[i]["city"]<<"sell price min: "<<jsonDataCaerleon[i]["sell_price_min"]<<std::endl;
        std::cout<<jsonDataBlackMarket[i]["item_id"]<<"quality: "<<jsonDataBlackMarket[i]["quality"]<<" "<<jsonDataBlackMarket[i]["city"]<<" buy price min: "<<jsonDataBlackMarket[i]["buy_price_min"]<<std::endl;
        std::cout<<"Benefit: "<<benefit<<std::endl;
        //std::cout << jsonDataCaerleon.toStyledString() << std::endl;
        //std::cout << jsonDataBlackMarket.toStyledString() << std::endl;
      }
      /*
      //if date = "0001-01-01T00:00:00" remove line from both text file
      if (jsonDataCaerleon[i]["sell_price_min_date"]!="0001-01-01T00:00:00"){
        std::cout<<std::endl<<"    "<<url<<" has been added from both files"<<std::endl;
        tempC << url << std::endl;
        tempB << url2 << std::endl;
      }
      */
    }
  }


  return 0;
}
