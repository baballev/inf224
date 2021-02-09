#include "Media.h"


#ifndef VIDEO
#define VIDEO

class Video:public Media{
protected:
    float duration = 0.0;

public:
    Video(std::string _name = "", std::string _path = "", float _duration = 0.0)
    :Media(_path, _name){
        duration = _duration;
    };
    ~Video(){
        std::cout << "Bye bye " << name << std::endl;
    };
    float getDuration() const{ return duration; };
    void setDuration(float _duration) { duration = _duration;};
    void print(std::ostream& stream) const override { // TODO chainer
        stream << name << " - Path: " << path << ", Duration: " << duration << std::endl;
    };
    void play() const override {
        std::string concatenated = "mpv " + path + " &"; 
        std::system(concatenated.c_str());
    }
};

typedef std::shared_ptr<Video> VideoPtr;


#endif