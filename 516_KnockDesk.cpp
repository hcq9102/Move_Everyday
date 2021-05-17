//given 1-100, if ones place or tens place has 7 or the number is the multiples of 7 --> cout "knock the desk" or cout the num

#include <iostream>
using namespace std;
int main() {
    for(int i =1; i<=100; i++){
        if(i%7 ==0 || i%10 == 7 || i/10 ==7){
            cout << "knock the desk"<<endl;
        }else{
            cout << i << endl;
        }
    }
    return 0;
}
