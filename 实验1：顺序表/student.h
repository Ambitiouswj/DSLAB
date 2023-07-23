#pragma once
#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#define endl '\n'
using namespace std;

class Student 
{
private:
    string name;
    string stuNumber;
    int score[3];
    int sum;
public:
    Student() {}
    Student(string name, string number, int math, int english, int program) 
    {
        this->name = name;
        this->stuNumber = number;
        score[0] = math;
        score[1] = english;
        score[2] = program;
        sum = math + english + program;
    }
    bool operator<(const Student& s) const
    {
        if (sum == s.sum) 
        {
            if (score[0] != s.score[0]) return score[0] < s.score[0];
            else if (score[1] != s.score[1]) return score[1] < s.score[1];
            else return score[2] < s.score[2];
        }
        return sum < s.sum;
    }
    bool operator>(const Student& s) const 
    {
        if (sum == s.sum) 
        {
            if (score[0] != s.score[0]) return score[0] > s.score[0];
            else if (score[1] != s.score[1]) return score[1] > s.score[1];
            else return score[2] > s.score[2];
        }
        return sum > s.sum;
    }
    bool operator==(const Student& s) 
    {
        // ֻͨ��ѧ�űȽ�
        return stuNumber == s.stuNumber;
    }
    friend ostream& operator<<(ostream&, Student s);
};



ostream& operator<<(ostream& os, Student s) 
{
    cout << "������" << s.name << ' ';
    cout << "ѧ�ţ�" << s.stuNumber << ' ';
    cout << "��ѧ��" << s.score[0] << ' ';
    cout << "Ӣ�" << s.score[1] << ' ';
    cout << "����" << s.score[2] << ' ';
    cout << "�ܷ֣�" << s.sum << endl;
    return cout;
}
