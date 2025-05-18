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
        cout<<"\n\nWhat do you want to convert?\n ";
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
        cout<<"\n\nWhat do you want to convert? \n";
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
        cout<<"\n\nWhat do you want to convert?\n ";
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
        cout<<"\n\nWhat do you want to convert? \n";
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
        cout<<"\n\nEnter your choice(1-20): ";
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

class speed
{
   public:
    void speed_intro()
    {
        int choice;
        cout << "\n\nYou have selected the Speed conversion calculator.";
        cout<<"\n\nWhat do you want to convert? \n";
        cout<<"\n1. Kilometer per hour to Meter per second";
        cout<<"\n2. Meter per second to Kilometer per hour";
        cout<<"\n3. Mile per hour to Kilometer per hour";
        cout<<"\n4. Kilometer per hour to Mile per hour";
        cout<<"\n5. Foot per second to Meter per second";
        cout<<"\n6. Meter per second to Foot per second";
        cout<<"\n7. Knot to Kilometer per hour";
        cout<<"\n8. Kilometer per hour to Knot";
        cout<<"\n9. Mach to Kilometer per hour";
        cout<<"\n10. Kilometer per hour to Mach";
        cout<<"\n11. Speed of light to Kilometer per hour";
        cout<<"\n12. Kilometer per hour to Speed of light";
        cout<<"\n13. Speed of sound to Kilometer per hour";
        cout<<"\n14. Kilometer per hour to Speed of sound";
        cout<<"\n15. Speed of sound to Meter per second";
        cout<<"\n16. Meter per second to Speed of sound";
        cout<<"\n17. Speed of sound to Mach";
        cout<<"\n18. Mach to Speed of sound";
        cout<<"\n19. Speed of sound to Knot";
        cout<<"\n20. Knot to Speed of sound";
        cout<<"\n21.Centemeter per second to Kilometer per hour";
        cout<<"\n22.Kilometer per hour to Centemeter per second";
        cout<<"\n\nEnter your choice (1-22): ";
        cin>>choice;

        float input, output;
        switch(choice)
        {
            case 1:
                cout << "\nEnter value in Kilometers per hour: ";
                cin >> input;
                output = input * 1000 / 3600;
                cout << "\nValue in Meters per second: " << output;
                break;
            case 2:
                cout << "\nEnter value in Meters per second: ";
                cin >> input;
                output = input * 3600 / 1000;
                cout << "\nValue in Kilometers per hour: " << output;
                break;
            case 3:
                cout << "\nEnter value in Miles per hour: ";
                cin >> input;
                output = input * 1.60934;
                cout << "\nValue in Kilometers per hour: " << output;
                break;
            case 4:
                cout << "\nEnter value in Kilometers per hour: ";
                cin >> input;
                output = input / 1.60934;
                cout << "\nValue in Miles per hour: " << output;
                break;
            case 5:
                cout << "\nEnter value in Feet per second: ";
                cin >> input;
                output = input * 0.3048;
                cout << "\nValue in Meters per second: " << output;
                break;
            case 6:
                cout << "\nEnter value in Meters per second: ";
                cin >> input;
                output = input / 0.3048;
                cout << "\nValue in Feet per second: " << output;
                break;
            case 7:
                cout << "\nEnter value in Knots: ";
                cin >> input;
                output = input * 1.852;
                cout << "\nValue in Kilometers per hour: " << output;
                break;
            case 8:
                cout << "\nEnter value in Kilometers per hour: ";
                cin >> input;
                output = input / 1.852;
                cout << "\nValue in Knots: " << output;
                break;
            case 9:
                cout << "\nEnter value in Mach: ";
                cin >> input;
                output = input * 1225.04;
                cout << "\nValue in Kilometers per hour: " << output;
                break;
            case 10:
                cout << "\nEnter value in Kilometers per hour: ";
                cin >> input;
                output = input / 1225.04;
                cout << "\nValue in Mach: " << output;
                break;
            case 11:
                cout << "\nEnter value in Speed of light: ";
                cin >> input;
                output = input * 1079252848.8;
                cout << "\nValue in Kilometers per hour: " << output;
                break;
            case 12:
                cout << "\nEnter value in Kilometers per hour: ";
                cin >> input;
                output = input / 1079252848.8;
                cout << "\nValue in Speed of light: " << output;
                break;
            case 13:
                cout << "\nEnter value in Speed of sound: ";
                cin >> input;
                output = input * 1235.5;
                cout << "\nValue in Kilometers per hour: " << output;
                break;
            case 14:
                cout << "\nEnter value in Kilometers per hour: ";
                cin >> input;
                output = input / 1235.5;
                cout << "\nValue in Speed of sound: " << output;
                break;
            case 15:
                cout << "\nEnter value in Speed of sound: ";
                cin >> input;
                output = input * 0.3048;
                cout << "\nValue in Meters per second: " << output;
                break;
            case 16:
                cout << "\nEnter value in Meters per second: ";
                cin >> input;
                output = input / 0.3048;
                cout << "\nValue in Speed of sound: " << output;
                break;
            case 17:
                cout << "\nEnter value in Speed of sound: ";
                cin >> input;
                output = input / 343.2;
                cout << "\nValue in Mach: " << output;
                break;
            case 18:
                cout << "\nEnter value in Mach: ";
                cin >> input;
                output = input * 343.2;
                cout << "\nValue in Speed of sound: " << output;
                break;
            case 19:
                cout << "\nEnter value in Speed of sound: ";
                cin >> input;
                output = input * 0.539957;
                cout << "\nValue in Knots: " << output;
                break;
            case 20:
                cout << "\nEnter value in Knots: ";
                cin >> input;
                output = input / 0.539957;
                cout << "\nValue in Speed of sound: " << output;
                break;
            case 21:
                cout << "\nEnter value in Centimeters per second: ";
                cin >> input;
                output = input / 100000;
                cout << "\nValue in Kilometers per hour: " << output;
                break;
            case 22:        
                cout << "\nEnter value in Kilometers per hour: ";
                cin >> input;
                output = input * 100000;
                cout << "\nValue in Centimeters per second: " << output;
                break;
            default:
                cout << "\nInvalid choice.";
        }
    }
};

