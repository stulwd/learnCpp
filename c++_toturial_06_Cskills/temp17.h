#ifndef TEMP17_H
#define TEMP17_H

#include <iostream>
#include <cstring>

using namespace std;

typedef struct
{
    /* data */
    int A;
    int B;
    int C;

}grade;


class student
{
private:
    /* data */
    string id;
    string name;
    grade score;

public:
    student(/* args */);
    ~student();
    student* printInfo();
    string getName(){return name;};
    string getId(){return id;};
    grade getScore(){return score;};
};

student::student(/* args */)
{
    cout << "请输入学生姓名、id、三门课的成绩（A B C）：";
    cin >> name >> id >> score.A >> score.B >> score.C;
}

student* student::printInfo(){
    //cout << name << "\t" << id << "\t" << score.A << "\t" << score.B << "\t" << score.C << "\t";
    return this;
}


student::~student()
{
}


#endif