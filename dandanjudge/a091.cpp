#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main() {
	cin.tie(NULL) -> ios::sync_with_stdio(false);
	ll v1 , v2 , u , L , t1 , t;
	cin >> v1 >> t1 >> v2 >> u >> L;
	t = ((L-v1*t1)/v2)+t1;//t = 全部游完的時間
	if (L == t*u) {//剛好在終點被追上 
		cout << "我被土匪又粗又硬的魚叉插到不能自己" << '\n';
		cout << t << " " << L << '\n'; 
	}
	else if (L > t*u) {//土匪追不上 
		cout << "我也好想被土匪又粗又硬的魚叉插哦" << '\n';
		cout << t*u << '\n'; 
	}
	else {
        int mid , l = t1+1 , r = t;
	    while (r - l > 1) {//針對會被追上以u2速度游泳的情況做二分搜 
	    	mid = (l+r)>>1;
	    	if ((mid-t1)*(u-v2) > (v1-u)*t1) r = mid;// 已經被追上
	    	else if ((mid-t1)*(u-v2) < (v1-u)*t1) l = mid;//還沒追上 
	    	else {
	    		cout << "我被土匪又粗又硬的魚叉插到不能自己" << '\n';
	    		cout << mid << " " << mid*u << '\n'; 
	    		break;	
	    	}
	    }
    } 
	return 0;
}   