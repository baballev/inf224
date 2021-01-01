#ifndef MEDIA
#define MEDIA
#include "Media.h"
#include <iostream>
#endif

#include "Image.h"
#include "Video.h"


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


    return 0;
}
