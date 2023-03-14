#ifndef UCM_FILES_H
#define UCM_FILES_H

#include <ios>
#include <cstdlib>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

vector<string> tokenize(string s, char delimiter= ','){

    vector <string> value;
    string words;
    stringstream ss(s);

    while(!ss.eof()){
        getline(ss,words,delimiter);
        value.push_back(words);
    }
    return value;
}

string getString(int n, string buffer=" "){
    string values = "";
    for(int i = 0; i < n; i++){
        values.append(buffer);
    }
    return values;
}
vector <int> computeMaxLengths(string filename){
    vector <int> maxLengths;
    string headerLine;
    string line;
    ifstream file;
    int lineCount = 0;

    file.open(filename, ios::in);

    if(file.is_open()){
        string output = "";
        getline(file, headerLine);
        vector<string> result = tokenize(headerLine);
        for(int i = 0; i < result.size(); i++){
            maxLengths.push_back(result[i].length());
        }
        while(getline(file,line)){
            output = "";
            vector<string> result = tokenize(line);
            for(int i = 0; i < result.size(); i++){
                if(result[i].length() > maxLengths[i]){
                    maxLengths[i] = result[i].length();
                }
            }
            lineCount++;
        }
    }
        maxLengths.push_back(lineCount);
        file.close();
        return maxLengths;
}

int getWidth(vector <int> maxLengths){
    int totalWidth = 0;
    for(int i = 0; i < maxLengths.size()-1; i++){
        totalWidth = totalWidth + maxLengths[i];
        if(i < maxLengths.size()-2){
            totalWidth = totalWidth + 4;
        }
    }
    return totalWidth;
}
void createOutputCSV(string filename, string outputFilename, vector<int> maxLengths){
    string headerLine;
    string line;
    ifstream file;
    ofstream outFile;
    int lineCount = 0;

    file.open(filename, ios::in);
    outFile.open(outputFilename, ios::out);

    if(file.is_open()){
        int totalWidth = getWidth(maxLengths);
        outFile << getString(totalWidth, "-") << endl;
        string outputStr = "";
        getline(file, headerLine);
        vector<string> result = tokenize(headerLine);
        
        for(int i = 0; i < result.size(); i++){
            outputStr.append(result[i]);
            int difference = maxLengths[i]- result[i].length();
            int spaces = abs(difference)+4;
            if(i < result.size()-1){
                outputStr.append(getString(spaces));   
            }
        }
        outFile << outputStr << endl;
        outFile << getString(totalWidth, "-") << endl;

        while(getline(file,line)){
            outputStr = "";
            vector<string> result = tokenize(line);
    
            for(int i =0; i < result.size(); i++){
                outputStr.append(result[i]);
                int difference = maxLengths[i] - result[i].length();
                int spaces = abs(difference)+ 4;
                if(i < result.size()-1){
                    outputStr.append(getString(spaces));
                }

            }
            lineCount++;
            outFile << outputStr;
            if(lineCount < maxLengths[maxLengths.size()-1]){
                outFile << endl;
            }
        }
        
            

    }
    file.close();
    outFile.close();
}
void visualizeCSV(string filename, string outputFile){
    vector<int> maxLengths = computeMaxLengths(filename);
    createOutputCSV(filename, outputFile, maxLengths);
}

#endif
