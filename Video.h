#include "Media.h"
#include <cstdlib>
#include <ostream>

class Video:public Media{
private:
    float duration = 0.0;

public:
    Video(std::string _name = "Vidéo", std::string _path = "./video.mpeg"){
        name = _name;
        path = _path;
    }

    float getDuration() const{ return duration; };
    void print(std::ostream& stream) const override {
        stream << name << "- Path: " << path << ", Duration: " << duration << std::endl;
    };
    void play() const override {
        std::string concatenated = "mpv " + path + " &"; 
        std::system(concatenated.c_str());
    }
};