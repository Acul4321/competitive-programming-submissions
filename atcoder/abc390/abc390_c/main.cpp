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
    int W,H;
    cin >> H >> W;
    vector<vector<char>> grid(H, vector<char>(W));
    for(int i=0;i<H;i++){
        string row;
        cin >> row;
        for(int j =0;j < W;j++){
            // if(row[j] == '?'){ //turn unpainted cells to black
            //     grid[i][j] = '#';
            //     continue;
            // }
            grid[i][j] = row[j];
        }
    }
    //functions

    auto solve = [&]()->void{
        //solve code
        pair<int,int> a,b,c,d; //create bounds

        bool found = false;
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(grid[i][j] == '#' && found == false){
                    a = make_pair(i,j);
                    found = true;
                    break;
                }
            }
        }
        found = false;

        for(int j=0;j<W;j++){
            for(int i=0;i<H;i++){
                if(grid[i][j] == '#' && found == false){
                    b = make_pair(i,j);
                    found = true;
                    break;
                }
            }
        }
        found = false;

        for(int i=H-1;i>=0;i--){
            for(int j=W-1;j>=0;j--){
                if(grid[i][j] == '#' && found == false){
                    c = make_pair(i,j);
                    found = true;
                    break;
                }
            }
        }
        found = false;

        for(int j=W-1;j>=0;j--){
            for(int i=H-1;i>=0;i--){
                if(grid[i][j] == '#' && found == false){
                    d = make_pair(i,j);
                    found = true;
                    break;
                }
            }
        }

        int min_x = min({a.first, b.first, c.first, d.first});
        int min_y = min({a.second, b.second, c.second, d.second});
        int max_x = max({a.first, b.first, c.first, d.first});
        int max_y = max({a.second, b.second, c.second, d.second});

        pair<int, int> top_left = {min_x, min_y};
        pair<int, int> bottom_right = {max_x, max_y};


        for(int i = top_left.first; i <= bottom_right.first; i++) {
            for(int j = top_left.second; j <= bottom_right.second; j++) {
                if(grid[i][j] == '.'){
                    cout << "No";
                    return;
                }
            }
        }
        cout << "Yes";

        return;
    };
    solve();
}