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
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for(ll i = 0; i < N; i++){
        cin >> A[i];
    }
    vector<ll> B(M);
    for(ll i = 0; i < M; i++){
        cin >> B[i];
    }
    //functions

    auto solve = [&]()->void{
        //solve code
        vector<ll> brusied;
        for(ll i = 0; i < M; i++){
            brusied.push_back(A[B[i]-1]);
        }

        sort(brusied.begin(), brusied.end());
        cout << distance(brusied.begin(), lower_bound(brusied.begin(), brusied.end(), K)) << ' ';
        cout << accumulate(brusied.begin(),lower_bound(brusied.begin(), brusied.end(), K), 0LL);

        return;
    };
    solve();
}