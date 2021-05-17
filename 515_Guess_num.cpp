// 1.random number
// 2. guess
// 3. evaluate the guess
//guess right --->exit
//guess wrong --->give the hint (more or less) ; return the second step

#include <iostream>
//#include <stdlib.h>
//#include <time.h>
#include <ctime>
using namespace std;

int main() {
    // add random seed according to the system time; avoid the same random number each time

    srand((unsigned int)time(NULL));
    // 1.random number [1,100]
    int Rd_num = rand()%100 +1;

    // 2. guess
    int guess = 0;
    cout << "please enter your guess number "<< endl;

    while(1){
        cin >> guess;
        // 3. evaluate the guess
        if(guess > Rd_num){
            cout << "your guess too larger, continue:" << endl;
        }
        else if(guess < Rd_num){
            cout << "your guess too small,continue:"<< endl;
        }
        else{
            cout <<" Congrats, your guess : "<<guess  <<" is correct!!"<<endl;
            break;
        }
    }

    return 0;
}
