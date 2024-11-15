#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long

signed main () {
  ordered_set<int> os;
  
  int k = 1, x = 5;
  
  os.insert(x); // O(log n)
  os.erase(x);  // O(log n)
  // os.count(x); order_set 沒有 count 方法
  os.find(x); // O(log n)

  // ordered_set 獨有的操作
  // 1. 查找第k小
  int val = *os.find_by_order(k); // O(log n)
  // 2. 求排名
  int order = os.order_of_key(x); // O(log n)

  // set 需要遍歷才能實現上述功能
  set<int> s;
  auto it = next(s.begin(), k);  // O(n)
  distance(s.begin(), s.lower_bound(x));  // O(n)
}
