#ifndef MEDIA
#define MEDIA
#include "Media.h"
#include <iostream>
#endif

#ifndef VIDEO
#define VIDEO
#include "Video.h"
#endif

#include "Image.h"
#include "Film.h"


using namespace std;

void print_medias(Media ** media_array, unsigned int length){
    for(unsigned int k = 0; k<length; k++){
        media_array[k]->print(std::cout);
    }
}

int main(int argc, const char* argv[])
{
    // std::cout << "Hello brave new world" << std::endl;
    // Media * media = new Media();
    // media->print(std::cout);
    Image *img = new Image(); 
    img->setHeight(145);
    img->setWidth(255);
    img->print(std::cout);
    delete img;
    // Etape 5 - Traitement Générique
    Media ** medias = new Media *[5];
    medias[0] = new Image(512, 512, "super image", "./super_image.jpg");
    medias[1] = new Video(12.1, "super vidéo", "./super_video.mp4");
    medias[2] = new Video(14.7, "super vidéo2", "./super_video2.mp4");
    medias[3] = new Video(0.4, "super vidéo3", "./super_video3.mp4");
    medias[4] = new Image(1920, 1080, "super imageHD", "./super_imageHD.jpg");
    print_medias(medias, 5);
    delete[] medias;
    
    // Etape 6
    double * t = new double[3];
    t[0] = 0.9;
    t[1] = 12.3;
    t[2] = 54.7;

    Film * film = new Film(t, 3, 120.4, "Lost in Tranlsation", "./lost_in_translation.mp4"); 
    film->print(std::cout);
    double * t2 = new double[5];
    t2[0] = 0.2;
    t2[1] = 1.4;
    t2[2] = 34.6;
    t2[3] = 56.7;
    t2[4] = 113.5;
    film->setTimestamps(t2, 5);
    film->print(std::cout);
    const double * t3 = film->getTimestamps();

    return 0;
}
