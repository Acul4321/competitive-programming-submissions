#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

int main() {
    //input code
    string S,T;
    cin >> S;
    cin >> T;

    auto solve = [&]()->void{
        //solve code
        int length;
        if (S.size() > T.size()){
          
  length = S.size();
        }else {
            length = T.size();
        }
        for(int i = 0;i < length; i++){
            char Sl = S[i];
            char Tl = T[i];
            if(Sl != Tl){
                cout << i+1;
                return;
            }
        }
        cout << 0;

        return;
    };
    solve();
}