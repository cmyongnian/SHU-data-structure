#pragma once

#include "CrossNode.h"
#include <string>

template<class ElemType>
class Student
{
public:
	// ���ݳ�Ա:
	int stunumber;
	string name;
	int coursecapacity;
	CrossNode<ElemType>* right;
	// ���캯��:
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

	//�����������
	friend ostream& operator<<(ostream& os, const Student<ElemType>& s) {
		os << "��ѧ��ѧ��Ϊ��";
		os << s.stunumber << endl;
		os << "��ѧ������Ϊ��";
		os << s.name << endl;
		return os;
	}

	friend istream& operator>>(istream& is, Student<ElemType>& s) {
		cout << "������ѧ����ѧ�ź�������";
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
