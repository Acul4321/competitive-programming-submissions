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
    ll Q;
    cin >> Q;
    vector<pair<ll,ll>> query(Q);
    for(ll i = 0; i < Q; i++){
        ll type;
        cin >> type;
        if(type != 2){
            ll param;
            cin >> param;
            query[i] = {type, param};
        } else {
            query[i] = {type, -1};
        }
    }
    //functions

    auto solve = [&]()->void{
        //solve code
        deque<pair<ll,ll>> snakes;
        ll curCoord = 0;
        ll removeCoord = 0;
        for(auto [type, peram]:query){
            if(type == 1){ // add snake
                if(snakes.size() == 0){ // if empty
                    snakes.push_back(make_pair(0,peram));
                    curCoord = peram;
                } else {
                    snakes.push_back(make_pair(curCoord,peram));
                    curCoord += peram;
                }
            }else if(type == 2){ //remove sname at front
                removeCoord += snakes[0].second;
                snakes.pop_front();
            }else if(type == 3){
                cout << snakes[peram-1].first-removeCoord << endl;
            }

        }
        return;
    };
    solve();
}