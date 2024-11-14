#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a = {1561, 777, 89898, 5}; // --> {3, 2, 4, 1}
    vector<int> b = a;

    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());

    for(int i:a)
    {
        cout << lower_bound(b.begin(), b.end(), i) - b.begin() + 1 << "\n";
    }
    return 0;
}