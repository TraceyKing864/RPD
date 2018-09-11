#include "JSONParser.hpp"

int main(int argc, char** argv) {
   std::string file_path(argv[1]);
   auto test_parser = new JSONParser(file_path);
}
