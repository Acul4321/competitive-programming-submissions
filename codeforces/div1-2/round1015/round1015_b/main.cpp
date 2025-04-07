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
            ll n;
            cin >> n;

            vector<ll> A(n);
            for(ll i = 0; i < n; i++){
                ll temp;
                cin >> temp;
                A[i] = temp;
            }
        
            vector<ll> minSec, gcdSec;
            ll minV = *min_element(A.begin(),A.end());
            A.erase(min_element(A.begin(),A.end()));
            

            for(ll i = A.size()-1; i >= 0; i--){
                if(A[i] % minV == 0){
                    gcdSec.push_back(A[i]);
                }
                else{
                    minSec.push_back(A[i]);
                }
            }
            
            if(gcdSec.size() > 0){
                ll gcdResult = 0;
                gcdResult = gcdSec[0];
                for (size_t i = 1; i < gcdSec.size(); i++) {
                    gcdResult = gcd(gcdResult, gcdSec[i]);
                }
                if(gcdResult == minV){
                    cout << "Yes" << endl;
                    continue;
                }
            
            }

            cout << "No" << endl;
            continue;
        }

        return;
    };
    solve();
}