class volume
{
    public:
    void volume_intro()
    {
        int choice;
        cout << "\n\nYou have selected the Volume conversion calculator.";
        cout<<"\n\nWhat do you want to convert? \n";
        cout<<"\n1. Cubic Meter to Liter";
        cout<<"\n2. Liter to Cubic Meter";
        cout<<"\n3. Cubic Centimeter to Liter";
        cout<<"\n4. Liter to Cubic Centimeter";
        cout<<"\n5. Gallon to Liter";
        cout<<"\n6. Liter to Gallon";
        cout<<"\n7. Pint to Liter";
        cout<<"\n8. Liter to Pint";
        cout<<"\n9. Quart to Liter";
        cout<<"\n10. Liter to Quart";
        cout<<"\n11. Milliliter to Liter";
        cout<<"\n12. Liter to Milliliter";
        cout<<"\n13. Cubic Inch to Liter";
        cout<<"\n14. Liter to Cubic Inch";
        cout<<"\n15. Cubic Foot to Liter";
        cout<<"\n16. Liter to Cubic Foot";
        cout<<"\n17. Acre-Foot to Cubic Meter";
        cout<<"\n18. Cubic Meter to Acre-Foot"; 
        cout<<"\n19. Cubic Yard to Liter";
        cout<<"\n20. Liter to Cubic Yard";
        cout<<"\n\nEnter your choice: ";
        cin>>choice;

        float input, output;
        switch(choice)
        {
        case 1:
            cout<<"\nEnter the value in Cubic Meter: ";
            cin>>input;
            output=input*1000;
            cout<<"\nThe value in Liter: "<<output;
            break;
        case 2:
            cout<<"\nEnter the value in Liter: ";
            cin>>input;
            output=input/1000;
            cout<<"\nThe value in Cubic Meter: "<<output;
            break;
        case 3:
            cout<<"\nEnter the value in Cubic Centimeter: ";
            cin>>input;
            output=input/1000;
            cout<<"\nThe value in Liter: "<<output;
            break;
        case 4:
            cout<<"\nEnter the value in Liter: ";
            cin>>input;
            output=input*1000;
            cout<<"\nThe value in Cubic Centimeter: "<<output;
            break;
        case 5:
            cout<<"\nEnter the value in Gallon: ";
            cin>>input;
            output=input*3.78541;
            cout<<"\nThe value in Liter: "<<output;
            break;
        case 6:
            cout<<"\nEnter the value in Liter: ";
            cin>>input;
            output=input/3.78541;
            cout<<"\nThe value in Gallon: "<<output;
            break;
        case 7:
            cout<<"\nEnter the value in Pint: ";
            cin>>input;
            output=input*0.473176;
            cout<<"\nThe value in Liter: "<<output;
            break;
        case 8:
            cout<<"\nEnter the value in Liter: ";
            cin>>input;
            output=input/0.473176;
            cout<<"\nThe value in Pint: "<<output;
            break;
        case 9:
            cout<<"\nEnter the value in Quart: ";
            cin>>input;
            output=input*0.946353;
            cout<<"\nThe value in Liter: "<<output;
            break;
        case 10:
            cout<<"\nEnter the value in Liter: ";
            cin>>input;
            output=input/0.946353;
            cout<<"\nThe value in Quart: "<<output;
            break;
        case 11:
            cout<<"\nEnter the value in Milliliter: ";
            cin>>input;
            output=input/1000;
            cout<<"\nThe value in Liter: "<<output;
            break;
        case 12:
            cout<<"\nEnter the value in Liter: ";
            cin>>input;
            output=input*1000;
            cout<<"\nThe value in Milliliter: "<<output;
            break;
        case 13:
            cout<<"\nEnter the value in Cubic Inch: ";
            cin>>input;
            output=input*0.0163871;
            cout<<"\nThe value in Liter: "<<output;
            break;
        case 14:
            cout<<"\nEnter the value in Liter: ";
            cin>>input;
            output=input/0.0163871;
            cout<<"\nThe value in Cubic Inch: "<<output;
            break;
        case 15:
            cout<<"\nEnter the value in Cubic Foot: ";
            cin>>input;
            output=input*28.3168;
            cout<<"\nThe value in Liter: "<<output;
            break;
        case 16:
            cout<<"\nEnter the value in Liter: ";
            cin>>input;
            output=input/28.3168;
            cout<<"\nThe value in Cubic Foot: "<<output;
            break;
        case 17:
            cout<<"\nEnter the value in Acre-Foot: ";
            cin>>input;
            output=input*1233.5;
            cout<<"\nThe value in Cubic Meter: "<<output;
            break;
        case 18:
            cout<<"\nEnter the value in Cubic Meter: ";
            cin>>input;
            output=input/1233.5;
            cout<<"\nThe value in Acre-Foot: "<<output;
            break;
        case 19:
            cout<<"\nEnter the value in Cubic Yard: ";
            cin>>input;
            output=input*0.764555;
            cout<<"\nThe value in Liter: "<<output;
            break;
        case 20:
            cout<<"\nEnter the value in Liter: ";
            cin>>input;
            output=input/0.764555;
            cout<<"\nThe value in Cubic Yard: "<<output;
            break;
        default:
            cout << "\nInvalid choice.";
        }
    }
};

class area
{
    public:
    void area_intro()
    {
        int choice;
        cout << "\n\nYou have selected the Area conversion calculator.";
        cout<<"\n\nWhat do you want to convert? \n";
        cout<<"\n1. Square Meter to Square Kilometer";
        cout<<"\n2. Square Kilometer to Square Meter";
        cout<<"\n3. Hectare to Square Meter";
        cout<<"\n4. Square Meter to Hectare";
        cout<<"\n5. Acre to Square Meter";
        cout<<"\n6. Square Meter to Acre";
        cout<<"\n7. Square Foot to Square Meter";
        cout<<"\n8. Square Meter to Square Foot";
        cout<<"\n9. Square Inch to Square Meter";
        cout<<"\n10. Square Meter to Square Inch";
        cout<<"\n11. Are to Hectare";
        cout<<"\n12. Hectare to Are";
        cout<<"\n13. Barn to Square Meter";
        cout<<"\n14. Square Meter to Barn"; 
        cout<<"\n15. Section to Acre"; 
        cout<<"\n16. Acre to Section"; 
        cout<<"\n17. Rood to Acre"; 
        cout<<"\n18. Acre to Rood"; 
        cout<<"\n19. Township to Acre"; 
        cout<<"\n20. Acre to Township"; 
        cout<<"\n\nEnter your choice (1-20): ";
        cin>>choice;

        float input, output;
        switch(choice)
        {
        case 1:
            cout<<"\nEnter the value in Square Meter: ";
            cin>>input;
            output=input/1000000;
            cout<<"\nThe value in Square Kilometer: "<<output;
            break;
        case 2:
            cout<<"\nEnter the value in Square Kilometer: ";
            cin>>input;
            output=input*1000000;
            cout<<"\nThe value in Square Meter: "<<output;
            break;
        case 3: 
            cout<<"\nEnter the value in Hectare: ";
            cin>>input;
            output=input*10000;
            cout<<"\nThe value in Square Meter: "<<output;
            break;
        case 4: 
            cout<<"\nEnter the value in Square Meter: ";
            cin>>input;
            output=input/10000;
            cout<<"\nThe value in Hectare: "<<output;
            break;
        case 5:
            cout<<"\nEnter the value in Acre: ";
            cin>>input;
            output=input*4046.86;
            cout<<"\nThe value in Square Meter: "<<output;
            break;
        case 6:
            cout<<"\nEnter the value in Square Meter: ";
            cin>>input;
            output=input/4046.86;
            cout<<"\nThe value in Acre: "<<output;
            break;
        case 7:
            cout<<"\nEnter the value in Square Foot: ";
            cin>>input;
            output=input*0.092903;
            cout<<"\nThe value in Square Meter: "<<output;
            break;
        case 8:
            cout<<"\nEnter the value in Square Meter: ";
            cin>>input;
            output=input/0.092903;
            cout<<"\nThe value in Square Foot: "<<output;
            break;
        case 9:
            cout<<"\nEnter the value in Square Inch: ";
            cin>>input;
            output=input*0.00064516;
            cout<<"\nThe value in Square Meter: "<<output;
            break;
        case 10:
            cout<<"\nEnter the value in Square Meter: ";
            cin>>input;
            output=input/0.00064516;
            cout<<"\nThe value in Square Inch: "<<output;
            break;
        case 11:
            cout<<"\nEnter the value in Are: ";
            cin>>input;
            output=input*100;
            cout<<"\nThe value in Hectare: "<<output;
            break;
        case 12:
            cout<<"\nEnter the value in Hectare: ";
            cin>>input;
            output=input/100;
            cout<<"\nThe value in Are: "<<output;
            break;
        case 13:
            cout<<"\nEnter the value in Barn: ";
            cin>>input;
            output=input*1e-28;
            cout<<"\nThe value in Square Meter: "<<output;
            break;
        case 14:
            cout<<"\nEnter the value in Square Meter: ";
            cin>>input;
            output=input/1e-28;
            cout<<"\nThe value in Barn: "<<output;
            break;
        case 15:
            cout<<"\nEnter the value in Section: ";
            cin>>input;
            output=input*640;
            cout<<"\nThe value in Acre: "<<output;
            break;
        case 16:
            cout<<"\nEnter the value in Acre: ";
            cin>>input;
            output=input/640;
            cout<<"\nThe value in Section: "<<output;
            break;
        case 17:
            cout<<"\nEnter the value in Rood: ";
            cin>>input;
            output=input*0.25;
            cout<<"\nThe value in Acre: "<<output;
            break;
        case 18:
            cout<<"\nEnter the value in Acre: ";
            cin>>input;
            output=input/0.25;
            cout<<"\nThe value in Rood: "<<output;
            break;
        case 19:
            cout<<"\nEnter the value in Township: ";
            cin>>input;
            output=input*368640;
            cout<<"\nThe value in Acre: "<<output;
            break;
        case 20:
            cout<<"\nEnter the value in Acre: ";
            cin>>input;
            output=input/368640;
            cout<<"\nThe value in Township: "<<output;
            break;
        default:
            cout << "\nInvalid choice.";
        }
    }
};

