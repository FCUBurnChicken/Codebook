#include<bits/stdc++.h>
#define int long long

using namespace std;

void count_sort(auto &p, auto &c){
	int n = p.size();  
	vector<int> cnt(n);      
	for(auto el : c) cnt[el] ++;
	vector<int> p_new(n), pos(n);
	pos[0] = 0;
	for(int i=1;i<n;i++) pos[i] = pos[i-1] + cnt[i-1];
	for(auto el : p){
		int i = c[el];
		p_new[pos[i]] = el;
		pos[i] ++;
	}
	p = p_new;	
}

signed main(){
	string s;
	cin>>s;
	s += "$";
	int n = s.size();
	vector<pair<char, int>> v(n);
	vector<int> p(n), c(n);
	for(int i=0;i<n;i++) v[i] = {s[i], i};
	sort(v.begin(), v.end());
	
	for(int i=0;i<v.size();i++) p[i] = v[i].second;
	c[p[0]] = 0;
	for(int i=1;i<v.size();i++){
		if(v[i].first == v[i-1].first) c[p[i]] = c[p[i-1]];
		else c[p[i]] = c[p[i-1]] + 1;
	}
	
	int k = 0;
	while((1 << k) < n){
		for(int i=0;i<n;i++) p[i] = (p[i] - (1 << k) + n) % n;
		count_sort(p, c);
		
		vector<int> c_new(n);
		c_new[p[0]] = 0;
		for(int i=1;i<v.size();i++){
			pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1  << k)) % n]};
			pair<int, int> now = {c[p[i]], c[(p[i] + (1  << k)) % n]};
			if(prev == now) c_new[p[i]] = c_new[p[i-1]];
			else c_new[p[i]] = c_new[p[i-1]] + 1;
		}
		c = c_new;
		k++;
	}
	for(int i=0;i<n;i++) cout<<p[i]<<"\n";
}