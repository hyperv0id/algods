#include<bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/submission/71/203224281
int main(){
    int n;
    string word;
    cin >> n;
    while(n--){
        cin>>word;
        if(word.size()<=10){
            cout << word << endl;
            continue;
        }
        printf("%c%d%c\n", word.front(), word.size()-2,word.back());
    }

    return 0;
}