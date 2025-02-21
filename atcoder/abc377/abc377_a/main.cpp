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
#define ll long long
#define ld long double
using namespace std;

int main() {
    cout << fixed << setprecision(11);//allows large decimal numbers
    //input code
    string S;
    cin >> S;
    //functions

    auto solve = [&]()->void{
        //solve code

        if(S.find('A')== std::string::npos){
            cout << "No";
            return;
        }
        if(S.find('B')== std::string::npos){
            cout << "No";
            return;
        }
        if(S.find('C')== std::string::npos){
            cout << "No";
            return;
        }
        cout << "Yes";
        return;
    };
    solve();
}