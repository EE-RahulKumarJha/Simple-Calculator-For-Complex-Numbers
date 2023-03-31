#include <iostream>
#include <cmath>

using namespace std;

class Complex {
  
       

    public:
    	 double real, imag;
        Complex(double r = 0, double i = 0) : real(r), imag(i) {}

        Complex operator+(const Complex& other) const {
            return Complex(real + other.real, imag + other.imag);
        }

        Complex operator-(const Complex& other) const {
            return Complex(real - other.real, imag - other.imag);
        }

        Complex operator*(const Complex& other) const {
            return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
        }

        Complex operator/(const Complex& other) const {
            double denominator = pow(other.real, 2) + pow(other.imag, 2);
            return Complex((real * other.real + imag * other.imag) / denominator, (imag * other.real - real * other.imag) / denominator);
        }

        void print() {
            cout << real << " + " << imag << "i" << endl;
        }
};

int main() {
    char op;
    Complex num1, num2;
    

    cout << "Enter an operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter the first complex number (real imag): ";
    cin >> num1.real >> num1.imag;

    cout << "Enter the second complex number (real imag): ";
    cin >> num2.real >> num2.imag;

    Complex result;

    switch(op) {
        case '+':
            result = num1 + num2;
            break;

        case '-':
            result = num1 - num2;
            break;

        case '*':
            result = num1 * num2;
            break;

        case '/':
            result = num1 / num2;
            break;

        default:
            cout << "Error: Invalid operator";
            return 0;
    }

    cout << "Result: ";
    result.print();

    return 0;
}

