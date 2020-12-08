#ifndef MEDIA
#define MEDIA
#include "Media.h"
#endif

#ifndef CSTD
#define CSTD
#include <cstdlib>
#endif

#ifndef STREAM
#define STREAM
#include <sstream>
#include <iostream>
#include <ostream>
#endif

class Image:public Media{
private:
    int width = 0;
    int height = 0;

public:
    Image(int _width = 0, int _height = 0, std::string _name = "Image", std::string _path = "./image.jpg"){
        width = _width;
        height = _height;
        name = _name;
        path = _path;
    }

    int getWidth() const{ return width; };
    int getHeight() const { return height; };
    void setWidth(int _width) { width = _width; };
    void setHeight(int _height) { height = _height; };
    void print(std::ostream& stream) const override {
        stream << name << " - Path: " << path << ", Width: " << width << " , Height: " << height << std::endl;
    };
    void play() const override {
        std::string concatenated = "imagej " + path + " &"; 
        std::system(concatenated.c_str());
    }
};