// 水仙花数是指一个3位数，它的每个位上的数字的3次幂之和等于它本身
// range: 100 - 999
// 获取：个位，十位， 百位
//对数字取模于10， 得个位数字
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "Please get all 3 digit Narcissistic number: " << endl;
    int i = 100;
    do{
        int a1 = i / 100; //百位
        int remainder = i % 100;
        int a2 = remainder / 10;//十位
        int a3 = remainder % 10;//个位
        /*
         int a3 = i % 10;
         int a2 = i /10 %10;
         int a1 = i /100;
         */
        int val = pow(a1,3) + pow(a2,3) + pow(a3,3);
        if(val == i){
            cout << i << endl;
        }
        i++;
    }while(i<1000);

    return 0;
}
