#include<iostream>
using namespace std;

class Shape
{
    public:
    int n;

    void setN()
    {
        cout << "Enter the number of lines: ";
        cin >> n;
    }

    int returnN()
    {
        return n;
    }
};

class Square: public Shape
{
    public:
    Square(int size) 
    { 
        n = size; 
    }

    void draw_square()
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                cout << " * ";
            }
            cout << endl;
        }
    }
};

class Rectangle: public Shape
{
    public:
    Rectangle(int size) 
    { 
        n = size; 
    }
    void draw_rectangle()
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
                cout << "*";
            cout << endl;
        }
    }
};

class hollow_rectangle: public Shape
{
    public:
    hollow_rectangle(int size) 
    { 
        n = size; 
    }
    void draw_hollow_rectangle()
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i==1 || i==n || j==1 || j==n)
                    cout << "*";
                else
                    cout << " ";
            }
            cout << endl;
        }
    }
};

class Pyramid: public Shape
{
    public:
    Pyramid(int size) 
    { 
        n = size; 
    }
    void draw_triangle()
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n-i; j++)
                cout << " ";
            for(int k=1; k<=2*i-1; k++)
                cout << "*";
            cout << endl;
        }
    }
};

class InversePyramid: public Shape
{
    public:
    InversePyramid(int size) 
    { 
        n = size; 
    }
    void draw_triangle()
    {
        for(int i=n; i>=1; i--)
        {
            for(int j=1; j<=n-i; j++)
                cout << " ";
            for(int k=1; k<=2*i-1; k++)
                cout << "*";
            cout << endl;
        }
    }
};

class hollow_pyramid: public Shape
{
    public:
    hollow_pyramid(int size) 
    { 
        n = size; 
    }
    void draw_hollow_pyramid()
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=i; j<=n; j++)
                cout << " ";
            for(int k=1; k<=2*i-1; k++)
            {
                if(k==1 || k==2*i-1 || i==n)
                    cout << "*";
                else
                    cout << " ";
            }
            cout << endl;
        }
    }
};

class RightTriangle: public Shape
{
    public:
    RightTriangle(int size) 
    { 
        n = size; 
    }
    void draw_RightTriangle()
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=i; j++)
                cout << "*";
            cout << endl;
        }
    }
};

class InverseRightTriangle: public Shape
{
    public:
    InverseRightTriangle(int size) 
    { 
        n = size; 
    }
    void draw_InverseRightTriangle()
    {
        for(int i=n; i>=1; i--)
        {
            for(int j=1; j<=i; j++)
                cout << "*";
            cout << endl;
        }
    }
};

class LeftTriangle: public Shape
{
    public:
    LeftTriangle(int size) 
    { 
        n = size; 
    }
    void draw_LeftTriangle()
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n-i; j++)
                cout <<" ";
            for(int k=1; k<=i; k++)
                cout << "*";
            cout << endl;
        }
    }
};

class InverseLeftTriangle: public Shape
{
    public:
    InverseLeftTriangle(int size) 
    { 
        n = size; 
    }
    void draw_InverseLeftTriangle()
    {
        for(int i=n; i>=1; i--)
        {
            for(int j=1; j<=n-i; j++)
                cout <<" ";
            for(int k=1; k<=i; k++)
                cout << "*";
            cout << endl;
        }
    }
};

class half_diaond_inverse: public Shape
{
    public:
    half_diaond_inverse(int size) 
    { 
        n = size; 
    }
    void drawhalfdiamondinverse()
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n+1-i; j++)
                cout << "*";
            cout << endl;
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=i+1; j++)
                cout << "*";
            cout << endl;
        }
    }
};

class half_diaond_inverse2: public Shape
{
    public:
    half_diaond_inverse2(int size) 
    { 
        n = size; 
    }
    void drawhalfdiamondinverse2()
    {
        for(int i=n; i>=1; i--)
        {
            for(int j=1; j<=n-i; j++)
                cout <<" ";
            for(int k=1; k<=i; k++)
                cout << "*";
            cout << endl;
        }
        for(int i=2; i<=n; i++)
        {
            for(int j=1; j<=n-i; j++)
                cout <<" ";
            for(int k=1; k<=i; k++)
                cout << "*";
            cout << endl;
        }

    }
};

class half_diamond : public Shape
{
    public:
    half_diamond(int size) 
    { 
        n = size; 
    }
    void drawhalfdiamond()
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n-i; j++)
                cout <<" ";
            for(int k=1; k<=i; k++)
                cout << "*";
            cout << endl;
        }
        for(int i=n-1; i>=1; i--)
        {
            for(int j=1; j<=n-i; j++)
                cout << " ";
            for(int k=1; k<=i; k++)
                cout << "*";
            cout << endl;
        }
    }
};

class half_diamond_2: public Shape
{
    public:
    half_diamond_2(int size) 
    { 
        n = size; 
    }
    void drawhalfdiamond2()
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=i; j++)
                cout << "*";
            cout << endl;
        } 
        for(int i=n-1; i>=1; i--)
        {
            for(int j=1; j<=i; j++)
                cout << "*";
            cout << endl;
        }
    }

};

class Diamond: public Shape
{
    public:
    Diamond (int size) 
    { 
        n = size; 
    }
    void draw_diamond()
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n-i; j++)
                cout << " ";
            for(int k=1; k<=2*i-1; k++)
                cout << "*";
            cout << endl;
        }
        for(int i=n-1; i>=1; i--)
        {
            for(int j=1; j<=n-i; j++)
                cout << " ";
            for(int k=1; k<=2*i-1; k++)
                cout << "*";
            cout << endl;
        }
    }
}; 

