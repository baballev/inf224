#include <ostream>
#include <string>
#include <sstream>
#include <iostream>

class Media {
private:
    std::string name = "media";
    std::string path = "./"; //Dossier courant = path par défaut
public:
    Media(); // 2 constructeurs + destructeur
    Media(std::string _path, std::string _name);
    ~Media();

    std::string getName() const;
    std::string getPath() const;
    void setName(std::string _name);
    void setPath(std::string _path);
    void print(std::ostream& stream) const;

};