class pressure 
{
    public:
    void pressure_intro()
    {
        int choice;
        cout << "\n\nYou have selected the Pressure conversion calculator.";
        cout<<"\n\nWhat do you want to convert? \n";
        cout<<"\n1. Pascal to Bar";
        cout<<"\n2. Bar to Pascal";
        cout<<"\n3. PSI to Pascal";
        cout<<"\n4. Pascal to PSI";
        cout<<"\n5. Torr to Pascal";
        cout<<"\n6. Pascal to Torr";
        cout<<"\n7. Atmosphere to Pascal";
        cout<<"\n8. Pascal to Atmosphere";
        cout<<"\n9. mmHg to Pascal";
        cout<<"\n10. Pascal to mmHg";
        cout<<"\n11. kgf/cm^2 to Pascal";
        cout<<"\n12. Pascal to kgf/cm^2"; 
        cout<<"\n13. Newton per square meter to Pascal";
        cout<<"\n14. Pascal to Newton per square meter";
        cout<<"\n15. Pound per square inch to Pascal";
        cout<<"\n16. Pascal to Pound per square inch";
        cout<<"\n17. Bar to PSI";
        cout<<"\n18. PSI to Bar";
        cout<<"\n19. Bar to Torr";
        cout<<"\n20. Torr to Bar";
        cout<<"\n21. Bar to mmHg";
        cout<<"\n22. mmHg to Bar";
        cout<<"\n23. Bar to kgf/cm^2";
        cout<<"\n24. kgf/cm^2 to Bar";
        cout<<"\n25. kgf/cm^2 to PSI";
        cout<<"\n26. PSI to kgf/cm^2";
        cout<<"\n27. kgf/cm^2 to Torr";
        cout<<"\n28. Torr to kgf/cm^2";
        cout<<"\n29. kgf/cm^2 to mmHg";
        cout<<"\n30. mmHg to kgf/cm^2";
        cout<<"\n\nEnter your choice (1-12): ";
        cin>>choice;

        float input, output;
        switch(choice)
        {
            case 1:
                cout << "\nEnter value in Pascals: ";
                cin >> input;
                output = input / 100000;
                cout << "\nValue in Bar: " << output;
                break;
            case 2:
                cout << "\nEnter value in Bar: ";
                cin >> input;
                output = input * 100000;
                cout << "\nValue in Pascals: " << output;
                break;
            case 3:
                cout << "\nEnter value in PSI: ";
                cin >> input;
                output = input * 6894.76;
                cout << "\nValue in Pascals: " << output;
                break;
            case 4:
                cout << "\nEnter value in Pascals: ";
                cin >> input;
                output = input / 6894.76;
                cout << "\nValue in PSI: " << output;
                break;
            case 5:
                cout << "\nEnter value in Torr: ";
                cin >> input;
                output = input * 133.322;
                cout << "\nValue in Pascals: " << output;
                break;
            case 6:
                cout << "\nEnter value in Pascals: ";
                cin >> input;
                output = input / 133.322;
                cout << "\nValue in Torr: " << output;
                break; 
            case 7:
                cout << "\nEnter value in Atmosphere: ";
                cin >> input;
                output = input * 101325;
                cout << "\nValue in Pascals: " << output;
                break;
            case 8:
                cout << "\nEnter value in Pascals: ";
                cin >> input;
                output = input / 101325;
                cout << "\nValue in Atmosphere: " << output;
                break;
            case 9:
                cout << "\nEnter value in mmHg: ";
                cin >> input;
                output = input * 133.322;
                cout << "\nValue in Pascals: " << output;
                break;
            case 10:
                cout << "\nEnter value in Pascals: ";
                cin >> input;
                output = input / 133.322;
                cout << "\nValue in mmHg: " << output;
                break;
            case 11:    
                cout << "\nEnter value in kgf/cm^2: ";
                cin >> input;
                output = input * 98066.5;
                cout << "\nValue in Pascals: " << output;
                break;
            case 12:
                cout << "\nEnter value in Pascals: ";
                cin >> input;
                output = input / 98066.5;
                cout << "\nValue in kgf/cm^2: " << output;
                break;
            case 13:
                cout << "\nEnter value in Newton per square meter: ";
                cin >> input;
                output = input; // 1 N/m^2 = 1 Pascal
                cout << "\nValue in Pascals: " << output;
                break;
            case 14:
                cout << "\nEnter value in Pascals: ";
                cin >> input;
                output = input; // 1 Pascal = 1 N/m^2
                cout << "\nValue in Newton per square meter: " << output;
                break;
            case 15:
                cout << "\nEnter value in Pound per square inch: ";
                cin >> input;
                output = input * 6894.76;
                cout << "\nValue in Pascals: " << output;
                break;
            case 16:
                cout << "\nEnter value in Pascals: ";
                cin >> input;
                output = input / 6894.76;
                cout << "\nValue in Pound per square inch: " << output;
                break;
            case 17:
                cout << "\nEnter value in Bar: ";
                cin >> input;
                output = input * 14.5038;
                cout << "\nValue in PSI: " << output;
                break;
            case 18:
                cout << "\nEnter value in PSI: ";
                cin >> input;
                output = input / 14.5038;
                cout << "\nValue in Bar: " << output;
                break;
            case 19:
                cout << "\nEnter value in Bar: ";
                cin >> input;
                output = input * 750.062;
                cout << "\nValue in Torr: " << output;
                break;
            case 20:
                cout << "\nEnter value in Torr: ";
                cin >> input;
                output = input / 750.062;
                cout << "\nValue in Bar: " << output;
                break;
            case 21:
                cout << "\nEnter value in Bar: ";
                cin >> input;
                output = input * 1000;
                cout << "\nValue in mmHg: " << output;
                break;
            case 22:
                cout << "\nEnter value in mmHg: ";
                cin >> input;
                output = input / 1000;
                cout << "\nValue in Bar: " << output;
                break;
            case 23:
                cout << "\nEnter value in Bar: ";
                cin >> input;
                output = input * 0.1;
                cout << "\nValue in kgf/cm^2: " << output;
                break;
            case 24:
                cout << "\nEnter value in kgf/cm^2: ";
                cin >> input;
                output = input / 0.1;
                cout << "\nValue in Bar: " << output;
                break;
            case 25:
                cout << "\nEnter value in kgf/cm^2: ";
                cin >> input;
                output = input * 14.2233;
                cout << "\nValue in PSI: " << output;
                break;
            case 26:
                cout << "\nEnter value in PSI: ";
                cin >> input;
                output = input / 14.2233;
                cout << "\nValue in kgf/cm^2: " << output;
                break;
            case 27:
                cout << "\nEnter value in kgf/cm^2: ";
                cin >> input;
                output = input * 98066.5;
                cout << "\nValue in Torr: " << output;
                break;
            case 28:
                cout << "\nEnter value in Torr: ";
                cin >> input;
                output = input / 98066.5;
                cout << "\nValue in kgf/cm^2: " << output;
                break;
            case 29:
                cout << "\nEnter value in kgf/cm^2: ";
                cin >> input;
                output = input * 750.062;
                cout << "\nValue in mmHg: " << output;
                break;
            case 30:
                cout << "\nEnter value in mmHg: ";
                cin >> input;
                output = input / 750.062;
                cout << "\nValue in kgf/cm^2: " << output;
                break;
            default:
                cout << "\nInvalid choice.";
        }
    }
};

