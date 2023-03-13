#ifndef UCM_FILES_H
#define UCM_FILES_H
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>


void createCSV(std::string filename, std::vector<std::vector<std::string>> data) {
    std::ofstream outfile(filename);

    if(!outfile.is_open()){

        return;
    }
    else {
    for (auto row : data) {
        for(int i = 0; i < row.size(); i++){
            outfile << row[i];
            if(i < row.size()-1){
                outfile << ",";
            }
        }

        outfile << "\n";
    }

    outfile.close();
}

}


#endif
