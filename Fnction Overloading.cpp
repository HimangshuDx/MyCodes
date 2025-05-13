#include <iostream>
#include <conio.h> // For compatibility with Turbo C++ (if required)
using namespace std;

class Family 
{
private:
    char name[50]; // Use char array instead of string
public:
    // Overloaded function to get the name
    void getName( char relation[]) 
    {
        cout << "Enter " << relation << "'s Name: ";
        cin >> name; // Takes input (spaces are not allowed with cin)
    }

    // Overloaded function to display the name
    void displayName( char relation[]) 
    {
        cout << relation << "'s Name is: " << name << endl;
    }
};

int main() 
{
    Family father, mother, child;

    // Input names using overloaded functions
    father.getName("Father");
    mother.getName("Mother");
    child.getName("Your");

    // Display names using overloaded functions
    father.displayName("Father");
    mother.displayName("Mother");
    child.displayName("Your");

    return 0;
}
