#include "Media.h"
#include <list>

#ifndef GROUP
#define GROUP

class Group:public std::list<MediaPtr>{
private:
    std::string name;

public:
    Group(std::string _name){name = _name;};
    ~Group(){};
    std::string getName() const {return name;};
    void print(std::ostream& stream) {
        
        stream << name << std::endl;
        std::list<MediaPtr>::iterator it;
        for (it = begin(); it != end(); it++){
            (*it)->print(stream);
        }
    }

};

typedef std::shared_ptr<Group> GroupPtr;

#endif