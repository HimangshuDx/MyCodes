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
        std::cin >> n;
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
           cin >> n;
        cout<<"\n what is the TOTAL MARKS of each subjects? ";
           cin >> t;
        cout<<"\n\nEnter the marks of each subjects: \n";
        for(i=1; i<=n; i++)
        {
            cout<<"Subject "<<i<<": ";
               cin >> a[i]; 
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

class length
{
public:
    void length_intro() 
    {
        int choice;
        cout << "\n\nYou have selected the Length conversion calculator.";
        cout<<"\n\nWhat do you want to convert? ";
        cout<<"\n1. Kilometer to Meter";   
        cout<<"\n2. Meter to Kilometer";
        cout<<"\n3. Centimeter to Meter";
        cout<<"\n4. Meter to Centimeter";
        cout<<"\n5. Millimeter to Meter";
        cout<<"\n6. Meter to Millimeter";
        cout<<"\n7. Mile to Kilometer";
        cout<<"\n8. Kilometer to Mile";
        cout<<"\n9. Yard to Meter";
        cout<<"\n10. Meter to Yard";
        cout<<"\n11. Foot to Meter";
        cout<<"\n12. Meter to Foot";
        cout<<"\n13. Inch to Meter";
        cout<<"\n14. Meter to Inch";
        cout<<"\n15. Nautical Mile to Kilometer";
        cout<<"\n16. Kilometer to Nautical Mile";
        cout<<"\n17. Light Year to Kilometer";
        cout<<"\n18. Kilometer to Light Year";
        cout<<"\n19. Astronomical Unit to Kilometer";
        cout<<"\n20. Kilometer to Astronomical Unit";
        cout<<"\n\nEnter your choice (1-20): ";
        std::cin >> choice;

        float input, output;
        switch (choice)
        {
        case 1:
            cout << "\nEnter value in Kilometers: ";
            std::cin >> input;
            output = input * 1000;
            cout << "\nValue in Meters: " << output;
            break;
        case 2:
            cout << "\nEnter value in Meters: ";
            std::cin >> input;
            output = input / 1000;
            cout << "\nValue in Kilometers: " << output;
            break;
        case 3:
            cout << "\nEnter value in Centimeters: ";
            std::cin >> input;
            output = input / 100;
            cout << "\nValue in Meters: " << output;
            break;
        case 4:
            cout << "\nEnter value in Meters: ";
            std::cin >> input;
            output = input * 100;
            cout << "\nValue in Centimeters: " << output;
            break;
        case 5:
            cout << "\nEnter value in Millimeters: ";
            std::cin >> input;
            output = input / 1000;
            cout << "\nValue in Meters: " << output;
            break;
        case 6:
            cout << "\nEnter value in Meters: ";
            std::cin >> input;
            output = input * 1000;
            cout << "\nValue in Millimeters: " << output;
            break;
        case 7:
            cout << "\nEnter value in Miles: ";
            std::cin >> input;
            output = input * 1.60934;
            cout << "\nValue in Kilometers: " << output;
            break;
        case 8:
            cout << "\nEnter value in Kilometers: ";
            std::cin >> input;
            output = input / 1.60934;
            cout << "\nValue in Miles: " << output;
            break;
        case 9:
            cout << "\nEnter value in Yards: ";
            std::cin >> input;
            output = input * 0.9144;
            cout << "\nValue in Meters: " << output;
            break;
        case 10:
            cout << "\nEnter value in Meters: ";
            std::cin >> input;
            output = input / 0.9144;
            cout << "\nValue in Yards: " << output;
            break;
        case 11:
            cout << "\nEnter value in Feet: ";
            std::cin >> input;
            output = input * 0.3048;
            cout << "\nValue in Meters: " << output;
            break;
        case 12:
            cout << "\nEnter value in Meters: ";
            std::cin >> input;
            output = input / 0.3048;
            cout << "\nValue in Feet: " << output;
            break;
        case 13:
            cout << "\nEnter value in Inches: ";
            std::cin >> input;
            output = input * 0.0254;
            cout << "\nValue in Meters: " << output;
            break;
        case 14:
            cout << "\nEnter value in Meters: ";
            std::cin >> input;
            output = input / 0.0254;
            cout << "\nValue in Inches: " << output;
            break;
        case 15:
            cout << "\nEnter value in Nautical Miles: ";
            std::cin >> input;
            output = input * 1.852;
            cout << "\nValue in Kilometers: " << output;
            break;
        case 16:
            cout << "\nEnter value in Kilometers: ";
            std::cin >> input;
            output = input / 1.852;
            cout << "\nValue in Nautical Miles: " << output;
            break;
        case 17:
            cout << "\nEnter value in Light Years: ";
            cin >> input;
            output = input * 9.461e+12;
            cout << "\nValue in Kilometers: " << output;
            break;
        case 18:
            cout << "\nEnter value in Kilometers: ";
            cin >> input;
            output = input / 9.461e+12;
            cout << "\nValue in Light Years: " << output;
            break;
        case 19:
            cout << "\nEnter value in Astronomical Units: "; 
            cin>> input;
            output = input * 1.496e+8;
            cout << "\nValue in Kilometers: " << output;
            break;
        case 20:
            cout << "\nEnter value in Kilometers: ";
            cin >> input;
            output = input / 1.496e+8;
            cout << "\nValue in Astronomical Units: " << output;
            break;
        default:
            cout << "\nInvalid choice.";
        }
    }
};

class mass
{
public:
    void mass_intro() 
    {
        int choice;
        cout << "\n\nYou have selected the Mass conversion calculator.";
        cout<<"\n\nWhat do you want to convert? ";
        cout<<"\n1. Kilogram to Gram";   
        cout<<"\n2. Gram to Kilogram";
        cout<<"\n3. Milligram to Gram";
        cout<<"\n4. Gram to Milligram";
        cout<<"\n5. Pound to Kilogram";
        cout<<"\n6. Kilogram to Pound";
        cout<<"\n7. Ounce to Gram";
        cout<<"\n8. Gram to Ounce";
        cout<<"\n9. Metric Ton to Kilogram";
        cout<<"\n10. Kilogram to Metric Ton";
        cout<<"\n11. Quintal to Kilogram";
        cout<<"\n12. Kilogram to Quintal";
        cout<<"\n13. Carat to Gram";
        cout<<"\n14. Gram to Carat";
        cout<<"\n15. Atomic Mass Unit to Kilogram";
        cout<<"\n16. Kilogram to Atomic Mass Unit";
        cout<<"\n17. Solar Mass to Kilogram";
        cout<<"\n18. Kilogram to Solar Mass";   
        cout<<"\n\nEnter your choice (1-18): ";
        cin >> choice; 
        
        float input, output;
        switch (choice)
        {
        case 1:
            cout << "\nEnter value in Kilograms: ";
            cin >> input;
            output = input * 1000;
            cout << "\nValue in Grams: " << output;
            break;
        case 2: 
            cout << "\nEnter value in Grams: ";
            cin >> input;
            output = input / 1000;
            cout << "\nValue in Kilograms: " << output;
            break;
        case 3:
            cout<<"\nEnter the value in Milligrams: ";
            cin>>input;
            output = input/1000;
            cout<<"\nValue in Grams: "<<output;
            break;
        case 4:
            cout<<"\nEnter the value in Grams: ";   
            cin>>input; 
            output = input*1000;
            cout<<"\nValue in Milligrams: "<<output;
            break;
        case 5:
            cout<<"\nEnter the value in Pounds: ";  
            cin>>input;
            output= input*0.453592;
            cout<<"\nValue in Kilograms: "<<output;
            break;
        case 6:
            cout<<"\nEnter the value in Kilograms: ";
            cin>>input;
            output= input/0.453592;
            cout<<"\nValue in Pounds: "<<output;
            break;
        case 7:
            cout<<"\nEnter the value in Ounces: ";
            cin>>input;
            output= input*28.3495;
            cout<<"\nValue in Grams: "<<output;
            break;
        case 8:
            cout<<"\nEnter the value in Grams: ";
            cin>>input;
            output= input/28.3495;
            cout<<"\nValue in Ounces: "<<output;
            break;
        case 9:
            cout<<"\nEnter the value in Metric Tons: ";
            cin>>input;
            output= input*1000;
            cout<<"\nValue in Kilograms: "<<output;
            break;
        case 10:
            cout<<"\nEnter the value in Kilograms: ";
            cin>>input;
            output= input/1000;
            cout<<"\nValue in Metric Tons: "<<output;
            break;
        case 11:
            cout<<"\nEnter the value in Quintals: ";
            cin>>input;
            output= input*100;
            cout<<"\nValue in Kilograms: "<<output;
            break;
        case 12:
            cout<<"\nEnter the value in Kilograms: ";
            cin>>input;
            output= input/100;
            cout<<"\nValue in Quintals: "<<output;
            break;
        case 13:
            cout<<"\nEnter the value in Carats: ";
            cin>>input;
            output= input/5;
            cout<<"\nValue in Grams: "<<output;
            break;
        case 14:
            cout<<"\nEnter the value in Grams: ";
            cin>>input;
            output= input*5;
            cout<<"\nValue in Carats: "<<output;
            break;
        case 15:
            cout<<"\nEnter the value in Atomic Mass Units: ";
            cin>>input;
            output= input*1.66054e-27;
            cout<<"\nValue in Kilograms: "<<output;
            break;
        case 16:
            cout<<"\nEnter the value in Kilograms: ";
            cin>>input;
            output= input/1.66054e-27;
            cout<<"\nValue in Atomic Mass Units: "<<output;
            break;
        case 17:    
            cout<<"\nENter the value in Solar Mass: ";
            cin>>input; 
            output= input*1.98847e+30;
            cout<<"\nValue in Kilograms: "<<output;
            break;
        case 18:
            cout<<"\nEnter the value in Kilograms: ";
            cin>>input;
            output= input/1.98847e+30;
            cout<<"\nValue in Solar Mass: "<<output;
            break;
        }
    }
};

class temperature
{
    public:
    void temp_intro() 
    {
        int choice;
        cout << "\n\nYou have selected the Temperature conversion calculator.";
        cout<<"\n\nWhat do you want to convert? ";
        cout<<"\n1. Celsius to Fahrenheit";   
        cout<<"\n2. Fahrenheit to Celsius";
        cout<<"\n3. Celsius to Kelvin";
        cout<<"\n4. Kelvin to Celsius";
        cout<<"\n5. Fahrenheit to Kelvin";
        cout<<"\n6. Kelvin to Fahrenheit";
        cout<<"\n\nEnter your choice (1-6): ";
        cin >> choice;

        float input, output;
        switch (choice)
        {
        case 1:
            cout << "\nEnter value in Celsius: ";
            cin >> input;
            output = (input * 9/5) + 32;
            cout << "\nValue in Fahrenheit: " << output;
            break;
        case 2:
            cout << "\nEnter value in Fahrenheit: ";
            cin >> input;
            output = (input - 32) * 5/9;
            cout << "\nValue in Celsius: " << output;
            break;
        case 3:
            cout << "\nEnter value in Celsius: ";
            cin >> input;
            output = input + 273.15;
            cout << "\nValue in Kelvin: " << output;
            break;
        case 4:
            cout << "\nEnter value in Kelvin: ";
            cin >> input;
            output = input - 273.15;
            cout << "\nValue in Celsius: " << output;
            break;
        case 5:
            cout << "\nEnter value in Fahrenheit: ";
            cin >> input;
            output = (input - 32) * 5/9 + 273.15;
            cout << "\nValue in Kelvin: " << output;
            break;
        case 6:
            cout << "\nEnter value in Kelvin: ";
            cin >> input;
            output = (input - 273.15) * 9/5 + 32;
            cout << "\nValue in Fahrenheit: " << output;
            break;
        default:
            cout << "\nInvalid choice.";
        }
    }
};

class Time
{
   public:
    void time_intro()
    {
        int choice;
        cout << "\n\nYou have selected the Time conversion calculator.";
        cout<<"\n\nWhat do you want to convert? ";
        cout<<"\n1. Second to Minute";
        cout<<"\n2. Minute to Second";
        cout<<"\n3. Hour to Minute";
        cout<<"\n4. Minute to Hour";
        cout<<"\n5. Day to Hour";
        cout<<"\n6. Hour to Day";
        cout<<"\n7. Week to Day";
        cout<<"\n8. Day to Week";
        cout<<"\n9. Hours to Second";
        cout<<"\n10. Day to Minute";
        cout<<"\n11. Day to Second";
        cout<<"\n12. Years to Day";
        cout<<"\n13. Years to Week";
        cout<<"\n14. Week to Year";
        cout<<"\n15. Week to Hours";
        cout<<"\n\nEnter your choice: ";
        cin>>choice;

        float input, output;
        switch(choice)
        {
        case 1:
            cout<<"\nENter the valeu in Seconds: ";
            cin>>input;
            output=input/60;
            cout<<"\nThe value in Minutes: "<<output;
            break;
        case 2:
            cout<<"\nEnter the value in Minutes: ";
            cin>>input;
            output=input*60;
            cout<<"\nThe value in Seconds: "<<output;
            break;
        case 3:
            cout<<"\nEnter the value in Hours: ";
            cin>>input;
            output=input*60;
            cout<<"\nThe value in Minutes: "<<output;
            break;
        case 4:
            cout<<"\nEnter the value in Minutes: ";
            cin>>input;
            output=input/60;
            cout<<"\nThe value in Hours: "<<output;
            break;
        case 5:
            cout<<"\nEnter the number if Days: ";
            cin>>input;
            output=input*24;
            cout<<"\nThe value in Hours: "<<output;
            break;
        case 6:
            cout<<"\nEnter the value in Hours: ";
            cin>>input;
            output=input/24;
            cout<<"\nThe number of Days: "<<output;
            break;
        case 7:
            cout<<"\nEnter the number of Weeks: ";
            cin>>input;
            output=input*7;
            cout<<"\nThe Number of days: "<<output;
            break;
        case 8:
            cout<<"\nEnter the number of days: ";
            cin>>input;
            output=input/7;
            cout<<"\nThe number of weeks: "<<output;
            break;
        case 9:
            cout<<"\nEnter the value in Hours: ";
            cin>>input;
            output=input*60*60;
            cout<<"\nThe value in Seconds: "<<output;
            break;
        case 10:
            cout<<"\n ";
            cin>>input;
            output=input*24*60;
            cout<<"\nThe value of Minutes: "<<output;
            break;
        case 11:
            cout<<"\nEnter the number of Days: ";
            cin>>input;
            output=input*24*60*60;
            cout<<"\nThe value in seconds: "<<output;
            break;
        case 12:
            cout<<"\nEnter the number of Years: ";
            cin>>input;
            output=input*365;
            cout<<"\nThe nuber of days: "<<output;
            break;
        case 13:
            cout<<"\nEnter the number of years: ";
            cin>>input;
            output=input/52;
            cout<<"\nThe number of weeks: "<<output;
            break;
        case 14:
            cout<<"\nEnter the number of Weeks: ";
            cin>>input;
            output=input*52;
            cout<<"\nThe number of years: "<<output;
            break;
        case 15:
            cout<<"\nEnter the numbre of weeks: ";
            cin>>input;
            output=input*7*24;
            cout<<"\nThe Hours in a weeks: "<<output;
            break;
            default:
            cout << "\nInvalid choice.";
        }

    }
};

class conversion
{
public:

    length l; // Declare the length object
    mass m; // Declare the mass object
    temperature t; // Declare the temperature object
    Time ti; // Declare the time object


    void con_intro() 
    {    
        int choice;
        cout << "\n\nYou have selected the Conversion calculator.";
        cout << "\n\nWhat do you want to convert? ";
        cout << "\n1. Length";
        cout << "\n2. Mass";
        cout << "\n3. Temperature";
        cout << "\n4. Time";
        cout << "\n5. Volume";
        cout << "\n6. Area";
        cout << "\n7. Pressure";
        cout << "\n8. Energy";
        cout << "\n9. Power";
        cout << "\n10. Data Storage";
        cout << "\n11. Currency";
        cout << "\n\nEnter your choice (1-11): ";
        cin >> choice;

        if (choice == 1)
        {    
            l.length_intro();
        }
        else if (choice == 2)
        {
            mass m;
            m.mass_intro();
        }
        else if (choice == 3)
        {
            temperature t;
            t.temp_intro();
        }
    else if(choice == 4)
    {
        ti.time_intro();
    }
        else if(choice == 5)
        {
            
        }
        else if(choice == 6)
        {
            
        }
        else if(choice == 7)
        {
            
        }
        else if(choice == 8)
        {
            
        }
        else if(choice == 9)
        {
            
        }
        else if(choice == 10)
        {
           
        }
        else if(choice == 11)
        {
            
        }
        else
        {
            cout << "\nConversion type not implemented yet.\n";
        }
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
    conversion con;


    c.input();

    cout << "What will you do? (+,-,*,/,P,C): ";
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

    else if(o == 'c' || o == 'C')
    {
        con.con_intro(); 
    }
    else 
    {
        cout << "\nUnable to perform task.";
    }

    cout<<"\n\nDo you want to contine with more calculations? (Y/N): ";
    cin>>o;
    if(o=='Y' || o=='y')
    {
        return main(); // Use return to avoid potential stack overflow
    }
    else if( o=='N' || o=='n')
    {
        cout<<"\n\nThank you for using the calculator.\n\n\n";
    }
    return 0;
/* ToDO=> conversions of temperature , speed conversion , mass conversion , distance conversion, time conversion, volume conversion, area conversion, pressure conversion, energy conversion, power conversion, data storage conversion, currency conversion */
}
