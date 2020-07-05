#include <iostream>
#include "landOwnerV2.h"
#include "student.h"
using namespace std;

int x = 100; //全局内存区

void showArray(string (*)[6], int);
void changeVal(string (*)[6], int, int, string);
int& receivePtr();
int& receiveMainPtr(int& ref_main);
int main(void){


    //对象初始化写法（尽量使用堆内存创建对象）
    //在栈内存中构造，会自动释放
    landOwnerV4 landOwner4;
    student student1; 
    student student2(18);
    student student3("撒贝宁", "北大还行");
    student student4 = 50;
    student student5 = {"撒贝宁", "北大还行"};
    student5.showInfo();

    //指针类型，在堆内存中构造，要手动析构(多)
    student* stu6 = new student("杰克马", "悔创阿里");    
    stu6 -> showInfo();

    int num = 1;
    cout << "x的地址（全局内存区）：" << &x << endl;
    cout << "num的地址(栈内存)：" << &num << endl;
    cout << "student5的地址(栈内存)：" << &student5 << endl;
    cout << "stu6指向的内存地址（堆内存）：" << stu6 << endl;
    //当堆内存的对象使用结束时，不会自动释放，记得delete， 手动释放！、
    delete stu6;

    /*比较出学霸*/
    //用堆内存创建第七个student迪丽热巴
    student* ptrStu7 = new student("迪丽热巴", "微胖女孩");
    ptrStu7->addScore(78.9f);
    ptrStu7->addScore(88.9f);
    ptrStu7->addScore(98.9f);
    ptrStu7->addScore(5476.9f);
    ptrStu7->showInfo(); 
    //用栈内存创建第八个student刘强东
    student student8("刘强东", "不爱美人");
    student8.addScore(38.9f);
    student8.addScore(48.9f);
    student8.addScore(548.9f);
    student8.addScore(568.9f);
    student8.showInfo();

    student scholor1 = student8.getSuperScholar(*ptrStu7);      //返回迪丽热巴的引用赋值给了scholor1对象
    student scholor2 = ptrStu7->getSuperScholar(student8);      //返回迪丽热巴的引用赋值给了scholor2对象
    cout << "scholar1的地址：" << &scholor1 << endl;
    cout << "scholar2的地址：" << &scholor2 << endl;
    cout << "ptrStu7的地址：" << ptrStu7 << endl;
    cout << "学霸是" << scholor1.getName() << endl;
    cout << "学霸是" << scholor2.getName() << endl;
    //scholar1，scholar2为在栈内存中的两份相同的对象，所以最后会被分别释放
    //而ptrStu7依然指向堆内存，所以要手动释放
    delete ptrStu7;

    /*以上写法消耗内存空间，可以改为用引用类型接受,不用担心引用指向的数据被销毁，因为返回的不是局部创建的变量*/
    //student& scholor1 = student8.getSuperScholar(*ptrStu7);      //返回迪丽热巴的引用赋值给了scholor1引用
    //student& scholor2 = ptrStu7->getSuperScholar(student8);      //返回迪丽热巴的引用赋值给了scholor2引用
    



    string Array2[4][6] = {
        {"lwd","fda","fd","qwe","rv","bvx"},
        {"fd","qwe","vd","sdgf","lwd","fda"},
        {"gfds","ds","f","gfds","gfd","gfds"},
        {"gfds","gfds","fdsg","s","s","gfds"}
    };
    string (*ptrArray)[6] = Array2;

    cout << "修改前：" << endl;
    showArray(ptrArray, 4);
    changeVal(ptrArray, 1, 1, "ops");
    cout << "修改后：" << endl;
    showArray(Array2, 4);

    int& ref = receivePtr();    //用引用接受函数内部定义的变量的引用是危险的
    cout << ref << endl;cout << ref << endl; cout << ref << endl;cout << ref << endl;

    int a = 88;
    int& ref1 = receiveMainPtr(a);  //用引用类型接受同一级别栈的变量的引用是安全的
    cout << ref1 << endl;cout << ref1 << endl;cout << ref1 << endl;cout << ref1 << endl;
    while(1);
}

int& receivePtr(){
    int a = 99;
    int& ref = a;
    return ref;
}
int& receiveMainPtr(int& ref_main){
    int a = 99;
    int& ref = a;
    return ref_main;
}

void showArray(string (*ptrArray)[6], int n_line){
    for(int i = 0; i < n_line; i++){
        for(int j = 0; j < 6; j++){
            cout << *(*(ptrArray + i) + j) << "\t";
        }
        cout << endl;
    }
}

void changeVal(string (*ptrArray)[6], int x, int y, string val){
    ptrArray[x][y] = val;
}