#include "complex.h"

ostream& operator<<(ostream& out , const complex& other){
    out << other.a << "+" << other.b << "i";
    return out;
}

istream& operator>>(istream& in, complex& other){
    in >> other.a >> other.b;
    return in;
}

const complex complex::operator+(const complex& other)
{
    return complex(this->a + other.a, this->b + other.b);
}
const complex complex::operator-(const complex& other)
{
    return complex(this->a - other.a, this->b - other.b);
}

const complex complex::operator*(const complex& other)
{
    return complex( (this->a * other.a) - (this->b * other.b) , (this->a * other.b)+(this->b * other.a) );
}
complex::complex(){
    this->a = 0;
    this->b = 0;
}


complex::complex(float val_a, float val_b){
    this->a = val_a;
    this->b = val_b;
}

complex::~complex(){
    
}