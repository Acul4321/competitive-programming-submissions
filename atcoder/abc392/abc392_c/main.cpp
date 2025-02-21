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
    ll N;
    cin >> N;

    map<ll,ll> people; // Qi,Pi

    //temp for P,Q
    vector<ll> P(N),Q(N);
    for(ll i=0;i<N;i++){
        ll temp;
        cin >> temp;
        P[i] = temp;
    }
    for(ll i=0;i<N;i++){
        ll temp;
        cin >> temp;
        Q[i] = temp;
    }

    for(ll i=0;i<N;i++){
        people[Q[i]] = P[i];
    }
    //functions

    auto solve = [&]()->void{
        //solve code
        for(ll i = 1;i<=N;i++){
            ll stare = people[i];
            ll ithPerson = Q[stare-1];
            cout << ithPerson << ' ';
        }

        return;
    };
    solve();
}