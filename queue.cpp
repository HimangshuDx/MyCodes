#include<conio.h>
#include<iostream>
using namespace std;
const int MAX=10;
class queue
{
    private: int a[MAX];
             int front, rear;
    public:  queue();
             void addq();
             int delq();
};
queue::queue()
{
    front=rear=-1;
}
void queue::addq()
{
    int item;
    if(rear==MAX-1)
         cout<<"\nQueue is full.";
    rear++;
    cout<<"\nEnter the element: ";
    cin>>item;
    a[rear]=item;
    if(front==-1)
        front=0;
}
int queue::delq()
{
    int data;
    if(front==-1)
    {
        cout<<"\nQueue is empty.";
        return 0;
    }
    data=a[front];
    a[front]=0;
    if(front==rear)
        front=rear=-1;
    else
        front++;
    return data;
}
int main()
{
    queue a;
    a.addq();
    a.addq();
    a.addq();
    int i=a.delq();
    cout<<"\nItem Deleted  "<<i;
    i=a.delq();
    cout<<"\nItem Deleted  "<<i;
    getch();
}
