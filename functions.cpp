#include "functions.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>
#include <conio.h>


using namespace std;

void inputBase( CardOfBuyer *Array, int firstIndex, int lastIndex )
{
    cin.ignore();
    for( int i = firstIndex; i < lastIndex; ++i )
    {
        cout << " Enter surname: ";
        cin.getline( Array[ i ].surname, 30, '\n' );

        cout << " Enter first name: ";
        cin.getline( Array[ i ].firstname, 20, '\n' );

        cout << " Enter Amount Of Purchases: ";
        cin >> Array[ i ].amountOfPurchases;

        cout << " Enter Number Of Purchases: ";
        cin >> Array[ i ].numberOfPurchases;
    }
}

void showMenu()
{
    int key;
    cout << " Press key: " << endl;
    cout << " ~1~ - For enter new base " << endl;
    cout << " ~2~ - For adding Buyer " << endl;
    cout << " ~3~ - For deleting Buyer " << endl;
    cout << " ~4~ - For changing information about Buyer " << endl;
    cout << " ~5~ - For show base " << endl;
    cout << " ~6~ - For sorting by Firstname " << endl;
    cout << " ~7~ - For sorting by Surname " << endl;
    cout << " ~8~ - For sorting by Amount of Purchases " << endl;
    cout << " ~9~ - For sorting by Number of Purchases " << endl;
    cin >> key;
    if( key )
    {
        getMenu( key);
    }
}


void getMenu ( int key )
{
    switch( key )
    {
    case 1:
        inputNewBase();
        break;
    case 2:
        addBuyer();
        break;
    case 3:
        deleteBuyer();
        break;
    case 4:
        changeBuyer();
        break;
    case 5:
        showBase();
        break;
    case 6:
        sortingByFirstname();
        break;
    case 7:
        sortingBySurname();
        break;
    case 8:
        sortingByAmountOfPurchases();
        break;
    case 9:
        sortingByNumberOfPurchases();
        break;
    default:
        Error();

    }
}

void inputNewBase( CardOfBuyer *Array, int quantity )
{
    system( " cls " );
    fstream dataOut( " data.txt ", ios::out|ios::binary|ios::trunc );
    dataOut.write(( char *)Array, quantity * sizeof( CardOfBuyer )) << endl;
    dataOut.close;
    inputBase( Array, 0, quantity );
    system( " pause " );
}

void addBuyer( CardOfBuyer *Array )
{
    system( " cls " );
    int index = sizeof( Array ) / sizeof( int );
    inputBase( Array, index , index + 1 );
    fstream dataOut( " data.txt ", ios::out|ios::binary|ios::trunc );
    dataOut.write(( char *)Array, index * sizeof( CardOfBuyer )) << endl;
    dataOut.close;
}

void deleteBuyer( CardOfBuyer *Array)
{
    int indexOfDeleted
    cout << " Enter Index Of Deleted Buyer : ";
    cin >> indexOfDeleted;
    for( int i = indexOfDeleted; i < sizeof( Array ) / sizeof( int ) - 1; ++i )
    {
        Array[ i ].surname = Array[ i + 1 ].surname;
        Array[ i ].firstname = Array[ i + 1 ].firstname;
        Array[ i ].amountOfPurchases = Array[ i + 1 ].amountOfPurchases;
        Array[ i ].numberOfPurchases = Array[ i + 1 ].numberOfPurchases;
    }
    fstream dataOut( " data.txt ", ios::out|ios::binary|ios::trunc );
    dataOut.write(( char *)Array, sizeof( Array ) * sizeof( CardOfBuyer )) << endl;
    dataOut.close;
}

void changeBuyer( CardOfBuyer *Array )
{
    int indexOfChanged;
    cout << " Enter Index Of Changed Buyer: ";
    cin >> indexOfChanged;

    cout << " Change The Surname:  ";
    cin.getline( Array[ indexOfChanged ].surname, 30, endl );

    cout << " Change The Firstname: ";
    cin.getline( Array[ indexOfChanged ].firstname, 20, endl );

    cout << " Change Amount Of Purchases: ";
    cin >> Array[ indexOfChanged ].amountOfPurchases >> endl;

    cout << " Change Number Of Purchases: ";
    cin >> Array[ indexOfChanged ].numberOfPurchases >> endl;

    fstream dataOut( " data.txt ", ios::out|ios::binary|ios::trunc );
    dataOut.write(( char *)Array, sizeof( Array ) * sizeof( CardOfBuyer )) << endl;
    dataOut.close;
}

void showBase( CardOfBuyer *Array, int quantity )
{
    system( " cls " );
    cout << " Surname     Firstname    Amount    Quantity " << endl;
    for( int i = 0; i < quantity; ++i )
    {
        cout << endl;
        cout << Array[ i ].surname << "      ";
        cout << Array[ i ].firstname << "        ";
        cout << Array[ i ].amountOfPurchases << "      ";
        cout << Array[ i ].numberOfPurchases << endl;
    }
}
