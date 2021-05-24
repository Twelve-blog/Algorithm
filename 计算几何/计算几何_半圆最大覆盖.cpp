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
		return Point(x - op2.x, y - op2.y);		//���������� 
	}
	double operator ^(const Point &op2) const{
		return x*op2.y - y*op2.x;	//�������������Ĳ������ 
	}
	inline int sign(const double &x){
		if(x > eps) return 1;
		if(x < -eps) return -1;
		return 0;
	}
	inline double sqr(const double &x){
		return x*x;		//����ƽ�� 
	}
	inline double mul(const Point &p0, const Point &p1,const Point &p2){
		return (p1 - p0) ^ (p2 - p0);	//����p0p1������p0p2�Ĳ�� 
	}
	inline double dis2(const Point &p0, const Point &p1){
		return sqr(p0.x - p1.x) + sqr(p0.y - p1.y);	//����������ģ ��ƽ�� 
	} 
	inline double dis(const Point &p0, const Point &p1){
		return sqrt(dis2(p0, p1));	//������ģ 
	}
};
Point cp,p[N];
double r;
void solve(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++) cin >> p[i].x >> p[i].y;
	int res = 0;
	for(int i=0;i<n;i++){ 	//ѡȡһ������Բ����Ϊ��Բ���±߽����� 
		int tmp = 0;
		for(int j=0;j<n;j++){
			if(cp.sign(cp.dis(p[j],cp) - r) !=1 ){	//!=1��ΪС�ڰ뾶 
				if(cp.sign(cp.mul(cp,p[i],p[j]))!=-1) { 	//!=-1��>0, ���ڰ�Բ�� 
					tmp++;
				}
			} 
		}
		res = max(res,tmp);
	}
	printf("%d\n",res);
}
int main(){
	IOS;
	while(cin >> cp.x >> cp.y >> r and r >= 0){
		solve();
	}
	return 0;
}

