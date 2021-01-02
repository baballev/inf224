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

#ifndef VIDEO
#define VIDEO
#include "Video.h"
#endif

class Film:public Video{
private:
    double * timestamps = new double[10];
    int timestamps_num = 10;

public:
    Film(double * _timestamps, int _timestamps_num, float _duration, std::string _name, std::string _path){
        timestamps = new double[_timestamps_num];
        for (int k = 0; k<_timestamps_num; k++){
            timestamps[k] = _timestamps[k];
        }
        timestamps_num = _timestamps_num;
        duration = _duration;
        name = _name;
        path = _path;
    };
    ~Film(){
        delete[] timestamps;
    };
    const double * getTimestamps() {
        return timestamps;
    }; //TODO: CHECK THAT CONST ACTUALLY PROTECTS FROM MODIFICATIONS
    int getTimestampsNum() const{
        return timestamps_num;
    };  
    void setTimestamps(double * _timestamps, int _length) {
        timestamps = new double[_length];
        for (int k = 0; k<_length; k++){
            timestamps[k] = _timestamps[k];
        }
        timestamps_num = _length;
    };

    void print(std::ostream & stream) const override{
        stream << name << " - Path: " << path << ", Duration: " << duration << std::endl;
        stream << "Timestamps: " << std::endl;
        for(int k = 0; k<timestamps_num; k++){
            stream << timestamps[k] << std::endl;
        }
    };

    //Film(const Film& film) = delete;
    //Film& operator=(const Film& film) = delete;

};
