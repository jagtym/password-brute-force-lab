#include <fstream>
#include <iostream>
#include <string>

#include "encrypt.h"

int main() {
    std::ifstream file("password.txt");

    if (!file.is_open()) {
        std::cout << "Nie udało się otworzyć pliku do odczytu\n";
        return 1;
    }

    std::string password;
    file >> password;

    const std::string chars =
        "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int len = 1; len <= 10; ++len) {
        std::string comb(len, '0');
        for (int i = 0; i < len; ++i) {
            comb[i] = chars[0];
        }

        bool done = false;
        while (!done) {
            std::cerr << comb << "   |   ";
            std::string enc = encrypt(comb);
            std::cerr << enc << '\n';

            if (enc == password) {
                std::cout << comb << std::endl;
                return 0;
            }

            for (int i = len - 1; i >= 0; --i) {
                int pos = chars.find(comb[i]) + 1;
                if (pos >= chars.size()) {
                    comb[i] = chars[0];
                } else {
                    comb[i] = chars[pos];
                    break;
                }
                if (i == 0)
                    done = true;
            }
        }
    }
}
