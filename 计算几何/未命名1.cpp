#include<iostream>
using namespace std;
const double eps = 1e-10;
const int maxn = 110;
struct Line{
	double x,y1,y2;
	
	int s;
	Line(double _a = 0,double _b = 0,double _c = 0,int _d = 0) : x(_a),y1(_b),y2(_c),s(_d){}
	
	bool operator < (const Line &op2) const{
		return x < op2.x;
	}
};
double ly[maxn << 1];
class SegmentTree{
	int cover;
	SegmentTree *child[2];
	
	void deliver(){
		if(cover) len = ly[r] - ly[l];
		else len = child[0]->len + child[1]->len;
	}
	public:
		int l,r;
		double len;
		void setup(int _l,int _r){
			l = _l,r = _r;
			cover = 0; len = 0;
			if(_l+1 == _r) return;
			
			int mid = (l+r) >> 1;
			child[0] = new SegmentTree(),child[1] = new SegmentTree();
			
			child[0]->setup(_l,mid); child[1]->setup(mid,_r);
		}
		void paint(const int &_l,const int &_r,const int &v){
			if(_l >= r || _r <= l) return;
			
		}
};
int cs(0);
int n,tot,ty;
Lint l[maxn << 1];
SegmentTree *seg_tr;
int main(){
	while(scanf("%d",&n),n){
		tot = ty = 0;
		for(int i=0;i<n;i++){
			double x,y,r;
			scanf("%lf%lf%lf",&x,&y,&r);
			l[tot++] = Lint(x-r,y-r,y+r,1);	//×ó±ßx 
			l[tot++] = Lint(x+r,y-r,y+r,-1);//ÓÒ±ßx 
			ly[ty++] = y-r,ly[ty++] = y+r;//´æ´¢ÉÏÏÂÁ½±ßyµÄ×ø±ê 
		}
		sort(l,l+tot);
		sort(ly,ly+ty);
		ty = unique(ly,ly+ty) - ly;
		
		double ans = 0;
		seg_tr = new SegmentTree();
		seg_tr->setup(0,ty-1);
		 
	}
	return 0;
}
