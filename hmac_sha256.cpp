// g++ -o test hmac_sha256.cpp -lssl
#include <openssl/hmac.h>
#include <openssl/evp.h>
#include <iostream>
#include <string>

int main() {
  unsigned int md_len = 0;
  unsigned char md[EVP_MAX_MD_SIZE] = {0};
  char result[EVP_MAX_MD_SIZE * 2] = {0}; 
  unsigned int i = 0;
  std::string key = "ZQXHxgPfqlgW3NNpDjwMiLYenx86FkxP";
  std::string d = "client_id=1325897899&expires=1462786872&type=all&user_id=123456";
  HMAC(EVP_sha256(), key.data(), key.length(), 
       (const unsigned char*)d.data(), d.length(),
       md, &md_len);
  // Convert the message digest to hexadecimal format string
  for (i = 0; i < md_len; i++) {
    sprintf(&(result[i * 2]), "%02x", md[i]);
  }        
  std::string sign_final = std::string(result, md_len * 2); 
  std::cout << "final:" << sign_final << std::endl;
  return 0;
}
