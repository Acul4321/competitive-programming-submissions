#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <set>
#include <map>
#include <stdio.h>
#define ll long long
using namespace std;

int main() {
    //input code
    int N;
    cin >> N;
    string S;
    cin >> S;


    auto solve = [&]()->void{
        //solve code
        int count =0;
        for(int i = 1;i<S.length()-1;i++){
            char l = S[i];
            if(l == '.'){
                if(S[i-1] == '#' and S[i+1] == '#'){
                    count++;
                }
            }
        }
        cout << count;

        return;
    };
    solve();
}