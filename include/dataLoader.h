#include <curl/curl.h>
#include <jsoncpp/json/json.h>
#include <bits/stdc++.h> 

namespace HACK {
	

class dataLoader{
	
public:
    
		bool LoadData(std::string url, Json::Value &jsonData);
    static size_t write_cb(char *data, size_t size, size_t nmemb, void *userp);
    static void add_transfer(CURLM *cm, int i);
    int multiLoad();
	
};
}
