#include <iostream>
#include "Dictionary.h"

int main()
{
    Dictionary<int> dictNum;
    dictNum.add("Hello", 120);
    std::cout << dictNum.read("Hello") << std::endl;
    dictNum.remove("Hello");
    std::cout << dictNum.read("Hello") << std::endl;
}