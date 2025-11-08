#include <complex>
#include <iostream>
#include "qbit.h"

using namespace std;

int main()
{

    complex<double> a = {1.0 / sqrt(2), 0};
       complex<double> b = {1.0 / sqrt(2), 0};

    Qbit q(a,b);

    cout<<q.getalpha();



    return 0;
}
