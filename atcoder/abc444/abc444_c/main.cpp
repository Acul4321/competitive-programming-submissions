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
#include <numeric>
#include <utility>
#define ll long long
#define ld long double
#define MOD(x,y) (x%y+y)%y
using namespace std;

int main() {
    cout << fixed << setprecision(11);//allows large decimal numbers
    ios::sync_with_stdio(false); //disables the synchronization between the C and C++ standard streams
    cin.tie(nullptr); //This unties cin from cout not ensures that one stream is flushed automatically before each I/O operation on the other stream.
    //input code
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(ll i = 0; i < N; i++){
        cin >> A[i];
    }
    //functions

    auto solve = [&]()->void{
        //solve code
        set<ll> Aset;
        set<ll> ans;
        for(ll i = 0; i < N-1; i++){
            Aset.insert(A[i] + A[i+1]);
            Aset.insert(A[i]);
        }
        Aset.insert(A[N-1]);

        ll sum = accumulate(A.begin(), A.end(), 0LL);

        for(ll i=N; i>= round(N/2); i--){
            if(i * 2 < N) continue;

            if(Aset.count(sum/i) > 0) {
                ans.insert(sum/i);
            }
        }

        for(auto x: ans){
            cout << x << ' ';
        }

        return;
    };
    solve();
}