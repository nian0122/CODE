#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int N=1e6+10;

typedef vector<pair<int,int>> PII;
PII add,query;
vector<int>alls;
int n,m,x,c;
int a[N],s[N];

//���ֲ���Ѱ��ӳ��
int find(int x)
{
    int l=0,r=alls.size()-1;
   
    while(l<r)
    { 
        int mid = l+r >>1;
        if(alls[mid]>=x)r=mid;
        else l=mid+1;
    }
    return l+1;
}

int main()
{
    //¼������
    cin>>n>>m;
    while(n--){
        cin>>x>>c;
        add.push_back({x,c});
        alls.push_back(x);
    }
    while(m--){
        int l,r;
        cin>>l>>r;
        query.push_back({l,r});
        alls.push_back(l);
        alls.push_back(r);
    }

    //ȥ������
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());

    //��ֵ 
    for(auto iteam:add){
        int i=find(iteam.first);
        a[i]=iteam.second;
    }

    //ǰ׺��
    for(int i=1;i<=alls.size();i++){
        s[i]=s[i-1]+a[i];
    }

    //ѯ��
    for(auto iteam:query){
        int l=find(iteam.first);
        int r=find(iteam.second);
        cout<<s[r]-s[l-1]<<endl;
    }
        
    return 0;
   
}

