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
    int A,B,C,D;
    cin >> A >> B >> C >> D;
    //functions

    auto solve = [&]()->void{
        //solve code
        int submitTime = D + (C*60);
        int dueTime = B + (A*60);
        if(submitTime <= dueTime){
            cout << "Yes";
        } else{
            cout << "No";
        }

        return;
    };
    solve();
}