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

class Video:public Media{
private:
    float duration = 0.0;

public:
    Video(float _duration = 0.0, std::string _name = "Vidéo", std::string _path = "./video.mpeg"){
        duration = _duration;
        name = _name;
        path = _path;
    };
    ~Video(){};
    float getDuration() const{ return duration; };
    void setDuration(float _duration) { duration = _duration;};
    void print(std::ostream& stream) const override {
        stream << name << " - Path: " << path << ", Duration: " << duration << std::endl;
    };
    void play() const override {
        std::string concatenated = "mpv " + path + " &"; 
        std::system(concatenated.c_str());
    }
};