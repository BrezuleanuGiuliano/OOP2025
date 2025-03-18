#include "Canvas.h"
#include <iostream>

using namespace std;

int main() {
    Canvas canvas(70, 70);

    
    canvas.DrawCircle(30, 30, 20, '*');
    canvas.FillCircle(30, 30, 19, '#');
    canvas.DrawRect(2, 2, 8, 6, '+');
    canvas.FillRect(12, 2, 18, 6, '@');
    canvas.DrawLine(35, 0,70,35 , '-');

    
    canvas.Print();



    return 0;
}
