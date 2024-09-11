#include <iostream>
using namespace std;
const int mod=1e9+7;
long long int dp[1000000+1];
int fid(int n){
	if( n == 1 )return 0;
	if( n == 2 || n == 3 )return 1;
	if(dp[n] != 0)return dp[n];
	dp[n] %=mod;
	return dp[n] = (fid(n-1)+fid(n-2))%mod;
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
    double  q,a1;
	cin>>q;
    dp[0]=1;
    dp[1]=1;
    for(int i=0;i<q;i++){
    	cin>>a1;
    	cout<<fid(a1)<<'\n';
	}
return 0;
}
