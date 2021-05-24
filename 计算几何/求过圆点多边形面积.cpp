#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<stack>
#include<queue>
#include<map>
#include<set>
#define ll long long
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a*b/(__gcd(a,b))
#define rep(i,s,e) for(int i=s;i<e;i++)
#define fep(i,s,e) for(int i=s;i<=e;i++)
#define mem(a,n) memset(a, n ,sizeof(a))
#define Fill(a,n,b) fill(a,a+n,b)
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
//priority_queue <int,vector<int>,less<int> > Q;
const int eps = 1e-7;
const int inf= 0x3f3f3f3f;
const int N = 5005;
struct Point{
	double x,y;
	Point(double _x = 0,double _y = 0) : x(_x), y(_y){}
	Point operator -(const Point &op2) const{
		return Point(x - op2.x, y - op2.y);		//定义向量减 
	}
	Point operator +(const Point &op2) const{
		return Point(x + op2.x, y + op2.y);		//定义向量加 
	}
	double operator ^(const Point &op2) const{
		return x*op2.y - y*op2.x;	//定义两个向量的叉积运算 
	}
	inline int sign(const double &x){
		if(x > eps) return 1;
		if(x < -eps) return -1;
		return 0;
	}
	inline double sqr(const double &x){
		return x*x;		//计算平方 
	}
	inline double mul(const Point &p0, const Point &p1,const Point &p2){
		return (p1 - p0) ^ (p2 - p0);	//向量p0p1与向量p0p2的叉积 
	}
	inline double dis2(const Point &p0, const Point &p1){
		return sqr(p0.x - p1.x) + sqr(p0.y - p1.y);	//计算向量的模 的平方 
	} 
	inline double dis(const Point &p0, const Point &p1){
		return sqrt(dis2(p0, p1));	//向量的模 
	}
};
void solve(){
	string s;
	cin >> s;
	ll ans = 0;
	Point p = Point(0,0);
	Point p1;
	for(int i=0;i<s.length();i++){
		if(s[i] == '1') p1 = p + Point(-1,-1);
		if(s[i] == '2') p1 = p + Point(0,-1);
		if(s[i] == '3') p1 = p + Point(1,-1);
		if(s[i] == '4') p1 = p + Point(-1,0);
		if(s[i] == '5') p1 = p + Point(0,0);
		if(s[i] == '6') p1 = p + Point(1,0);
		if(s[i] == '7') p1 = p + Point(-1,1);
		if(s[i] == '8') p1 = p + Point(0,1);
		if(s[i] == '9') p1 = p + Point(1,1);
		ans += p^p1;
		p = p1;
	}
	if(ans < 0) ans = -ans;
	cout << ans/2;
	if(ans%2) cout << ".5";
	cout << endl;
//	printf("%.1lf\n",double(ans)/2);
}
int main(){
	IOS;
	int t;
	cin >>t;
	while(t--){
		solve();
	}
	return 0;
}

