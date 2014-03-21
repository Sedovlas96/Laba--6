#ifndef FUNCTIONS_H
#define FUNCTIONS_H

struct CardOfBuyer
{
    char surname[ 30 ];
    char firstname[ 20 ];
    int amountOfPurchases;
    int numberOfPurchases;
};

void showMenu();
void inputNewBase( CardOfBuyer *Array, int quantity );
void showBase( CardOfBuyer *Array, int quantity );
void getMenu ( int key );
void addBuyer( CardOfBuyer *Array );
void deleteBuyer( CardOfBuyer *Array);
void changeBuyer( CardOfBuyer *Array );


#endif // FUNCTIONS_H
