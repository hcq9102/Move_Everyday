/*
学校正在做毕业设计项目，每名老师带5个学生，总共有3名老师，需求如下：
 设计学生和老师结构体，其中老师的结构体中，有老师姓名和一个存放5名学生的数组作为成员；
 学生的成员有姓名，考试分;
 创建数组存放3名老师，通过函数给每个老师以及所带的学生赋值；
 最终打印老师数据以及老师所带的学生数据；
*/

#include <iostream>
#include <string>
#include<ctime>
using namespace std;

struct Student{
    string s_name;
    int score;

};

using namespace std;
struct Teacher{
    string t_name;
    struct Student sArray[5];
};
//给老师和学生赋值的函数

void allocateSpace(struct Teacher tArray[], int len){
    for(int i =0; i< len; i++){
        string nameSeed = "ABCDE";
        tArray[i].t_name = "Teacher_";
        tArray[i].t_name +=nameSeed[i];
        //通过循环给每个老师所带的学生赋值
        for(int j =0; j<5 ;j++){
            tArray[i].sArray[j].s_name = "Student_";
            tArray[i].sArray[j].s_name = nameSeed[j];
            //

            int random  = rand()%61 +40; // 40-100
            tArray[i].sArray[j].score = random;
        }


    }
}

void printInfo(struct Teacher tArray[], int len){
    for(int i =0 ;i<len; i++){
        cout <<"Teachers' name: "<< tArray[i].t_name << endl;
        for(int j =0; j<5 ;j++){
            cout<<"\t Students' name: " << tArray[i].sArray[j].s_name <<
                "; score :" << tArray[i].sArray[j].score << endl;

        }
    }
}
int main() {
    srand((unsigned int) time(NULL));
    //创建数组存放3名老师
    struct Teacher tArray[3];
    //通过函数给每个老师以及所带的学生赋值,同时给老师带的学生信息也赋值
    int len = sizeof(tArray)/sizeof(tArray[0]);
    allocateSpace(tArray,len);
    //打印所有老师以及所带学生的信息
    printInfo(tArray,len);
    return 0;
}
