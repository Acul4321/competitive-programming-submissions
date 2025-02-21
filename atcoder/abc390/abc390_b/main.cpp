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
#include <climits>
#define ll long long
#define ld long double
#define MOD(x,y) (x%y+y)%y
using namespace std;

int main() {
    cout << fixed << setprecision(11);//allows large decimal numbers
    //input code
    ll N;
    cin >> N;
    vector<ld> A(N);
    for(ll i=0;i<N;i++){
        ld temp;
        cin >> temp;
        A[i] = temp;
    }
    //functions

    auto solve = [&]()->void{
        //solve code
        if(A[0] == 0 || A[1] == 0){
            cout << "No";
            return;
        }
        ld ratio = A[1]/A[0];
        for(ll i=1;i<N;i++){
            if(A[i-1] == 0 || (A[i]/A[i-1]) != ratio){
                cout << "No";
                return;
            }
        }
        cout << "Yes";

        return;
    };
    solve();
}