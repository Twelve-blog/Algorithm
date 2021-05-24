#include<bits/stdc++.h>
#define ll long long
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a*b/(__gcd(a,b))
#define rep(i,s,e) for(int i=s;i<e;i++)
#define fep(i,s,e) for(int i=s;i<=e;i++)
#define mem(a,n) memset(a, n ,sizeof(a))
#define Fill(a,n,b) fill(a,a+n,b)
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
long long fastPower(long long base, long long power){long long result = 1;while (power > 0) {if (power & 1) {result = result * base % 1000;}power >>= 1;base = (base * base) % 1000;}return result;}
priority_queue <int,vector<int>,less<int> > Q;
const int inf= 0x3f3f3f3f;
const int N = 1e5+5;
ll sum = 0;
int a[100000+5];
int b[100000+5];
void merge(int l,int mid ,int r){
	int p1 = l;
	int p2 = mid+1;
	for(int i=l;i<=r;i++){
		if(p1 <= mid && (p2 > r || a[p1] <= a[p2])){
			b[i] = a[p1];
			p1++;
		}
		else{
			b[i] = a[p2];
			p2++;
			sum+=mid-p1+1;
		}
	}
	for(int i=l;i<=r;i++) a[i] = b[i];
}

void erfen(int l,int r){
	int mid = (l+r) >> 1;
	if(l<r){
		erfen(l,mid);
		erfen(mid+1,r);
	}
	merge(l,mid,r);
}
int main(){
	IOS;
	int n;
	cin >> n;
	sum=0;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	erfen(1,n);
	printf("%d\n",sum);
	return 0;
}

