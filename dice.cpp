#include <iostream> //all of the libraries where random is imported
#include <cstdlib>
#include <ctime>


using namespace std;

int main(){
const short minValue = 1; //min value
const short maxValue = 6; //max value

srand(time(0)); //time set to 0
short first = rand()% (maxValue-minValue) + minValue; //formula for random generator
short second = rand()% (maxValue-minValue) + maxValue;

cout << first << "," << second;






}