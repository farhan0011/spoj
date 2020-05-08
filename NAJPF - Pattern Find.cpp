#include<bits/stdc++.h>
using namespace std;
#define LIM 10004
int pref[LIM];
string text,pat;
void generatePrefix()
{
    pref[0] = -1;pref[1] = 0;
    for(int i=2, j=0; i<pat.size(); i++)
    {
        while(j>=0 && pat[j+1]!= pat[i])
        {
            j = pref[j];
        }
        if(pat[j+1] == pat[i])
            {
                pref[i] = j+1;
                j++;
            }
        else{
            pref[i] = 0;
            j = 0;
        }
    }
//    for(int i=1;i<pat.size();i++)
//        cout<<pref[i]<<" ";
//    cout<<endl;
}
void patternMathing()
{
    vector<int>pos;
    for(int i=0, j=0; i<text.size(); i++)
    {
        //cout<<"YES"<<endl;
        while(j>=0&&pat[j+1]!= text[i])
            j = pref[j];
        if(pat[j+1] == text[i])
        {
            //cout<<"YES"<<endl;
            j++;
        }
        else
            j=0;
        if(j == pat.size()-1)
        {
            pos.push_back(i-pat.size()+3);
        }
    }
    if(pos.size() == 0)
        cout<<"Not Found"<<endl;
    else
    {
        cout<<pos.size()<<endl;
        for(int i=0; i<pos.size(); i++)
            cout<<pos[i]<<" ";
        cout<<endl;
    }
}
/**
ababcababcabaabcabaabcab
abcabaabcabb
*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>text>>pat;
        pat = "#" + pat;
        generatePrefix();
        patternMathing();
        if(t)
            cout<<endl;
    }
}

