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
    ll N,M;
    cin >> N >> M;
    vector<pair<ll,ll>> P(M);
    for(int i=0;i<M;i++){
        ll a,b;
        cin >> a >> b;
        a--;
        b--;   
        P[i] = make_pair(a,b);
    }
    //functions

    auto solve = [&]()->void{
        //solve code
        ll free = N*N;
        set<pair<ll,ll>> visited;
        for(auto [a,b]:P){
            visited.insert(make_pair(a,b));
            free--;
        }
        for(auto [i,j]:P){
            vector<pair<ll,ll>> takable = {make_pair(i+2,j+1),make_pair(i+1,j+2),make_pair(i-1,j+2),make_pair(i-2,j+1),make_pair(i-2,j-1),make_pair(i-1,j-2),make_pair(i+1,j-2),make_pair(i+2,j-1)};
            for(auto [x,y]:takable){
                    if(visited.find(make_pair(x,y)) == visited.end()){//not in visited
                        if(x >=0 && x <N && y >=0 && y<N){//bounds
                            free--;
                            visited.insert(make_pair(x,y));
                        }
                    }
            }
        }
        cout << free;
        return;
    };
    solve();
}