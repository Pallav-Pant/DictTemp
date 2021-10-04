#include <iostream>
#include <cstdlib>
#include "Dictionary.h"
int main()
{
    Dictionary<char, int> dict;
    dict.addPair('a', 1);
    std::cout << dict.getValue('a') << std::endl;
    //DynamicList<char> letters;
    //letters.addEnd('a');
    //letters.addEnd('b');
    //std::cout << letters.at(1) << std::endl;

}

