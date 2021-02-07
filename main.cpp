
#include "Media.h"
#include "Video.h"
#include "Image.h"
#include "Film.h"
#include "Group.h"
#include <iostream>

using namespace std;

void print_medias(Media ** media_array, unsigned int length){
    for(unsigned int k = 0; k<length; k++){
        media_array[k]->print(std::cout);
    }
}


// TODELETE, TESTS
class Point{
private:
    int x = 0;
    int y = 0;
public:
    Point(int _x, int _y);
    void get(int * x, int * y) const;
    void set(int _x, int _y);
    static void useless_test();
};

Point::Point(int _x, int _y){
    x = _x;
    y = _y;
}
void Point::set(int _x, int _y){
    x = _x;
    y = _y;
    std::cout << "Point's x = " << x << " , Point's y = " << y <<std::endl;
}
void Point::useless_test(){
    std::cout << "Test successful." << std::endl;

}
void Point::get(int * _x, int * _y) const{
    *_x = x;
    *_y = y; 
}


#include <iostream>

class X {
public:
    virtual char foo() { return 'x'; }
};

class Y : public X {
public:
    char foo() override { return 'y'; }
};


#include <iostream>

 class Object {
public:
   virtual ~Object() {} 
   Object();
   virtual void draw();
};
 
 class Line : public Object {
 public:
     void draw() {std::cout << "draw" << std::endl;} 
     Line() {};
     virtual ~Line();
 };
 
 void drawObject(Object * obj) { 
     obj->draw();
 }

// TODELETE UNTIL THIS LINE



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
    medias[1] = new Video("super vidéo", "./super_video.mp4", 12.41);
    medias[2] = new Video("super vidéo2", "./super_video2.mp4", 14.7);
    medias[3] = new Video("super vidéo3", "./super_video3.mp4", 0.7);
    medias[4] = new Image(1920, 1080, "super imageHD", "./super_imageHD.jpg");
    print_medias(medias, 5);
    
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

    // Etape 7
    //delete[] t3;
    delete[] t2;
    delete[] t;
    film->print(std::cout);

    delete film;

    // Etape 8
    std::cout << "Etape 8" << std::endl;

    Group * g1 = new Group("Groupe 1");
    Group * g2 = new Group("Groupe 2");

    g1->push_back(medias[0]);
    g1->push_back(medias[1]);
    g1->push_back(medias[2]);
    g2->push_back(medias[1]);
    g2->push_back(medias[3]);

    g1->print(std::cout);
    g2->print(std::cout);
    
    delete[] medias;


    return 0;
}
