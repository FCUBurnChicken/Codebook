#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN (int)(5e5 + 10)

vector<int> lazy(4 * MAXN, 0);
void build_tree(vector<int>& arr, vector<int>& tree, int node, int start, int end) {
  if ( start == end ) {
    tree[node] = arr[start];
    return;
  }
  int mid = ( start + end ) >> 1;
  int left_node  = 2 * node + 1;
  int right_node = 2 * node + 2;
  build_tree(arr, tree, left_node, start, mid);
  build_tree(arr, tree, right_node, mid + 1, end);
  tree[node] = tree[left_node] + tree[right_node];
  return;
}

void lazy_node(vector<int>& tree, int node, int start, int end) {
  if ( lazy[node] == 0 ) return;

  tree[node] += lazy[node] * ( end - start + 1 );
  int left_node  = 2 * node + 1;
  int right_node = 2 * node + 2;
  if ( start != end ) {
    lazy[left_node]  += lazy[node];
    lazy[right_node] += lazy[node];
  }
  lazy[node] = 0;
  return;
} 

void update(vector<int>& arr, vector<int>& tree, int node, int start, int end, int l, int r, int k) {
  lazy_node(tree, node, start, end);
  if ( start > r || end < l ) return;
  int mid = ( start + end ) >> 1;
  int left_node  = 2 * node + 1;
  int right_node = 2 * node + 2;
  if ( start >= l && end <= r ) {
    tree[node] += k * (end - start + 1);
    if ( start != end ) {
      lazy[left_node]  += k;
      lazy[right_node] += k;
    }
    return;
  }
  update(arr, tree, left_node, start, mid, l, r, k);
  update(arr, tree, right_node, mid + 1, end, l, r, k);
  tree[node] = tree[left_node] + tree[right_node];
  return;
}
int query_tree(vector<int>& arr, vector<int>& tree, int node, int start, int end, int l, int r) {
  if ( start > r || end < l ) return 0;

  lazy_node(tree, node, start, end);

  int mid = ( start + end ) >> 1;
  int left_node  = 2 * node + 1;
  int right_node = 2 * node + 2;

  if ( start >= l && end <= r  ) {
    return tree[node];
  }

  return query_tree(arr, tree, left_node, start, mid, l, r) + query_tree(arr, tree, right_node, mid + 1, end, l, r);
}

void solve(){
  int n;
  cin >> n;
  vector<int> arr(MAXN), tree(4 * MAXN);
  for(int i = 0; i < n; i++) cin >> arr[i];
  build_tree(arr, tree, 0, 0, n - 1);
  int q, v, l, r, k;
  cin >> q;
  while(q--) {
    cin >> v >> l >> r;
    if ( v == 1 ) {
      cin >> k;
      update(arr, tree, 0, 0, n - 1, l - 1, r - 1, k);
    } else if ( v == 2 ) {
      cout << query_tree(arr, tree, 0, 0, n - 1, l - 1, r - 1) << "\n";
    }
  }
  return;
}
signed main(){
  solve();
  return 0;
}
