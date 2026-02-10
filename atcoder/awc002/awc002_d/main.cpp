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
    ll N,M;
    cin >> N >> M;
    vector<ll> C(N);
    vector<ll> R(M);
    for(ll i = 0; i < N; i++){
        cin >> C[i];
    }
    for(ll i = 0; i < M; i++){
        cin >> R[i];
    }
    //functions

    auto solve = [&]()->void{
        //solve code
        sort(C.begin(), C.end(), greater<ll>());
        sort(R.begin(), R.end(), greater<ll>());

        ll unlockCount = 0;
        ll chestNum = 0;
        ll keyNum = 0;
        while(keyNum < M && chestNum < N){
            if(chestNum >= N) break;

            if(R[keyNum] >= C[chestNum]){
                unlockCount++;
                chestNum++;
                keyNum++;
            } else {
                chestNum++;
            }
        }

        cout << unlockCount;
        return;
    };
    solve();
}