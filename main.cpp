#include <iostream>
#include <fstream>
#include <cstring>
#include "functions.h"



using namespace std;



int main()
{
    CardOfBuyer *Array;
    int quantityOfBuyers = 20;
    Array = new CardOfBuyer[ quantityOfBuyers ];
    showbase();
    delete[] Array;

    return 0;
}
