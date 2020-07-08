#include <string>
#include <iostream>
#include "App.h"

using namespace std;

App::App(string cN, string pN, string r) 
: compName(cN), posName(pN), response(r) {
    dateApplied = __DATE__;
}

string App::getCompName(){
    return compName;
}

string App::getPosName()
{
    return posName;
}

string App::getResponse()
{
    return response;
}

string App::getDate(){
    return dateApplied;
}

void App::toString()
{
    cout << compName << ' ' << posName << ' ' << response << endl;
}

