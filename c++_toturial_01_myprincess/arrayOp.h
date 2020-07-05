#ifndef GZDEMO_H_INCLUDED
#define GZDEMO_H_INCLUDED

#include <iostream>

using namespace std;
/*采用数组指针作为函数参数*/
// void input(int *[5], int);
// void print(int *[5], int);
void input(int [], int);
void print(int [], int);
void show(string (*)[5], int, int);
void showOneLine(string *, int);
// void input(int (*array)[5], int len){
//     if( len > sizeof(*array) / 4){
//         cout << "长度超出数组范围";
//         return;
//     }
//     for(int i = 0; i < len; i++){
//         cout << "输入第" << i << "个元素：";
//         cin >> (*array)[i];
//     }
// }

// void print(int (*array)[5], int len){
//     if( len > sizeof(*array) / 4){
//         cout << "长度超出数组范围";
//         return;
//     }
//     for(int i = 0; i < len; i++){
//         cout << "第" << i << "个元素值为：" << (*array)[i] << endl;
//     }
// }

void show(string (*array)[5], int len_i, int len_j){
    for(int i = 0; i < len_i; i++){
        // for(int j = 0; j < len_j; j++){
        //     cout << *(*(array + i) + j) << "\t";
        // }
        showOneLine( *(array+i) , len_j );
        cout << endl;
    }
}
void showOneLine(string array[], int len){
    for(int i = 0; i < len; i++){
        cout << *(array + i) << "\t";
    }
    cout << endl;
}
/*采用指针作为参数*/
void input(int array[], int len){
    //if( len > sizeof(array) / 4){ 不能用sizeof求出数组的长度,array作为参数时变为指针变量
    if( len > 5 ){
        cout << "长度超出数组范围";
        return;
    }

    for(int i = 0; i < len; i++){
        cout << "输入第" << i << "个元素：";
        cin >> array[i];
    }
}

void print(int array[], int len){
    // if( len > sizeof(*array) / 4){   错误的写法
    if( len > 5 ){
        cout << "长度超出数组范围";
        return;
    }
    for(int i = 0; i < len; i++){
        cout << "第" << i << "个元素值为：" << array[i] << endl;
    }
}

#endif