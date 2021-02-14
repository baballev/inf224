#include "Media.h"

Media::Media(std::string _path, std::string _name){
    path = _path;
    name = _name;
}

Media::Media(){
    path = "./";
    name = "media";
}

Media::~Media(){
}


std::string Media::getPath() const{
    return path;
}

std::string Media::getName() const{
    return name;
}

void Media::setName(std::string _name){
    name = _name;
}

void Media::setPath(std::string _path){
    path = _path;
}

void Media::print(std::ostream& stream) const{
    stream << "Media - Name: " << name << ", Path: " << path << std::endl;
}

std::string Media::getInfo() const{

    return "Media - Name: " + name + ", Path: " + path;
}

