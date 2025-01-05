#include <stdio.h>

const int mod = 1e9 + 7;
long long dp[10001];
long long fpow(int a, int n) {
	if( n == 0 ) return 1;
	if( n % 2 == 0 ) {
		long long tmp = fpow(a, n/2);
		return tmp * tmp % mod;
	}
	return a * fpow(a,n-1) % mod;
}
int check(int idx) {
	if( dp[idx] != 0 ) return 1;
	return 0;
}
long long solve(int idx, long long (f1)(int , int), int (f2)(int)) {
	if( f2(idx) == 1 ) return dp[idx];
	else {
		long long a = solve(idx-1, f1, f2);
		long long b = solve(idx-1, f1, f2);
		dp[idx] = f1(a, 20242025) + f1(b, 20252024) % mod;
		return dp[idx];
	}
}
int main() {
	dp[0] = 2024;
	dp[1] = 2025;
	
	int n;
	scanf("%d", &n);
	printf("%lld", solve(n,fpow,check));
	return 0;
} 