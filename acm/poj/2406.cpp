//#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define LOCAL/*
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;*/
//const int MAXN = 10010
char s[1000005];
int next[1000005];
int t;
void getnext(){
	int i = 0,j = -1;
	next[i] = j;
	while(i < t){
		if(j == -1||s[i] == s[j])next[++i] = ++j;
		else j = next[j];
	}
}

int main(){
	std::ios::sync_with_stdio(false);
    /*
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif */
    int ca = 0;
	while(1){
	    cin>>s;
            if(s[0] =='.'&&s[1] == 0)break;
		t = strlen(s);
		//cout<<t;
		getnext();
		//cout<<"Test case #"<<++ca<<endl;
		//REP(i,t+1){
            if(next[t]>0&&t%(t-next[t])==0)
                cout<<t/(t-next[t])<<endl;
            else cout<<"1"<<endl;
		//}
       // cout<<endl;
	}

   //printf("Time used = %.2lf\n",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}
