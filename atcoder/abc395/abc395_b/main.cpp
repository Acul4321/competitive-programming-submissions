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
#define ll long long
#define ld long double
#define MOD(x,y) (x%y+y)%y
using namespace std;

int main() {
    cout << fixed << setprecision(11);//allows large decimal numbers
    //input code
    int N;
    cin >> N;
    //functions

    auto solve = [&]()->void{
        //solve code
        vector<vector<char>> grid(N,vector<char>(N, '?'));
        
        char col = '#';
        for(int x=N;x>=0;x--){
            int S = x;
            for(int i=N-S; i<S;i++){
                grid[i][N-S] = col;
                grid[N-S][i] = col;
                grid[S-1][i] = col;
                grid[i][S-1] = col;
            }
            if(col == '#'){
                col = '.';
            }else{
                col = '#';
            }
        } 

        
        //output
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout << grid[i][j];
            }
            cout << endl;
        }

        return;
    };
    solve();
}
