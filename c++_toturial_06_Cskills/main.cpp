#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "temp17.h"

#define SQUARE(a) ((a)*(a))

using namespace std;

char * getStr(void){
    char p[] = "hello world";
    return p;
}

int func(int num){
    return num;
}
void show(int *ptr[3]){
    for(int i = 0; i <= 3; i++){
        cout << *(*ptr+i) << endl;
    }
}

void deleteSpecialChar(char* start){
    char* ptr = start;
    while( *ptr != '\0' ){
        if( !((*ptr >= 'a' && *ptr <= 'z') || (*ptr >= 'A' && *ptr <= 'Z') || (*ptr >= '0' && *ptr <= '1')) ){
            char* movePtr = ptr;
            while( *movePtr != '\0'){
                *movePtr = *(movePtr+1);
                movePtr++;
            }
        }
        else{
            ptr++;
        }
    }
}
void quickDeleteSpecialChar(char* start){
    char* ptr1 = start;
    char* ptr2 = start;
    while(*ptr1 != '\0'){
        while( !((*ptr2 >= 'a' && *ptr2 <= 'z') || (*ptr2 >= 'A' && *ptr2 <= 'Z') || (*ptr2 >= '0' && *ptr2 <= '1')) ){
            ptr2++;
        }
        *ptr1 = *ptr2;
        if(*ptr1 == '\0') return;
        ptr1++;ptr2++;
    }
}

