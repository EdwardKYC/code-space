#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
bool cmp(pair<char,int> &x,pair<char,int> &y){
return x.first==y.first ? x.second < y.second : x.first < y.first;
}
int main (){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,s;
	bool m;
	cin>>n>>m>>s;
	while(n--){ 
		string str;
		cin>>str;
		vector< pair<char,int> > v;
		for(int i=0;i<str.size();i++)
		v.push_back(make_pair(str[i],i+1));
		for(auto &i:v){
			if(i.first<97)
			i.first+=32 ;
	    }
        if(m){
        	for(auto &i : v){
        		if(i.first+(s%26)>122)
        		i.first='a'+(s%26)-(122-i.first)-1;
        		else if(i.first+(s%26)<122)
        		i.first+=(s%26);
        		else
        		i.first=122;
			}
			
		}
		else
			for(auto &i : v){
        		if(i.first-(s%26)<97)
        		i.first='z'-(s%26)+(i.first-97)+1;
        		else if(i.first+(s%26)>97)
        		i.first=i.first-(s%26);
        		else
        		i.first=97;
	     	}   
		
		sort(v.begin(),v.end(),cmp);
		cout<<!m<<" "<<(s%26)<<'\n';
		for(auto &i : v)
		cout<<i.second;
		cout<<'\n';
	    for(auto &i : v)
		cout<<i.first;
		cout<<'\n';
	}
}
