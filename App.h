#include <string>
using namespace std;

class App{
public:
    App();
    App(string compName, string posName, string response);
    void toString();
    //Getters
    string getCompName();
    string getPosName();
    string getResponse();
    string getDate();

    //Setters
    void setCompName(string *);
    void setPosName(string *);
    void setResponse(string *);
    string createDate();

private:
    string compName;
    string posName;
    string response;
    string dateApplied;
};
