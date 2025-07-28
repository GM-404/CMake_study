#include <iostream>
#include <cmath>

int main()
{
    std::cout << "hello world" << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        if (i % 2 == 0)
            break;
        ;
        std::cout << "i = " << i << std::endl;
    }
    return 0;
}