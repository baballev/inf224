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


std::string Media::getPath(){
    return path;
}

void Media::setName(std::string _name){
    name = _name;
}

void Media::setPath(std::string _path){
    path = _path;
}