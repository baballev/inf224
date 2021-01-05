#include "Media.h"
#include <list>

#ifndef GROUP
#define GROUP

class Group:public std::list<Media *>{

};
#endif