class energy
{ 
    public:
    void energy_intro()
    {
        int choice;
        cout << "\n\nYou have selected the Energy conversion calculator.";
        cout<<"\n\nWhat do you want to convert? \n";
        cout<<"\n1. Joule to Calorie";
        cout<<"\n2. Calorie to Joule";
        cout<<"\n3. Kilojoule to Calorie";
        cout<<"\n4. Calorie to Kilojoule";
        cout<<"\n5. Megajoule to Kilojoule";
        cout<<"\n6. Kilojoule to Megajoule";
        cout<<"\n7. Gigajoule to Megajoule";
        cout<<"\n8. Megajoule to Gigajoule";
        cout<<"\n9. Watt-hour to Joule";
        cout<<"\n10. Joule to Watt-hour";
        cout<<"\n11. Kilowatt-hour to Joule";
        cout<<"\n12. Joule to Kilowatt-hour"; 
        cout<<"\n13. British Thermal Unit (BTU) to Joule"; 
        cout<<"\n14. Joule to British Thermal Unit (BTU)"; 
        cout<<"\n15. Electronvolt to Joule"; 
        cout<<"\n16. Joule to Electronvolt"; 
        cout<<"\n17. Erg to Joule"; 
        cout<<"\n18. Joule to Erg"; 
        cout<<"\n19. Horsepower-hour to Joule"; 
        cout<<"\n20. Joule to Horsepower-hour"; 
        cout<<"\n21. Foot-pound to Joule";
        cout<<"\n22. Joule to Foot-pound";
        cout<<"\n23. Kilocalorie to Joule";
        cout<<"\n\nEnter your choice (1-24): ";
        cin>>choice;
    
        float input, output;
        switch(choice)
        {
            case 1:
                cout << "\nEnter value in Joules: ";
                cin >> input;
                output = input / 4.184;
                cout << "\nValue in Calories: " << output;
                break;
            case 2:
                cout << "\nEnter value in Calories: ";
                cin >> input;
                output = input * 4.184;
                cout << "\nValue in Joules: " << output;
                break;
            case 3:
                cout << "\nEnter value in Kilojoules: ";
                cin >> input;
                output = input * 239.006;
                cout << "\nValue in Calories: " << output;
                break;
            case 4:
                cout << "\nEnter value in Calories: ";
                cin >> input;
                output = input / 239.006;
                cout << "\nValue in Kilojoules: " << output;
                break; 
            case 5:
                cout << "\nEnter value in Megajoules: ";
                cin >> input;
                output = input * 1000;
                cout << "\nValue in Kilojoules: " << output;
                break; 
            case 6:
                cout << "\nEnter value in Kilojoules: ";
                cin >> input;
                output = input / 1000;
                cout << "\nValue in Megajoules: " << output;
                break; 
            case 7:
                cout << "\nEnter value in Gigajoules: ";
                cin >> input;
                output = input * 1000;
                cout << "\nValue in Megajoules: " << output;
                break; 
            case 8:
                cout << "\nEnter value in Megajoules: ";
                cin >> input;
                output = input / 1000;
                cout << "\nValue in Gigajoules: " << output;
                break; 
            case 9: 
                cout << "\nEnter value in Watt-hours: ";
                cin >> input;
                output = input * 3600;
                cout << "\nValue in Joules: " << output;
                break;
            case 10:    
                cout << "\nEnter value in Joules: ";
                cin >> input;
                output = input / 3600;
                cout << "\nValue in Watt-hours: " << output;
                break;
            case 11:
                cout << "\nEnter value in Kilowatt-hours: ";
                cin >> input;
                output = input * 3.6e6;
                cout << "\nValue in Joules: " << output;
                break;
            case 12:
                cout << "\nEnter value in Joules: ";
                cin >> input;
                output = input / 3.6e6;
                cout << "\nValue in Kilowatt-hours: " << output;
                break;
            case 13:
                cout << "\nEnter value in British Thermal Units (BTU): ";
                cin >> input;
                output = input * 1055.06;
                cout << "\nValue in Joules: " << output;
                break;
            case 14:
                cout << "\nEnter value in Joules: ";
                cin >> input;
                output = input / 1055.06;
                cout << "\nValue in British Thermal Units (BTU): " << output;
                break;
            case 15:
                cout << "\nEnter value in Electronvolts: ";
                cin >> input;
                output = input * 1.60218e-19;
                cout << "\nValue in Joules: " << output;
                break;
            case 16:
                cout << "\nEnter value in Joules: ";
                cin >> input;
                output = input / 1.60218e-19;
                cout << "\nValue in Electronvolts: " << output;
                break;
            case 17:
                cout << "\nEnter value in Ergs: ";
                cin >> input;
                output = input * 1e-7;
                cout << "\nValue in Joules: " << output;
                break;
            case 18:
                cout << "\nEnter value in Joules: ";
                cin >> input;
                output = input / 1e-7;
                cout << "\nValue in Ergs: " << output;
                break;
            case 19:
                cout << "\nEnter value in Horsepower-hours: ";
                cin >> input;
                output = input * 2684519.54;
                cout << "\nValue in Joules: " << output;
                break;
            case 20:
                cout << "\nEnter value in Joules: ";
                cin >> input;
                output = input / 2684519.54;
                cout << "\nValue in Horsepower-hours: " << output;
                break;
            case 21:
                cout << "\nEnter value in Foot-pounds: ";
                cin >> input;
                output = input * 1.35582;
                cout << "\nValue in Joules: " << output;
                break;
            case 22:
                cout << "\nEnter value in Joules: ";
                cin >> input;
                output = input / 1.35582;
                cout << "\nValue in Foot-pounds: " << output;
                break;
            case 23:
                cout << "\nEnter value in Kilocalories: ";
                cin >> input;
                output = input * 4184;
                cout << "\nValue in Joules: " << output;
                break;
            default:    
                cout << "\nInvalid choice.";
        }
    }
};

