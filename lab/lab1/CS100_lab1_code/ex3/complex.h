#ifndef CLASS_COMPLEX
#define CLASS_COMPLEX

#include <iostream>

using namespace std;

class Complex
{
    // friend functions
    friend ostream& operator << (ostream&, const Complex&);
    friend Complex operator+ (const Complex&, const Complex&);
private:
    double real_;
    double imag_;

public:
    Complex (double = 0.0, double = 0.0);

    void setReal(double);
    void setImag(double);
    double getReal() const;
    double getImag() const;

    bool operator== (const Complex&);
    bool operator< (const Complex&);
    
};

inline Complex::Complex(double rl, double im)
: real_(rl), imag_(im)
{}

inline void Complex::setReal(double rl)
{
    real_ = rl;
}

inline void Complex::setImag(double im)
{
    imag_ = im;
}

inline double Complex::getReal() const
{
    return real_;
}

inline double Complex::getImag() const
{
    return imag_;
}

ostream& operator<< (ostream&, const Complex&);
Complex operator+ (const Complex&, const Complex&);

#endif
   
