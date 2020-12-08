//
// main.cpp
// Created on 21/10/2018
//
#include <iostream>
#include "Media.h"
using namespace std;

int main(int argc, const char* argv[])
{
    std::cout << "Hello brave new world" << std::endl;
    Media * media = new Media();
    media->print(std::cout);

    return 0;
}
