#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct segtree {
	
	vector<ll> sums;
	ll size;

	// 線段樹初始化
	void init(ll n){
		size = 1;
		while(size < n) size<<1;
		sums.assign(size<<1, 0LL);
	}
	
	// 更新數值
	void update(ll i, ll v, ll x, ll Lptr, ll Rptr){
		if(Rptr - Lptr == 1){
			sums[x] = v;
			return;	
		} 
		ll m = ( Lptr + Rptr )/2;
		if(i<m) update(i, v, 2*x+1, Lptr, m);
		else update(i, v, 2*x+2, m, Rptr);
		sums[x] = sums[2*x+1] + sums[2*x+2];
	}
	
	void update(ll a, ll b){
		update(a, b, 0, 0, size);
	}
	
	// 查詢資訊
	ll query(ll l, ll r, ll x, ll Lptr, ll Rptr){
		if( Lptr >= r || Rptr <= l ) return 0;
		if( Lptr >= l && Rptr <= r ) return sums[x];
		ll m = (Lptr + Rptr) /2;
		ll s1 = query(l, r, 2*x+1, Lptr, m);
		ll s2 = query(l, r, 2*x+2, m, Rptr);
		return s1 + s2;
	}
	
	ll query(ll a, ll b){
		return query(a, b, 0, 0, size);
	}
};