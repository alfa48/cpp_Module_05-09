#include <iostream>

int main()
{

    // static_cast
    {
        double PI = 3.1416;
        int i = static_cast<int>(PI);
        std::cout << i << std::endl;
    }

    // dynamic_cast
    {
        class Base{
            virtual void dizOla();
        };
        class Derivada : public Base{

        };
        Base *b = new Base();
        Derivada *d = dynamic_cast<Derivada*>(b);
    }
        // dynamic_cast
    {
        class Base{
            virtual void dizOla();
        };
        class Derivada : public Base{

        };
        Derivada *d = new Derivada();
        Base *b = (d);
    }
    return 0;
}