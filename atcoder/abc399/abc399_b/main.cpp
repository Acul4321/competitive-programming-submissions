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
#include <iterator>
#define ll long long
#define ld long double
#define MOD(x,y) (x%y+y)%y
using namespace std;

int main() {
    cout << fixed << setprecision(11);//allows large decimal numbers
    //input code
    int N;
    cin >> N;
    vector<int> P(N);
    for(int i =0;i<N;i++){
        int temp;
        cin >> temp;
        P[i] = temp;
    }
    //functions

    auto solve = [&]()->void{
        //solve code
        int r = 1;
        bool ranked = false;
        vector<int> unranked = P;
        vector<int> placement(N);
        while(!ranked){
            int x = *max_element(unranked.begin(),unranked.end());
            int k = 0;
            for(auto i:P){
                if(i == x){
                    k++;
                }
            }

            for(int i =0;i<N;i++){
                if(P[i] == x){
                    placement[i] = r;
                    unranked[i] = -1;
                }
            }
            r+=k;

            if(*max_element(unranked.begin(),unranked.end()) == -1){
                ranked = true;
            }

        }
        for(auto p:placement){
            cout << p << endl;
        }

        

        return;
    };
    solve();
}