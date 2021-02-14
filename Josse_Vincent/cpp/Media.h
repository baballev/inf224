#include <sstream>
#include <iostream>
#include <ostream>
#include <memory>


#ifndef MEDIA
#define MEDIA



class Media {
protected:
    std::string name = "";
    std::string path = "";
public:
    Media(); // 2 constructeurs + destructeur
    Media(std::string _path, std::string _name);
    virtual ~Media();

    // Getters, Setters & Printer
    std::string getName() const;
    std::string getPath() const;
    void setName(std::string _name);
    void setPath(std::string _path);
    virtual void print(std::ostream& stream) const;
    virtual std::string getInfo() const;
    virtual void play() const = 0; // Méthode abstraite.

};
typedef std::shared_ptr<Media> MediaPtr;



#endif