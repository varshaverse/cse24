#ifndef CRYPTO_H
#define CRYPTO_H

#include <string>

std::string decode(long s){
    std::string result = "";

std::string decode(long num) {
    std::string word;
    for (int i = 0; i < 8; i++) {
        char c = 'a' + (num % 26);
        word = c + word;
        num /= 26;
    }
    return word;
}

    return result;
}

#endif
#include <iostream>
#include "crypto.h"

using namespace std;

int main(int argc, char* argv[]){
	// Your code here

    if (argc < 2){
        cerr << "Not enough arguments" << endl;
        return 1;
    }

    long secret = stol(argv[1]);

    string message = decode(secret);

    cout << message << endl;

	return 0;
}
