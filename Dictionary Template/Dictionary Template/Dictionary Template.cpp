#include <iostream>
#include <cstdlib>
#include "Dictionary.h"
int main()
{
    Dictionary<char, int> dict;
    dict.addPair('a', 1);
    dict.addPair('b', 2);
    dict.getValue('a');
    dict.getValue('b');
    //dict.remove('b');
    //std::cout << dict.getValue('a') << std::endl;
    //std::cout << dict.getValue('b') << std::endl;
}

