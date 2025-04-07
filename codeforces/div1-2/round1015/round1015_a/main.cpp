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

            if(n % 2 == 0){
                cout << -1 << endl;
                continue;
            }
            
            vector<ll> A(n);
            A[0] = n;
            for(int i = 1; i < n; i++){
                A[i] = i;
            }


            for(auto a:A){
                cout << a << ' ';
            }
            cout << endl;

        }

        return;
    };
    solve();
}