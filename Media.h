#include <string>

class Media {
private:
    std::string name = "media";
    std::string path = "./";
public:
    Media();
    Media(std::string _path, std::string _name);

    ~Media();

    std::string getName();
    std::string getPath();
    void setName(std::string name);
    void setPath(std::string path);


};