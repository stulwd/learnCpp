#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

#include <iostream>

using namespace std;

void calcCuboid();      //计算长方体体积
void calcCylinder();    //计算圆柱体体积
void calcCone();        //计算圆锥体体积
int power(int, int);   //求幕
double addition(double, double);
double substraction(double, double);
double multiplication(double, double);
double division(double, double);

double addition(double x, double y){
    return x + y;
}
double substraction(double x, double y){
    return x - y;
}
double multiplication(double x, double y){
    return x * y;
}
double division(double x, double y){
    if( y == 0 ){
        cout << "除数不能为０";
        return 0;
    }
    return x / y;
}

int power(int x, int n){
    int result = 1;
    for(int i = 1; i <= n; i++){
        result *= x;
    }
    return result;
}

// int main()
// {
//     int choice = -1;
//     while(choice){
//         cout << "１、计算长方体体积" << endl;
//         cout << "２、计算圆柱体体积" << endl;
//         cout << "３、计算圆锥体体积" << endl;
//         cout << "０、退出" << endl;
//         cout << "请选择：" << endl;
//         cin >> choice;
//         switch(choice){
//             case 1: calcCuboid(); break;
//             case 2: calcCylinder(); break;
//             case 3: calcCone(); break;
//         }
//     }
//     cout << "感谢使用本软件！" << endl;
//     return 0;
// }

void calcCuboid(void){
    double len, width, height;  //定义长方体长宽高
    cout << "输入长方体长、宽、高：";
    cin >> len >> width >> height;
    double volume = len * width * height;   //计算体积
    cout << "长方体体积为：" << volume << endl;
}

void calcCylinder(){
    double redius, height;
    cout << "输入圆柱半径、高：";
    cin >> redius >> height;
    double volume = redius * redius * 3.14 * height;
    cout << "圆柱体积为：" << volume << endl;
}

void calcCone(){
    double redius, height;
    cout << "输入圆锥半径、高：";
    cin >> redius >> height;
    double volume = redius * redius * 3.14 * height / 3.0;
    cout << "圆锥体积为：" << volume << endl;
}

#endif