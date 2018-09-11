#ifndef RPB_JSONPARSER_H
#define RPB_JSONPARSER_H

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>

#include <json.hpp>

class JSONParser { 
public: 
   explicit JSONParser(const std::string filePath);

};

#endif // RPB_JSONPARSER_H
