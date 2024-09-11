#include<bits/stdc++.h>
#include <iomanip>	     //00 12 20 10 11
using namespace std;     //001220 001210 001211 002010 002011 001011 122010 122011 121011 201011
int main() {			 //2	  1		 0.5	0	   1 	  0.5	 2      0.5    0      0.5    =8
	cin.tie(NULL) ->ios::sync_with_stdio(false);
	int n;
	double ans = 0 , m , p , q;
	cin >> n;
	vector< pair<double , double> > a(n);
	for (int i = 0 ; i < n ; i++) {
		cin >> a[i].first >> a[i].second;
	}
	for (int i = 0 ; i < n ; i++) {
		for (int j = i+1 ; j < n ; j++) {
			p = a[i].first*a[j].second;
			q = a[j].first*a[i].second;
			for (int l = j+1 ; l < n ; l++){
				m = p+(a[j].first*a[l].second)+(a[l].first*a[i].second)-q-(a[l].first*a[j].second)-(a[i].first*a[l].second);
				if (m > 0){
					ans += m/2;
				}
				else {
					ans += (-1)*m/2;
				}
			}
		}
	}
//	int i = 0 , b = 1;
//	while(b == 1) {
//		if ((ans-i) > 0) i++;
//		else if ((ans-i) == 0) {
//			break;
//		}
//		else {
//			b = 0;
//			break;
//		}
//	}
	double d = ans;
	int i = static_cast<int>(d);
	if (ans == i){
		cout << fixed << setprecision(1) << d << '\n';
	}
	else{
		cout << fixed << setprecision(1) << d << '\n';	}
	return 0;
}


