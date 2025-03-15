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
#include <unordered_set>
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
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    //functions

    auto solve = [&]()->void{
        //solve code
        ll total = -1;
        deque<ll> left;   
        deque<ll> right(A.begin(), A.end());

        map<ll,ll> occurence;
        for(ll i = 0; i < N; i++){
            occurence[A[i]]++;
        }

        for(ll i = 0; i < N-1; i++){
            left.push_back(A[i]);
            right.pop_front();

            unordered_set<ll> L(left.begin(), left.end());
            unordered_set<ll> R(right.begin(), right.end());

            total = max(total, (ll)(L.size() + R.size()));
        }

        cout << total;

        return;
    };
    solve();
}