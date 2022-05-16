//
// Created by khanh on 10/12/2021.
//

#include <iostream>
#include <stdio.h>
using namespace std;
const int nmax=10e4+9;
int IT[4*nmax];
int a[nmax];
int b[nmax]={};
int n,m,q;

void MakeIT(int id, int l ,int r)
{
    int mid;
    if (l>r)
        return;
    if (l==r)
    {
        IT[id]=a[l];
        return ;
    }
    mid = (l+r)/2;
    MakeIT(id*2,l,mid);
    MakeIT(id*2+1,mid+1,r);
    IT[id]=max(IT[id*2],IT[id*2+1]);
}
int Query(int id, int l, int r, int u, int v)
{
    if (r<u || l>v)
        return -10e8;
    if (u<=l && r<=v)
        return(IT[id]);
    int mid = (l+r)/2;
    return (max (Query (id*2,l,mid,u,v) , Query(id*2+1,mid+1,r,u,v) ) ) ;
}
int main()
{
    scanf("%d%d",&n,&m);
    int u,v,k;
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&u,&v,&k);
        b[u]+=k;
        b[v+1]-=k;
    }
    int x=0;
    for (int i=1;i<=n;i++)
    {
        x+=b[i];
        a[i]=x;
    }
    MakeIT(1,1,n);
    scanf("%d",&q);
    for (int i=1;i<=q;i++)
    {
        scanf("%d%d",&u,&v);
        printf("%d\n",Query(1,1,n,u,v));
    }
}