class heart : public Shape
{
public:
    heart(int size)
    {
        n = size;
    }
    void draw_heart()
    {
        for(int i=n/2; i<=n; i+=2)
        {
            for(int j=1; j<n-i ; j+=2)
                cout << " ";
            for(int j=1; j<=i; j++)
                cout << "*";
            for(int j=1; j<=n-i; j++)   
                cout << " ";
            for(int j=1; j<=i; j++)
                cout << "*";
            cout << endl;
        }
        for(int i=n; i>=1; i--)
        {
            for( int j=i; j<n; j++)
                cout << " ";
            for(int j=1; j<=2*i-1; j++)
                cout << "*";
            cout << endl;
        }
    
    }
};

class big_x: public Shape
{
    public:
    big_x(int size) 
    { 
        n = size; 
    }
    void draw_big_x()
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(j==i || j==n-i+1)
                    cout << "*";
                else
                    cout << " ";
            }
            cout << endl;
        }
    }
};

class number1: public Shape
{
    public:
    number1(int size) 
    { 
        n = size; 
    }
    void drawnumber1()
    {
        for(int i=1; i<=n; i++)                     // 1 2 3
        {                                           // 1 2 3
            for(int j=1; j<=3; j++)                 // 1 2 3
            {                                       // 1 2 3
                cout <<" "<<j;                      // so on...
            }
            cout << endl;
        }
    }
};

class number2: public Shape
{
    public:
    number2(int size) 
    { 
        n = size; 
    }
    void drawnumber2()
    {
        for(int i=1; i<=n; i++)                     // 1 1 1
        {                                           // 2 2 2
            for(int j=1; j<=3; j++)                 // 3 3 3
            {                                       // 4 4 4
                cout <<" "<<i;                      // so on...
            }
            cout << endl;
        }
    }
};

class number3: public Shape
{
    public:
    number3(int size) 
    { 
        n = size; 
    }
    void drawnumber3()
    {
        for(int i=1; i<=n; i++)                     // 1 2 3
        {                                           // 2 3 4
            for(int j=1; j<=3; j++)                 // 3 4 5
            {                                       // 4 5 6
                cout <<" "<<i+j-1;                  // so on...
            }
            cout << endl;
        }
    }
};

class number4: public Shape                         //kaam baki asee...
{
    public:
    number4(int size) 
    { 
        n = size; 
    }
    void draawnumber4()  
    {

                             
    }                 
};

int main()
{   
    Shape s;
    s.setN();  
    int size = s.returnN();

    Square sq(size);
    Rectangle r(size);
    hollow_rectangle hr(size);
    Pyramid P(size);
    InversePyramid IP(size);
    hollow_pyramid hp(size);
    RightTriangle rt(size);
    InverseRightTriangle irt(size);
    LeftTriangle lt(size);
    InverseLeftTriangle ilt(size);
    half_diaond_inverse hdi(size);
    half_diaond_inverse2 hdi2(size);
    half_diamond hd(size);
    half_diamond_2 hd2(size);
    Diamond d(size);
    heart h(size);
    big_x bx(size); 
    number1 n1(size);
    number2 n2(size);
    number3 n3(size);
    number4 n4(size);

    cout << "Square: \n" << endl;
        sq.draw_square();
    cout << endl;

    cout << "Rectangle: \n" << endl;
        r.draw_rectangle();
    cout << endl;

    cout<<"Hollow Rectangle: \n"<<endl;
        hr.draw_hollow_rectangle();
    cout<<endl;

    cout << "Pyramid: \n" << endl;
        P.draw_triangle();  
    cout << endl;

    cout << "Inverse Pyramid: \n" << endl;
        IP.draw_triangle();
    cout << endl;

    cout << "Hollow Pyramid: \n" << endl;
        hp.draw_hollow_pyramid();
    cout << endl;   

    cout << "Right-alligned Triangle: \n" << endl;
        rt.draw_RightTriangle();
    cout << endl;

    cout << "Inverse Right-alligned Triangle: \n" << endl;
        irt.draw_InverseRightTriangle();
    cout << endl;

    cout << "Left-alligned Triangle: \n" << endl;
        lt.draw_LeftTriangle();
    cout << endl;

    cout << "Inverse Left-alligned Triangle: \n" << endl;
        ilt.draw_InverseLeftTriangle();
    cout << endl;

    cout << "Half Diamond Inverse: \n" << endl;
        hdi.drawhalfdiamondinverse();
    cout << endl;

    cout << "Half Diamond Inverse 2: \n" << endl;
        hdi2.drawhalfdiamondinverse2();
    cout << endl;

    cout << "Half Diamond: \n" << endl;
        hd.drawhalfdiamond();
    cout<<endl;

    cout << "Half Diamond 2: \n" << endl;
        hd2.drawhalfdiamond2();
    cout << endl;

    cout << "Diamond: \n" << endl;
        d.draw_diamond();
    cout << endl;

    cout << "Heart: \n" << endl;
        h.draw_heart();
    cout << endl;

    cout << "Big X: \n" << endl;
        bx.draw_big_x();
    cout << endl;

    cout<<"Some Patterns with numbers: \n"<<endl;

    cout<<"Pattern 1: \n"<<endl;
        n1.drawnumber1();
    cout<<endl;

    cout<<"Pattern 2: \n"<<endl;
        n2.drawnumber2();
    cout<<endl;

    cout<<"Pattern 3: \n"<<endl;
        n3.drawnumber3();
    cout<<endl;

    cout<<"Pattern 4: \n"<<endl;
        n4.draawnumber4();
    cout<<endl;
}