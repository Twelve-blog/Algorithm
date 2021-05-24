#include<bits/stdc++.h> 
#define ll long long
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a*b/(__gcd(a,b))
using namespace std;
//priority_queue <int,vector<int>,less<int> > Q;
ll qpow(ll a,ll x){ll ans=1;while(x>0){if(x&1){ans=(ans*a);}a=(a*a);x/=2;}return ans;}
const int eps = 1e-7;
const ll inf= 0x3f3f3f3f3f3f3f3f;
const int N = 1e5+5;
const int mod = 1e9+7;
ll a[N];
struct node{
    int l,r;
    ll sum;
    int lz;
}tree[N*4];
void build(int i, int l,int r){
    tree[i].l = l;tree[i].r = r;tree[i].lz = 0;
    if(l == r){
        tree[i].sum = a[l];
        return ;
    }
    int mid = (l+r) >> 1;
    build(i*2, l, mid);
    build(i*2+1, mid+1, r);
    tree[i].sum = tree[i*2].sum + tree[i*2+1].sum;
}

void push_down(int i){
    if(tree[i].lz!=0){
        tree[i*2].lz += tree[i].lz; // 左右儿子分别加上父亲的lz
        tree[i*2+1].lz += tree[i].lz;
        // 更新儿子
        int mid = (tree[i].l + tree[i].r) >> 1;
        tree[i*2].sum += tree[i].lz * (mid - tree[i*2].l + 1);
        tree[i*2+1].sum += tree[i].lz * (tree[i*2+1].r - (mid+1) + 1);
        tree[i].lz = 0;
    }
    return ;
}
void add(int i, int l, int r, int num){
    if(tree[i].l>=l && tree[i].r <= r){
        tree[i].sum += num*(tree[i].r-tree[i].l + 1);
        tree[i].lz += num;
        return ;
    }
    push_down(i);
    if(tree[i*2].r >=l){
        add(i*2, l, r, num);
    }
    if(tree[i*2+1].l <=r){
        add(i*2+1, l, r ,num);
    }
    tree[i].sum = tree[i*2].sum + tree[i*2+1].sum;
    return ;
}
ll finds(int i, int l, int r){
    if(tree[i].l>=l && tree[i].r <= r){
        return tree[i].sum;
    }
    if(tree[i].r<l || tree[i].l > r) return 0;
    push_down(i);
    ll s = 0;
    if(tree[i*2].r >=l ){
        s += finds(i*2, l, r);
    }
    if(tree[i*2+1].l <=r ){
        s += finds(i*2+1, l, r);
    }
    return s;
}
void solve(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    build(1,1,n);
    while(m--){
        int x;scanf("%d",&x);
        if(x == 1){
            int l,r;scanf("%d%d",&l,&r);
            ll num;scanf("%lld",&num);
            add(1,l,r,num);
        }
        else{
            int l,r;scanf("%d%d",&l,&r);
            printf("%lld\n",finds(1,l,r));
        }
    }
}
int main(){
	solve();
	return 0;
}
