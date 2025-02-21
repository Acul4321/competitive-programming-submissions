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

    map<ll,vector<ll>> dice; //numberof sides:side values
    for(int i=0;i<N;i++){
        ll faces;
        cin >> faces;

        vector<ll> values(faces);
        for(ll j=0;j<faces;j++){
            ll val;
            cin >> val;
            values[j] = val;
        }

        dice[faces] = values;
    }
    //functions

    auto solve = [&]()->void{
        //solve code
        set<pair<ll,ll>> memo;
        set<ld> val;
        for (auto const& [faces1, values1] : dice){
            for (auto const& [faces2, values2] : dice){
                if(faces1 == faces2 || 
                    find(memo.begin(), memo.end(), make_pair(faces1, faces2)) != memo.end() ||
                    find(memo.begin(), memo.end(), make_pair(faces2, faces1)) != memo.end()) {
                    continue;
                }
                memo.insert({faces1, faces2});
                
                set<ll> uniq;
                uniq.insert(values1.begin(), values1.end());
                uniq.insert(values2.begin(), values2.end());
                
                vector<ll> values(uniq.begin(),uniq.end());

                // cout << "1/" << values.size() << endl;
                val.insert(1.0L / values.size());
            }
        }
        
        cout << *max_element(val.begin(),val.end());

        return;
    };
    solve();
}