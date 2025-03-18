#include <iostream>
#include <cstring>
#include "Math.h"

using namespace std;
 

int main()
{

    cout << "Add(2, 3) = " << Math::Add(2, 3) << endl;
    cout << "Add(2, 3, 4) = " << Math::Add(2, 3, 4) << endl;
    cout << "Add(2.5, 3.1) = " << Math::Add(2.5, 3.1) << endl;
    cout << "Add(2.5, 3.1, 4.4) = " << Math::Add(2.5, 3.1, 4.4) << endl;

    cout << "Mul(2, 3) = " << Math::Mul(2, 3) << endl;
    cout << "Mul(2, 3, 4) = " << Math::Mul(2, 3, 4) << endl;
    cout << "Mul(2.5, 3.1) = " << Math::Mul(2.5, 3.1) << endl;
    cout << "Mul(2.5, 3.1, 4.4)= " << Math::Mul(2.5, 3.1, 4.4) << endl;

    cout << "Add(4, 1, 2, 3, 4)= "<< Math::Add(4, 1, 2, 3, 4) << endl;
    
    cout << "Add(Merge, bine)= " << Math::Add("Merge", " bine") << endl;
   

	return 0;
}