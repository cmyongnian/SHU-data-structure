#pragma once

#include "CrossNode.h"
#include <string>

template<class ElemType>
class Student
{
public:
	// 数据成员:
	int stunumber;
	string name;
	int coursecapacity;
	CrossNode<ElemType>* right;
	// 构造函数:
	Student(int Stunumber = 0, string Name = "");

	bool operator ==(const Student& S)
	{
		if (stunumber == S.stunumber && name == S.name)
			return true;
		else
			return false;
	}

	bool operator !=(const Student& S)
	{
		if (stunumber != S.stunumber || name != S.name)
			return true;
		else
			return false;
	}

	//重载输入输出
	friend ostream& operator<<(ostream& os, const Student<ElemType>& s) {
		os << "该学生学号为：";
		os << s.stunumber << endl;
		os << "该学生姓名为：";
		os << s.name << endl;
		return os;
	}

	friend istream& operator>>(istream& is, Student<ElemType>& s) {
		cout << "请输入学生的学号和姓名：";
		is >> s.stunumber;
		is >> s.name;
		return is;
	}
};


template<class ElemType>
Student<ElemType>::Student(int Stunumber, string Name)
{
	stunumber = Stunumber;
	name = Name;
	coursecapacity = 0;
}
