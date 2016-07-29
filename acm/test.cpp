//#define XINF INT_MAX
//#define INF 0x3FFFFFFF
//#define mp(X,Y) make_pair(X,Y)
//#define pb(X) push_back(X)
//#define rep(X,N) for(int X=0;X<N;X++)
//#define rep2(X,L,R) for(int X=L;X<=R;X++)
//#define dep(X,R,L) for(int X=R;X>=L;X--)
//#define clr(A,X) memset(A,X,sizeof(A))
//#define it iterator
//#define lson l,m,((rt)<<1)
//#define rson m+1,r,((rt)<<1|1)
//#define in(x) scanf("%d",&x)
//#define in2(x,y) scanf("%d%d",&x,&y)
//#define in3(x,y,z) scanf("%d%d%d",&x,&y,&z)
//#define out1(x)  printf("%d\n",x)
//typedef long long ll;
////#ifdef LOCAL
////freopen("input.txt","r",stdin);
////freopen("output.txt","w",stdout);
////#endif
//
//
////printf("Time used = %.2lf\n",(double)clock()/CLOCKS_PER_SEC);
#include<bits/stdc++.h>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X,N) for(int X=0;X<N;X++)
#define rep2(X,L,R) for(int X=L;X<=R;X++)
#define dep(X,R,L) for(int X=R;X>=L;X--)
#define clr(A,X) memset(A,X,sizeof(A))
#define it iterator
#define lson l,m,((rt)<<1)
#define rson m+1,r,((rt)<<1|1)
#define in(x) scanf("%d",&x)
#define in2(x,y) scanf("%d%d",&x,&y)
#define in3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define out1(x)  printf("%lld\n",x)
typedef long long ll;
const int maxn = 100005;
ll sum[maxn];
ll a[maxn];


struct node{
    int l,r;
}q[maxn];

int lb(int x){return x&(-x);}
template<typename X>
struct tree_arr{
    X bits[maxn];
    int n;
    void init(int s){n = s;for(int i = 0;i<=n;i++)bits[i] = 0;}
    void add(int x,X y){while(x<=n){bits[x]+=y;x+=lb(x);}}
    X query(int x){X s = 0;while(x>0){s+=bits[x];x-=lb(x);}return s;}
};
tree_arr<long long > tr;
int cmp(node x,node y){
    if(x.l == y.l)return x.r<y.r;
    return x.l<y.l;
}
int main(){
    int n,k,m;
    while(in3(n,k,m)!= EOF){
        memset(sum,0,sizeof(sum));

        for(int i = 1;i<=n;i++){
            scanf("%lld",&a[i]);
            sum[i]+=sum[i-1]+a[i];
        }
        tr.init(n);
        for(int i = 0;i<m;i++){
            in2(q[i].l,q[i].r);
        }
        sort(q,q+m,cmp);
        ll ans = 0;
        for(int i = 0;i<m;i++){
            tr.add(q[i].l,1);
            tr.add(q[i].r+1,-1);
            if(tr.query(q[i].l)>=k){
                int l = q[i].l, r = n;
                while(l<r){
                    int mid = (l+r-1)/2+1;
                    if(tr.query(mid)>=k) l = mid;
                    else r = mid-1;
                }
    //            cout<<l1<<" "<<l<<" "<<sum[l] - sum[l1-1]<<endl;
                ans = max(ans,sum[l] - sum[q[i].l-1]);
            }
        }
        printf("%lld\n",ans);
    }
}
