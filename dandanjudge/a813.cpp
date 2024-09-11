#include <bits/stdc++.h>
using namespace std;
int main(){
    int  T,N,M;
    cin>>T;
    for(int i=0;i<T;i++){ 
        cin>>N>>M;
        if(N%2==1 && M%2==1)
        cout<<"D"<<endl;
        else if(N%2==0 && M%2==0)
        cout<<"D"<<endl;
        else
        cout<<"F"<<endl;
    }
    return 0;
}