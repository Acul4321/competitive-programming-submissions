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
    int A, B, C;
    cin >> A >> B >> C;

    //functions

    auto solve = [&]()->void{
        //solve code
        vector<int> v;
        v.push_back(A);
        v.push_back(B);
        v.push_back(C);
        sort(v.begin(), v.end());
        cout << v[2] << v[1] << v[0] << endl;

        return;
    };
    solve();
}