#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <set>
#include <map>
#include <deque>
#include <stdio.h>
#include <cassert>
#include <climits>
#define ll long long
#define ld long double
#define MOD(x,y) (x%y+y)%y
using namespace std;

int main() {
    cout << fixed << setprecision(11);//allows large decimal numbers
    //input code
    int N;
    cin >> N;
    vector<vector<int>> S(N,vector<int>(N,0));
    vector<vector<int>> T(N,vector<int>(N,0));

    for(int i=0;i<N;i++){
        string temp;
        cin >> temp;
        for(int j=0;j<N;j++){
            if(temp[j] == '.'){
                S[i][j] = '0';
            } else{
                S[i][j] = '1';
            }
        }
    }
    for(int i=0;i<N;i++){
        string temp;
        cin >> temp;
        for(int j=0;j<N;j++){
            if(temp[j] == '.'){
                T[i][j] = '0';
            } else{
                T[i][j] = '1';
            }
        }
    }

    //functions
    auto rotate90 = [&]()->void{
        //transpose
        for (int i=0;i<N;i++) {
            for (int j = i + 1; j < N; ++j) {
                swap(S[i][j], S[j][i]);
            }
        }
        //reverse
        for (int i=0;i<N;i++) {
            reverse(S[i].begin(), S[i].end());
        }
    };
    
    auto solve = [&]()->void{
        //solve code
        //rotate 4 times calc the min difference and use that rotation value + difference
        
        int minDif = INT_MAX;
        int rotateAmount = 0;
        for(int i=0;i<4;i++){
            int dif = 0;
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    if(S[i][j] != T[i][j]){
                        dif++;
                    }
                }
            }
            if(dif + i < minDif + rotateAmount){
                minDif = dif;
                rotateAmount = i;
            }
            rotate90();
        }

        cout << rotateAmount + minDif;

        return;
    };
    solve();
}