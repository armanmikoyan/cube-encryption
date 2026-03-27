#include <iostream>

#include "cube.h"
#include "encryption.h"

int main() {
    std::string s = "hello_arman_mikoyan@mail.com";

    Encryption enc;
    
    std::string encrypted_value =  enc.encrypt(s);
    std::cout << encrypted_value << std::endl;

    std::string key = enc.get_key();
    std::cout << key << std::endl;

    std::string decrypted_value =  enc.decrypt(key);
    std::cout << decrypted_value << "\n";   
}
