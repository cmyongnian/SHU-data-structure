//课程类
#include"CrossNode.h"
#include <string>

template<class ElemType>
class Course
{
public:
	//数据域
	string num;         //课程号
	string name;        //课程名称
	int credit;        //学分
	int capacity;      //当前选课人数
	int Maxcapacity;   //最大人数

	//指针域
	CrossNode<ElemType>* down;

	Course(string cnum = "", string cname = "", int ccredit = 0, int ccapacity = 0, int cmaxcapacity = 45)
	{
		num = cnum; name = cname;credit = ccredit;capacity = ccapacity;Maxcapacity = cmaxcapacity;
	}
	
	bool operator == (const Course& c)
	{
		if (num == c.num && name == c.name) { return true; }
		else { return false; }
	}

	bool operator != (const Course& c)
	{
		if (num != c.num || name != c.name) { return true; }
		else { return false; }
	}

	//重载输入输出
	friend ostream& operator<<(ostream& os, const Course<ElemType>& c) {
		os << "课程号：";
		os << c.num;
		os << "  课程名称：";
		os << c.name;
		os << "  学分：";
		os << c.credit << endl;
		os << " 课程容量：";
		os << c.Maxcapacity << endl;

		return os;
	}

	friend istream& operator>>(istream& is, Course<ElemType>& c) {
		cout << "请输入该课程的课程号、课程名、学分：";
		is >> c.num;
		is >> c.name;
		is >> c.credit;
		return is;
	}
};
