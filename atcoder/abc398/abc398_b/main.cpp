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
    int N = 7;
    vector<int> A(N);
    for(int i = 0;i<N;i++){
        int temp;
        cin >> temp;
        A[i] = temp;
    }
    //functions

    auto solve = [&]()->void{
        //solve code
        map<int,int> freq;
        for(int i = 0;i<N;i++){
            freq[A[i]]++;
        }
        for(auto i:freq){
            for(auto j: freq){
                if(i.first!=j.first){
                    if(i.second + j.second >= 5 && i.second >= 2 && j.second >= 2){
                        cout << "Yes" << endl;
                        return;
                    }
                }
            }
        }
         cout << "No" << endl;

        return;
    };
    solve();
}