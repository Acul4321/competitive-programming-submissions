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
#define ll long long
#define ld long double
#define MOD(x,y) (x%y+y)%y
using namespace std;

int main() {
    cout << fixed << setprecision(11);//allows large decimal numbers
    //input code
    int A1,A2,A3;
    cin >> A1 >> A2 >> A3;
    //functions

    auto solve = [&]()->void{
        //solve code
        if(A1 * A2 == A3){
            cout << "Yes";
            return ;
        } else if(A1*A3 == A2){
            cout << "Yes";
            return;
        }else if(A2 * A3 == A1){
            cout << "Yes";
            return;
        } else{
            cout << "No";
            return;
        }

        return;
    };
    solve();
}