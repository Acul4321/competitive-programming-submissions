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
#include <numeric>
#include <cassert>
#define ll long long
#define ld long double
#define MOD(x,y) (x%y+y)%y
using namespace std;

int main() {
    cout << fixed << setprecision(11);//allows large decimal numbers
    //input code
    int t;
    cin >> t;

    //functions
    
    auto solve = [&]()->void{
        for(int j = 0;j<t;j++){
            int n;
            cin >> n;
            
            vector<ll> A(n);
            for(int i = 0; i < n; i++){
                cin >> A[i];
            }

            //solve code

            ll maxgcd = 0;
            for(int x = 0; x < n; x++){
                for(int y = 0; y < n; y++){
                    if(x != y){
                        maxgcd = max(maxgcd, abs(A[x] - A[y]));
                    }
                }
            }

            cout << maxgcd << endl;
        }

        return;
    };
    solve();
}