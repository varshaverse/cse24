#ifndef UCM_FILES_H
#define UCM_FILES_H

using namespace std;

#include <fstream>
#include <string>
#include <cctype>

bool authenticate(string filename, const string& email, string password){

    ifstream file(filename);
    string topEmail;

    for(int i = 1; i < email.size(); i++){

    topEmail += toupper(email[i]);
}
    string line;

    while(getline(file, line)){

    string upperLine;

for(int i = 1; i < line.size(); i++){

    upperLine += toupper(line[i]);
    } 

if(upperLine.find(topEmail) != string::npos && line.find(password) != string::npos){

    file.close();

        return true;
    }
    }

    file.close();

        return false;
}

#endif
