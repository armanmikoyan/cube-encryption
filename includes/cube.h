#ifndef CUBE_H
#define CUBE_H

#include <iostream>
#include <string>

class Cube {
public:
    Cube(std::string&&);
    char& operator[](size_t);

public:
    std::string      get_cube() const;
    void set_cube(const std::string&);

private:
    std::string _cube;
};

#endif // CUBE_H
