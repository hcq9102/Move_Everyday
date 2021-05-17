/*
   * if A>=B: if A>=C --> A
   *           else -->C
   * else (A<B): if B<C --->C
   *               else --->B
   * */
/*
#include <iostream>
using namespace std;
int main() {
   int pig1 = 0;
   int pig2 = 0;
   int pig3 = 0;
   // input 3 pigs' weight:
   cin>> pig1>>pig2>>pig3;
   if(pig1>=pig2){
       if(pig1>=pig3){
           cout << "pig1 is the weightest"<<endl;
       }else{
           cout << "pig3 is the weightest"<<endl;
       }
   }else{
       if(pig2>=pig3){
           cout << "pig2 is the weightest"<<endl;
       }else{
           cout << "pig3 is the weightest"<<endl;
       }
   }
    return 0;
}
*/


// ternary operator 三元运算符 返回的是变量 可以继续赋值

#include <iostream>
using namespace std;

int main(){
    int A = 0;
    int B = 0;
    int C = 0;
    int max = 0;
    cin>> A >> B >> C ;

    max = A>=B? (A>=C? A:C) :(B<=C? C : B);
    cout << "the weightest pig is "<< max << endl;
    return 0;
 }

