#include "cube.h"

Cube::Cube(std::string&& cube)
{
    _cube = cube;
    if (_cube.size() < 8) 
    {
        for (int i = cube.size(); i < 8; ++i)
        {
            _cube += '$';    
        }
    }
}

char& Cube::operator[](size_t i)
{
    return _cube[i];
}

std::string Cube::get_cube() const
{
    return _cube;
}

void Cube::set_cube(const std::string& cube)
{
    _cube = cube;
}