class power
{
    public:
    void power_intro()
    {
        int choice;
            cout << "\n\nYou have selected the Power conversion calculator.";
            cout<<"\n\nWhat do you want to convert? \n";
            cout<<"\n1. Watt to Horsepower";
            cout<<"\n2. Horsepower to Watt";
            cout<<"\n3. Kilowatt to Horsepower";
            cout<<"\n4. Horsepower to Kilowatt";
            cout<<"\n5. Megawatt to Horsepower";
            cout<<"\n6. Horsepower to Megawatt";
            cout<<"\n7. Gigawatt to Horsepower";
            cout<<"\n8. Horsepower to Gigawatt";
            cout<<"\n9. Watt to Kilowatt";
            cout<<"\n10. Kilowatt to Watt";
            cout<<"\n11. Megawatt to Kilowatt"; 
            cout<<"\n12. Kilowatt to Megawatt";
            cout<<"\n13. Gigawatt to Kilowatt";
            cout<<"\n14. Kilowatt to Gigawatt";
            cout<<"\n15. Watt to Megawatt";
            cout<<"\n16. Megawatt to Watt";
            cout<<"\n17. Watt to Gigawatt";
            cout<<"\n18. Gigawatt to Watt";
            cout<<"\n19. Horsepower to Megawatt";
            cout<<"\n20. Megawatt to Horsepower";
            cout<<"\nEnter your choice (1-20): ";
            cin>>choice;

        float input, output;
        switch(choice)
        {
            case 1:
                cout << "\nEnter value in Watts: ";
                cin >> input;
                output = input / 745.7;
                cout << "\nValue in Horsepower: " << output;
                break;
            case 2:
                cout << "\nEnter value in Horsepower: ";
                cin >> input;
                output = input * 745.7;
                cout << "\nValue in Watts: " << output;
                break;
            case 3:
                cout << "\nEnter value in Kilowatts: ";
                cin >> input;
                output = input * 1.34102;
                cout << "\nValue in Horsepower: " << output;
                break;
            case 4:
                cout << "\nEnter value in Horsepower: ";
                cin >> input;
                output = input / 1.34102;
                cout << "\nValue in Kilowatts: " << output;
                break; 
            case 5:
                cout << "\nEnter value in Megawatts: ";
                cin >> input;
                output = input * 1341.02;
                cout << "\nValue in Horsepower: " << output;
                break; 
            case 6:
                cout << "\nEnter value in Horsepower: ";
                cin >> input;
                output = input / 1341.02;
                cout << "\nValue in Megawatts: " << output;
                break; 
            case 7:
                cout << "\nEnter value in Gigawatts: ";
                cin >> input;
                output = input * 1341020;
                cout << "\nValue in Horsepower: " << output;
                break; 
            case 8:
                cout << "\nEnter value in Horsepower: ";
                cin >> input;
                output = input / 1341020;
                cout << "\nValue in Gigawatts: " << output;
                break; 
            case 9:
                cout << "\nEnter value in Watts: ";
                cin >> input;
                output = input / 1000;
                cout << "\nValue in Kilowatts: " << output;
                break; 
            case 10:
                 cout << "\nEnter value in Kilowatts: ";
                 cin >> input;
                 output = input * 1000;
                 cout << "\nValue in Watts: " << output;
                break;
            case 11:
                cout << "\nEnter value in Megawatts: ";
                cin >> input;
                output = input * 1000;
                cout << "\nValue in Kilowatts: " << output;
                break;
            case 12:
                cout << "\nEnter value in Kilowatts: ";
                cin >> input;
                output = input / 1000;
                cout << "\nValue in Megawatts: " << output;
                break;
            case 13:
                cout << "\nEnter value in Gigawatts: ";
                cin >> input;
                output = input * 1000;
                cout << "\nValue in Kilowatts: " << output;
                break;
            case 14:
                cout << "\nEnter value in Kilowatts: ";
                cin >> input;
                output = input / 1000;
                cout << "\nValue in Gigawatts: " << output;
                break;
            case 15:
                cout << "\nEnter value in Watts: ";
                cin >> input;
                output = input / 1e6;
                cout << "\nValue in Megawatts: " << output;
                break;
            case 16:
                cout << "\nEnter value in Megawatts: ";
                cin >> input;
                output = input * 1e6;
                cout << "\nValue in Watts: " << output;
                break;
            case 17:
                cout << "\nEnter value in Watts: ";
                cin >> input;
                output = input / 1e9;
                cout << "\nValue in Gigawatts: " << output;
                break;
            case 18:
                cout << "\nEnter value in Gigawatts: ";
                cin >> input;
                output = input * 1e9;
                cout << "\nValue in Watts: " << output;
                break;
            case 19:
                cout << "\nEnter value in Horsepower: ";
                cin >> input;
                output = input / 1341.02;
                cout << "\nValue in Megawatts: " << output;
                break;
            case 20:
                cout << "\nEnter value in Megawatts: ";
                cin >> input;
                output = input * 1341.02;
                cout << "\nValue in Horsepower: " << output;
                break;
            default:
                cout << "\nInvalid choice.";
        }
    
    }    
};

