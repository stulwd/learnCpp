#include <iostream>
#include <ctime>
#include <cstdlib>
#include "arrayOp.h"
#include "func.h"
#include "landOwnerV2.h"
using namespace std;

#define s(num) num * num
inline int S(int ); //内联
int S(int num){
    return num * num;
}

int* fun(){
    int num = 99;
    int* n1 = &num;
    cout << "num 的地址：" << n1 << endl;
    return n1;
}
void test(){
    int x = 1;
    int y = 2;
    int z = 3;
    int a = 4;
    int b = 5;
    int c = 6;
    int d = 7;
    cout <<  "x的地址：" << &x << endl <<  "y的地址：" << &y << endl <<  "z的地址：" << &z << endl
     <<  "a的地址：" << &a << endl <<  "b的地址：" << &b << endl <<  "c的地址：" << &c << endl <<  "d的地址：" << &d << endl;
}
/**
 *  @param toName 给谁发送信息
 *  @param content 发送的内容
 *  @return 返回拼接的字符串  
 */
string chatTo(const string& toName, const string& content);
string chatFrom(const string& fromName, const string& content);
string chatTo(const string& toName, const string& content){
    
    string msg;
    msg = "※　你悄悄对 [" + toName + "] 说： " + content;
    return msg;
}

string chatFrom(const string& fromName = "系统", const string& content = "正在忙碌，请稍后..."){
    
    string msg;
    msg = "※ [" + fromName +  "]悄悄对你说" + content;
    return msg;
}

/**
 * 函数重载
 * */
void sort(int* , int);
void sort(float* , int);
void sort(double* , int);
void sort(int *array, int len){
    int *ptr = array;
    int temp;
    for(int i = 0; i < len - 1; i++ ){
        for(ptr = array; ptr <= array + (len - 2) - i; ptr++){
            if(*ptr >= *(ptr+1) ){
                temp = *ptr;
                *ptr = *(ptr + 1);
                *(ptr + 1) = temp;
            }
        }
    }
}
void sort(float *array, int len){
    float *ptr = array;
    float temp;
    for(int i = 0; i < len - 1; i++ ){
        for(ptr = array; ptr <= array + (len - 2) - i; ptr++){
            if(*ptr >= *(ptr+1) ){
                temp = *ptr;
                *ptr = *(ptr + 1);
                *(ptr + 1) = temp;
            }

        }
    }
}
void sort(double *array, int len){
    double *ptr = array;
    double temp;
    for(int i = 0; i < len - 1; i++ ){
        for(ptr = array; ptr <= array + (len - 2) - i; ptr++){
            if(*ptr >= *(ptr+1) ){
                temp = *ptr;
                *ptr = *(ptr + 1);
                *(ptr + 1) = temp;
            }

        }
    }
}

