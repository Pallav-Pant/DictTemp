#include <iostream>

template<class V>
struct Pair
{
    std::string key;
    V value;
    Pair* Next;
    Pair(std::string key = NULL, V value = NULL)
    {
        this->key = key;
        this->value = value;
    }

    ~Pair() {}

};
