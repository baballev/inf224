
#include "Media.h"
#include "Video.h"
#include "Image.h"
#include "Film.h"
#include "Group.h"
#include "Table.h"

#include "tcpserver.h"

#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

using namespace std;
using namespace cppu;

const int PORT = 3331;


void print_medias(Media ** media_array, unsigned int length){
    for(unsigned int k = 0; k<length; k++){
        media_array[k]->print(std::cout);
    }
}

class MyDataBase{
private:
  Table * super_table = new Table();

public:


  bool processRequest(TCPConnection& cnx, const string& request, string& response)
  {
    cerr << "\nRequest: '" << request << "'" << endl;

    // 1) pour decouper la requête:
    // on peut par exemple utiliser stringstream et getline()
    std::string new_request = request;
    std::string commande =  new_request.substr(0, new_request.find(" "));
    new_request.erase(0, new_request.find(" ") + 1);
    std::string query = new_request.substr(0, new_request.find(" "));
    std::cout << "Commande: " << commande << std::endl;
    std::cout << "Query: " << query << std::endl;
    if (commande == "play"){
      super_table->playMedia(query);
    }
    else if (commande == "display") {
      response = super_table->getInfo(query);
    }
    else if (commande == "create"){
      super_table->createImage(100, 100, "cat", "./cat.png");
      super_table->createImage(100, 100, "dog", "./dog.png");
      super_table->createVideo(16.7, "ball", "./ball.mp4");
    }
    else {
        
    }
    
    // 2) faire le traitement:
    // - si le traitement modifie les donnees inclure: TCPLock lock(cnx, true);
    // - sinon juste: TCPLock lock(cnx);


    // 3) retourner la reponse au client:
    // - pour l'instant ca retourne juste OK suivi de la requête
    // - pour retourner quelque chose de plus utile on peut appeler la methode print()
    //   des objets ou des groupes en lui passant en argument un stringstream
    // - attention, la requête NE DOIT PAS contenir les caractères \n ou \r car
    //   ils servent à délimiter les messages entre le serveur et le client
    
    //response = "OK: " + request;
    cerr << "response: " << response << endl;
    
    // renvoyer false si on veut clore la connexion avec le client
    return true;
  }

};


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
    //const double * t3 = film->getTimestamps();

    // Etape 7
    //delete[] t3;
    delete[] t2;
    delete[] t;
    film->print(std::cout);

    delete film;

    // Etape 8
    std::cout << "Etape 8" << std::endl;
    /*
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
    delete g1;
    delete g2;
    */
    // Etape 9
    std::cout << "Etape 9" << std::endl;

    Group * g11 = new Group("Groupe 1");
    Group * g22 = new Group("Groupe 2");

    ImagePtr mega_image1 = ImagePtr(new Image(50, 50, "mega image1", "./mega_image1.png"));
    ImagePtr mega_image2 = ImagePtr(new Image(50, 50, "mega image2", "./mega_image2.png"));
    VideoPtr mega_video1 = VideoPtr(new Video("mega_video1", "./mega_video1", 1.7));
    VideoPtr mega_video2 =   VideoPtr(new Video("mega_video2", "./mega_video2", 1.7));

    g11->push_back(mega_image1);
    g11->push_back(mega_image2);
    g11->push_back(mega_video1);
    g22->push_back(mega_image1);
    g22->push_back(mega_video2);

    delete g11;
    delete g22;

    // Etape 10
    std::cout << "Etape 10" << std::endl;

    Table * table = new Table(); 
    table->createImage(100, 100, "cat", "./cat.png");
    table->createImage(100, 100, "dog", "./dog.png");
    table->createVideo(16.7, "ball", "./ball.mp4");
    
    delete table;

    // Etape 11

  shared_ptr<TCPServer> server(new TCPServer());
  
  // cree l'objet qui gère les données
  shared_ptr<MyDataBase> base(new MyDataBase());

  // le serveur appelera cette méthode chaque fois qu'il y a une requête
  server->setCallback(*base, &MyDataBase::processRequest);
  
  // lance la boucle infinie du serveur
  cout << "Starting Server on port " << PORT << endl;
  int status = server->run(PORT);
  
  // en cas d'erreur
  if (status < 0) {
    cerr << "Could not start Server on port " << PORT << endl;
    return 1;
  }
    
    return 0;
}
