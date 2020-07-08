#include <string>
using namespace std;

class App{
public:
    App(string compName, string posName, string response);
    void toString();
    string getCompName();
    string getPosName();
    string getResponse();
    string getDate();

private:
    string compName;
    string posName;
    string response;
    string dateApplied;

};
