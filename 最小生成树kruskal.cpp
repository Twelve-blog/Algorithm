#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
struct node{
    int u,v;//u->v
}dis[100005];
int vis[100005];
int main()
{
	int t;
	cin >> t;
	while(t--){
    int c,n,m;
    int sum=0;
    int ss = 0;
    cin >> n >> m;	
	ss = m;
    for(int i=0;i<m;i++){
    	int a,b;
		cin >> a >> b;
        if(a==b) ss--;
        else{
        	dis[sum].u = a;
        	dis[sum++].v = b;
		}
    }
    for(int i=1;i<=n;i++){
    	vis[i]=i;
	}
    for(int i=0;i<sum;i++){
    	if(vis[dis[i].u]==0 &&vis[dis[i].v]==0){
        	ss++;
		}
        if(vis[dis[i].u]!=vis[dis[i].v]){
        	vis[dis[i].u]=vis[dis[i].v] = 0;
		}
    }
    cout << ss << endl;
}
    return 0;
}
