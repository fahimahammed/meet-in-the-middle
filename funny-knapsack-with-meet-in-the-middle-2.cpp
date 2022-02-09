#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll arr[2000],x[50000],n,m,k,wt,p,y;

void cal(int i,ll s)
{
    if(i==m)
    {
        if(s<=wt)
            x[k++]=s;
        return;
    }
    cal(i+1,s);
    cal(i+1,s+arr[i]);
}

void cal1(int i,ll s)
{
    if(i>=n)
    {
        p=upper_bound(x,x+k,s)-x;
        if(p>0)
            y+=p;
        return;
    }
    cal1(i+1,s);
    cal1(i+1,s-arr[i]);
}


int main()
{
    ll id=1,l,i,j,s,e=INT_MAX,v=0,key,t,cnt;

    cin>>t;
    while(t--)
    {
        k=0,y=0,
        cin>>n>>wt;
        for(i=0;i<n;i++)
            scanf("%lld",&arr[i]);
        m=n/2+n%2;
        cal(0,0);
        sort(x,x+k);
        cal1(m,wt);
        printf("Case %lld: %lld\n",id++,y);
        memset(x,0,sizeof x);
    }
    return 0;
}
