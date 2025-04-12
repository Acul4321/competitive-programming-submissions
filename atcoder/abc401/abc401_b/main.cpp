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
    int N;
    cin >> N;
    vector<string> S(N);

    for(int i=0;i<N;i++){
        string temp;
        cin >> temp;
        S[i] = temp;
    }
    //functions

    auto solve = [&]()->void{
        //solve code
        bool isLoggedin = false;
        int authCount = 0;

        for(string s:S){
            if(!isLoggedin && s == "private"){
                authCount++;
            } else if(s == "login"){
                isLoggedin = true;
            } else if(s == "logout"){
                isLoggedin = false;
            } 
        }
        cout << authCount;

        return;
    };
    solve();
}