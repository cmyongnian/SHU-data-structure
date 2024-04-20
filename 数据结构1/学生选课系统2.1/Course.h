//�γ���
#include"CrossNode.h"
#include <string>

template<class ElemType>
class Course
{
public:
	//������
	string num;         //�γ̺�
	string name;        //�γ�����
	int credit;        //ѧ��
	int capacity;      //��ǰѡ������
	int Maxcapacity;   //�������

	//ָ����
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

	//�����������
	friend ostream& operator<<(ostream& os, const Course<ElemType>& c) {
		os << "�γ̺ţ�";
		os << c.num;
		os << "  �γ����ƣ�";
		os << c.name;
		os << "  ѧ�֣�";
		os << c.credit << endl;
		os << " �γ�������";
		os << c.Maxcapacity << endl;

		return os;
	}

	friend istream& operator>>(istream& is, Course<ElemType>& c) {
		cout << "������ÿγ̵Ŀγ̺š��γ�����ѧ�֣�";
		is >> c.num;
		is >> c.name;
		is >> c.credit;
		return is;
	}
};