void bubbleSort(float* array, int len){
    for(int i = 0; i < len - 1; i++){
        for(int j = 0; j < len - i - 1; j++){
            if( *(array+j) > *(array+j+1) ){
                float temp = *(array+j);
                *(array+j) = *(array+j+1);
                *(array+j+1) = temp;
            }
        }
    }
}
//比较排序法
void compareSort(float * array, int len){
    for(int i = 0; i < len - 1; i++){
        for(int j = i + 1; j < len; j++){
            if(*(array+i) > *(array+j)){
                //swap
                float temp = *(array+i);
                *(array+i) = *(array+j);
                *(array+j) = temp;
            }
        }
    }
}
int main(){
    //冒泡排序
    int array1[10] = {10,9,8,7,6,5,4,3,2,1};
    float array2[10] = {10.1,9.2,8.3,7.4,6.3,5.1,4.5,3.6,2.1,1.1};
    double array3[10] = {10.3,9.5,8.5,7.6,6.7,5.8,4.9,3.0,2.3,1.3};
    
    //排序前
    for(int i = 0; i < 10; i++){
        cout << array2[i] << " ";
    }
    cout << endl;
    //排序后
    sort(array2, 10);
    for(int i = 0; i < 10; i++){
        cout << array2[i] << " ";
    }
    cout << endl;

    
    //聊天ＡＰＰ
    string toName, content, chatMsg, fromName;
    cout << "请输入对方名称:";
    getline(cin, toName);
    fromName = toName;
    cout << "请输入发送给对方的聊天信息：";
    getline(cin, content);
    chatMsg = chatTo(toName, content);
    cout << chatMsg << endl;

    cout << "请输入对方发送给你的聊天信息：";
    getline(cin, content);
    chatMsg = chatFrom();
    cout << chatMsg << endl;
    chatMsg = chatFrom(fromName, content);
    cout << chatMsg << endl;


    //修改原变量的值，引用值也被修改
    int num = 100;
    int& num1 = num;
    num += 1;
    cout << "num1的值为：" << num1 << endl;
    /*返回目标对象为局部变量的指针或引用都是危险的操作*/
    int* n2 = fun(); 
    test();
    cout << *n2 << endl << endl; 
    /*test area*/
    string array[3][5] = {
        {"fda","ads","fdas","ads","fdas"},
        {"fda","ads","fdas","ads","fdas"},
        {"fda","ads","fdas","ads","fdas"}
    };
    show(array,2,3);    
    cout << "2的３次方＝" << power(2, 3) << endl;
    // int power(int, int);
    //　声明函数指针
    int (*funcPtr)(int, int);
    funcPtr = power;
    //调用函数指针
    cout << funcPtr(2, 3) << endl;

    cout << "5+5的平方：" << s((5+5)) << endl;  //5+5必须加（）
    cout << "5+5的平方：" << S(5+5) << endl;
    


    /*父亲姓名*/
    string value_father_name;
    /*女儿姓名*/
    string value_daughter_name;
    /*女儿生日的月份*/
    int value_birth_month = 6;
    /*女儿生日的日期*/

    int value_birth_date = 6;
    /*女儿的星座*/
    string value_daughter_constell;
    /*女儿的五项基本信息: 体力、智力、 魅力、道德、气质*/
    int value_array_baseinfo[5]; //动态分配内存的数组
    /*采用数组指针穿参*/
    // int (*p_array)[5] = &value_array_baseinfo;           //一维数组前加地址符＝数组指针
    // input(&value_array_baseinfo, 5);
    // print(&value_array_baseinfo, 5);
    // /*指针传参*/
    input(value_array_baseinfo, 5);
    print(value_array_baseinfo, 5);
    string value_array_baseinfo_names[5] = {
        "体力",
        "智力",
        "魅力",
        "道德",
        "气质"
        };//五项基本属性名
    int value_daughter_gold = 500; //金钱属性
    /*星座二维数组*/
    string constell_names[12][2] = {
        {"山羊座", "水瓶座"}, //一月
        {"水瓶座", "双鱼座"}, //二月
        {"双鱼座", "白羊座"}, //三月
        {"白羊座", "金牛座"}, //四月
        {"金牛座", "双子座"}, //五月
        {"双子座", "巨蟹座"}, //六月
        {"巨蟹座", "狮子座"}, //七月
        {"狮子座", "处女座"}, //八月
        {"处女座", "天秤座"}, //九月
        {"天秤座", "天蝎座"}, //十月
        {"天蝎座", "射手座"}, //十一月
        {"射手座", "山羊座"} //十二月
    }; 
    /*跨星座日期*/
    int constell_dates[] {20, 19, 21, 20, 21, 22, 23, 23, 23, 24, 23, 22};

    /*临时变量*/
    int choice, temp1, temp2, temp3, temp4;

    cout << "父亲的姓名：";
    cin >> value_father_name;
    cout << "女儿的姓名：";
    cin >> value_daughter_name;
    cout << "女儿的生日：（mm dd）";
    cin >> value_birth_month >> value_birth_date;
    value_daughter_constell = constell_names[ value_birth_month-1 ][ value_birth_date/constell_dates[ value_birth_month-1 ]];

    cout << "女儿的信息：" << endl;
    cout << "姓名：" << value_daughter_name << endl;
    cout << "生日：1695-" << value_birth_month << "-" << value_birth_date << endl;
    cout << "星座" << value_daughter_constell << endl;

    if( value_daughter_constell == "山羊座"){
        value_array_baseinfo[0] = 80; value_array_baseinfo[1] = 15; value_array_baseinfo[2] = 15; value_array_baseinfo[3] = 80; value_array_baseinfo[4] = 80; 
    }else if(value_daughter_constell == "水瓶座"){
        value_array_baseinfo[0] = 80; value_array_baseinfo[1] = 15; value_array_baseinfo[2] = 15; value_array_baseinfo[3] = 80; value_array_baseinfo[4] = 80; 
    }else if(value_daughter_constell == "双鱼座"){
        value_array_baseinfo[0] = 80; value_array_baseinfo[1] = 15; value_array_baseinfo[2] = 15; value_array_baseinfo[3] = 80; value_array_baseinfo[4] = 80; 
    }else if(value_daughter_constell == "白羊座"){
        value_array_baseinfo[0] = 80; value_array_baseinfo[1] = 15; value_array_baseinfo[2] = 15; value_array_baseinfo[3] = 80; value_array_baseinfo[4] = 80; 
    }else if(value_daughter_constell == "金牛座"){
        value_array_baseinfo[0] = 80; value_array_baseinfo[1] = 15; value_array_baseinfo[2] = 15; value_array_baseinfo[3] = 80; value_array_baseinfo[4] = 80; 
    }else if(value_daughter_constell == "双子座"){
        value_array_baseinfo[0] = 80; value_array_baseinfo[1] = 15; value_array_baseinfo[2] = 15; value_array_baseinfo[3] = 80; value_array_baseinfo[4] = 80; 
    }else if(value_daughter_constell == "巨蟹座"){
        value_array_baseinfo[0] = 80; value_array_baseinfo[1] = 15; value_array_baseinfo[2] = 15; value_array_baseinfo[3] = 80; value_array_baseinfo[4] = 80; 
    }else if(value_daughter_constell == "狮子座"){
        value_array_baseinfo[0] = 80; value_array_baseinfo[1] = 15; value_array_baseinfo[2] = 15; value_array_baseinfo[3] = 80; value_array_baseinfo[4] = 80; 
    }else if(value_daughter_constell == "处女座"){
        value_array_baseinfo[0] = 80; value_array_baseinfo[1] = 15; value_array_baseinfo[2] = 15; value_array_baseinfo[3] = 80; value_array_baseinfo[4] = 80; 
    }else if(value_daughter_constell == "天秤座"){
        value_array_baseinfo[0] = 80; value_array_baseinfo[1] = 15; value_array_baseinfo[2] = 15; value_array_baseinfo[3] = 80; value_array_baseinfo[4] = 80; 
    }else if(value_daughter_constell == "天蝎座"){
        value_array_baseinfo[0] = 80; value_array_baseinfo[1] = 15; value_array_baseinfo[2] = 15; value_array_baseinfo[3] = 80; value_array_baseinfo[4] = 80; 
    }else if(value_daughter_constell == "射手座"){
        value_array_baseinfo[0] = 80; value_array_baseinfo[1] = 15; value_array_baseinfo[2] = 15; value_array_baseinfo[3] = 80; value_array_baseinfo[4] = 80; 
    }

    for(int i=0; i<5; i++){
        cout << value_array_baseinfo_names[i] << value_array_baseinfo[i] << '\t';
    }
    cout << endl;

    /*游戏从1659年开始*/
    for(int year = 1659; year <= 1659+7; year++){
        for(int month = (year == 1659) ? value_birth_month : 1; month <= 12; month++ ){
            //判断本月是否是女儿生日
            if( month == value_birth_month){
                cout << "本月是" << value_daughter_name << "生日，要不要送礼物？" << endl;
                //根据用户输入进行判断
            }
            //显示游戏主菜单
            cout << "\n1、查看状态\n2、安排行程\n3、亲自谈话\n4、存档\n5、读档" << endl;
            cin >> choice;
            switch(choice){
                case 1://查看状态
                    cout << "女儿的信息：" << endl;
                    cout << "姓名：" << value_daughter_name << endl;
                    cout << "生日：1695-" << value_birth_month << "-" << value_birth_date << endl;
                    cout << "星座：" << value_daughter_constell << endl;
                    cout << "金币：" << value_daughter_gold << endl;
                    //打印核心属性
                    for(int i = 0; i < 5; i++){
                        cout << value_array_baseinfo_names[i] << ":"  << value_array_baseinfo[i];
                        //计算实心方框的数量
                        int solidCount = value_array_baseinfo[i] / 10;
                        //打印
                        for(int j = 0; j < 10; j++){
                            if( j < solidCount )
                                cout << "■";
                            else cout << "□";
                        }
                        cout << endl;
                    }
                    break;
                case 2:{ //安排行程:一个月最多三次
                    string month_parts[3] = {"上旬","中旬","下旬"};
                    for(int i = 0; i < 3; i++){
                        cout << "--" << month << "--" << month_parts[i] << endl;
                        cout << "1、学习武艺\n2、上私塾\n3、学习礼法\n4、出城修行\n5、打工赚钱" << endl;
                        cout << "请选择：";
                        cin >> choice;

                        srand(time(NULL));
                        if(choice == 1){ // +体力 +魅力 -金钱
                            value_array_baseinfo[0] += temp1 = rand() % 10;
                            value_array_baseinfo[2] += temp2 = rand() % 10;
                            value_daughter_gold -= temp3 = rand() % 51;
                            cout << "学习张无忌好榜样！！！！";
                            cout << "体力+" << temp1 << "魅力+" << temp2 << "金钱－" << temp3 << endl;
                        }else if(choice == 2){ // +智力 +魅力 -金钱
                            value_array_baseinfo[1] += temp1 = rand() % 10;
                            value_array_baseinfo[2] += temp2 = rand() % 10;
                            value_daughter_gold -= temp3 = rand() % 51;
                            cout << "学习孔子好榜样！！！！";
                            cout << "智力+" << temp1 << "魅力+" << temp2 << "金钱－" << temp3 << endl;                        
                        }else if(choice == 3){ // +道德 -金钱
                            value_array_baseinfo[3] += temp1 = rand() % 10;
                            value_daughter_gold -= temp3 = rand() % 51;
                            cout << "学习礼数好榜样！！！！";
                            cout << "道德+" << temp1 << "金钱－" << temp3 << endl;                        
                        }else if(choice == 4){ // +气质　-金钱
                            value_array_baseinfo[4] += temp2 = rand() % 10;
                            value_daughter_gold -= temp3 = rand() % 51;
                            cout << "出城修行好榜样！！！！";
                            cout << "气质+" << temp2 << "金钱－" << temp3 << endl;                        
                        }else if(choice == 5){// ＋金钱
                            value_daughter_gold += temp3 = rand() % 101;
                            cout << "努力赚钱好榜样！！！！";
                            cout << "金钱+" << temp3 << endl;                        
                        }
                    }
                    break;
                }
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                default:
                    break;

                

                
            }
        }
    }
}
