#include <iostream>
using namespace std;

int main (int argc, char* argv[]) {

    if(argc!=2){
        cout << "Error, invalid number of arguments."<<endl;
    } else{
        int days = stoi(argv[1]);
        int a = days/365;
        int b = (days % 365) / 7;
        int c = days - ((a * 365) + (b * 7));
        cout << a << " years, " << b << " weeks," << " and " << c << " days."<<endl;  
    }
    return 0;
}
