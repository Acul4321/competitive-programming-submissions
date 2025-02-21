#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

int main() {
    //input code
    string S,T;
    cin >> S;
    cin >> T;
    vector<int> ind;

    auto solve = [&]()->void{
        //solve code
        for(int l=0;l<S.length();l++){
            int min = (int)S[0];
            for(int l=0;l<S.length();l++){
                if (S[l] != T[l]){
                    (int)S[l];
                }
            }
            
        }

        return;
    };
    solve();
}