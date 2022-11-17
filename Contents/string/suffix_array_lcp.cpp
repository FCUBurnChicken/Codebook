#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> lcp(n);
int k = 0;
for(int i=0;i<n-1;i++){
    int pi = c[i];
    int j = p[pi - 1];
    while(s[i+k] == s[j+k]) k++;
    lcp[pi] = k;
    k = k-1 > 0 ? k-1 : 0;
}