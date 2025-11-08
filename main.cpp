#include <cmath>
#include <complex>
#include <iostream>
#include "qbit.h"
#include "multistate.h"

using namespace std;

int main()
{

    complex<double> a = {1.0 / sqrt(4), 0};
    complex<double> b = {1.0 / sqrt(4), 0};


    complex<double> c = {1.0/sqrt(4),0};
    complex<double> d = {1.0/sqrt(4),0};

    vector<complex<double>> v = {a,b,c,d};
    MultiState ms(v);

    cout<<ms;



    return 0;
}
