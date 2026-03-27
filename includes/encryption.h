#ifndef ENCRYIPTION_H
#define ENCRYIPTION_H

#include "cube.h"

#include <vector>
#include <string>
#include <random>

class Encryption {
public:
    Encryption() = default;
   ~Encryption(); 

public:     
    std::string& encrypt(std::string&);
    std::string   decrypt(std::string);
    std::string        get_key() const;

private:
    void rotate_right(Cube&, size_t);
    void  rotate_left(Cube&, size_t);
    void    rotate_up(Cube&, size_t);
    void  rotate_down(Cube&, size_t);
    void  create_cubes(std::string&);
    void  remove_additional_symbol();
    static int       random_number();

public:
   std::vector<Cube*> _cubes;
   std::string         _hash;
   std::string       _unhash;
   std::string          _key;
};

#endif // ENCRYIPTION_H
