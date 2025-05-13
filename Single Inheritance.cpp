#include <iostream>
using namespace std;
class base 
{
public:
    int x;
    void getdata() 
    {
        cout << "Enter the value of x: ";
        cin >> x;
    }
};

class derived : public base 
{
private:
    int y;
public: 
    void readdata() 
    {// Making readdata() and product() accessible from main()
        cout << "Enter the value of y: ";
        cin >> y;
    }
    void product() 
    {
        cout << "The product is: " << x * y << endl;
    }
};

int main() 
{
    derived a;
    a.getdata();
    a.readdata();
    a.product();
    return 0;
}
