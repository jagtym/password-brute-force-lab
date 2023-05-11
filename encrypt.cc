#include <fstream>
#include <iostream>
#include <string>

#include "encrypt.h"

int main() {
  std::ofstream file("password.txt");

  if (!file.is_open()) {
    std::cout << "Nie uda�~Bo si�~Y otworzy�~G pliku do zapisu!\n";
    return 1;
  }

  std::cout << "Wpisz has�~Bo do zaszyfrowania ;)\n";

  std::string password;
  std::cin >> password;

  file << encrypt(password) << std::endl;
}
