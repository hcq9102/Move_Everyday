/*
Address book managemnet system:
function requirements:
 1. add contacts
 2. show contacts
 3. delete contacts
 4. search contacts
 5. modify contacts
 6. clear up contacts
 7. exit management system
 */
#include <iostream>
#include <string>
using namespace std;

#define MAX 1000 // maximum size of address book
//1.set menu function : select item according to the index number
//void showMenu() to show the menu interface
void showMenu(){
    cout << "*********************************"<<endl;
    cout << "*** 1. add contacts           ***" << endl;
    cout << "*** 2. show contacts          ***" << endl;
    cout << "*** 3. delete contacts        ***" << endl;
    cout << "*** 4. search contacts        ***" << endl;
    cout << "*** 5. modify contacts        ***" << endl;
    cout << "*** 6. clear up contacts      ***" << endl;
    cout << "*** 0. exit management system ***" << endl;
    cout << "*********************************"<<endl;
}
/*
 添加联系人：
 。设计联系人结构体
 。设计通讯录结构体
 。main函数中创建通讯录
 。封装添加联系人函数
 。测试添加联系人功能
*/
struct Person{ //设计联系人结构体
    string p_name;
    int p_sex; // 1 male, 2 female
    string p_tel;
    int p_age;
    string p_addr;
};

struct Addressbooks{ //设计通讯录结构体
    struct Person personArray[MAX];
    int p_size;
};
//add contacts
void addPerson(Addressbooks * adbs){
    if(adbs->p_size == MAX){
        cout<<"the memory of address book is full now" << endl;
        return;
    }else{
        string name;
        cout << "please enter the name :" << endl;
        cin >> name;
        adbs->personArray[adbs->p_size].p_name = name;//在原有size基础上添加新的联系人

        cout << "please enter the sex :" << endl;
        cout <<"1 --- male"<<endl;
        cout <<"2 --- female"<<endl;
        int sex = 0;
        while(true){
            cin >> sex;
            if(sex ==1 || sex ==2){
                adbs->personArray[adbs->p_size].p_sex = sex;
                break;
            }
            cout << "error input!!! please enter the correct number" << endl;
        }

        cout << "please enter the phone number: "<< endl;
        string tel;
        cin >> tel;
        adbs->personArray[adbs->p_size].p_tel = tel;

        cout << "please enter the age : "<< endl;
        int age = 0;
        cin >> age;
        adbs->personArray[adbs->p_size].p_age= age;

        cout <<"please enter the address : "<< endl;
        string addr;
        cin >> addr;
        adbs->personArray[adbs->p_size].p_addr = addr;

        // update the size of the addressbooks
        adbs->p_size ++;

        cout << "add contacts successfully!" <<endl;

    }
}

//2. show contacts
void showPerson(Addressbooks * adbs){
    //判断通讯录中是否为0
    if(adbs ->p_size == 0){
        cout << "Sorry! Current record is empty:" << endl;
    }else{
        for(int i =0;i <adbs->p_size; i++){
            cout << "Name: " << adbs->personArray[i].p_name<<"\t";
            cout << "Sex: " << (adbs->personArray[i].p_sex ==2? "female": "male" )<<"\t";
            cout << "Age: " << adbs->personArray[i].p_age<<"\t";
            cout << "Telephone: " << adbs->personArray[i].p_tel<<"\t";
            cout << "Address: " << adbs->personArray[i].p_addr<<endl;
        }
    }
}
//3. delete contacts : 先检测是否存在，再删除，再测试是否删干净这个人
int isExist(Addressbooks* adbs, string name){
    for(int i =0;i <adbs->p_size; i++){
        if(adbs->personArray[i].p_name == name){
            return i; //find and return the index
        }
    }
    return -1;
}
void deletePerson(Addressbooks * adbs){
    cout << "please enter the name you want to delete: "<< endl;
    string dname;
    cin >> dname;
    int ret = isExist(adbs,dname);
    if(ret !=-1){
        for(int i = ret; i<adbs->p_size; i++){
            //数据前移，达到删除目标的作用；
            adbs->personArray[i] = adbs->personArray[i+1];
        }
        adbs->p_size--;
        cout << "delete successfully!" <<endl;
    }else{
        cout << "the name is not here!"<<endl;
    }
}

