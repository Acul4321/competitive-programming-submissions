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
    vector<ll> A(N);
    for(ll i = 0;i<N;i++){
        ll temp;
        cin >> temp;
        A[i] = temp;
    }
    //functions

    auto solve = [&]()->void{
        //solve code
        map<ll,ll> freq;
        for(ll i=0;i<N;i++){
            freq[A[i]]++;
        }
        ll maxPerson = -1;
        for(auto i:freq){
            if(i.second == 1){
                maxPerson = max(maxPerson,i.first);
            }
        }

        for(ll i=0;i<N;i++){
            if(A[i] == maxPerson){
                cout << i+1 << endl;
                return;
            }
        }
        cout << -1 << endl;

        return;
    };
    solve();
}