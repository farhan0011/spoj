#include<bits/stdc++.h>
using namespace std;
#define LIM 100005
int tree[3][4*LIM];
int prop[4*LIM];
int arr[LIM];

void build(int node,int b,int e)
{
    if(b == e)
    {
        tree[0][node] = 1;
        tree[2][node] = 0;
        tree[1][node] = 0;
        prop[node] = 0;
        return ;
    }
    int md = (b+e)/2;
    int lf = 2*node;
    int rg = lf + 1;
    build(lf,b,md);
    build(rg,md+1,e);
    tree[0][node] = tree[0][lf]+tree[0][rg];
    tree[1][node] = tree[1][lf]+tree[1][rg];
    tree[2][node] = tree[2][lf]+tree[2][rg];
}
///update er complexity log(n) cause every level e change hoi ekta...r level number holo log(n)
void update(int node,int st,int ed,int i,int j,int carry )
{
    //cout<<"UP"<<endl;
    if(carry == 1)
        {
            int temp = tree[0][node];
          tree[0][node] = tree[2][node];
          tree[2][node] = tree[1][node];
           tree[1][node] = temp;
           //cout<<"node : "<<node<<" = "<<tree[0][node]<<","<<tree[1][node]<<","<<tree[2][node]<<endl;
        }
        if(carry == 2)
        {
            int temp = tree[0][node];
          tree[0][node] = tree[1][node];
          tree[1][node] = tree[2][node];
           tree[2][node] = temp;
           //cout<<"node : "<<node<<" = "<<tree[0][node]<<","<<tree[1][node]<<","<<tree[2][node]<<endl;
        }
        prop[node]+=carry;
           prop[node] = prop[node]%3;
    if(st>j || ed<i)
        return ;
    if(st>=i && ed<=j)
    {
        int temp = tree[0][node];
          tree[0][node] = tree[2][node];
          tree[2][node] = tree[1][node];
           tree[1][node] = temp;
           //cout<<"YES"<<endl;
           //cout<<"node : "<<node<<" = "<<tree[0][node]<<","<<tree[1][node]<<","<<tree[2][node]<<endl;
           prop[node]++;
           prop[node] %= 3;
           return ;
    }
    int le = node * 2;
    int rg = 1 + node * 2;
    int md = (st+ed)/2;
    //cout<<node<<" "<<le<<" "<<rg<<" "<<md<<endl;
    update(le,st,md,i,j,prop[node]);
    update(rg,md+1,ed,i,j,prop[node]);
    tree[0][node] = tree[0][le]+tree[0][rg];
    tree[1][node] = tree[1][le]+tree[1][rg];
    tree[2][node] = tree[2][le]+tree[2][rg];
    //cout<<"node : "<<node<<" = "<<tree[0][node]<<","<<tree[1][node]<<","<<tree[2][node]<<endl;
    prop[node] = 0;
}
int query(int node,int st,int ed,int i,int j,int carry = 0)
{
    //cout<<"prop = "<<prop[node]<<endl;
    if(carry == 1)
        {
            int temp = tree[0][node];
          tree[0][node] = tree[2][node];
          tree[2][node] = tree[1][node];
           tree[1][node] = temp;
           //cout<<"node : "<<node<<" = "<<tree[0][node]<<","<<tree[1][node]<<","<<tree[2][node]<<endl;
        }
        if(carry == 2)
        {
            int temp = tree[0][node];
          tree[0][node] = tree[1][node];
          tree[1][node] = tree[2][node];
           tree[2][node] = temp;
           //cout<<"node : "<<node<<" = "<<tree[0][node]<<","<<tree[1][node]<<","<<tree[2][node]<<endl;
        }
        prop[node]+=carry;
           prop[node] = prop[node]%3;
    if(st>j||ed<i)
        return 0;
    if(st>=i && ed<=j)
    {
        //cout<<"node = "<<node<<"prop"<<prop[node]<<endl;

        return tree[0][node];
    }
    int md = (st + ed)/2;
    int lf = 2 * node;
    int rg = 1 + lf;
    int q1 = query(lf,st,md,i,j,prop[node]);
    int q2 = query(rg,md+1,ed,i,j,prop[node]);
    prop[node] = 0;
    return q1+q2;
}
int main()
{
    int n,q;
    cin>>n>>q;
    build(1,0,n-1);
    while(q--)
    {
        int a,b,c;
        cin>>a;
        if(a == 0)
        {
            cin>>b>>c;
            update(1,0,n-1,b,c,0);
        }
        else
        {
            cin>>b>>c;
            cout<<query(1,0,n-1,b,c)<<endl;
        }
    }
}
