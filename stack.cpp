#include<iostream>
#include<conio.h>
using namespace std;

const int MAX= 10;
class stack
{
    private:
        int a[MAX];
        int top;
    public:
        stack();
        void push(int item);
        int pop();
};
stack::stack()
{
    top=-1;
}
void stack::push(int item)
{
    if(top==MAX-1)
        cout<<"\nStack is full.";
    top++;
    a[top]=item;
    cout<<"\nThe item added is="<<a[top];
}
int stack::pop()
{
    if(top==-1)
    {
        cout<<"\nStack is empty.";
    
    }
    int data=a[top];
    top--;
    return data;
}
int main()
{
    stack s;
    s.push(5);
    s.push(15);
    int i=s.pop();
    cout<<"\nDeleted item is= "<<i;
    s.push(40);
    i=s.pop();
    cout<<"\nDeleted item is= "<<i;
    getch();
}