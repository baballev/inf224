#include <ostream>
#include <string>
#include <sstream>
#include <iostream>

class Media {
protected:
    std::string name = "";
    std::string path = "";
public:
    Media(); // 2 constructeurs + destructeur
    Media(std::string _path, std::string _name);
    ~Media();

    // Getters, Setters & Printer
    std::string getName() const;
    std::string getPath() const;
    void setName(std::string _name);
    void setPath(std::string _path);
    virtual void print(std::ostream& stream) const;
    virtual void play() const;

};