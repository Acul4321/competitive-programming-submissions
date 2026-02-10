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
#define ull unsigned long long
#define MOD(x,y) (x%y+y)%y
using namespace std;

int main() {
    cout << fixed << setprecision(11);//allows large decimal numbers
    ios::sync_with_stdio(false); //disables the synchronization between the C and C++ standard streams
    cin.tie(nullptr); //This unties cin from cout not ensures that one stream is flushed automatically before each I/O operation on the other stream.
    //input code
    ull N;
    cin >> N;
    vector<ull> A(N);
    for(ull i = 0; i < N; i++){
        cin >> A[i];
    }
    //functions

    auto solve = [&]()->void{
        //solve code
        sort(A.begin(), A.end());
        
        vector<ll> total(A[N-1]+1, 0);
        for(auto a:A){
            total[a] += 1;
        }

        reverse(total.begin(), total.end());

        ll count = 0;
        for(ll i = 0; i < (ll)total.size(); i++){
            if(total[i] >= 0) count += total[i];
            cout << count % 10 << ' ';
        }

        return;
    };
    solve();
}