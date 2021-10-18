#include <iostream>
#include "Dictionary.h"

int main()
{
    Dictionary<int> dictNum;
    dictNum.add("Hello", 120);
    std::cout << dictNum.lookup("Hello") << std::endl;
    dictNum.contains("Hello");
    dictNum.remove("Hello");
    std::cout << dictNum.lookup("Hello") << std::endl;
}