class current
{
    public:
    void current_intro()
    {
        int choice;
        cout << "\n\nYou have selected the Current conversion calculator.";
        cout<<"\n\nWhat do you want to convert? \n";
        cout<<"\n1. Ampere to Milliampere";
        cout<<"\n2. Milliampere to Ampere";
        cout<<"\n3. Ampere to Microampere";
        cout<<"\n4. Microampere to Ampere";
        cout<<"\n5. Ampere to Kiloampere";
        cout<<"\n6. Kiloampere to Ampere";
        cout<<"\n7. Ampere to Megaampere";
        cout<<"\n8. Megaampere to Ampere";
        cout<<"\n9. Ampere to Gigaampere";
        cout<<"\n10. Gigaampere to Ampere"; 
        cout<<"\n11. Ampere to Nanoampere"; 
        cout<<"\n12. Nanoampere to Ampere"; 
        cout<<"\n13. Ampere to Picoampere";
        cout<<"\n14. Picoampere to Ampere";
        cout<<"\n15. Ampere to Femtoampere";
        cout<<"\n16. Femtoampere to Ampere";
        cout<<"\n17. Ampere to Attoampere";
        cout<<"\n18. Attoampere to Ampere";
        cout<<"\n19. Ampere to Zeptoampere";
        cout<<"\n20. Zeptoampere to Ampere";
        cout<<"\nEnter your choice (1-20): ";
        cin>>choice;

        float input, output;
        switch(choice)
        {
            case 1:
                cout << "\nEnter value in Amperes: ";
                cin >> input;
                output = input * 1000;
                cout << "\nValue in Milliamperes: " << output;
                break;
            case 2:
                cout << "\nEnter value in Milliamperes: ";
                cin >> input;
                output = input / 1000;
                cout << "\nValue in Amperes: " << output;
                break;
            case 3:
                cout << "\nEnter value in Amperes: ";
                cin >> input;
                output = input * 1e6;
                cout << "\nValue in Microamperes: " << output;
                break;
            case 4:
                cout << "\nEnter value in Microamperes: ";
                cin >> input;
                output = input / 1e6;
                cout << "\nValue in Amperes: " << output;
                break; 
            case 5:
                cout << "\nEnter value in Amperes: ";
                cin >> input;
                output = input * 1000;
                cout << "\nValue in Kiloamperes: " << output;
                break; 
            case 6:
                cout << "\nEnter value in Kiloamperes: ";
                cin >> input;
                output = input / 1000;
                cout << "\nValue in Amperes: " << output;
                break;
            case 7: 
                cout << "\nEnter value in Amperes: ";
                cin >> input;
                output = input * 1e6;
                cout << "\nValue in Megaamperes: " << output;
                break;
            case 8:
                cout << "\nEnter value in Megaamperes: ";
                cin >> input;
                output = input / 1e6;
                cout << "\nValue in Amperes: " << output;
                break;
            case 9:
                cout << "\nEnter value in Amperes: ";
                cin >> input;
                output = input * 1e9;
                cout << "\nValue in Gigaamperes: " << output;
                break;
            case 10:
                cout << "\nEnter value in Gigaamperes: ";
                cin >> input;
                output = input / 1e9;
                cout << "\nValue in Amperes: " << output;
                break;
            case 11:    
                cout << "\nEnter value in Amperes: ";
                cin >> input;
                output = input * 1e9;
                cout << "\nValue in Nanoamperes: " << output;
                break;
            case 12:
                cout << "\nEnter value in Nanoamperes: ";
                cin >> input;
                output = input / 1e9;
                cout << "\nValue in Amperes: " << output;
                break;
            case 13:    
                cout << "\nEnter value in Amperes: ";
                cin >> input;
                output = input * 1e12;
                cout << "\nValue in Picoamperes: " << output;
                break;
            case 14:
                cout << "\nEnter value in Picoamperes: ";
                cin >> input;
                output = input / 1e12;
                cout << "\nValue in Amperes: " << output;
                break;
            case 15:
                cout << "\nEnter value in Amperes: ";
                cin >> input;
                output = input * 1e15;
                cout << "\nValue in Femtoamperes: " << output;
                break;
            case 16:
                cout << "\nEnter value in Femtoamperes: ";
                cin >> input;
                output = input / 1e15;
                cout << "\nValue in Amperes: " << output;
                break;
            case 17:
                cout << "\nEnter value in Amperes: ";
                cin >> input;
                output = input * 1e18;
                cout << "\nValue in Attoamperes: " << output;
                break;
            case 18:
                cout << "\nEnter value in Attoamperes: ";
                cin >> input;
                output = input / 1e18;
                cout << "\nValue in Amperes: " << output;
                break;
            case 19:
                cout << "\nEnter value in Amperes: ";
                cin >> input;
                output = input * 1e21;
                cout << "\nValue in Zeptoamperes: " << output;
                break;
            case 20:
                cout << "\nEnter value in Zeptoamperes: ";
                cin >> input;
                output = input / 1e21;
                cout << "\nValue in Amperes: " << output;
                break;
            default:
                cout << "\nInvalid choice.";
        }
    }
};

