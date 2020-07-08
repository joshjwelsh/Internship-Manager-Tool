#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "App.h"
using namespace std;

//Class

// Constants
const string filename = "intern.txt";
// ############

//Prototypes
void display();
void addApp();
void deleteApp();
void stat();
void updateApp();
//##############

// Append intern.txt
void addApp()
{
    string compName, posName, currResp;
    char confirm;
    int choice;

    cout << endl;
    cout << "Company Name: ";
    cin >> compName;
    cout << endl;

    cout << "Position Name: ";
    cin >> posName;
    cout << endl;

    cout << "Current response: ";
    cin >> currResp;
    cout << endl;

    cout << endl
         << endl;
    cout << "******* Confirmation Needed *******" << endl;
    cout << "Company Name: " << compName << "\t"
         << "Position Name: " << posName << "\t"
         << "Response: " << currResp << endl;
    cout << "Confirm (y,n) ?" << endl
         << endl;

    cin >> confirm;
    if (confirm == 'n')
    {
        return;
    }
    if (confirm == 'y')
    {
        App app(compName, posName, currResp);
        ofstream myfile;
        myfile.open(filename, ios::app);
        myfile << app.getCompName() << ' ' << app.getPosName() << ' ' << app.getResponse() << ' ' << app.getDate() << endl;
        myfile.close();
    }
}
//###############################

//Read from file
void display()
{
    ifstream myfile;
    string str;

    myfile.open(filename);
    cout << endl;
    cout << "********Internship Application********" << endl;
    while (getline(myfile, str))
    {
        cout << str << "\n";
    }
    cout << "**************************************" << endl;
}
//###############################

void menu()
{
    while (true)
    {
        int choice;

        cout << "****** Menu ********" << endl;
        cout << "1) Display applications " << endl;
        cout << "2) Add application" << endl;
        cout << "3) Update application " << endl;
        cout << "4) Delete application" << endl;
        cout << "5) Statistics " << endl;
        cout << "6) Exit " << endl;

        cout << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            display();
            break;
        case 2:
            addApp();
            break;
        case 3:
            //updateApp();
            break;
        case 4:
            //deleteApp();
            break;
        case 5:
            //stat();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "Please try again." << endl;
        }
    }
}

int main()
{
    // App app1("Reddit", "Software Engineer", "waiting");
    // App app2("Akuna", "Data Analysis", "waiting");

    // app1.toString();
    // app2.toString();
    menu();
    return 0;
}
