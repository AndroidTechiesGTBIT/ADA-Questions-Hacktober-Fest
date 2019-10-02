#include<bits/stdc++.h>
#include<queue>
#define INTMAX 10000000000
#define mod 1000000007
using namespace std;
 vector<pair<long long,long long> > adj[100005];
 vector<pair<long long,long long> > w;
 long long visited[100005];
 long long ans[100005];
long long dij(long long n)
{
    priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > > q;
    q.push(make_pair(0,0));
    while(!q.empty())
    {

  pair<long long,long long>  y=q.top();
  q.pop();
  long long x=y.second;
   visited[x]=1;
    for(long long i=0;i<adj[x].size();i++)
    {
    
        long long l=adj[x][i].second;
       long long  s=y.first+adj[x][i].first;
        if(s<w[l].first && visited[l]==0)
        {


        w[l].first=s;
        q.push(w[l]);
        ans[l]=(x+1)%mod;
        }
else if(s==w[l].first)
        {
         ans[l]=((ans[l]%mod)+((x+1)%mod))%mod;
        }
    }
    }
}
int main()
{

    long long t;
    cin>>t;
    while(t--)
    {
       w.clear();
       fill(ans,ans+100005,0);
        long long n,m;
        cin>>n>>m;
       for(long long i=0;i<m;i++)
        adj[i].clear();
        w.push_back(make_pair(0,0));
        for(long long i=1;i<n;i++)
        w.push_back(make_pair(INTMAX,i));
        for(long long i=0;i<n;i++)
            visited[i]=0;
        for(long long i=0;i<m;i++)
        {

            long long u,v,w;
            cin>>u>>v>>w;
            adj[u-1].push_back(make_pair(w,v-1));
            adj[v-1].push_back(make_pair(w,u-1));
        }

        dij(n);
        long long a=0;
for(long long i=0;i<n;i++)
{


    a=((a%mod)+(ans[i]%mod))%mod;
}
cout<<a<<"\n";
    }
}
