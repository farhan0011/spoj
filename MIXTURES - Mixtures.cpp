#include<bits/stdc++.h>
using namespace std;
int A[105];
int dp[105][105];
int dp1[105][105];
//int sum[105];
int n;
int sum(int st,int ed)
{
    //cout<<"YES"<<endl;
    if(st == ed)
        return A[st];
        if(st>ed)
            return 0;
    if(dp1[st][ed]!=0)
        return dp1[st][ed];
    int a=0,b=0;
    for(int i=st;i<ed;i++)
        {
             a = sum(st,i)%100;
             b = sum(i+1,ed)%100;
        }
    return dp1[st][ed] = (a+b)%100;
}
int f(int st,int ed)
{
    if(st>=ed)
        return 0;
        if(dp[st][ed]!=-1)
            return dp[st][ed];
        int ans = 1<<30;
    for(int i=st; i<ed; i++)
    {
        int opr_lft = f(st,i);
        int opr_rgt = f(i+1,ed);
        int opr_to_mlt = dp1[st][i]*dp1[i+1][ed];
        //cout<<opr_to_mlt<<endl;
        int total = opr_lft + opr_rgt + opr_to_mlt;
        //cout<<"ans = "<<ans<<" total = "<<total<<" lft = "<<opr_lft<<" rgt = "<<opr_rgt<<endl;
        ans = min(ans,total);
    }
    return dp[st][ed] = ans;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        memset(dp,-1,sizeof dp);
        memset(dp1,0,sizeof dp1);
        //memset(sum,0,sizeof sum);
        for(int i=0;i<n;i++)
            scanf("%d",&A[i]);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    dp1[i][j] = A[i];
            }
        }
            sum(0,n-1);
        printf("%d\n",f(0,n-1));
//        for(int i=0;i<5;i++)
//        {
//            for(int j=0;j<5;j++)
//                cout<<dp1[i][j]<<" ";
//            cout<<endl;
//        }
    }
}
