#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a = {1561, 777, 89898, 5}; // -> {3, 2, 4, 1}

    int now = 1;
    map<int, int>mp;
    set<int> ms;

    for(int i:a){
        ms.insert(i);
    }

    for(int i:ms){
        mp[i] = now++;
    }

    for(int i:a){
        cout << mp[i] << "\n";
    }

    return 0;
}
