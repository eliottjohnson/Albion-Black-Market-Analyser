#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include <curl/curl.h>
#include <jsoncpp/json/json.h>


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


	Json::Value jsonData;
	Json::Reader jsonReader;
	std::ifstream is1("urlsAllitemsCaerleon.txt");
	std::ifstream is2("urlsAllitemsBlackMarket.txt");
	std::string url,url2;
	while(getline(is1, url) && getline(is2, url2))
	{
		//std::cout << url << std::endl << url2 << std::endl;

		CURL* curl = curl_easy_init();
		CURL* curl2 = curl_easy_init();

		// Set remote URL.
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl2, CURLOPT_URL, url2.c_str());

		// Don't bother trying IPv6, which would increase DNS resolution time.
		curl_easy_setopt(curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);
		curl_easy_setopt(curl2, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);

		// Don't wait forever, time out after 10 seconds.
		curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);
		curl_easy_setopt(curl2, CURLOPT_TIMEOUT, 10);

		// Follow HTTP redirects if necessary.
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		curl_easy_setopt(curl2, CURLOPT_FOLLOWLOCATION, 1L);

		// Response information.
		long httpCode(0);
		long httpCode2(0);
		std::unique_ptr<std::string> httpData(new std::string());
		std::unique_ptr<std::string> httpData2(new std::string());

		// Hook up data handling function.
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
		curl_easy_setopt(curl2, CURLOPT_WRITEFUNCTION, callback);

		// Hook up data container (will be passed as the last parameter to the
		// callback handling function).  Can be any pointer type, since it will
		// internally be passed as a void pointer.
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());
		curl_easy_setopt(curl2, CURLOPT_WRITEDATA, httpData2.get());

		// Run our HTTP GET command, capture the HTTP response code, and clean up.
		curl_easy_perform(curl);
		curl_easy_perform(curl2);
		curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
		curl_easy_getinfo(curl2, CURLINFO_RESPONSE_CODE, &httpCode2);
		curl_easy_cleanup(curl);
		curl_easy_cleanup(curl2);

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
		if (httpCode2 == 200) //BLACK MARKET DATA
		{
			if (jsonReader.parse(*httpData2.get(), jsonData))
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
		else
		{
			std::cout << "Couldn't GET from " << url << " - exiting" << std::endl;
			return 1;
		}
	}
    return 0;
}