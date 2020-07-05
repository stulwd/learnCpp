#include <iostream>
#include <string>

using namespace std;

class teacher : private string
{
    
private:
    /* data */
    double salary;
public:
    teacher(/* args */){};
    teacher(const string& str):string(str){};
    teacher(int _salary):salary(_salary){};
    ~teacher(){};
    // string name;     //使用组合关系实现，比较简单
    //难点
    const string& getName() const
    {
        //return (const string&)*this;        //自己写出来的
    /*
     *  teacher是由string私有继承而来，所以可以使用强制类型转换，将teacher转换为string类型
     * 为了避免调用构造函数而创建新的对象（使用const string），所以强制转化成了string的引用类型来返回：(const string&)
     * 本方法返回一个引用，指向调用本方法的teacher对象中继承而来的string对象
     * teacher因为继承了string,所以可以理解为本身就是一个string,所以把它转化为string类型的指针，就可以直接访问值
     */
        return (const string&)*this;
    }
    int getLength(){
        return ((const string&)*this).length();

        /***以下这种写法不对***/
        // string str = this->getName();
        // cout << str << endl;
        // cout << sizeof(str) << endl;
        // char *ptr = (char *)&str;
        // // char* ptr = (char *)&(this->getName());
        // int i = 0;
        // while(*(ptr+i) != '\0'){
        //     i++;
        // }
        // return i;
    }
    double getSalary(){return this->salary;};
    void setSalary(double salary){this->salary = salary;};
    
};
