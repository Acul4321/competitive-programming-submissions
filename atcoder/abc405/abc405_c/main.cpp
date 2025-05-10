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
#include <numeric>
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
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    //functions

    auto solve = [&]()->void{
        //solve code
        ll sum = 0;
        ll precompSum = reduce(A.begin(), A.end());
        for(ll i=0;i<N;i++){
                precompSum -= A[i];
                sum += A[i] * precompSum;
        }
        cout << sum;

        return;
    };
    solve();
}