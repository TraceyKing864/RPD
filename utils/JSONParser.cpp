#include "JSONParser.hpp"

// the json data type only shows examples of taking a stringstream as 
// an input argument, so I that's why I create the stringstream and
// don't do any work directly on the ifstream object
JSONParser::JSONParser(std::string file_path) {
   std::ifstream file(file_path);
   std::stringstream usable_stream;
   if(file) {
      usable_stream << file.rdbuf();
      file.close();
   }
   nlohmann::json file_data = nlohmann::json::parse(usable_stream);
}
