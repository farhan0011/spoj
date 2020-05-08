#include<bits/stdc++.h>
using namespace std;
//int main()
//{
//    int T;
//    cin>>T;
//    for(int t=1; t<=T; t++)
//    {
//        string s;
//        cin>>s;
//        int sz = s.size();
//        int i=0,j,k,br;
//        for(i=0; i<sz-1; i++)
//        {
//             j = sz-1,k=i,br=0;
//            while(s[k] == s[j] && k<=j)
//            {
//                j--,k++;
//            }
//            if(k>=j)
//            {
//                break;
//            }
//        }
//        cout<<"Case "<<t<<": "<<sz+i<<endl;
//    }
//}
string text,pat;
#define LIM 2000100
int pref[LIM];
void generatePat()
{
    pref[0] = -1;
    pref[1] = 0;
    for(int i=2,j=0; i<pat.size(); i++)
    {
        while(j>=0&&pat[j+1]!=pat[i])
            j = pref[j];
        if(pat[j+1] == pat[i])
        {
            pref[i] = j+1;
            j++;
        }
        else
            {
                j = 0;
                pref[i] = 0;
            }
    }
}
int main()
{

    while(cin>>text)
    {
        string tmp = text;
        reverse(tmp.begin(),tmp.end());
        pat = "#" + tmp + "$" + text;
        //cout<<pat<<endl;
        memset(pref,0,sizeof pref);
        generatePat();
//        for(int i=0;i<pat.size();i++)
//            cout<<pref[i]<<" ";
//        cout<<endl;
        int ans = pref[pat.size()-1];
        //cout<<ans<<endl;
        string s = "";
        for(int i=ans+1;i<=tmp.size();i++)
            s+=pat[i];
            reverse(s.begin(),s.end());
        cout<<s+tmp<<endl;
        //string f = "";
        //f =s+tmp;
        //reverse(f.begin(),f.end());
        //cout<<f<<endl;

    }
}

