#include<iostream>
using namespace std;
void sum();
void sum(int a,int b);
void sum(int a, float b);
int main()
{
    sum();
    sum(10,20);
    sum(10,20.5f);     // 20.5f is float value , 20.5 is double value so it will give error , so we have to write 20.5f
    return 0;
}
void sum()
{
    cout<<"SUM (without argument)= "<<10+1<<endl;
}
void sum(int a,int b)
{
    cout<<"SUM (with int,int argument)= "<<a+b<<endl;
}
void sum(int a, float b)
{
    cout<<"SUM (with int,float argument)= "<<a+b<<endl;
}