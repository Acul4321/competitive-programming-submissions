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
#include <queue>
#define ll long long
#define ld long double
#define MOD(x,y) (x%y+y)%y
using namespace std;

int main() {
    cout << fixed << setprecision(11);//allows large decimal numbers
    //input code
    int H, W;
    cin >> H >> W;
    vector<string> grid(H);
    for(int i=0;i<H;i++) {
        cin >> grid[i];
    }
    
    
    auto solve = [&]()->void {
        vector<pair<int,int>> exits;
        for(int i=0;i<H;i++) {
            for(int j=0;j<W;j++) {
                if(grid[i][j] == 'E') {
                    exits.push_back({i, j});
                }
            }
        }

        vector<int> dx =   {-1,   0,   1,   0};
        vector<int> dy =   { 0,   1,   0,  -1};
        vector<char> dir = {'^', '>', 'v', '<'};
        
        vector<vector<char>> flowField(H, vector<char>(W));
        vector<vector<bool>> visited(H, vector<bool>(W, false));
        
        queue<pair<int,int>> q;
        
        for(auto [i, j] : exits) {
            q.push({i, j});
            visited[i][j] = true;
            flowField[i][j] = 'E';
        }
        
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            for(int d=0;d<4;d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                
                if(nx>=0 && nx<H && ny>=0 && ny<W && grid[nx][ny] != '#' && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    if(d == 0){
                        flowField[nx][ny] = dir[2];
                    } else if(d == 1){
                        flowField[nx][ny] = dir[3];
                    } else if(d == 2){
                        flowField[nx][ny] = dir[0];
                    } else if(d == 3){
                        flowField[nx][ny] = dir[1];
                    }
                    q.push({nx, ny});
                }
            }
        }
        
        for(int i=0; i<H;i++) {
            for(int j=0;j<W;j++) {
                if(grid[i][j] == '#') {
                    cout << '#';
                }else {
                    cout << flowField[i][j];
                }
            }
            cout << endl;
        }
        
        return;
    };
    solve();
}