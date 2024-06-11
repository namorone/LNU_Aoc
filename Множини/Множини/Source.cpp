#include "Header.h"
void main()
{
    Set s0;
    Set s1;
    s0.append('1');
    s0.append('s');
    s1.append('a');
    s1.append('b');
    s0.print();
    cout << "\n";

    s1.print();

    cout << "\n";
    s0.unit(s1);
    s0.print();
}