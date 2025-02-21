#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
    //input code
    string S;
    cin >> S;

    auto solve = [&]()->void{
        string a;
        //solve code
        for (auto &i: S){
            if(i!= '.'){
                a = a + i;
            }
        }
        cout << a;

        return;
    };
    solve();
}