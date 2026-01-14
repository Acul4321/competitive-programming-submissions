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
#include <utility>
#define ll long long
#define ld long double
#define MOD(x,y) (x%y+y)%y
using namespace std;

int main() {
    cout << fixed << setprecision(11);//allows large decimal numbers
    //input code
    ll N, M;
    cin >> N >> M;

    vector<pair<ll,ll>> coords(M);
    for(ll i = 0; i < M; i++) {
        cin >> coords[i].first >> coords[i].second;
    }
    
    //functions

    auto solve = [&]()->void{
        //solve code
        set<pair<ll,ll>> visited;
        ll placed = 0;
        for(auto coord : coords) {
            ll y = coord.first;
            ll x = coord.second;

            if(x < 1 || y < 1 || x > N-1 || y > N-1) continue;

            pair<ll,ll> square1 = {y, x};
            pair<ll,ll> square2 = {y+1, x};
            pair<ll,ll> square3 = {y, x+1};
            pair<ll,ll> square4 = {y+1, x+1};

            if(visited.find(square1) != visited.end() || visited.find(square2) != visited.end() || visited.find(square3) != visited.end() || visited.find(square4) != visited.end()){
                continue;
            }

            visited.insert(square1);
            visited.insert(square2);
            visited.insert(square3);
            visited.insert(square4);

            placed++;
        }

        cout << placed;

        return;
    };
    solve();
}