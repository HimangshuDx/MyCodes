#include<iostream>
#include<conio.h>
using namespace std;
class MAN
{
    public:
        char Mname[20];
        void getMan();
        void disMan();
};
class WOMAN: public MAN
{
       public:
        char Wname[20];
        void getWom();
        void disWom();
};
class CHILD: public WOMAN
{
    private:
        char Cname[20];
    public: 
        void getCh();
        void disCh(); 
};
void MAN::getMan() 
{
    cout << "\nEnter Father's Name: ";
    cin >> Mname;
}
void MAN::disMan() 
{
    cout << "\nFather's Name is: " << Mname << endl;
}
void WOMAN::getWom()
{
    cout << "Enter Mother's Name: ";
    cin >> Wname;
}
void WOMAN::disWom() 
{
    cout << "Mother's Name is: " << Wname << endl;
}
void CHILD:: getCh()
{
    cout<<"Enter Your Name: ";
    cin>>Cname;
    cout<<endl;
}
void CHILD :: disCh()
{
    cout<<"Your Name is:  "<<Cname<<endl<<endl;
}

int main() 
{
    CHILD c;
    c.getMan(); 
    c.getWom(); 
    c.getCh();
    c.disMan();
    c.disWom();    
    c.disCh();
    return 0;
}