//有个n 个数，我们维护两个堆，一个小根堆，维护前 ?÷2??n÷2? 个数，显然堆顶就是第 ?÷2??n÷2? 大，一个大根堆，维护后 ?÷2??n÷2? 个数，显然堆顶是第 ?÷2??n÷2? 小。
//查询 + 删除中位数：如果 n 是奇数，则输出小根堆堆顶，并弹出小根堆堆顶，n 如果是偶数，则输出大根堆堆顶，并弹出。注意，弹出后还要维护一下两个堆，保证小根堆的堆顶是第 ?÷2??n÷2? 大，大根堆堆顶是第 ?÷2??n÷2? 小！
//插入：和小根堆堆顶比较一下，如果这个数 ≥小根堆堆顶，则插进小根堆，否则插进大根堆，插进去后也要像弹出那样维护一下两个堆里面的元素个数！而且如果是空堆的话是没有堆顶的，要特判！
#include <cstdio>
#include <queue>
using namespace std;
void work() {
    priority_queue<int,vector<int>, greater<int> > heap1;
    priority_queue<int> heap2;
    int n=0,x;
    for(scanf("%d",&x);x;scanf("%d",&x)) {
        if(~x) {
            ++n;
            if(n==1||x>=heap1.top()) {
                heap1.push(x);
                if(!(n&1))
                    heap2.push(heap1.top()),heap1.pop();
            }
            else {
                heap2.push(x);
                if(n&1)
                    heap1.push(heap2.top()),heap2.pop();
            }
        }
        else {
            if(n&1) 
                printf("%d\n",heap1.top()),heap1.pop();
            else
                printf("%d\n",heap2.top()),heap2.pop();
            --n;
        }
    }
}
int main() {
    int t;
    std::scanf("%d",&t);
    while(t--)
        work();
    return 0;
}
