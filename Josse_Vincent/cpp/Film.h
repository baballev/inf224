#include "Media.h"
#include "Video.h"

#ifndef FILM
#define FILM


class Film:public Video{
private:
    double * timestamps = nullptr;
    int timestamps_num = 0;

public:
    Film(double * _timestamps, int _timestamps_num, float _duration, std::string _name, std::string _path){
        timestamps = new double[_timestamps_num]; // TODO use setTimestamps
        for (int k = 0; k<_timestamps_num; k++){
            timestamps[k] = _timestamps[k];
        }
        timestamps_num = _timestamps_num;
        duration = _duration;
        name = _name; // TODO
        path = _path; //TODO
    };
    Film(const Film& _film):Video(_film){
        for (int k = 0; k<_film.timestamps_num; k++){
            timestamps[k] = _film.timestamps[k];
        }
        timestamps_num = _film.timestamps_num;
    };
    Film& operator=(const Film& _film){
        Video::operator=(_film);
       for (int k = 0; k<_film.timestamps_num; k++){
            timestamps[k] = _film.timestamps[k];
        }
        timestamps_num = _film.timestamps_num; 

        return *this;
    };
    ~Film(){
        delete[] timestamps;
    };

    const double * getTimestamps() {
        return timestamps;
    }; 

    int getTimestampsNum() const{
        return timestamps_num;
    };  
    void setTimestamps(const double * _timestamps, int _length) {
        delete[] timestamps;
        // TODO check length > 0
        timestamps = new double[_length];
        for (int k = 0; k<_length; k++){
            timestamps[k] = _timestamps[k];
        }
        timestamps_num = _length;
    };

    void print(std::ostream & stream) const override{ // Call parent print
        stream << name << " - Path: " << path << ", Duration: " << duration << std::endl;
        stream << "Timestamps: " << std::endl;
        for(int k = 0; k<timestamps_num; k++){
            stream << timestamps[k] << std::endl;
        }
    };
};

#endif