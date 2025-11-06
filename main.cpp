#include <iostream>
#include "qbit.h"

using namespace std;

int main()
{
    Complex a(1,0.4);
    Complex b(0,0);

    Qbit q(a,b);

    cout<<q;


    return 0;
}
