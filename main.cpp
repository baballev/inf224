//
// main.cpp
// Created on 21/10/2018
//
#ifndef MEDIA
#define MEDIA
#include "Media.h"
#include <iostream>
#endif

#include "Image.h"
#include "Video.h"


using namespace std;

int main(int argc, const char* argv[])
{
    std::cout << "Hello brave new world" << std::endl;
    //Media * media = new Media();
    //media->print(std::cout);
    Image *img = new Image(); 
    img->setHeight(145);
    img->setWidth(255);
    img->print(std::cout);

    return 0;
}
