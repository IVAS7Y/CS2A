// Pet_Store.cpp
#include <iostream>
#include <sstream>
#include <vector>
#include "Pet_Store.h"
#include "Pet.h"
using namespace std;
Pet_Store::Pet_Store(size_t n)
{
    _pets.resize(n);
    _sort_order = NONE;

}
void Pet_Store::set_size(size_t n)
{
    _pets.resize(n);
}
size_t Pet_Store::get_size() const
{
    return _pets.size();
}
void Pet_Store::clear()
{
    _pets.clear();
}
void Pet_Store::populate_with_n_random_pets(size_t n)
{
    Pet::get_n_pets(n, _pets, 7);
    _sort_order = BY_ID;
}

bool Pet_Store::_id_compare(const Pet &p1, const Pet &p2)
{
    return p1.get_id() < p2.get_id();
}
bool Pet_Store::_name_compare(const Pet &p1, const Pet &p2)
{
    return p1.get_name() < p2.get_name();
}
void Pet_Store::_sort_pets_by_id()
{
    std::sort(_pets.begin(), _pets.end(), Pet_Store::_id_compare);
    _sort_order = BY_ID;
}
void Pet_Store::_sort_pets_by_name()
{
    std::sort(_pets.begin(), _pets.end(), Pet_Store::_name_compare);
    _sort_order = BY_NAME;
}
bool Pet_Store::find_pet_by_id_lin(long id, Pet &pet)
{

    for (const Pet &p : _pets)
    {
        if (p.get_id() == id)
        {
            pet = p;
            return true;
        }
    }
    return false;
}

bool Pet_Store::find_pet_by_name_lin(string name, Pet &pet)
{
    for (const Pet &p : _pets)
    {
        if (p.get_name() == name)
        {
            pet = p;
            return true;
        }
    }
    return false;
}

bool Pet_Store::find_pet_by_id_bin(long id, Pet &pet)
{
    if (_sort_order != BY_ID)
    {
        _sort_pets_by_id();
    }
    int low = 0;
    int num_pets = _pets.size();
    int high = num_pets - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (_pets[mid].get_id() == id)
        {
            pet = _pets[mid];
            return true;
        }
        else if (id > _pets[mid].get_id())
        {
            low = mid + 1;
        }
        else if (id < _pets[mid].get_id())
        {
            high = mid - 1;
        }
    }
    return false;
}

bool Pet_Store::find_pet_by_name_bin(string name, Pet &pet)
{
    if (_sort_order != BY_NAME)
    {
        _sort_pets_by_name();
    }
    int low = 0;
    int num_pets = _pets.size();
    int high = num_pets - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (_pets[mid].get_name() == name)
        {
            pet = _pets[mid];
            return true;
        }
        else if (name > _pets[mid].get_name())
        {
            low = mid + 1;
        }
        else if (name < _pets[mid].get_name())
        {
            high = mid - 1;
        }
    }
    return false;
}

string Pet_Store::to_string(size_t n1, size_t n2)
{
    string res;
    if((n2 - n1) > ((sizeof(_pets)/sizeof(_pets[0]))-1)){
        return res;
    } else {    
        for(size_t i = n1; i <= n2; i++){
            res += _pets[i].to_string() + "\n";
        }
        return res;
    }
}