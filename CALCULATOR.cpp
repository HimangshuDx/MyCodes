#include <iostream>
using namespace std;
class intro
{ 
    public:
    void welcome()
    {
        cout<<"\n\n\n       WELCOME TO THE CALCULATOR \n\n";
    }
};
class calculator 
{
public:
    float a[500]; 
    int n, i;
    void input() 
    {
        cout << "\nEnter the number of elements (Or 0): ";
        cin >> n;
        cout << "\n\nEnter the elements: \n";
        for (i = 0; i < n; i++) 
        {
            cin >> a[i];
        }
     }
};
    
class percentage
{
public: 
    float a[50], per,sum=0;
    int i,n,t;  
    void per_intro() 
    {
        cout<< "\n\nYou have selected the percentage calculator.";
    }
    void per_input()
    {
        cout<<"\nHow many Subjects? ";
           cin>>n;
        cout<<"\n what is the TOTAL MARKS of each subjects? ";
           cin>>t;
        cout<<"\n\nEnter the marks of each subjects: \n";
        for(i=1; i<=n; i++)
        {
            cout<<"Subject "<<i<<": ";
               cin>>a[i]; 
        }
    }
    void calculate_per()
    {
        for(i=1; i<=n; i++)
        {
            sum+=a[i];
        }
         per=(sum*100)/(t*n);
        }
    void dispper() 
    {
        cout<<"\n\nYour percentage is: "<<per<<"%";
    }  
};

class summation : public calculator 
{
public:
    float sum_result = 0;
    void calculate_sum() 
    { 
        for (i = 0; i < n; i++) 
        {
            sum_result += a[i];
        }
    }
    void dispsum() 
    {
        cout << "\nThe summation of the numbers is: " << sum_result;
    }
};

class subtraction : public calculator 
{ 
public:
    float sub_result = 0;
    void calculate_sub() 
    { 
        if (n > 0)
        {
            sub_result = a[0]; 
            for (i = 1; i < n; i++)
            { 
                sub_result -= a[i];
            }
        }
    }
    void dispsub() 
    {
        cout << "\nThe subtraction of the numbers is: " << sub_result;
    }
};

class multiplication : public calculator 
{
public:
    float mul_result = 1;
    void calculate_mul() 
    { 
        for (i = 0; i < n; i++) 
        {
            mul_result *= a[i];
        }
    }
    void dispmul() 
    {
        cout << "\nThe multiplication of the numbers is: " << mul_result;
    }
};

class division : public calculator 
{
public:
   float div_result = 1;
   void calculate_div() 
   {
    if (n > 0) // check if there are elements to divide
    { 
        div_result = a[0]; // Start with the first element
        for (i = 1; i < n; i++) //devide the rest of the elements 
        { 
            if (a[i] != 0)  // Check for division by zero
            {   div_result /= a[i];
            } 
            else {
                cout << "\nError: Division by zero encountered at index " << i << ".";
                return; // Exit the function on encountering division by zero
            }
        }
    } else {
        cout << "\nNo elements to divide.";
    }
}
   void dispdiv() 
    {
        cout << "\nThe division of the numbers is: " << div_result;
    }
};



int main() 
{   
    char o;
    static bool first_time = true; // Ensure welcome message appears only once.
    if (first_time) {
        intro i;
        i.welcome();
        first_time = false;
    }

    calculator c; 
    percentage p;
    summation s;
    subtraction sb; 

    c.input();

    cout << "What will you do? (+,-,*,/,P): ";
    cin >> o; 
 
    if (o == '+') 
    {
        s.n = c.n; // Pass the number of elements to summation.
        for (int i = 0; i < c.n; i++) {
            s.a[i] = c.a[i]; // Pass the elements to summation.
        }
        s.calculate_sum();
        s.dispsum();
    } 
    else if (o == '-') 
    {
        sb.n = c.n; // Pass the number of elements to subtraction.
        for (int i = 0; i < c.n; i++) 
        {
            sb.a[i] = c.a[i]; // Pass the elements to subtraction.
        }
        sb.calculate_sub();
        sb.dispsub();
    } 
    else if(o == '*') 
    {
        multiplication m; 
        m.n = c.n; // Pass the number of elements to multiplication.
        for (int i = 0; i < c.n; i++) 
        {
            m.a[i] = c.a[i]; // Pass the elements to multiplication.
        }
        m.calculate_mul();
        m.dispmul();
    }
    else if ( o == '/') 
    {
        division d;
        d.n = c.n; // Pass the number of elements to division.
        for (int i = 0; i < c.n; i++) 
        {
            d.a[i] = c.a[i]; // Pass the elements to division.
        }
        d.calculate_div();
        d.dispdiv();
    }
    else if (o == 'p' || o == 'P')   
        {
        c.n = c.n; // Pass the number of elements to percentage.
        for (int i = 0; i < c.n; i++) 
        {
            c.a[i] = c.a[i]; // Pass the elements to percentage.
        }
        p.per_intro();
        p.per_input();
        p.calculate_per();
        p.dispper();
    }
    else 
    {
        cout << "\nUnable to perform task.";
    }

    cout<<"\n\nDo you want to contine with more calculations? (Y/N): ";
    cin>>o;
    if(o=='Y' || o=='y')
    {
        main();
    }
    else if( o=='N' || o=='n')
    {
        cout<<"\n\nThank you for using the calculator.";
    }
    return 0;
}
