#include <cstring>
#include <iomanip>
#include <openssl/sha.h>
#include <sstream>

std::string encrypt(std::string password) {

  unsigned char hash[SHA_DIGEST_LENGTH];

  SHA1((const unsigned char *)password.c_str(), password.length(), hash);

  std::stringstream ss;
  for (int i = 0; i < SHA_DIGEST_LENGTH; i++) {
    ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
  }

  std::string hash_str = ss.str();
  return hash_str;
}
