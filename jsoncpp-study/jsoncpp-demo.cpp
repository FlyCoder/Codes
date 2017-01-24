#include <iostream>
#include <fstream>
#include "dist/jsoncpp.cpp"
#include "dist/json/json.h"
#include "dist/json/json-forwards.h"
#include <string>
using namespace std;

void JsonParse(const std::string& doc);
int main(int argc, char *argv[]) {
    if (argc == 1) {
      cout << "Please a file name as param" << endl;
      return 0;
    }
    ifstream in(argv[1], ios_base::in);
    istreambuf_iterator<char> beg(in), end;
    string strdata(beg, end); 
    in.close();
    cout << strdata << endl;
    
    JsonParse(strdata);
    return 0;
}

void JsonParse(const std::string& doc) {
   Json::Value root;
   Json::Reader reader;
   bool parsing_right = reader.parse(doc, root);
   if (!parsing_right) {
     cout << "Fail to parse document." << endl;
     return;
   }
   if (!root.isMember("request")) {
     cout << "Can not get request" << endl;
     return;
   }
   auto request = root["request"];
   Json::Value::Members members = request.getMemberNames();
   cout << "Get all members:" << members.size() << endl;
   for (size_t i = 0; i < members.size(); i++) {
     cout << members[i] << endl;
   }
   cout << "------------" << endl;
   if (request.isMember("id")) {
     cout << "Get a id:" << request["id"].asString() << endl;
   }
}
