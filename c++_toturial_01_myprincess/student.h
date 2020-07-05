#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class student
{
private:
    /* data */
    string _name;
    string _desc;
    int _age;
    int scoreCount;         //学生成绩个数
    float* scores;          //学生的分数数组

public:
    student(/* args */);
    student(string, string);            //带参构造
    student(int);                       //带参构造
    ~student();

    void setName(string name){ _name = name; };
    string getName(){ return _name; };
    void setDesc(string desc){ _desc = desc; };
    string getDesc(){ return _desc; };
    void setAge(int age){
        if(age < 0) _age = 18;
        else   _age = age; 
    };
    int getAge(){ return _age; };

    void showInfo();
    void initScores();          //初始化学生成绩数组，默认分配一个空间
    void addScore(float);       //向scores数组中添加一个分数

    student& getSuperScholar(student&); //返回学霸对象
    float getTotal();       //获取总分    
};


#endif