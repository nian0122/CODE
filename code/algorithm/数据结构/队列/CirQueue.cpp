#include<iostream>
using namespace std;

class Node {
    public:
        int data;
};

typedef class Node qNode;
typedef qNode *qlink;

class QueueList {
private:
    bool isEmpty();
public:
    qlink base;
    int front;
    int rear;
    int size;
    int length;
    void enqueue(int data);
    bool dequeue(int &e);
    void TravalQueueList();
    void CreateLinkList(int n);
};


bool QueueList::isEmpty(){
    return  front == rear;
}

void QueueList::CreateLinkList (int n )
{
    base = new Node[n + 1];
    rear = front = 0;
    size = n + 1;
    for (int i = 1; i <= n; i++)
    {
        cout << "请输入第" << i << "个值: " ;
        cin >> base[rear % size].data;
        rear = (rear + 1) % size;
        length++;
    }
}

void QueueList::TravalQueueList()
{
    if (isEmpty()) {
        cout << "queue is empty!" << endl;
        return;
    }

    int p = front;
    int q = rear;
    while (p % size != q) {
        cout << base[p].data << ' ';
        p = (p+1)%size;
    }
    cout << endl;
}

void QueueList::enqueue(int data) {
    if ((rear + 1) % size == front) {
        cout << "queue is full!" << endl;
        return;
    }

    base[rear % size].data = data;
    rear = (rear + 1) % size;
    length++;
}

bool QueueList::dequeue(int &e) {
    if (isEmpty()) {
        cout << "queue is empty!" << endl;
        return false;
    }
    e=base[front].data;
//    *num = base[front];
    front = (front + 1) % size;
    length--;
    return true;
}


int main(){
    int i, data, n;
    QueueList l;
    cout << "************************" << endl;
    cout << "Creat:   1   Print:   2" << endl;
    cout << "Pop:  3   Push:  4" << endl;
    cout << "Length: 5  Esc:  0" << endl;
    cout << "************************" << endl;
    do
    {
        cout << "请输入要执行的操作: ";
        cin >> i;
        switch (i)
        {
            case 1:
                cout << "请输入队列的长度: ";
                cin >> n;
                l.CreateLinkList(n);
                break;
            case 2:
                l.TravalQueueList();
                break;
            case 3:
                int e;
                if(l.dequeue(e)) cout << e << "is out！" << endl;
                break;
            case 4:
                cout << "请输入入队值：";
                cin >> data;
                l.enqueue(data);
                break;
            case 5:
                cout << l.length << endl;
                break;
            default:
                break;
        }
    }while (i != 0);
    system("pause");
    return 0;
}