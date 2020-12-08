#include "Media.h"

Media::Media(string _path, string _name){
    path = _path;
    name = _name;
}

Media::Media(){
    path = "./";
    name = "media"
}

string Media::getPath(){
    return path;
}