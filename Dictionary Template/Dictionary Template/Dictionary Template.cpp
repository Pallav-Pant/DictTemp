#include <iostream>
#include <cstdlib>
#include "Dictionary.h"
int main()
{
    Dictionary<char, int> dict;
    dict.addPair('a', 1);
    dict.addPair('b', 2);
    std::cout << dict.getValue('b') << std::endl;
}

