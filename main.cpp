#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "App.h"
using namespace std;

//Class

// Constants
const string FILENAME = "intern.txt";
const string TEMPNAME = "temp.txt";
// ############

//Prototypes
void display();
void addApp();
void deleteApp();
void stat();
void updateApp();
void createAfterUpdate();
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
    cout << "Confirm (y,n)? " << endl;


    cin >> confirm;
    if (confirm == 'n')
    {
        return;
    }
    if (confirm == 'y')
    {
        App app(compName, posName, currResp);
        ofstream myfile;
        myfile.open(FILENAME, ios::app);
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
    char choice;
    int counter =  1;
    myfile.open(FILENAME);
    cout << endl;
    cout << "************ Internship Application ***********" << endl;
    cout << endl;
    while (getline(myfile, str))
    {
        cout << counter << ") " << str << "\n";
        counter++;
    }
    cout << endl;

    cout << "**************************************" << endl;
    cout << endl;
    myfile.close();
}
//###############################

int lineCount(){
    ifstream myfile;
    int counter = 0;
    string str;

    myfile.open(FILENAME);
    while (getline(myfile, str))
    {
        counter++;
    }
    myfile.close();
    return counter;
}

void updateApp(){

    int line;
    string fLine, str1, str2, str3;
    ifstream myfile;
    ofstream tempFile;
    App changedApp;

    int count = 1;
    int maxLine = lineCount();

    display();
   
    cout << "Which line would you like to change?" << endl;
    cin >> line;

    if(line > maxLine){
        cout << "Please Enter a valid number." << endl;
        return;
    }

    cout << "Enter the new line in the format: Company-Name Position-Name Current-Response" << endl;
    cout << endl;
    cin >> str1 >> str2 >> str3;

    changedApp.setCompName(&str1);
    changedApp.setPosName(&str2);
    changedApp.setResponse(&str3);

    myfile.open(FILENAME);
    tempFile.open(TEMPNAME);

    while(!myfile.eof()){
        getline(myfile, fLine);

        if(count == line){
            ++count;
            tempFile << changedApp.getCompName() << ' ' << changedApp.getPosName() << ' '
                     << changedApp.getResponse() << ' ' << changedApp.getDate() << endl;
        }else{
            ++count;
            tempFile << fLine << endl;
        }
    }

    myfile.close();
    tempFile.close();
    createAfterUpdate();
}


void createAfterUpdate(){

    ofstream newFile;
    ifstream tFile;
    string newLine;

    newFile.open(FILENAME);
    tFile.open(TEMPNAME);
    while (getline(tFile, newLine))
    {
        char test = newLine[0];
        if (!isalpha(test)){
            break;
        }
        else{
            newFile << newLine << endl;
        } 
    }
    newFile.close();
    tFile.close();
    remove("temp.txt");
}

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
        if(isalpha(choice)){
            cout << "Fatal Error. Input number not character." << endl;
            cout << endl << endl;

            return;
        }
        if(choice < 1 || choice > 6){
            cout << "Invalid number." << endl;
            cout << endl << endl;
            return;
        }

        switch (choice)
        {
        case 1:
            display();
            break;
        case 2:
            addApp();
            break;
        case 3:
            updateApp();
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
    menu();  
    return 0;
}
