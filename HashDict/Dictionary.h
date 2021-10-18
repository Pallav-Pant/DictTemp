#include "List.h"

template <class V>
class Dictionary
{
    List<V> dict[10];

    int hash(std::string key)
    {
        int index = 0;
        for (int i = 0; i < key.length(); i++)
        {
            index += key[i];
        }
        index %= 10;
        return index;
    }


public:
    Dictionary() {}



    void add(std::string key, V value)
    {
        dict[hash(key)].add(key, value);

    }

    V lookup(std::string key)
    {
        return dict[hash(key)].getValue(key);
    }

    void remove(std::string key)
    {
        dict[hash(key)].remove(key);
    }

    void contains(std::string key)
    {
        if (dict[hash(key)].exists(key))
        {
            std::cout << "The key \"" << key << "\" exists in this dictionary." << std::endl;
            return;
        }
        std::cout << "The key \"" << key << "\" does not exist in this dictionary." << std::endl;
    }

    ~Dictionary() {}//Automatically deletes stuff since static array of objects so no code required
};

