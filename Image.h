#include "Media.h"

#ifndef IMAGE
#define IMAGE


class Image:public Media{
private:
    int width = 0;
    int height = 0;

public:
    Image(int _width = 0, int _height = 0, std::string _name = "", std::string _path = ""):
    Media(_path, _name){
        width = _width;
        height = _height;

    };
    ~Image(){
        std::cout << "Bye bye " << name << std::endl;
    };

    int getWidth() const{ return width; };
    int getHeight() const { return height; };
    void setWidth(int _width) { width = _width; };
    void setHeight(int _height) { height = _height; };
    void print(std::ostream& stream) const override {
        Media::print(stream);
        stream << "Width: " << width << " , Height: " << height << std::endl;
    };
    void play() const override {
        std::string concatenated = "imagej " + path + " &"; 
        std::system(concatenated.c_str());
    }
};

typedef std::shared_ptr<Image> ImagePtr;


#endif