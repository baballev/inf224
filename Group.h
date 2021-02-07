#include "Media.h"
#include <list>

#ifndef GROUP
#define GROUP

class Group:public std::list<Media *>{
private:
    std::string name;

public:
    Group(std::string _name){name = _name;};
    ~Group();
    std::string getName() const {return name;};
    void print(std::ostream& stream) {
        
        stream << name << std::endl;
        std::list<Media *>::iterator it;
        for (it = begin(); it != end(); it++){
            (*it)->print(stream);
        }
    }

};
#endif