//4. search contacts
void findPerson(Addressbooks *adbs){
    cout << "please enter the name you want to look up : " <<endl;
    string fname;
    cin>> fname ;
    int ret = isExist(adbs,fname);
    if(ret !=-1){
        cout << "Find the person you want " <<endl;
        cout << "Name: " << adbs->personArray[ret].p_name<<"\t";
        cout << "Sex: " << (adbs->personArray[ret].p_sex ==2? "female": "male" )<<"\t";
        cout << "Age: " << adbs->personArray[ret].p_age<<"\t";
        cout << "Telephone: " << adbs->personArray[ret].p_tel<<"\t";
        cout << "Address: " << adbs->personArray[ret].p_addr<<endl;
    }else{
        cout << " Did not find the person you want"<<endl;
    }
}

//5. modify contacts
void modifyPerson(Addressbooks *adbs){
    cout << "please enter the name you want to modify: "<< endl;
    string mname;
    cin >> mname;
    int ret = isExist(adbs,mname);
    if(ret !=-1){
        //find
        string name;
        cout << "please enter the name :" << endl;
        cin >> name;
        adbs->personArray[ret].p_name = name;

        cout << "please enter the sex :" << endl;
        cout <<"1 --- male"<<endl;
        cout <<"2 --- female"<<endl;
        int sex = 0;
        while(true){
            cin >> sex;
            if(sex ==1 || sex ==2){
                adbs->personArray[ret].p_sex = sex;
                break;
            }
            cout << "error input!!! please enter the correct number" << endl;
        }

        cout << "please enter the age : "<< endl;
        int age = 0;
        cin >> age;
        adbs->personArray[ret].p_age= age;

        cout << "please enter the phone number: "<< endl;
        string tel;
        cin >> tel;
        adbs->personArray[ret].p_tel = tel;

        cout <<"please enter the address : "<< endl;
        string addr;
        cin >> addr;
        adbs->personArray[ret].p_addr = addr;
        cout << "Modify successfully!"<<endl;
    }else{
        cout << "Did not find the person!"<<endl;
    }
}
//6. clear up contacts
void emptyPerson(Addressbooks *adbs){

    adbs-> p_size = 0;
    cout << "The address book is empty now!" << endl;
}

int main() {
    //main函数中创建通讯录结构体变量
    Addressbooks adbs;
    //初始化
    adbs.p_size = 0;


    int select = 0; // 创建用户选择输入的变量
    while(true){
        // call menu
        showMenu();
        cout << "please enter your choice : " << endl;
        cin >> select;
        switch(select) {
            case 1: // add contacts
                addPerson(&adbs); //利用地址传递可以修饰实参
                break;
            case 2: //show contacts
                showPerson(&adbs);
                break;
            case 3: //delete contacts
//            {
//                cout << "please enter the name you want to delete: " << endl;
//                string Dname;
//                cin >> Dname;
//                if (isExist(&adbs, Dname) == -1) {
//                    cout << Dname << " is not here!" << endl;
//                } else {
//                    cout << " find " << Dname << endl;
//                }
//            }
                deletePerson(&adbs);
                break;
            case 4: //search contacts
                findPerson(&adbs);
                break;
            case 5: //modify contacts
                modifyPerson(&adbs);
                break;
            case 6: //clear up contacts
                emptyPerson(&adbs);
                break;
            case 0: //exit management system
                cout << "welcome next time " << endl;
                system("pause");
                return 0;
                break;
            default :
                break;
        }
    }
    return 0;
}
