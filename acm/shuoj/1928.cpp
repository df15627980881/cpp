#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
#define INF 0x3f3f3f3f
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define M_PI 3.14159265358979323846
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define X first
#define Y second
#define MAX_V 10101
#define maxn 567
#define lowbit(X) (X & (-X))
#include<ctime>
#include<stdio.h>
#include<string.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
typedef pair<PII,int>PPI;


string a;
int main()
{
    while(getline(cin,a))
    {
        int x = -1;
        int t = a.length();
        REP(i,t)
        {
            if(a[i]>='A'&&a[i]<='Z')
            a[i] = a[i]-'A'+'a';
        }
        REP(i,t)
        {
            if(i<=t-2)
            {
                if(a[i] == 'b'&&a[i+1] == 'o'&&a[i+2] == 'b')
                //cout<<i<<endl;
                {
                    x = i;
                    break;
                }
            }
        }
        cout<<x<<endl;
    }
    return 0;
}

/**************************************************************
    Problem: 1928
    User: xiaohuihui
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1560 kb
****************************************************************/
