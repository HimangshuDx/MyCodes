#include<iostream>
using namespace std;
class Number
{
    private:
        int x,y;
    public:
    Number()
    {
        x=10;
        y=20;
    }
    Number(Number &n)
    {
        x=n.x;              //copy constructor , n is object of Number class
        y=n.y;
    }
    void display()
    {
        cout<<"x= "<<x<<"\ny= "<<y<<endl;
    }
};
int main()
{
    Number a;         //default constructor is called   
    Number b (a);         //copy constructor is called
    a.display();
    b.display();
    return 0;
}