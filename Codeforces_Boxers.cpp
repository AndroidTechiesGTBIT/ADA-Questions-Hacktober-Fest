#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int ld;
#define v 150003
#define mod 1000000007
#define fori(i,l,n) for(int i=int(l);i<int(n);i++)
#define forI(i,n,l) for(int i=int(n);i>=int(l);i--)
#define in(n) scanf("%d",&n);
#define In(n) scanf("%lld",&n);
#define iin(n,m) scanf("%d %d",&n,&m);
#define IIN(n,m) scanf("%lld %lld",&n,&m);
#define Pr(n) printf("%d\n",n);
#define pr(n,m) printf("%d %d\n",n,m);
#define flush fflush(stdout);
#define S(a) a.size()
#define pb push_back
#define sr(a) sort(a.begin(),a.end())
#define Sr(a,n) sort(a,a+n);
#define rv(a) reverse(a.begin(),a.end())
#define mp(u,w) make_pair(u,w)
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
priority_queue<pair<int,int>, vector<pair<int,int> >,greater<pair<int,int> > >heapp;
priority_queue<pair<int,int> >heapp2;
vector<int>tree1[v];
vector<pair<int,int> >tree2[v];
class comp{
	public:
		bool operator()(pair<int,int> n1,pair<int,int> n2)
		{
			return(n1.second > n2.second);
		}
};
int main()
{
	int n;
	in(n);
	vector<int>a(n);
	fori(i,0,n)
		in(a[i]);
	sr(a);
	bool c[v]={0};
	int cnt=0;
	fori(i,0,S(a))
	{
		if(c[a[i]]==0)
		{
			if(a[i]-1 !=0 && c[a[i]-1]==0)
			{
				c[a[i]-1]=1;
				a[i]--;
				cnt++;
			}
			else
			{
				cnt++;
				c[a[i]]=1;
			}
		}
		else
		{
			if(a[i]-1!=0 && c[a[i]-1]==0)
			{
				a[i]--;
				c[a[i]]=1;
				cnt++;
			}
			else if(c[a[i]+1]==0 && a[i]+1 <= 150001)
			{
				a[i]++;
				c[a[i]]=1;
				cnt++;
			}
		}
	}
	Pr(cnt);
	return 0;
}
