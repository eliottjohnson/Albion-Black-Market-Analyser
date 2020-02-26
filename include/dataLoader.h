#include <curl/curl.h>
#include <jsoncpp/json/json.h>

namespace HACK {
	

class dataLoader{
	
public:

		bool LoadData(std::string url, Json::Value &jsonData);
    
	
};
}
