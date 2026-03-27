#include "encryption.h"


Encryption::~Encryption()
{
    for (int i = 0; i < _cubes.size(); ++i)
    {
        delete _cubes[i];
    }
}

int Encryption::random_number()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(1, 3);

    return distribution(gen);
}

std::string Encryption::get_key() const
{
    return _key;
}

void Encryption::create_cubes(std::string& text)
{
    if (text.size() < 8 && text.size() > 0)
        {
            _cubes.push_back(new Cube{std::move(text)});
        }
        else 
        {
            int count = 0;
            std::string tmp;
            for (int i = 0; i < text.size(); ++i)
            {
                tmp += text[i];
                count++;
                if (count == 8)
                {
                    _cubes.push_back(new Cube{std::move(tmp)});
                    count = 0;
                    tmp.clear();
                }  
            }
            if (count > 0)
            {   
                _cubes.push_back(new Cube{std::move(tmp)});
            }
        }
}

std::string& Encryption::encrypt(std::string& text)
{
    create_cubes(text);
    int random_num{random_number()};
    for (int i = 0; i < _cubes.size(); ++i)
    {
        rotate_right(*(_cubes[i]), random_num);
        _key += 'R';
        _key += static_cast<char>(random_num) + '0';
        _key += ':';
        random_num = random_number();

        rotate_left(*(_cubes[i]), random_num);
        _key += 'L';
        _key += static_cast<char>(random_num) + '0';
        _key += ':';
        random_num = random_number();

        rotate_up(*(_cubes[i]), random_num);
        _key += 'U';
        _key += static_cast<char>(random_num) + '0';
        _key += ':';
        random_num = random_number();

        rotate_down(*(_cubes[i]), random_num);
        _key += 'D';
        _key += static_cast<char>(random_num) + '0';
        _key += ':';
        random_num = random_number();

        _hash += _cubes[i]->get_cube();
    }
    return _hash;
}



std::string Encryption::decrypt(std::string key)
{
    
    int current = 11;
    int difference = 12;
    int k = 2;
    for (int i = 0; i < _cubes.size(); ++i)
    {
        for(int t = 0; t < 13; ++t)
        {
            char sym = key[current];
            int rotation_count = key[current + 1] - '0';
            if (sym == 'D')
            {
                rotate_up(*(_cubes[i]), rotation_count);
            }
            else if (sym == 'U')
            {
                rotate_down(*(_cubes[i]), rotation_count);
            }
            else if (sym == 'L')
            {
                rotate_right(*(_cubes[i]), rotation_count);
            }
            else if (sym == 'R')
            {
                rotate_left(*(_cubes[i]), rotation_count);
            }
            --current;  
        }
        _unhash += _cubes[i]->get_cube();
        current = difference * k - 1;   
        k++;  
    }
    remove_additional_symbol();
    return _unhash;
}


void Encryption::rotate_right(Cube& cube, size_t count)
{
    for (int i = 0; i < count; ++i)
    {
        std::string tmp = cube.get_cube();
        cube[1] = tmp[0];
        cube[5] = tmp[1];
        cube[4] = tmp[5];
        cube[0] = tmp[4];

        cube[2] = tmp[3];
        cube[6] = tmp[2];
        cube[7] = tmp[6];
        cube[3] = tmp[7];  
    }
}

void Encryption::rotate_left(Cube& cube, size_t count)
{
    for (int i = 0; i < count; ++i)
    {
        std::string tmp = cube.get_cube();
        cube[0] = tmp[1];
        cube[4] = tmp[0];
        cube[5] = tmp[4];
        cube[1] = tmp[5];

        cube[3] = tmp[2];
        cube[7] = tmp[3];
        cube[6] = tmp[7];
        cube[2] = tmp[6];  
    }
}

void Encryption::rotate_up(Cube& cube, size_t count)
{
    for (int i = 0; i < count; ++i)
    {
        std::string tmp = cube.get_cube();
        cube[4] = tmp[0];
        cube[7] = tmp[4];
        cube[3] = tmp[7];
        cube[0] = tmp[3];

        cube[5] = tmp[1];
        cube[6] = tmp[5];
        cube[2] = tmp[6];
        cube[1] = tmp[2];  
    }
}

void Encryption::rotate_down(Cube& cube, size_t count)
{
    for (int i = 0; i < count; ++i)
    {
        std::string tmp = cube.get_cube();
        cube[3] = tmp[0];
        cube[7] = tmp[3];
        cube[4] = tmp[7];
        cube[0] = tmp[4];

        cube[2] = tmp[1];
        cube[6] = tmp[2];
        cube[5] = tmp[6];
        cube[1] = tmp[5];  
    }
}

void Encryption::remove_additional_symbol()
{
    size_t found = _unhash.find('$');
    while (found != std::string::npos) 
    {
        _unhash.erase(found, 1);
        found = _unhash.find('$', found);
    }
}
