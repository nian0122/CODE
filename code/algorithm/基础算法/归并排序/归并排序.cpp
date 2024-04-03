#include<iostream>

using namespace std;

const int N =1e6+10;

int n,l,r;
int q[N],temp[N];

void merge_sort(int q[],int l,int r)
{
    if(l>=r)return;

    int mid = (l+r)>>1;

    merge_sort(q,l,mid);
    merge_sort(q,mid+1,r);

    int k=0, i = l, j = mid + 1;

    while(i<=mid&&j<=r)
    {
        if(q[i]<q[j])temp[k++]=q[i++];
        else temp[k++]=q[j++];
    }
    while(i<=mid)temp[k++]=q[i++];
    while(j<=r)temp[k++]=q[j++];
    for(int u=0,p=l;p<=r;u++,p++)q[p]=temp[u];

}

int main()
{
    scanf("%d",&n);

    for(int i=0;i<n;i++)scanf("%d",&q[i]);

    merge_sort(q,0,n-1);

    for(int i=0;i<n;i++)printf("%d",q[i]);

    return 0;
}
// void merge_sort(一个数组) {
//   if (可以很容易处理) return;
//   merge_sort(左半个数组);
//   merge_sort(右半个数组);
//   merge(左半个数组, 右半个数组);
// }