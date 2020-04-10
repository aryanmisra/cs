#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main(){
    cout << "Hello World" << endl;

    const double PI  = 3.1415926535; //8 bytes - accurate to 15 decimals

    char myGrade = 'A'; //Takes up 1 byte of memory

    bool isHappy = true; //1 byte

    int myAge = 39; //2 bytes

    float favNum = 3.342342; // 4 bytes accurate to 6 decimals

    cout << "Fav Num " << favNum << endl;

    //short int: at least 16 bit
    //long int: at least 32 bit
    // long long int: at least 64 bit
    // unsigned int: same size as signed
    // long double: not less than double

    cout << "Size of int " << sizeof(myAge)
        << endl;

    cout << "Size of double " << sizeof(PI)
        << endl;
    
    cout << "Size of char " << sizeof(myGrade)
        << endl;
    
    cout << "Size of bool " << sizeof(isHappy)
        << endl;

    cout << "Size of float " << sizeof(favNum)
        << endl;

    // +,-,*,/,%, ++, -- operations are valid

    // ==,!=,>,<,<=,>=, &&, ||, !
    int age = 70;
    int ageLast = 16;
    bool isNotDrunk = true;

    if((age>=1) && (age<16)){
        cout << "cant drive" << endl;

    } else if(! isNotDrunk){
        cout << "u cant drive "<< endl;

    }

    int greetingoption = 2;
    switch (greetingoption)
    {
    case 1:
        cout << "bonjour" << endl;
        break;
    case 2:
        cout << "hola" << endl;
        break;
    
    default:
        break;
    }

    // variable = (condition) ? true : false
    int largestNum = (5>2) ? 5 : 2;

    int myFavNums[5];

    int badnums[5] = {4,13,14,24,23};

    cout << "Bad number 1: " << badnums[0] << endl;

    char myname[5][5] = {{'D','e','n'},
                        {'B','e','n'}};
    cout << "2nd letter in 2nd arr " <<myname[1][1] << endl;

    for(int i = 1; i <= 10; i++){
        cout << i<< endl;
    }

    int randnum = (rand() % 100) + 1;

    while(randnum != 100){
        cout << randnum << ", ";

        randnum = (rand() % 100) + 1;
    }
    cout << endl;

    string numberGuessed;
    int intNumguessed = 0;

    do {
        cout << "Gueess a num betw 1 and 10: ";
        getline(cin, numberGuessed);
        intNumguessed = stoi(numberGuessed);
        cout << intNumguessed << endl;
    } while(intNumguessed !=4);

    string bday = "Birthday";

    


    return 0;
}