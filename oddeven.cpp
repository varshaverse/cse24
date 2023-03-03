#include <iostream>
using namespace std;

int main (int v, char* argv[]) {

    if(v < 2){
        cout << "Error, invalid number of arguments."<<endl;
    }else{   
        int counteven = 0;
        int countodd  = 0;

        for(int i = 1; i < v; i++) {
            if(stoi(argv[i]) % 2 == 0){
                counteven++;
            }else{
                countodd++;
            }
        }

        if(counteven > countodd){;
            cout << "More even numbers than odd numbers." << endl;
             cout << argv[4];
        }
        else if(countodd > counteven){
            cout << "More odd numbers than even numbers."<< endl;
        }
        else{
            cout << "Same number of even and odd numbers." << endl;
        }
    }

    return 0;
    

}







  
