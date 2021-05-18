#include <iostream>
#include <string>

using namespace std;
//设计英雄结构体
struct Heros{
    string name;
    int age;
    string sex;
};
//bubbleSort by age increasing order
void bubbleSort(struct Heros heroArray[],int len){
    for(int i =0; i< len-1; i++){
        for(int j =0; j< len-i-1; j++){
            if(heroArray[j].age>heroArray[j+1].age){
                struct Heros temp = heroArray[j];
                heroArray[j] = heroArray[j+1];
                heroArray[j+1] = temp;
            }
        }
    }
}

void printHero(struct Heros heroArray[], int len){
    for( int i = 0; i< len; i++){
        cout << "name: " << heroArray[i].name << " age:" << heroArray[i].age << " sex: " <<heroArray[i].sex << endl;
    }
}



int main() {
    //创建数组存放5名英雄
    struct Heros heroArray[5]{
            //初始化
            {"liu bei", 23, "male"},
            {"guan yu", 22, "male"},
            {"zhang fei", 20, "male"},
            {"zhao yun", 21, "male"},
            {"diao chan", 19, "female"}
    };
    //print origin
    cout << "original data: "<< endl;
    int len = sizeof(heroArray) / sizeof(heroArray[0]);
    for( int i = 0; i< len; i++){
        cout << "name: " << heroArray[i].name << " age:" << heroArray[i].age << " sex: " <<heroArray[i].sex << endl;
    }
    //bubble sort
    bubbleSort(heroArray,len);
    //结果打印输出
    cout << "\t After Sort: "<< endl;
    printHero(heroArray,len);
    return 0;
}
