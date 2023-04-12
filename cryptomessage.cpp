#ifndef CRYPTO_H
#define CRYPTO_H

#include <string>
#include "RandomSupport.h"
#include <bitset>
#include <sstream>
#include <string>

void encode(std::string plaintext, int **result){
    *result = new int[plaintext.size()];
    RNG rngPos(0, 2);
    RNG rngLetter(65, 91);

    for(int i = 0; i < plaintext.size(); i++){
        char letter = plaintext[i];
        int position = rngPos.get();
        int number = 0;
        unsigned char* c = (unsigned char*)(&number);
        for (int j = 0; j < 3; j++){
            if (j == position){
                *c = letter;
            }
            else{
                int temp = rngLetter.get();
                if (temp == 91){
                    temp = 32;
                }
                *c = (char)temp;
            }
            c++;
        }
        *c = (char)position;
        (*result)[i] = number;
    }

}

std::string decode(int ciphertext[], int size){
std::string text;
    for (int i = 0; i < size; i++) {
       int numbers = ciphertext[i];
        unsigned char* m = reinterpret_cast<unsigned char*>(&numbers); //reintrepret cast treats as an integral type
        int position = *(m + 3); // m is a pointer to the array that is given to us
        text += *(m + position); // value is added to the array
    }
    return text;
}

//binary
//reverse name
//gives ASCII
// position = add the thing to string

#endif

//main.cpp
#include <iostream>
#include "crypto.h"

using namespace std;



int main(int argc, char* argv[]){

    int secret[20] = {4803673, 38751578, 21976410, 4347424, 37835843, 21582416, 5457477, 35671373, 5196353, 35674194, 22628164, 22499152, 38751052, 21316675, 35669832, 21709636, 4604239, 38031940, 5265989, 38946387};

    decode(secret, 20);

	return 0;
}







