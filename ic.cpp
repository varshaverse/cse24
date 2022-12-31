#include <iostream>

using namespace std;


int main(){

//incrementing differences

int x = 10;
int y = 1;

int t = x++;
int z = y++; // prints y, does increment
int k = ++y; 

int j = ++y;
int l = ++y;
int i = x++;
int p = ++x;

cout<< t << std::endl;
cout<< z << std::endl;
cout<< k << std::endl;
cout<< j << std::endl;
cout<< i << std::endl;
cout<<p;


}

