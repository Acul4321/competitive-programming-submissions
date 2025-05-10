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
    string S;
    cin >> S;
    //functions

    auto solve = [&]()->void{
        //solve code
        vector<char> alphabet = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        for(char l:S){
            for(int i=0;i<alphabet.size();i++){
                if(l == alphabet[i]){
                    alphabet.erase(alphabet.begin()+i);
                    break;
                }
            }
        }
        cout << alphabet[0];

        return;
    };
    solve();
}