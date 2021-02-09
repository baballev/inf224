#include "Group.h"
#include "Media.h"
#include "Image.h"
#include "Video.h"
#include <ostream>

#ifndef TABLE
#define TABLE
#include <map>

typedef std::map<std::string, GroupPtr> GroupTable;
typedef std::map<std::string, MediaPtr> MediaTable;

class Table {
private:    
    GroupTable * group_table;
    MediaTable * media_table;

public:
    Table(){
        group_table = new GroupTable();
        media_table = new MediaTable();
    };
    ~Table(){
        delete group_table;
        delete media_table;
    };
    ImagePtr createImage(int _width, int _height, std::string _name, std::string _path) const{
        ImagePtr _img = ImagePtr(new Image(_width, _height, _name, _path));
        media_table->insert(std::pair<std::string, MediaPtr>(_name, _img));
        return _img;
    };
    VideoPtr createVideo(float _duration, std::string _name, std::string _path) const{
        VideoPtr _vid = VideoPtr(new Video(_name, _path, _duration));
        media_table->insert(std::pair<std::string, MediaPtr>(_name, _vid));
        return _vid;
    };
    GroupPtr createGroup(std::string _name) const{
        GroupPtr _grp = GroupPtr(new Group(_name));
        group_table->insert(std::pair<std::string, GroupPtr>(_name, _grp));
        return _grp;
    };

    void printMedia(std::string _name, std::ostream & _stream){
        auto it = media_table->find(_name);
        if (it != media_table->end()){
            it->second->print(_stream);
        }
        else {
            _stream << "Media " << _name << " non trouvé." << std::endl;
        }

    }

    void printGroup(std::string _name, std::ostream & _stream){
        auto it = group_table->find(_name);
        if (it != group_table->end()){
            it->second->print(_stream);
        } 
        else {
            _stream << "Groupe " << _name << " non trouvé." << std::endl;
        }
    }

    void playMedia(std::string _name){
        auto it = media_table->find(_name);
        if (it != media_table->end()){
            it->second->play();
        }
        else {
            std::cout << "Erreur: Media non trouvé." << std::endl;
        }

    }

};



typedef std::shared_ptr<Table> TablePtr;



#endif