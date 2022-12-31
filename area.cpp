#include <iostream>

int main() {

std::cout << "Enter radius: ";
double r;
std::cin >> r;
const double pi = 3.14; // we are declaring this variable as a constant because pi's value cannot be changed, use constants to keep the same value.
double area = pi * (r * r); // area formula 
std::cout << "Area: " << area; //prints the area
std::cout << std::endl; //prevents a new line, code is more easier to read

}