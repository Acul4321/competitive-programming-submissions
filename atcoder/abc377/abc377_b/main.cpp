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
#define ll long long
#define ld long double
using namespace std;

int main() {
    cout << fixed << setprecision(11);//allows large decimal numbers
    //input code
    vector<string> grid(8);
    for(int i=0;i<8;i++){
        string s;
        cin >> s;
        grid[i] = s;
    }
    //functions

    auto solve = [&]()->void{
        //solve code
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(grid[i][j] == '#'){
                    for(int k=0;k<8;k++){
                        if(grid[k][j] != '#'){
                            grid[k][j] = 'x';
                        }
                        if(grid[i][k] != '#'){
                            grid[i][k] = 'x';
                        }
                    }

                }
            }
        }
        int placable = 0;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                //cout << grid[i][j] << ' ';
                if(grid[i][j] == '.'){
                    placable++;
                }
            }
            //cout <<endl;
        }

        cout << placable;
        return;
    };
    solve();
}