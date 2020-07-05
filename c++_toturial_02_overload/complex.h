#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;

class complex
{
public:
    float a;
    float b;
    complex();
    complex(float, float);
    ~complex();
    friend ostream & operator<<(ostream&, const complex&);
    friend istream & operator>>(istream&, complex&);
    const complex operator+(const complex& other);
    const complex operator-(const complex& other);
    const complex operator*(const complex& other);
    
private:

};

#endif