

class Media {
private:
    string name = "media";
    string pathname = "./";
public:
    Media();
    Media(string _path, string _name);

    string getName();
    string getPath();

};