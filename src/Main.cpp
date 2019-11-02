#include <iostream>

int main(int argc, char** argv)
{

    char c;

    do
    {
        std::cout << "Hello World" << std::endl;
        std::cin >> c;
    }
    while(c != 'q');

	return 0;
}