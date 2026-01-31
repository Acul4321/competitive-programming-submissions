#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <climits>
#include <vector>
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
    vector<ll> P(M);
    vector<string> S(M);
    for(ll i = 0; i < M; i++) {
        cin >> P[i] >> S[i];
    }
    //functions

    auto solve = [&]()->void{
        //solve code
        vector<bool> solved(N, false);
        vector<ll> wrong(N, 0);
        for(ll i = 0; i < M; i++) {
            if(S[i] == "AC") {
                solved[P[i] - 1] = true;
            } else if(S[i] == "WA" && !solved[P[i] - 1]){
                wrong[P[i] - 1]++;
            }
        }

        ll ACCount = 0;
        ll WACount = 0;
        for(ll i = 0; i < N; i++) {
            if(solved[i]) {
                ACCount++;
                WACount += wrong[i];
            }
        }

        cout << ACCount << ' ' << WACount << endl;

        return;
    };
    solve();
}