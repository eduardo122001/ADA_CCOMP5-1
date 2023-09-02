#include <iostream>

// Class CVector definition
class CArithmetic
{
private:
    // Some attributes go here

public:
    static double Addition(double a, double b);
    static double Substraction(double a, double b);
    static double Multiplication(double a, double b);
    static double Division(double a, double b);
    // More methods go here
};

 double CArithmetic::Division(double a, double b)
{
    if (b == 0.0)
        throw (int)0; // an exceptions is thrown here
    return a / b;
}

double CArithmetic::Addition(double a, double b)
{
    return a + b;
}

double CArithmetic::Substraction(double a, double b)
{   
    return a - b;
}
double CArithmetic::Multiplication(double a, double b)
{   
    return a * b;
}


int main()
{   
    typedef double (*lpfnOperation)(double, double);
    // CVector of pointer to functions
    lpfnOperation vpf[4] = { CArithmetic::Addition, CArithmetic::Substraction,
    CArithmetic::Multiplication, CArithmetic::Division };
    float a, b, c; int opt;
    // enter the operands
    std::cin >> a >> b;
    // enter the operation 0-Addition, 1-Subtraction, 3-Multiplication, 4-Division
    std::cin >> opt;
    // The next line replaces the switch and replaces the whole switch
    c = (*vpf[opt])(a, b);
    std::cout << c << "\n";

    std::cout << "END\n";
}
/*
//caso de usar el switch
int main()
{   
   
    float a, b, c; int opt;
    // enter the operands
    std::cin >> a >> b;
    // enter the operation 0-Addition, 1-Subtraction, 3-Multiplication, 4-Division
    std::cin >> opt;
    // The next line replaces the switch and replaces the whole switch
    switch( opt )
    {
      case 0: c = CArithmetic::Addition(a, b); break;
      case 1: c = CArithmetic::Substraction(a, b); break;
      case 2: c = CArithmetic::Multiplication(a, b); break;
      case 3: c = CArithmetic::Division(a, b); break;
      // more cases operations go here
    }
    std::cout << c << "\n";
    std::cout << "END\n";
}
*/