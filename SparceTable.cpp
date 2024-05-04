#include <bits/stdc++.h>
using namespace std;
#define FAST_DOT_COM  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
const int N = 2e5+5 ,MOD=1e9+7, INF=0X3F3F3F3F , MAX= 1e9+7;
int n , q , a[N] , T[N][22] ,Log[N];
int merge(int a , int b){
	return min(a,b);
}
void build(){
	for (int i = 0; i < n; ++i){
		T[i][0]=a[i];
	}
	for (int pw = 1; (1<<pw)<=n; ++pw){   // nLog(n) 
		for (int i = 0; i+(1<<pw)<=n; ++i){
			T[i][pw]=merge(T[i][pw-1],T[i+(1<<pw-1)][pw-1]);
		}
	}
}
int query(int l , int r){
	int sz=r-l+1;
	int ret=INT_MAX ;
	for(int i=21 ; i>=0 ;i--){
		if((sz>>i)&1){
			ret=merge(ret,T[l][i]);
			l+=(1<<i);
		}
	}
	return ret;
}
int query2(int l , int r){
	int sz=r-l+1 ;
	int pw=Log[sz];
	return merge(T[l][pw],T[r-(1<<pw)+1][pw]);
}
void preCount(){
	Log[1]=0;
	for (int i = 2; i < N; ++i)
	{
		Log[i]=Log[i>>1]+1;
	}
}
void solve() {
	preCount();
	cin >> n >> q;
    for (int i = 0; i < n; ++i){
    	cin >> a[i];
    }
    build();
    // for (int i = 0; i < 8; ++i){
    // 	for (int j = 0; j < 4; ++j){
    // 		cout<<T[i][j]<<" ";
    // 	}
    // 	cout<<"\n";
    // }
    while(q--){
    	int l , r ;
    	cin >> l >> r ;
    	l-- , r-- ;
    	cout<<query2(l,r)<<"\n";
    }
}
int32_t main(){
	FAST_DOT_COM
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1 ;
    // cin>>t ;
    while (t--) solve();
    return 0;
}
