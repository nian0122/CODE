//�и�n ����������ά�������ѣ�һ��С���ѣ�ά��ǰ ?��2??n��2? ��������Ȼ�Ѷ����ǵ� ?��2??n��2? ��һ������ѣ�ά���� ?��2??n��2? ��������Ȼ�Ѷ��ǵ� ?��2??n��2? С��
//��ѯ + ɾ����λ������� n �������������С���ѶѶ���������С���ѶѶ���n �����ż�������������ѶѶ�����������ע�⣬������Ҫά��һ�������ѣ���֤С���ѵĶѶ��ǵ� ?��2??n��2? �󣬴���ѶѶ��ǵ� ?��2??n��2? С��
//���룺��С���ѶѶ��Ƚ�һ�£��������� ��С���ѶѶ�������С���ѣ�����������ѣ����ȥ��ҲҪ�񵯳�����ά��һ�������������Ԫ�ظ�������������ǿնѵĻ���û�жѶ��ģ�Ҫ���У�
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
