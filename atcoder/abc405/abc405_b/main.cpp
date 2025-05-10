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
    int N,M;
    cin >> N >> M;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    //functions

    auto solve = [&]()->void{
        //solve code
        bool solved = false;
        int total = 0;
        while(!solved){
            set<int> includes;
            for(int i=0;i<A.size();i++){
                includes.insert(A[i]);
            }
            if(includes.size() != M){
                solved = true;
                break;
            }
            total++;
            A.pop_back();
        }
        cout << total;

        return;
    };
    solve();
}