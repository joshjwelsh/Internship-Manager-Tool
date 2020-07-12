#include <string>
#include <iostream>
#include <ctime>
#include "App.h"

using namespace std;

App::App(){
    dateApplied = createDate();
}

App::App(string cN, string pN, string r) 
: compName(cN), posName(pN), response(r) {
    dateApplied = createDate();
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

void App::setCompName(string* cn){
    compName = *cn;
}

void App::setPosName(string* pn)
{
    posName = *pn;
}

void App::setResponse(string* r)
{
    response = *r;
}

void App::toString()
{
    cout << compName << ' ' << posName << ' ' << response << endl;
}

string App::createDate(){
    string dateStr;
    time_t now = time(0);
    tm *date = localtime(&now);
    int day, month, year;
    day = date -> tm_mday;
    month = 1 + date -> tm_mon;
    year = 1900 +  date -> tm_year;
    dateStr = to_string(day) + '/' + to_string(month) + '/' + to_string(year);
    return dateStr;
}