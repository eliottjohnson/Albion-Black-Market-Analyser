#include <iostream>
#include <fstream>
#include "json.hpp"
using json = nlohmann::json;

int main()
{
  std::cout<<"\nAlbion\n"<<std::endl;

  //JSON readout
  //std::ifstream f("/mnt/c/Users/Eliott Johnson/Google Drive/AlbionHack/data.json");
  std::ifstream f("/mnt/c/Users/eliot/Google Drive/AlbionHack/data.json");
  json myjson = json::parse(f);

  for (int i=0; i<myjson.size();i++){
    std::cout<<myjson[i]["item_id"].get<std::string>()<<std::endl;
  }

  return 0;
}