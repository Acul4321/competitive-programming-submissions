#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <set>
#include <map>
#include <stdio.h>
#define ll long long
#define ld long double
using namespace std;

long double calcDist(pair<ld,ld> i,pair<ld,ld> j){
    return sqrt((pow((i.first-j.first),2))+(pow((i.second-j.second),2)));
}

int main() {
    cout << fixed << setprecision(11);
    //input code
    ll N;
    cin >> N;
    vector<pair<ld,ld>> grid(N);
    for(ll i=0;i<N;i++){
        ld X,Y;
        cin >> X >> Y;
        grid[i] = make_pair(X,Y);
    }

    auto solve = [&]()->void{
        //solve code
        pair<ld,ld> cur = make_pair(0,0);
        ld totalDist=0;
        for(auto i:grid){
            totalDist += calcDist(cur,i);
            cur = i;
        }
        totalDist += calcDist(cur,make_pair(0,0));
        cout << totalDist;

        return;
    };
    solve();
}