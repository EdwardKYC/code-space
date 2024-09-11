#include <bits/stdc++.h>
using namespace std;
int main(){
	int n ;
	while( cin >> n ){
		for( int i = 0 ; i < n ; i++){
			int j = n*2 - 1 - i*2 ;
			for( int k = 0 ; k < i ; k++)
	        cout<<" ";
			for( int I = 0 ; I < j ; I++){
			if(i == (n-1) / 2 && I == (j-1) / 2){
				cout<<"@";
				continue;
			}
			
				cout<<"-";
				 
			}
			cout<<'\n';
		}
	}
    
	return 0;
}