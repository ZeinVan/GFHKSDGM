//
// Created by Anthony Wong on 2023/4/7.
//
/*
建立一个学生类Student，学生信息包括学号(id)、姓名(name)、性别(gender)、分数(score)。
(1) 建立类Student的带参构造函数及复制构造函数；
(2) 建立一个显示学生全部信息的成员函数；
(3) 创建主程序，从键盘输入5个学生的信息，按照分数进行排序，输出每个学生的信息；
(4) 在主程序中显示所有性别为男性的学生信息；
(5) 统计全班同学的平均成绩，并在主程序中显示输出。
*/
//请用您的姓名全拼音+学号后三位命名您的源程序文件，如：zhengshuo821.cpp
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

class Student {
private:
    int id;
    string name;
    char gender;
    float score;
public:
    Student(int id, string name, char gender, float score) {
        this->id = id;
        this->name = name;
        this->gender = gender;
        this->score = score;
    }

    Student(const Student& s) {
        this->id = s.id;
        this->name = s.name;
        this->gender = s.gender;
        this->score = s.score;
    }

    void display() {
        cout << "ID: " << id << "\tName: " << name << "\t\tGender: " << gender << "\tScore: " << score << endl;
    }

    float getScore() const {
        return score;
    }

    char getGender() const {
        return gender;
    }
};

bool compareStudent(const Student& s1, const Student& s2) {
    return s1.getScore() > s2.getScore();
}

int main() {
    vector<Student> students;
    students.reserve(5);

    for (int i = 1; i <= 5; i++) {
        int id;
        string name;
        char gender;
        float score;
        cout << "Input the information of students " << i << ":" << endl;
        cout << "ID Name Gender(m/M/F/f) Score:"<<endl;
        cin >> id>>name>>gender>>score;
        Student s(id, name, gender, score);
        students.push_back(s);
    }

    sort(students.begin(), students.end(), compareStudent);

    cout <<endl<< "After Sorted:" << endl;
    for (Student s : students) {
        s.display();
    }

    cout << endl << "Male student information:" << endl;
    for (Student s : students) {
        if (s.getGender() == 'M'||s.getGender() == 'm') {
            s.display();
        }
    }

    float totalScore = 0;
    for (Student s : students) {
        totalScore += s.getScore();
    }
    float avgScore = totalScore / students.size();
    cout <<endl<< "Average score: " << avgScore << endl;

    return 0;
}
