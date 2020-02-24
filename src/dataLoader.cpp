#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <jsoncpp/json/json.h>
#include "dataLoader.h"

namespace
{
    std::size_t callback(
            const char* in,
            std::size_t size,
            std::size_t num,
            std::string* out)
    {
        const std::size_t totalBytes(size * num);
        out->append(in, totalBytes);
        return totalBytes;
    }
}
using namespace HACK;

bool dataLoader::LoadData(std::string url){
  
  Json::Value jsonData;
	Json::Reader jsonReader;

  std::cout << url << std::endl;

  CURL* curl = curl_easy_init();

  // Set remote URL.
  curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

  // Don't bother trying IPv6, which would increase DNS resolution time.
  curl_easy_setopt(curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);

  // Don't wait forever, time out after 10 seconds.
  curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

  // Follow HTTP redirects if necessary.
  curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

  // Response information.
  long httpCode(0);
  std::unique_ptr<std::string> httpData(new std::string());

  // Hook up data handling function.
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);

  // Hook up data container (will be passed as the last parameter to the
  // callback handling function).  Can be any pointer type, since it will
  // internally be passed as a void pointer.
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());

  // Run our HTTP GET command, capture the HTTP response code, and clean up.
  curl_easy_perform(curl);
  curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
  curl_easy_cleanup(curl);

  if (httpCode == 200) //CAERLEON DATA
  {
    if (jsonReader.parse(*httpData.get(), jsonData))
    {
      std::cout << jsonData.toStyledString() << std::endl;
      //const std::size_t buy_price_max(jsonData[0]["buy_price_max"].asUInt());
      //const std::string city(jsonData[0]["city"].asString());
      //std::cout <<"Buy Price Max: " << buy_price_max << std::endl;
      //std::cout <<"City: " << city << std::endl;
    }
    else
    {
      std::cout << "Could not parse HTTP data as JSON" << std::endl;
      std::cout << "HTTP data was:\n" << *httpData.get() << std::endl;
      return 1;
    }
  }
	
  return 0;
}