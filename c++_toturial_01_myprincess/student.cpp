#include "student.h"


student::student(/* args */)
{
    cout << "student的无参构造被调用" << endl;
    setName("无名氏");
    setDesc("nothing");
    cout << "姓名：" << getName() << endl;
    cout << "描述：" << getDesc() << endl;
    initScores();
}


student::student(int age)
{
    cout << "student的参数构造被调用：student(int age)" << endl;
    setAge(age);
    cout << "姓名：" << getName() << endl;
    cout << "描述：" << getDesc() << endl;
    cout << "年龄：" << getAge() << endl;
    initScores();
}


student::student(string name, string desc) : _name(name),_desc(desc)
{
    cout << "student的参数构造被调用：student(string name, string desc)" << endl;
    // setName(name);
    // setDesc(desc);
    cout << "姓名：" << getName() << endl;
    cout << "描述：" << getDesc() << endl;
    initScores();
}


void student::initScores(){
    this->scores = new float[1];
    this->scoreCount = 0;
}

void student::addScore(float score){
    *((this->scores) + scoreCount) = score;
    scoreCount++;

    float *newScores = new float[scoreCount + 1];
    memcpy(newScores, scores, sizeof(float)*scoreCount);
    float *oldScores = scores;
    this->scores = newScores;
    delete oldScores;

    // this->scores[this->scoreCount - 1] = score;
    // //1.创建一个新数组，分配scoreCount + 1个空间
    // //2.复制原数组中的内容到新数组中
    // //3.scoreCount总数+1
    // //4.scores指向新数组

    // float* newScores = new float[scoreCount + 1];
    // float* oldScores = scores;
    // memcpy(newScores, scores, sizeof(float) * scoreCount);
    // scoreCount++;
    // scores = newScores;
    // delete oldScores;    
}

void student::showInfo(){
     cout << _desc << _name << endl; 
     for(int i = 0; i < scoreCount - 1; i++){
         cout << *(scores + i) << "\t" << endl;
     }
}
float student::getTotal(){
    float sum = 0;
    for(int i = 0; i < scoreCount; i++){
        sum += scores[i];
    }
    return sum;
}
// void myshow(const student*);
// void myshow(const student* thiz){
//     thiz->addScore(90.0);
// }

/**
 * 返回学霸对象
 * @param otherstu 要对比的另外一个学生对象
 * @return 返回总分比较大的那个学生对象
 */
// student& student::getSuperScholar(student& otherstu){
//     //分别计算两个学生的
//     if(this->getTotal() > otherstu.getTotal()){
//         return *this;   //返回当前对象的引用
//     }else{
//         return otherstu;
//     }
// }

student::~student()
{
    cout << _name << "被释放" << endl;
    delete this->scores;
}