#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "dataLoader.h"
#include<unistd.h> //for usleep
#define _ms 1000 // used for usleep
#include <curl/curl.h>
#include <jsoncpp/json/json.h>
#include "datetime_utils.hpp"

using namespace HACK;

int main()
{

  std::cout<<std::endl;

std::cout<<" █████╗ ██╗     ██████╗ ██╗ ██████╗ ███╗   ██╗██╗  ██╗ █████╗  ██████╗██╗  ██╗"<<std::endl;
std::cout<<"██╔══██╗██║     ██╔══██╗██║██╔═══██╗████╗  ██║██║  ██║██╔══██╗██╔════╝██║ ██╔╝"<<std::endl;
std::cout<<"███████║██║     ██████╔╝██║██║   ██║██╔██╗ ██║███████║███████║██║     █████╔╝ "<<std::endl;
std::cout<<"██╔══██║██║     ██╔══██╗██║██║   ██║██║╚██╗██║██╔══██║██╔══██║██║     ██╔═██╗ "<<std::endl;
std::cout<<"██║  ██║███████╗██████╔╝██║╚██████╔╝██║ ╚████║██║  ██║██║  ██║╚██████╗██║  ██╗"<<std::endl;
std::cout<<"╚═╝  ╚═╝╚══════╝╚═════╝ ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝"<<std::endl;
std::cout<<"                                                              by Eliottlerouge\n"<<std::endl;

  dataLoader *dLoader = new dataLoader();
  
   // Setup the RFC-822 HTTP date-time format handlers
   dt_utils::datetime dt;
   dt_utils::datetime_format10 fmt(dt);
  
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
      const std::string buy_price_min_date(jsonDataBlackMarket[i]["buy_price_min_date"].asString());
      const std::size_t sell_price_min(jsonDataCaerleon[i]["sell_price_min"].asUInt());
      const std::string sell_price_min_date(jsonDataCaerleon[i]["sell_price_min_date"].asString());
      

     std::string data = buy_price_min_date;
     std::string data2 = sell_price_min_date;
     
     /*
     dt.clear();
     if (strtk::string_to_type_converter(data, fmt))
     {
        std::cout << "Date-Time: " << data      ;
        std::cout << "Year:   "    << dt.year   ;
        std::cout << "Month:  "    << dt.month  ;
        std::cout << "Day:    "    << dt.day    ;
        std::cout << "Hour:   "    << dt.hour   ;
        std::cout << "Minute: "    << dt.minute ;
        std::cout << "Second: "    << dt.second ;
        
     }
     else{
      std::cout << "Error occured during parsing of date-time: " << data << "\n";
     }
     */
       
      int benefit = (buy_price_min-(3*buy_price_min/100))-sell_price_min;
      if (benefit>1000 && sell_price_min!=0){ //implement a check time must be less then 1 hour
        dt.clear();
        strtk::string_to_type_converter(data, fmt);
        std::cout<<jsonDataCaerleon[i]["city"]<<"      sell price min: "<<jsonDataCaerleon[i]["sell_price_min"]
                                                            <<" "<<dt.day<<"-"<<dt.month<<" "<<dt.hour<<"h"<<dt.minute
                                                            <<"   "<<jsonDataCaerleon[i]["item_id"]<<" quality: "<<jsonDataCaerleon[i]["quality"]<<std::endl;

        dt.clear();
        strtk::string_to_type_converter(data2, fmt);
        std::cout<<jsonDataBlackMarket[i]["city"]<<"   buy price min: "<<jsonDataBlackMarket[i]["buy_price_min"]
                                                            <<" "<<dt.day<<"-"<<dt.month<<" "<<dt.hour<<"h"<<dt.minute<<std::endl;
        std::cout<<std::string(23,' ')+"Benefit: "<<benefit<<std::endl;
        //std::cout << jsonDataCaerleon.toStyledString() << std::endl;
        //std::cout << jsonDataBlackMarket.toStyledString() << std::endl;
      }
    }
  }


  return 0;
}
