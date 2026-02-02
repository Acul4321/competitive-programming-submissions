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
    //input code
    ll N,K;
    cin >> N >> K;
    //functions

    auto solve = [&]()->void{
        //solve code
        cout << (ll)(K * pow(K-1,N-1));

        return;
    };
    solve();
}