class data
{
    public:
    void data_intro()
    {
        int choice;
        cout << "\n\nYou have selected the Data Storage conversion calculator.";
        cout<<"\n\nWhat do you want to convert? \n";
        cout<<"\n1. Bit to Byte";
        cout<<"\n2. Byte to Bit";
        cout<<"\n3. Bit to Nibble";
        cout<<"\n4. Nibble to Bit";
        cout<<"\n5. Nibble to Byte";
        cout<<"\n6. Byte to Nibble";
        cout<<"\n7. Byte to Kilobyte";
        cout<<"\n8. Kilobyte to Byte";  
        cout<<"\n9. Kilobyte to Megabyte";
        cout<<"\n10. Megabyte to Kilobyte";
        cout<<"\n11. Megabyte to Gigabyte";
        cout<<"\n12. Gigabyte to Megabyte";
        cout<<"\n13. Gigabyte to Terabyte";
        cout<<"\n14. Terabyte to Gigabyte";
        cout<<"\n15. Terabyte to Petabyte";
        cout<<"\n16. Petabyte to Terabyte";
        cout<<"\n17. Petabyte to Exabyte";
        cout<<"\n18. Exabyte to Petabyte";
        cout<<"\n19. Exabyte to Zettabyte";
        cout<<"\n20. Zettabyte to Exabyte";
        cout<<"\n21. Zettabyte to Yottabyte";
        cout<<"\n22. Yottabyte to Zettabyte";
        cout<<"\n23. Yottabyte to Brontobyte";
        cout<<"\n24. Brontobyte to Yottabyte";
        cout<<"\n25. Brontobyte to Geopbyte";
        cout<<"\n26. Geopbyte to Brontobyte";
        cout<<"\n27. Geopbyte to Saganbyte";
        cout<<"\n28. Saganbyte to Geopbyte";
        cout<<"\n29. Saganbyte to Quettabyte";
        cout<<"\n30. Quettabyte to Saganbyte";
        cout<<"\n31. Quettabyte to Ronnabyte";
        cout<<"\n32. Ronnabyte to Quettabyte";
        cout<<"\n33. Ronnabyte to Quettabyte";
        cout<<"\n34. Quettabyte to Ronnabyte";
        cout<<"\n\nEnter your choice (1-30): ";
        cin>>choice;

        float input, output;
        switch(choice)
        {
            case 1:
                cout << "\nEnter value in Bits: ";
                cin >> input;
                output = input / 8;
                cout << "\nValue in Bytes: " << output;
                break;
            case 2:
                cout << "\nEnter value in Bytes: ";
                cin >> input;
                output = input * 8;
                cout << "\nValue in Bits: " << output;
                break;
            case 3:  
                cout << "\nEnter value in Bits: ";
                cin >> input;
                output = input / 4;
                cout << "\nValue in Nibbles: " << output;
                break;
            case 4:
                cout << "\nEnter value in Nibbles: ";
                cin >> input;
                output = input * 4;
                cout << "\nValue in Bits: " << output;
                break;
            case 5:
                cout << "\nEnter value in Nibbles: ";
                cin >> input;
                output = input / 2;
                cout << "\nValue in Bytes: " << output;
                break;
            case 6:
                cout << "\nEnter value in Bytes: ";
                cin >> input;
                output = input * 2;
                cout << "\nValue in Nibbles: " << output;
                break;
            case 7:
                cout << "\nEnter value in Bytes: ";
                cin >> input;
                output = input / 1024;
                cout << "\nValue in Kilobytes: " << output;
                break;
            case 8:
                cout << "\nEnter value in Kilobytes: ";
                cin >> input;
                output = input * 1024;
                cout << "\nValue in Bytes: " << output;
                break; 
            case 9:
                cout << "\nEnter value in Kilobytes: ";
                cin >> input;
                output = input / 1024;
                cout << "\nValue in Megabytes: " << output;
                break; 
            case 10:
                cout << "\nEnter value in Megabytes: ";
                cin >> input;
                output = input * 1024;
                cout << "\nValue in Kilobytes: " << output;
                break; 
            case 11:
                 cout << "\nEnter value in Megabytes: ";
                 cin >> input;
                 output = input / 1024;
                 cout << "\nValue in Gigabytes: " << output;
                 break; 
            case 12:
                 cout << "\nEnter value in Gigabytes: ";
                 cin >> input;
                 output = input * 1024;
                 cout << "\nValue in Megabytes: " << output;
                 break; 
            case 13:
                 cout << "\nEnter value in Gigabytes: ";
                 cin >> input;
                 output = input / 1024;
                 cout << "\nValue in Terabytes: " << output;
                 break; 
            case 14:
                 cout << "\nEnter value in Terabytes: ";
                 cin >> input;
                 output = input * 1024;
                 cout << "\nValue in Gigabytes: " << output;
                 break; 
            case 15:
                cout   << "\nEnter value in Terabytes: ";
                cin >> input;
                output = input / 1024;  
                cout << "\nValue in Petabytes: " << output; 
                break;
            case 16:    
                cout << "\nEnter value in Petabytes: ";
                cin >> input;
                output = input * 1024;
                cout << "\nValue in Terabytes: " << output;
                break;
            case 17:
                cout << "\nEnter value in Petabytes: ";
                cin >> input;
                output = input / 1024;
                cout << "\nValue in Exabytes: " << output;
                break;
            case 18:
                cout << "\nEnter value in Exabytes: ";
                cin >> input;
                output = input * 1024;
                cout << "\nValue in Petabytes: " << output;
                break;
            case 19:
                cout << "\nEnter value in Exabytes: ";
                cin >> input;
                output = input / 1024;
                cout << "\nValue in Zettabytes: " << output;
                break;
            case 20:
                cout << "\nEnter value in Zettabytes: ";
                cin >> input;
                output = input * 1024;
                cout << "\nValue in Exabytes: " << output;
                break;
            case 21:
                cout << "\nEnter value in Zettabytes: ";
                cin >> input;
                output = input / 1024;
                cout << "\nValue in Yottabytes: " << output;
                break;
            case 22:
                cout << "\nEnter value in Yottabytes: ";
                cin >> input;
                output = input * 1024;
                cout << "\nValue in Zettabytes: " << output;
                break;
            case 23:
                cout << "\nEnter value in Yottabytes: ";
                cin >> input;
                output = input / 1024;
                cout << "\nValue in Brontobytes: " << output;
                break;
            case 24:
                cout << "\nEnter value in Brontobytes: ";
                cin >> input;
                output = input * 1024;
                cout << "\nValue in Yottabytes: " << output;
                break;
            case 25:
                cout << "\nEnter value in Brontobytes: ";
                cin >> input;
                output = input / 1024;
                cout << "\nValue in Geopbytes: " << output;
                break;
            case 26:
                cout << "\nEnter value in Geopbytes: ";
                cin >> input;
                output = input * 1024;
                cout << "\nValue in Brontobytes: " << output;
                break;
            case 27:
                cout << "\nEnter value in Geopbytes: ";
                cin >> input;
                output = input / 1024;
                cout << "\nValue in Saganbytes: " << output;
                break;
            case 28:
                cout << "\nEnter value in Saganbytes: ";
                cin >> input;
                output = input * 1024;
                cout << "\nValue in Geopbytes: " << output;
                break;
            case 29:
                cout << "\nEnter value in Saganbytes: ";
                cin >> input;
                output = input / 1024;
                cout << "\nValue in Quettabytes: " << output;
                break;
            case 30:
                cout << "\nEnter value in Quettabytes: ";
                cin >> input;
                output = input * 1024;
                cout << "\nValue in Saganbytes: " << output;
                break;
            case 31:
                cout << "\nEnter value in Quettabytes: ";
                cin >> input;
                output = input / 1024;
                cout << "\nValue in Ronnabytes: " << output;
                break;
            case 32:
                cout << "\nEnter value in Ronnabytes: ";
                cin >> input;
                output = input * 1024;
                cout << "\nValue in Quettabytes: " << output;
                break;
            case 33:
                cout << "\nEnter value in Ronnabytes: ";
                cin >> input;
                output = input / 1024;
                cout << "\nValue in Quettabytes: " << output;
                break;
            case 34:
                cout << "\nEnter value in Quettabytes: ";
                cin >> input;
                output = input * 1024;
                cout << "\nValue in Ronnabytes: " << output;
                break;
            default:
                cout << "\nInvalid choice.";
        }

    }

};

