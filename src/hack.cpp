#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "dataLoader.h"
#include<unistd.h> //for usleep
#define _ms 1000 // used for usleep
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
  
  dLoader->multiLoad();
  
  /*
  std::ifstream is("../urls/shortURLsCaerleon.txt");
  std::ifstream is2("../urls/shortURLsBlackMarket.txt");
  std::ofstream tempC,tempB;
  tempC.open("shortURLsCaerleon.txt");
  tempB.open("shortURLsBlackMarket.txt");
  int counter=0;
  std::string url,url2;
  Json::Value jsonDataCaerleon;
  Json::Value jsonDataBlackMarket;
  
  while(getline(is, url) && getline(is2, url2)){
    counter+=1;
    dLoader->LoadData(url,jsonDataCaerleon);
    dLoader->LoadData(url2,jsonDataBlackMarket);
    
    for (int i=0; i<jsonDataCaerleon.size(); i++){
      const std::size_t buy_price_min(jsonDataBlackMarket[i]["buy_price_min"].asUInt());
      const std::string buy_price_min_date(jsonDataBlackMarket[i]["buy_price_min_date"].asString());
      const std::size_t sell_price_min(jsonDataCaerleon[i]["sell_price_min"].asUInt());
      const std::string sell_price_min_date(jsonDataCaerleon[i]["sell_price_min_date"].asString());
      
      int benefit = (buy_price_min-(3*buy_price_min/100))-sell_price_min;
      if (benefit>5000 && sell_price_min!=0){
        
        std::string dataCaerleon = buy_price_min_date;
        dtCaerleon.clear();
        strtk::string_to_type_converter(dataCaerleon, fmtCaerleon);
        std::string dataBlackMarket = sell_price_min_date;
        dtBlackMarket.clear();
        strtk::string_to_type_converter(dataBlackMarket, fmtBlackMarket);
        
        if (dtCaerleon.day==gmtm->tm_mday && dtCaerleon.month==1 + gmtm->tm_mon && dtBlackMarket.day==gmtm->tm_mday && dtBlackMarket.month==1 + gmtm->tm_mon){ 
          std::cout<<std::string(200,' ')<<"\r";
          std::cout<<jsonDataCaerleon[i]["city"]<<"      Sell price min: "<<jsonDataCaerleon[i]["sell_price_min"]
                                                              <<" "<<dtCaerleon.day<<"-"<<dtCaerleon.month<<" "<<dtCaerleon.hour<<"h"<<dtCaerleon.minute
                                                              <<"   "<<jsonDataCaerleon[i]["item_id"]<<" quality: "<<jsonDataCaerleon[i]["quality"]<<std::endl;


          std::cout<<jsonDataBlackMarket[i]["city"]<<"   Buy price min: "<<jsonDataBlackMarket[i]["buy_price_min"]
                                                              <<" "<<dtBlackMarket.day<<"-"<<dtBlackMarket.month<<" "<<dtBlackMarket.hour<<"h"<<dtBlackMarket.minute<<std::endl;
          std::cout<<std::string(23,' ')+"Benefit: "<<benefit<<std::endl;
        }
      }
    }
    std::cout<<std::string(200,' ')<<"\r";
    std::cout<<"Searching: "<<counter<<"/2981 "<<url<<"\r"<<std::flush;
  }
  std::cout<<std::endl;
  */
  return 0;
}
