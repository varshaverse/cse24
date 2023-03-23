#ifndef UCM_VECTORS_H
#define UCM_VECTORS_H

#include <iostream>
#include <vector>
#include <string>

std::vector<std::vector<int>> findIndexesOfSum(std::vector<int> &x, int target) {
    std::vector<std::vector<int>> yes;

    for (int t = 0; t < x.size(); t++) {
      
      #include <iostream>
#include <vector>
#include "ucm_vectors.h"
using namespace std;

int main() {
    vector<int> a = {1, 4, 6, 2, 4, 8, 9, 3, 7};
    int target = 10;

    vector<vector<int>> pos = findIndexesOfSum(a, target);

    cout << "[ ";
    for (int i = 0; i < pos.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < pos[i].size(); j++) {
            cout << pos[i][j] << ((j == (pos[i].size() - 1)) ? "" : ", ");
        }
        cout << ((i == (pos.size() - 1)) ? " ]" : " ], ");
    }
    cout << " ]" << endl;;

    return 0;
}
        if (x[t] + x[t+1] == target) {
            yes.push_back({t, t+1});
        }
    }
    return yes; 
}

#endif

#include <iostream>
#include <vector>
#include "ucm_vectors.h"
using namespace std;

int main() {
    vector<int> a = {1, 4, 6, 2, 4, 8, 9, 3, 7};
    int target = 10;

    vector<vector<int>> pos = findIndexesOfSum(a, target);

    cout << "[ ";
    for (int i = 0; i < pos.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < pos[i].size(); j++) {
            cout << pos[i][j] << ((j == (pos[i].size() - 1)) ? "" : ", ");
        }
        cout << ((i == (pos.size() - 1)) ? " ]" : " ], ");
    }
    cout << " ]" << endl;;

    return 0;
}
