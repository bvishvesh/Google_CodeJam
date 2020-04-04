#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional>
using namespace std;
#define ft ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> new_data_set;
vector<int>graph[200006];
bool visited[200006]={false};
int dfs(int x){
	visited[x]=true;
	int child = 1;
	for(int i=0;i<graph[x].size();i++){
		if(!visited[graph[x][i]]){
			child+=dfs(graph[x][i]);
		}
	}
	return child;
}
int ds[100005],s[100005];
int root(int x){
	while(ds[x]!=x){
		x = ds[x];
	}
	return x;
}
void uni(int x,int y){
	int p = root(x);
	int q = root(y);
	if(p==q){
		return;
	}
	else{
		if(s[p]<s[q]){
			s[q]+=s[p];
			ds[p] = q;
		}
		else{
			s[p]+=s[q];
			ds[q] = p;
		}
	}
}
signed main(){
	ft
	int test;
	cin>>test;
	int temp = test;
	while(test--){
		cout<<"Case #"<<temp-test<<": ";
		int n;
		cin>>n;
		vector<pair<int,int>>v,vi;
		map<pair<int,int>,int>mp;
		for(int i=0;i<n;i++){
			int x,y;
			cin>>x>>y;
			v.push_back({x,y});
			vi.push_back({x,y});
			mp[{x,y}] = i;
		}
		sort(v.begin(),v.end());
		char a[n];
		for(int i=0;i<n;i++){
			a[i]='J';
		}
		a[mp[{v[0].first,v[0].second}]]='J';
		int jmx=v[0].second,cmx=0,f1=0,f=0;
		for(int i=1;i<n;i++){
			if(v[i].first>=jmx){
				a[mp[{v[i].first,v[i].second}]]='J';
				jmx = v[i].second;
			}
			else if(f==0){
				a[mp[{v[i].first,v[i].second}]]='C';
				cmx = v[i].second;
				f++;
			}
			else if(v[i].first>=cmx){
				a[mp[{v[i].first,v[i].second}]]='C';
				cmx = v[i].second;
			}
			else{
				f1++;
				break;
			}
		}
		if(f1!=0){
			cout<<"IMPOSSIBLE"<<endl;
		}
		else{
			for(int i=0;i<n;i++)cout<<a[i];
			cout<<endl;
		}
	}
}