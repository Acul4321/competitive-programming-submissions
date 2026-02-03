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
    ll n;
    cin >> n;

    //functions
    auto weird = [&](auto weird, ll n) -> void{
        cout << n << ' ';
        if(n == 1) return;
        if(n % 2 == 0) weird(weird, n/2);
        else weird(weird, 3*n + 1);
    };

    auto solve = [&]()->void{
        //solve code
        weird(weird, n);

        return;
    };
    solve();
}