# 酷爱收集数字的Ereflect

## 题面翻译
Ereflect是一个喜欢中位数的下北洋沼气动力学园学园偶像问好会兼恋恋的信仰者教团改二数字收集癖，他有一个包含若干数据的数字储存箱，某一天不小心打翻了这个储存箱，储存箱中全部数字都掉落出来，Ereflect急忙想回收这些数字，如果这个数字是正数，Ereflect就会回收这个数字重新放入储存箱，如果这个数字是-1，Ereflect就想知道此时储存箱中所有数字的中位数，如果箱子中有偶数个数字，则输出较小的那个中位数。

### 输入格式

输入的第一行包含一个正整数 $t$ ，表示数据组数。

每一组数据会有若干行，每一行都有一个整数 $n$ 。如果 $n$ 是正数，把它加入数列；如果 $n=-1$ ，那么输出当前数列中的中位数；如果 $n=0$，表示这组数据结束。

**在每一个数据中，最多会有 $10^5$ 个整数加进数列，最多会有 $10^5$ 次询问。**

### 输出格式

对于每次询问，输出当前数列中的中位数。

## 说明/提示

对于 $100 \%$ 的数据，$n \le 10^9$。


## 样例 #1

### 样例输入 #1

```
1
9
10
2
5
1
18
-1
-1
4
3
-1
8
7
-1
0
```

### 样例输出 #1

```
5
9
3
7
```

```cpp
#include<iostream>
#include<algorithm>
#define int long long

using namespace std;
const int N = 1e5 + 10;
int a[N];

void work(){
    int n=-1,x;
    for(scanf("%lld",&x);x;scanf("%lld",&x)) {
        if(~x) {
            ++n;
            a[n] = x;
        }
        else {
            if(n&1) {
                sort(a,a+n+1);
                printf("%lld\n",a[(n-1)/2]);
            }    
            else{
                sort(a,a+n+1);
                printf("%lld\n",a[(n-1)/2]);
            }   
            
        }
    }
}    


int32_t main() {
    int t;
    scanf("%d",&t);
    while(t--)
        work();
    return 0;
}
```