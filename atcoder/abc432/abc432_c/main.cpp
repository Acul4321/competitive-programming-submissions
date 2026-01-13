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
    ll N, X, Y;
    cin >> N >> X >> Y;
    vector<ll> A(N);
    for(ll i = 0; i < N; i++){
        cin >> A[i];
    }

    //functions

    auto solve = [&]()->void{
        //solve code
        ll weightDiff = Y - X;

        map<ll, pair<ll, ll>> weightCounts;
        for(ll a : A){
            weightCounts[a] = make_pair(a*X, a*Y);
        }

        map<ll, pair<ll, ll>>::iterator it = weightCounts.begin();


        ll currentMin, currentMax;

        ll currentAmount = it->first;
        currentMin = it->second.first;
        currentMax = it->second.second;
        
        ll totalGrams = currentMax;
        ll totalCandy = 0;
        for(auto it = next(weightCounts.begin()); it != weightCounts.end(); ++it){
            if(weightCounts.size() == 1){
                cout << totalGrams/Y*N << endl;
                return;
            }

            ll nextMin = it->second.first;
            ll nextMax = it->second.second;
            ll nextAmount = it->first;

            if((currentMax >= nextMin && currentMax <= nextMax) || (currentMin >= nextMin && currentMin <= nextMax)){
                totalCandy += (currentAmount - ((currentMax - totalGrams) / weightDiff));
            } else {
                cout << -1 << endl;
                return;
            }

            currentAmount = nextAmount;
            currentMin = nextMin;
            currentMax = nextMax;
        }

        totalCandy += (currentAmount - ((currentMax - totalGrams) / weightDiff));

        cout << totalCandy << endl;

        return;
    };
    solve();
}