class currency
{
    public:
    void currency_intro()
    {
        int choice;
        cout << "\n\nYou have selected the Currency conversion calculator.";
        cout<<"\n\nWhat do you want to convert? \n";
        cout<<"\n1. USD to INR";
        cout<<"\n2. INR to USD";
        cout<<"\n3. EUR to INR";
        cout<<"\n4. INR to EUR";  
        cout<<"\n5. GBP to INR";
        cout<<"\n6. INR to GBP";
        cout<<"\n7. JPY to INR";
        cout<<"\n8. INR to JPY";
        cout<<"\n9. AUD to INR";
        cout<<"\n10. INR to AUD"; 
        cout<<"\n11. CAD to INR"; 
        cout<<"\n12. INR to CAD"; 
        cout<<"\n13. CHF to INR";
        cout<<"\n14. INR to CHF";
        cout<<"\n15. CNY to INR";
        cout<<"\n16. INR to CNY";
        cout<<"\n17. NZD to INR";
        cout<<"\n18. INR to NZD";
        cout<<"\n19. SGD to INR";
        cout<<"\n20. INR to SGD";
        cout<<"\nEnter your choice (1-20): ";
        cin>>choice;

        float input, output;
        switch(choice)
        {
            case 1:
                cout << "\nEnter value in USD: ";
                cin >> input;
                output = input * 74.85; // Example conversion rate
                cout << "\nValue in INR: " << output;
                break;
            case 2:
                cout << "\nEnter value in INR: ";
                cin >> input;
                output = input / 74.85; // Example conversion rate
                cout << "\nValue in USD: " << output;
                break;
            case 3:
                cout << "\nEnter value in EUR: ";
                cin >> input;
                output = input * 88.50; // Example conversion rate
                cout << "\nValue in INR: " << output;
                break;
            case 4:
                cout << "\nEnter value in INR: ";
                cin >> input;
                output = input / 88.50; // Example conversion rate
                cout << "\nValue in EUR: " << output;
                break; 
            case 5:
                 cout << "\nEnter value in GBP: ";
                 cin >> input;
                 output = input * 103.50; // Example conversion rate
                 cout << "\nValue in INR: " << output;
                 break; 
            case 6:
                 cout << "\nEnter value in INR: ";
                 cin >> input;
                 output = input / 103.50; // Example conversion rate
                 cout << "\nValue in GBP: " << output;
                 break; 
            case 7:
                 cout << "\nEnter value in JPY: ";
                 cin >> input;
                 output = input * 0.67; // Example conversion rate
                 cout << "\nValue in INR: " << output;
                 break; 
            case 8:
                 cout << "\nEnter value in INR: ";
                 cin >> input;
                 output = input / 0.67; // Example conversion rate
                 cout << "\nValue in JPY: " << output;
                 break; 
            case 9:
                 cout << "\nEnter value in AUD: ";
                 cin >> input;
                 output = input * 54.50; // Example conversion rate
                 cout << "\nValue in INR: " << output;
                 break; 
            case 10:
                 cout << "\nEnter value in INR: ";
                 cin  >> input; 
                output = input / 54.50; // Example conversion rate
                cout << "\nValue in AUD: " << output;
                break;
            case 11:
                cout << "\nEnter value in CAD: ";
                cin >> input;
                output = input * 59.50; // Example conversion rate
                cout << "\nValue in INR: " << output;
                break;
            case 12:
                cout << "\nEnter value in INR: ";
                cin >> input;
                output = input / 59.50; // Example conversion rate
                cout << "\nValue in CAD: " << output;
                break;
            case 13:
                cout << "\nEnter value in CHF: ";
                cin >> input;
                output = input * 81.50; // Example conversion rate
                cout << "\nValue in INR: " << output;
                break;
            case 14:
                cout << "\nEnter value in INR: ";
                cin >> input;
                output = input / 81.50; // Example conversion rate
                cout << "\nValue in CHF: " << output;
                break;
            case 15:
                cout << "\nEnter value in CNY: ";
                cin >> input;
                output = input * 11.50; // Example conversion rate
                cout << "\nValue in INR: " << output;
                break;
            case 16:
                cout << "\nEnter value in INR: ";
                cin >> input;
                output = input / 11.50; // Example conversion rate
                cout << "\nValue in CNY: " << output;
                break;
            case 17:
                cout << "\nEnter value in NZD: ";
                cin >> input;
                output = input * 52.50; // Example conversion rate
                cout << "\nValue in INR: " << output;
                break;
            case 18:
                cout << "\nEnter value in INR: ";
                cin >> input;
                output = input / 52.50; // Example conversion rate
                cout << "\nValue in NZD: " << output;
                break;
            case 19:
                cout << "\nEnter value in SGD: ";
                cin >> input;
                output = input * 55.50; // Example conversion rate
                cout << "\nValue in INR: " << output;
                break;
            case 20:
                cout << "\nEnter value in INR: ";
                cin >> input;
                output = input / 55.50; // Example conversion rate
                cout << "\nValue in SGD: " << output;
                break;
            default:
                cout << "\nInvalid choice.";
        }

    }
};

class conversion
{       
public:

    length l; 
    mass m; 
    temperature t;
    Time ti;
    speed spd; 
    volume v; 
    area a;
    pressure ps;
    energy e;
    power pwr;
    current curr;
    data d; 
    currency money;  

    void con_intro() 
    {    
        char back;
     do{
        int choice;
         cout << "\n\nYou have selected the Conversion calculator.";
         cout << "\n\nWhat do you want to convert? ";
         cout << "\n1. Length";
         cout << "\n2. Mass";
         cout << "\n3. Temperature";
         cout << "\n4. Time";
         cout << "\n5. Speed";
         cout << "\n6. Volume";
         cout << "\n7. Area";
         cout << "\n8. Pressure";
         cout << "\n9. Energy";
         cout << "\n10. Power";
         cout << "\n11. Current";
         cout << "\n12. Data Storage";
         cout << "\n13. Currency";
         cout<<"\n Press 0 to go back to the previous menu: \n";
         cout << "\n\nEnter your choice (1-13): ";
         cin >> choice;

        if (choice == 0)
        {  
        }
            if (choice == 1)
            {    
                l.length_intro();
            }
            
            else if (choice == 2)
            {
                
                m.mass_intro();
            }
            
            else if (choice == 3)
            {
                
                t.temp_intro();
            }
            
            else if(choice == 4)
            {
                ti.time_intro();
            }
            
            else if(choice == 5)
            {
                spd.speed_intro();
            }
            
            else if(choice == 6)
            {
                v.volume_intro();
            }
            
            else if(choice == 7)
            {
                a.area_intro();
            }
            
            else if(choice == 8)
            {
                ps.pressure_intro();
            }
            
            else if(choice == 9)
            {
                e.energy_intro();
            }
            
            else if(choice == 10)
            {
                pwr.power_intro(); 
            }
            
            else if(choice == 7)
            {
                curr.current_intro();
            }
            
            else if(choice == 12)
            {
                d.data_intro();
            }
            
            else if(choice == 13)
            {
                money.currency_intro();
            }
            
            else
            {
                cout << "\nConversion type not implemented yet.\n";
            }
           cout << "\n\nPress 0 to return to conversion menu or pres any numbr to exit: ";
           cin >> back;
    } while (back == '0');
 
    
    }
};


int main() 
{   
    char o;
    static bool first_time = true; // Ensure welcome message appears only once.
    if (first_time)
    {
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
        for (int i = 0; i < c.n; i++)
        {
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


char m,n;
do {
    cout<<"\n\nDo you want to continue with more calculations? (Y/N): ";
    cin>>m;
    if(m=='Y' || m=='y')
    {
        cout<<"\n\nPress 0 to go back to the previous menu or Press 1 to go to the Home Menu: \n";
        cin>>n;
        if(n=='0')
        {
            if(o=='+' || o=='-' || o=='*' || o=='/')
            {
                c.input(); // Get fresh input first
                
                if(o=='+')
                { 
                    s.n = c.n;
                    s.sum_result = 0; // Reset result
                    for(int i = 0; i < c.n; i++)
                    {
                        s.a[i] = c.a[i];
                    }
                    s.calculate_sum();
                    s.dispsum();
                }
                else if(o=='-')
                {
                    sb.n = c.n;
                    sb.sub_result = 0; // Reset result
                    for(int i = 0; i < c.n; i++)
                    {
                        sb.a[i] = c.a[i];
                    }
                    sb.calculate_sub();
                    sb.dispsub();
                }
                else if(o=='*')
                {
                    multiplication m;
                    m.n = c.n;
                    m.mul_result = 1; // Reset result
                    for(int i = 0; i < c.n; i++)
                    {
                        m.a[i] = c.a[i];
                    }
                    m.calculate_mul();
                    m.dispmul();
                }
                else if(o=='/')
                {
                    division d;
                    d.n = c.n;
                    d.div_result = 1; // Reset result
                    for(int i = 0; i < c.n; i++)
                    {
                        d.a[i] = c.a[i];
                    }
                    d.calculate_div();
                    d.dispdiv();
                }
            }
            else if(o=='p' || o=='P')
            {
                p.per_intro();
                p.per_input();
                p.calculate_per();
                p.dispper();
            }
            else if(o=='c' || o=='C')
            {
                con.con_intro();
            }
        }
        else if(n=='1')
        {
            main(); // Return to main menu
            return 0;
        }
        else
        {
            cout<<"\n\nInvalid input. Exiting the program.\n\n";
            return 0;
        }
    }
} while(m=='Y' || m=='y');

if(m=='N' || m=='n')
{   
    cout<<"\n\nThank you for using the calculator.\n\n\n";
}

return 0;
}
