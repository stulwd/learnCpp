#include <iostream>
#define MAXSIZE 20
#define OK    1
#define ERROR 0
#define TRUE  1
#define FALSE 0

using namespace std;

typedef int elemtype;
typedef int status;

/**
 * 线性表的顺序存储方式
 * */
typedef struct{
    elemtype data[MAXSIZE];
    int length;
} sqList;

/**
 *  获取元素操作
 * */
status getElem(sqList l, int i, int *e){
    if( l.length == 0 || i < 1 || i > l.length){
        return ERROR;
    }
    *e = l.data[i-1];
    return OK;
}

/** 
 * 插入操作
 * 时间复杂度：
 *    最坏情况ｏ（ｎ）
 *    最好情况ｏ（１）
 *    平均：ｏ（(n - 1) / 2） = o(n)
 * 优点：不需要内存开销
 * 缺点：需要移动大量元素
 */
status listInsert(sqList *l, int i, elemtype e){

    if(l->length == MAXSIZE){
        return ERROR;
    }
    if(i < 1 || i > l->length + 1){
        return ERROR;
    }
    if(i <= l->length){                                     //移动元素
        for(int k = l->length - 1; k >= i-1; k--){
            l->data[k+1] = l->data[k];
        }
    }
    l->data[i-1] = e;       //插入元素
    l->length++;
    return OK;
}

/**
 * 删除操作
 * 时间复杂度：
 *    最坏情况ｏ（ｎ）
 *    最好情况ｏ（１）
 *    平均：ｏ（(n - 1) / 2） = o(n)
 * */
status listDelete(sqList *l, int i, elemtype *e){

    if(l->length == 0){
        return ERROR;
    }
    if(i < 1 || i > l->length){
        return ERROR;
    }
    *e = l->data[i-1];              //返回被删除的元素值
    if(i <= l->length){                                     //移动元素
        for(int k = i-1; k <= l->length - 1 - 1; k++){
            l->data[k] = l->data[k+1];
        }
    }
    l->data[l->length-1] = 0;       //删除最后一个元素
    l->length--;
    return OK;
}


/**
 * 链表概念
 * 数据域：存储数据
 * 指针域：存储指向下一个元素的指针
 * 头指针：1.指向第一个node的指针
 *        2.具有标识作用，指针变量的名字就是链表名
 *        ３.无论链表是否空，头指针不空
 * 头结点：1.放在第一个元素结点之前
 *        2.数据域无意义，或存放长度
 *        3.有了头结点，第一元素的操作和其他元素就会统一
 * */
typedef struct node{
    elemtype data;      //数据域
    node *next;
} node;

typedef struct node* linkList;      // 头指针别名


/**
 * 时间复杂度ｏ（ｎ）
 * */
status getElemOfLL( linkList l, int i, elemtype *e){        //传入头指针，头指针指向的是头结点
    linkList p;                     //定义工作指针
    p = l->next;                    //令ｐ指向第一个元素
    int j = 1;
    while( p && j < i){             //令ｐ指向第ｉ个元素
        p = p->next;
        j++;
    }
    if( p == NULL || j > i){
        return ERROR;
    }

    *e = p->data;
    return OK;
}