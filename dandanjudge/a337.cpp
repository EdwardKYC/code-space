#include <bits/stdc++.h> 
using namespace std ;

struct point {int x , y , ans ;} ;

int main() {
	cin.tie(NULL) -> ios::sync_with_stdio(false);
	int n , m ;
	int dx[4] = {1 , -1 , 0 , 0} , dy[4] = {0 , 0 , 1 , -1} ;
	while (cin >> n >> m) {
		bool vst[n][m] ;
		for (int i = 0 ; i < n ; i++) {
			for (int j = 0 ; j < m ; j++)
				cin >> vst[i][j] ; 
    	}
    	if (vst[0][0] == true) {
    		cout << "Am I a joke to you?" << '\n';
    		continue;
		}
		queue <point> q ;
		point s ;
		s.x = 0 ;
		s.y = 0 ;
		s.ans = 0 ;
		q.push(s) ;
		while (!q.empty()) {
			point s = q.front();
			if (s.x == n-1 && s.y == m-1) {
				cout << s.ans << '\n';
				break;
			}		
			q.pop() ;
			vst[s.x][s.y] = true ;
			for (int i = 0 ; i < 4 ; i++) {
				int nx = s.x + dx[i];
                int ny = s.y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vst[nx][ny]) {
                    point np;
                    np.x = nx;
                    np.y = ny;
                    np.ans = s.ans + 1;
                    q.push(np);
                }
            }
  		}	
  		if (q.empty())
            cout << "Am I a joke to you?" << '\n';
	}		
    return 0; 	
}
