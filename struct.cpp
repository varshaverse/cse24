#ifndef PY_LIST_H
#define PY_LIST_H

#include <iostream>
#include <vector>


//appending elements to a list

struct PyList {
    std::vector<int> integerList;
    std::vector<char> charList;
    std::vector<float> floatList;

    PyList(){
       
        
    }

    void append(int l){

        integerList.push_back(l);
    }

    void append(char l){
        charList.push_back(l);
        
    }

    void append(float l){
        floatList.push_back(l);
       
    }

    ~PyList(){
        
    }
    
};

std::ostream& operator<<(std::ostream& os, const PyList& pyList){
    os << '[';

   size_t intSize = pyList.integerList.size();
    for (size_t i = 0; i < intSize; i++) {
        os << pyList.integerList[i];
        if (i < intSize - 1) os << ", ";
    }

    size_t charSize = pyList.charList.size();
    if (intSize > 0 && charSize > 0) 
    os << ", " << "'";
    for (size_t i = 0; i < charSize; i++) {
        os << pyList.charList[i];
        if (i < charSize) os << "'";
    }

    size_t floatSize = pyList.floatList.size();
    if ((intSize > 0 || charSize > 0) && floatSize > 0) os << ", ";
    for (size_t i = 0; i < floatSize; i++) {
        os << pyList.floatList[i];
    }
    
    os << ']';
    return os;
}

#endif