void reverseInt(int& i){
    int result = 0;
    while( i == 0 ){
        result = result*10 + i%10;
        i = i / 10;
    }
    i = result;
}
int main(){
    // /*c语言操作*/

    // 0.打印对应字符的ascii码
    // char chr[] = {'a', 'z', 'A', 'Z', '0', '1', '9'};
    // int ch2int;
    // for(int i = 0; i < 7; i++){
    //     ch2int = (int)chr[i];
    //     cout << ch2int << endl;
    // }

    // 1.当array为一个数组，则＆代表数组指针
    // int array[5] = {1,2,3,4,5};
    // int * p = (int *)(&array+1);
    // cout << *(p-1) << endl;    // 5
    // cout << array << endl;
    // cout << array+1 << endl;
    // cout << (&array + 1) << endl;
    // int sq[5] = {1,2,3,4,5};
    // cout << "sq[]长度为" << sizeof(sq) << endl;
    // cout << "sq[]长度为" << sizeof(*(&sq)) << endl;
    // int array2[3][3] = {
    //     {1,2,3},
    //     {4,5,6},
    //     {7,8,9}
    // }; 
    // int  array1[3] = {
    //     3,4,5
    // };
    // show(array2);   //当array为二维数组变量，array变量名本身就是数组指针
    // show(&array1);  //当array为一位数组变量，&array为指向这个数组的数组指针

    // // 2.涉及宏定义时，不要使用＋＋或－－
    // int a = 5;
    // cout << SQUARE(a++) << endl;
    // cout << a << endl;
   
    // // 3.判断是否为２的幂次方   
    // int num = 1025;
    // cout << ((num&(num-1))? "no" : "yes") << endl;

    // // 4.嵌入式Ｃ语言中中断服务函数没有返回值、没有传入参数、尽量不要做浮点运算

    // // 5.
    // char *str = NULL;
    // str = getStr();
    // cout << str << endl;
    
    // // 6.strcpy()
    // char string[9], str[10];
    // for(int i = 0; i < 10; i++){
    //     str[i] = 'a';
    // }
    // strcpy(string, str);
    // cout << string << endl;

    // 7.函数指针的用法
    // int (*ptr)(int);
    // ptr = func;
    // int n = (ptr)(123);     //也可以　n = (*ptr)(123)
    // cout << n << endl;

    // // 8.数组函数指针
    // int (*ptrArray[10])(int);
    // *ptrArray = func;
    // int n1 = (*ptrArray)(123);      //也可以　n1 = (**ptrArray)(123)
    // cout << n1 << endl;

    // // ９.const 关键字
    // const int a = 1;  //变量ａ的类型不能变
    // int const b = 1;
    // int * p;
    // int n1 = 1; const int *c = &n1;       //指针所指的值不能变,指针本身可以修改
    // c = p;
    // int n2 = 1; int* const d = &n2;     //指针本身不能变,指向的值可以修改
    // *d = 2;

    //10.字符串长度问题
    // string str;
    // cout << "请输入要处理的字符串：";
    // cin >> str;
    // cout << str << endl;
    // cout << str.length() << endl;
    // string* ptr = &str;
    // cout << ptr->at(0);


    // 11.sizeof的用法
    // char str[] = "hellow";                                           //1.不指定数组长度，最终长度又右值决定，此处长度为6+1
    // cout << "str[]长度为" << sizeof(str) << endl;                    //  sizeof可接受数组变量求数组长度，此处长度为6+1
    // cout << "\"string字符串的长度为\"" << sizeof("string") << endl;   //  当sizeof参数是字符串时，把字符串当做一个数组来看待,返回数组长度
    // char *ptr = "hellow";                                          //
    // cout << "sizeof(ptr)：" << sizeof(ptr) << endl;                //  sizeof不能用指针变量获取字符串长度，所以此处只返回指针本身的长度
    // //*ptr = "string";                                            //  (ps).”hellow“为常量，定义后不可用指针去修改值 因此此处为非法操作
  
    // 12.cout << 的用法
    // cout << "ptr指向的字符串为：" << ptr << endl;                      //2.cout只接受指针，输出到字符'\0'为止
    // cout << "str数组元素为" << str << endl;                           //  虽然也可接受数组变量，但会将其转换为指针,所以和上一行结果一样
    // cin >> str;                                                     //  所以用cin重新给字符串赋值后，即使str数组总长度未改变，但只会打印到'\0'截止  
    // cout << "修改后的字符串为" << str << endl;                        //   （ps.）cin会在输入的字符后加一个\0字符表示结束
    // cout << "sizeof(str) : " << sizeof(str) << endl;               //
    // char c[5] = {'a','b','c','\0','e'};                            //    
    // cout << c << endl;                                             //
    // int a[5] = {1,2,3,4,5};                                        //
    // cout << a << endl;                                             //
    // char ch = 'a';                                                 //
    // cout << ch << endl;                                            //
    // cout << &ch << endl;                                           // 总结：cout除了(char *)，输出指向的内容直到’\0‘结束，其他类型都是接受什么输出什么

    // 13.删除字符串特殊字符的两种方法
    // char str[1000] = "fda@#$fs3@423x$D23$C32D4@#$$#@d@#$dX#@$x#@x4c234cxX$#@C4#@4#@xc$#@432X4324X32$6243X$84324#@64X@#446fda@#$fs3@423x$D23$C32D4@#$$#@d@#$dX#@$x#@x4c234cxX$#@C4#@4#@xc$#@432X4324X32$6243X$84324#@64X@#446fda@#$fs3@423x$D23$C32D4@#$$#@d@#$dX#@$x#@x4c234cxX$#@C4#@4#@xc$#@432X4324X32$6243X$84324#@64X@#446fda@#$fs3@423x$D23$C32D4@#$$#@d@#$dX#@$x#@x4c234cxX$#@C4#@4#@xc$#@432X4324X32$6243X$84324#@64X@#446fda@#$fs3@423x$D23$C32D4@#$$#@d@#$dX#@$x#@x4c234cxX$#@C4#@4#@xc$#@432X4324X32$6243X$84324#@64X@#446fda@#$fs3@423x$D23$C32D4@#$$#@d@#$dX#@$x#@x4c234cxX$#@C4#@4#@xc$#@432X4324X32$6243X$84324#@64X@#446fda@#$fs3@423x$D23$C32D4@#$$#@d@#$dX#@$x#@x4c234cxX$#@C4#@4#@xc$#@432X4324X32$6243X$84324#@64X@#446fda@#$fs3@423x$D23$C32D4@#$$#@d@#$dX#@$x#@x4c234cxX$#@C4#@4#@xc$#@432X4324X32$6243X$84324#@64X@#446fda@#$fs3@423x$D23$C32D4@#$$#@d@#$dX#@$x#@x4c234cxX$#@C4#@4#@xc$#@432X4324X32$6243X$84324#@64X@#446fda@#$fs3@423x$D23$C32D4@#$$#@d@#$dX#@$x#@x4c234cxX$#@C4#@4#@xc$#@432X4324X32$6243X$84324#@64X@#446";
    // char *sptr = str;
    // char *move = sptr;
    // clock_t start, end;
    // start = clock();
    // // 方法一：冗余搬移较多
    // while( *sptr != '\0' ){
    //     if( (*sptr >= 'a' && *sptr <= 'z') || (*sptr >= 'A' && *sptr <= 'Z')
    //     || (*sptr >= '0' && *sptr <= '9') ){
    //         sptr++;
    //     }else{  //移位操作
    //         move = sptr;
    //         while( *move != '\0' ){
    //             *move = *(move + 1);
    //             move++;
    //         }
    //     }
    // }
    // // 方法二：算法更快，冗余搬移越少
    // // char *lptr = sptr, *rptr = sptr;
    // // while( *lptr != '\0' ){
    // //     while( !((*rptr >= 'a' && *rptr <= 'z') || (*rptr >= 'A' && *rptr <= 'Z')
    // //     || (*rptr >= '0' && *rptr <= '9') || (*rptr == '\0')) ){
    // //         rptr++;      //12@*24%42$#435
    // //     }
    // //     *lptr = *rptr;
    // //     lptr++;rptr++;
    // // }
    // end = clock();
    // cout << "算法运行时间为" << end - start << endl;
    // cout << "修改后的字符串为：" << str << endl;

    // 14.文件操作
    // 写入文件
    // char sentence[100];
    // FILE *fptr;
    // fptr = fopen("test", "w");
    // if(fptr == NULL){
    //     cout << "打开文件失败";
    //     exit(1);
    // }else{
    //     cout << "输入字符串：";
    //     cin >> sentence;
    //     // fgets(sentence, sizeof(sentence)/sizeof(sentence[0]), stdin);
    //     fprintf(fptr, "%s", sentence);
    //     cout << "写入完毕";
    //     fclose(fptr);
    // }
    // 读文件的某一行
    // char content[100];
    // FILE *fptr_read;
    // int line = 3, col = 2;
    // if( (fptr_read = fopen("test", "r")) == NULL ){
    //     cout << "打开文件失败";
    //     exit(1);
    // }else{
    //     for(int i = 0; i < line; i++){
    //         fscanf( fptr_read, "%s", content);
    //     }
    //     cout << "读取的结果为：" << content << endl;
    // }
    //
    // 指定位置读取
    // char content[100];
    // FILE *fr;
    // int line = 3, col = 2, n = 5;
    // if( (fr = fopen("test", "r")) == NULL){
    //     cout << "error";
    //     exit(1);
    // }else{
    //     for(int i = 0; i < line - 1;){         //跳转到第line行
    //         if( fgetc(fr) == '\n' ) i++;
    //     }
    //     for(int i = 0; i < col - 1; i++){      //跳转到第col个字符前
    //         fgetc(fr);
    //     }
    //     char ch = fgetc(fr);                   //读取一个字符
    //     cout << ch << endl;
    //     char str[100];
    //     fgets(str, 8, fr);                     //读取n个字符
    //     cout << str;
    // }

    // 15.五人分鱼问题
    // (n - 1) % 5 != 0; n = 4 * [(n - 1)%5]
    // int n; bool find = false;
    // for(int total = 1; ; total++){
    //     n = total;
    //     for(int i = 0; i < 5; i++){
    //         if( (n != 0 )&&( (n - 1) % 5) == 0 ){
    //             if(i == 4){
    //                cout << "最少钓了" << total << "条鱼";
    //                find = true;
    //             }else{
    //                 n = 4 * ((n - 1)/5);
    //             }
    //         }
    //         else{
    //             break;
    //         }
    //     }
    //     if(find == true){
    //         break;
    //     }
    // }

    // 16.约瑟夫生死游戏
    // int total = 30, out = 15, BeriMax = 9;            //参数：总人数８、需要退出的人数７、报数最大值
    // int num[total] = { 0 };                 
    // int count = 0;
    // while(out){
    //     for(int i = 0; i < BeriMax; i++){
    //         if(num[count] == 1)
    //             i--;
    //         if(i == BeriMax - 1)
    //             break;
    //         if(count == total - 1)
    //             count = 0;
    //         else count++;
    //     }
    //     num[count] = 1;
    //     cout << "第" << count + 1 << "个人下船了" << endl;
    //     out--;
    // }
    
    // 17.学生成绩录入并保存到文件
    // cout << "请输入需要录入信息的学生人数：";
    // int n;
    // cin >> n;
    // student* table[n];
    // for(int i = 0; i < n; i++){         //创建n个学生的记录
    //     cout << "学生" << i << ": " << endl;
    //     table[i] = new student();
    // }
    // FILE* fstu;
    // fstu = fopen("学生信息表", "w");
    // if( fstu == NULL ){
    //     cout << "打开文件错误" << endl;
    //     exit(1);
    // }else{
    //     fprintf(fstu, "姓名\t学号\t语文\t数学\t英语\n");
    //     for(int i = 0; i < n; i++)
    //         // string info = table[i]->printInfo()
    //         fprintf(fstu, "%s\t%s\t%d\t%d\t%d\n", table[i]->getName().c_str(), table[i]->getId().c_str(), table[i]->getScore().A, table[i]->getScore().B, table[i]->getScore().C);
    // }
    // fclose(fstu);

    // 18.小写转大写
    // ｃ语言方法
    // char string[100];
    // cout << "请输入字符串";
    // cin >> string;
    // char *p = string;
    // while( *p != '\0'){
    //     if( *p >= 'a' && *p <= 'z'){
    //         *p = *p + ('A' - 'a');
    //     }
    //     p++;
    // }
    // cout << string;
    
    // 19.字符串子串出现的次数(包含重叠)
    // char string[100], substr[100];
    // cout << "依次输入母串、子串：";
    // cin >> string >> substr;
    // char *ptr = string, *ptrSub = substr;
    // int count = 0;
    // int len = 0;
    // while( *(ptrSub+len) != '\0') len++;               //计算子串长度len
    // while( *ptr != '\0'){                           //大循环为母字符串的遍历
    //     for(int i = 0; i < len; i++){               //验证是否匹配
    //         if( ptr[i] == ptrSub[i] ){
    //             if(i == len-1) count++;
    //             continue;
    //         }else break;
    //     }
    //     ptr++;
    // }
    // cout << "子串出现的次数为:" << count << endl;

    // 19.字符串子串出现的次数(不包含重叠)
    // char str[100], subStr[100];
    // cout << "子串出现的次数：" << endl << "请输入字符串:" << endl;
    // cin >> str;
    // cout << "请输入子串：" << endl;
    // cin >> subStr;
    // char *ptr1 = str, *ptr2 = subStr;
    // int count = 0;
    // while( *ptr1 != '\0'){
    //     if( *ptr1 == *ptr2 ){
    //         ptr2++;
    //         if(*ptr2 == '\0'){
    //             count++;
    //             ptr2 = subStr;
    //         }
    //     }else{
    //         ptr2 = subStr;
    //     }
    //     ptr1++;
    // }
    // cout << "子串出现的次数为：" << count << endl;
    // 20.时间函数
    // time_t rawtime;
    // struct tm * timeinfo;
    // time(&rawtime);
    // timeinfo = localtime(&rawtime);
    // cout << asctime( timeinfo );                        //按照格式打印时间

    // 21.反转整数
    // int number, reverseNum = 0;
    // cout << "输入要翻转的整数：";
    // cin >> number;
    // int n;
    // while( number != 0 ){
    //     n = number%10;                                  //取个位
    //     reverseNum = reverseNum*10 + n;                 //添加到reverse 
    //     number = number / 10;                           
    // }
    // cout << "翻转后的整数为：" << reverseNum;

    // 22.移动数组
    // int n;
    // cout << "输入数组大小：";
    // cin >> n;
    // int array[n];
    // cout << "以次输入数组元素:";
    // for(int i = 0; i < n; i++)  cin >> array[i];
    // int m;
    // cout << "输入移动的位数:";
    // cin >> m;

    // int buff[m];
    // for(int i = 0; i < m; i++) buff[i] = array[n-m+i];          //备份后ｍ个元素
    // for(int i = 0; i < n-m; i++) array[n-1-i] = array[n-1-m-i]; //移动
    // for(int i = 0; i < m; i++) array[i] = buff[i];              //还原前ｍ个元素
    // for(int i = 0; i < n; i++) cout << array[i] << ", ";        //打印移动后的数组

    // 23.输出杨辉三角
    int line = 10;
    int array[100];
    array[0] = 1;
    for(int i = 0; i < line; i++){
        for(int j = 0; j < i+1; j++){
            if(j == 0)  array[j] = 1;
            else if(j == i) array[j] = 1;
            else array[j] = array[j-1] + array[j];
            cout << array[j] << " ";
        }
        cout << endl;
    }
}

