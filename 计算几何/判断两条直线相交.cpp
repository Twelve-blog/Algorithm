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
const int N = 100005;
struct Point{
	double x,y;
	Point(double _x = 0,double _y = 0) : x(_x), y(_y){}
	Point operator -(const Point &op2) const{
		return Point(x - op2.x, y - op2.y);		//���������� 
	}
	Point operator +(const Point &op2) const{
		return Point(x + op2.x, y + op2.y);		//���������� 
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
	inline int corss(const Point &p1, const Point &p2, const Point &p3, const Point &p4){
		double a1 = mul(p1,p2,p3); double a2 = mul(p1,p2,p4);
		if(sign( a1 ) == 0 && sign( a2 ) == 0) return 2;	//�غ�
		if(sign(a1) == sign(a2)) return 0;//������
		return 1; //���� 
	}
};
Point p1[N],p2[N],tp;
void solve(int n){
	for(int i=0;i<n;i++){
		cin >> p1[i].x >> p1[i].y >> p2[i].x >> p2[i].y;
	}
	printf("Top sticks:");
	bool f1 = false;
	for(int i=0;i<n;i++){
		bool flag = false;
		for(int j=i+1;j<n;j++){
			if(tp.corss(p1[i],p2[i],p1[j],p2[j]) == 1 && tp.corss(p1[j],p2[j],p1[i],p2[i]) == 1){
				flag = true;
				break;
			}
		}
		if(flag == false && f1 == true) printf(",");
		if(flag == false){
			printf(" %d",i+1);
			f1 = true;
		}
	}
	puts(".");
//	Top sticks: 2, 4, 5.
}
int main(){
	IOS;
	int n;
	while(cin >> n and n!=0){
		solve(n);
	}
	
	return 0;
}

