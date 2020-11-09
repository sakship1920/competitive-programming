/*
The little girl loves the problems on array queries very much.

One day she came across a rather well-known problem: you've got an array of n elements (the elements of the array are indexed starting from 1); also, there are q queries, each one is defined by a pair of integers li, ri (1 ≤ li ≤ ri ≤ n). You need to find for each query the sum of elements of the array with indexes from li to ri, inclusive.

The little girl found the problem rather boring. She decided to reorder the array elements before replying to the queries in a way that makes the sum of query replies maximum possible. Your task is to find the value of this maximum sum.

Input
The first line contains two space-separated integers n (1 ≤ n ≤ 2·105) and q (1 ≤ q ≤ 2·105) — the number of elements in the array and the number of queries, correspondingly.

The next line contains n space-separated integers ai (1 ≤ ai ≤ 2·105) — the array elements.

Each of the following q lines contains two space-separated integers li and ri (1 ≤ li ≤ ri ≤ n) — the i-th query.

Output
In a single line print a single integer — the maximum sum of query replies after the array elements are reordered.

Please, do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.
*/




#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define endl			"\n"
#define pb 				emplace_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
#define token(str,ch)	(std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;)
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}

int main(int argc, char const *argv[]) {
	file_i_o();
	int n, q;
	cin>>n>>q;
	vi arr(n);
	loop(i, 0, n-1) {
		cin>>arr[i];
	}
	vi idx(n, 0);
	while(q--) {
		int l, r;
		cin>>l>>r;
		l--;
		r--;
		idx[l]++;
		if(r+1 < n) idx[r+1]--;
	}
	loop(i, 1, n-1) {
		idx[i] += idx[i-1];
	}
	sort(arr.begin(), arr.end());
	sort(idx.begin(), idx.end());
	ll ans = 0;
	loop(i, 0, n-1) {
		ans += (arr[i]*idx[i]);
	}
	cout<<ans;
	return 0;
}