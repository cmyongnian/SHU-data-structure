#include"YYKVector.h"

#include<iostream>
using namespace std;
class bad {
		 public:
			 bool operator==(const bad& x)throw(int) { throw - 1; }
			 bool operator!=(const bad& x)throw(int) { throw - 1; }
			 bool operator>(const bad& x)throw(int) { throw - 1; }
			 bool operator>=(const bad& x)throw(int) { throw - 1; }
			 bool operator<(const bad& x)throw(int) { throw - 1; }
			 bool operator<=(const bad& x)throw(int) { throw - 1; }
			 bad operator+(const double& x)throw(int) { throw - 1; }
			 bad& operator+=(const double& x)throw(int) { throw - 1; }
			 bad operator*(const double& x)throw(int) { throw - 1; }
			 bad& operator*=(const double& x)throw(int) { throw - 1; }
			 bad operator+(const bad& x)throw(int) { throw - 1; }
			 bad& operator+=(const bad& x)throw(int) { throw - 1; }
			 bad operator*(const bad& x)throw(int) { throw - 1; }
			 bad& operator*=(const bad& x)throw(int) { throw - 1; }
		 };

int main() {

	int a0[4] = { 1,2,3,4 };
	int b0[1] = { 5 };
	int c0[4] = { 4,3,2,1 };
	
	YYKVector<int> c(c0, 4),e;
	YYKVector<int> f(a0, 4);
	try {
		cout << "���Թ��캯���쳣������nΪ����" << endl;
		YYKVector<int> m(a0, -5);
	    }
	catch (int d) {
		if (d == 0) cout << "���캯���쳣������nΪ����" << endl;
	}

		cout << "�������죬a=[1,2,3,4]��b=[5]" << endl;
		YYKVector<int> a(a0, 4);
		YYKVector<int> b(b0, 1);
		cout << "���a��n��ֵ" << endl;
		cout << a.N() << endl;
		try
		{
			cout << "���Բ��뺯���쳣������nΪ������Խ��" << endl;
			a.ins(b, -1);
		}
		catch (int d)
		{
			if (d == 2) cout << "���뺯���쳣������nΪ������Խ��" << endl;
		}
		try
		{
			a.ins(b, 5);
		}
		catch (int d)
		{
			if (d == 2) cout << "���뺯���쳣������nΪ������Խ��" << endl;
		}
		cout << "���Բ��뺯��,����λ��Ϊ0��ͷ�壩" << endl;
		a.ins(b);
		cout << a << endl;
		try
		{
			cout << "����ɾ�������쳣������nΪ������Խ��" << endl;
			a.del(1, -1);
		}
		catch (int d)
		{
			if (d == 3) cout << "ɾ�������쳣������nΪ������Խ��" << endl;
		}
		try
		{
			a.del(6, 1);
		}
		catch (int d)
		{
			if (d == 3) cout << "ɾ�������쳣������nΪ������Խ��" << endl;
		}
		cout << "����ɾ������,ɾ��λ��Ϊ3" << endl;
		a.del(3, 100);
		cout << a << endl;
		cout << "�����滻����,�滻λ��Ϊ1���ڶ��" << endl;
		a.rep(b, 1);
		cout << a << endl;
		try {
			cout << "����ȡ�Ӵ������쳣������nΪ������Խ��" << endl;
			a.slice(-1, 3);
		}
		catch (int d)
		{
			if (d == 4) cout << "ȡ�Ӵ������쳣������nΪ������Խ��" << endl;
		}
		try
		{
			cout << "����ȡ�Ӵ�����,ȡ�ڶ��������" << endl;
			cout << "a=" << a << endl;
			e = a.slice(1, 2);
			cout << e  << endl;
		}
		catch (int d)
		{
			if (d == 4) cout << "ȡ�Ӵ������쳣������nΪ������Խ��" << endl;
			if (d == 6) cout << "[ ]�����쳣�����븺����Խ��" << endl;
		}
		
		try {
			cout << "����[ ]�����쳣�����븺����Խ��(����ֵΪa[-1],a[10])" << endl;
			a[-1];
		}
		catch (int d)
		{
			if (d == 6) cout << "[ ]�����쳣�����븺����Խ��" << endl;
		}
		try {
			a[10];
		}
		catch (int d)
		{
			if (d == 6) cout << "[ ]�����쳣�����븺����Խ��" << endl;
		}
		cout << "�����2��a[1],��ȷ���Ϊ5�������a" << endl;
		cout << a << endl;
		cout << a[1] << endl;
		cout << "���Ը�ֵ����c[4]={4,3,2,1}" << endl;
		a = c;
		cout << a << endl;
		cout << "���������ȴ�С" << endl;
		cout << "����ά����ͬ����(a>=b)" << endl;
		try
		{
			a >= b;
		}
		catch (int d)
		{
			if (d == -1)
				cout<<"ά����ͬ"<<endl;
		}
		
		cout << "����ά����ͬ������a��ֵ{1,2,3,4}" << endl;
		a = f;
		
		cout << "a=" << a << endl;
		cout << "����a==c,a>=c,a<=c,a>c,a<c,a!=c";
	
		cout << (a == c) << (a >= c) << (a <= c) << (a > c) << (a < c)<<(a != c) <<endl ;

		cout<<"����a*b"<<endl;
		try {
			cout << (a * b);
		    }
		catch (int d)
		{
			if (d == -1)
				cout << "ά����ͬ" << endl;
		}
		cout << "����a*c(��ˣ����Ϊ������4,6,6,4��,���Ϊ(a * c))" << endl;
		try {
			cout << (a * c);
		}
		catch (int d)
		{
			if (d == -1)
				cout << "ά����ͬ" << endl;
		}
		cout << "����a*=c(���Ϊa)" << endl;
		 (a *= c);
		 cout << a<<endl;
		 

			 bad zx1, zx2;
			 YYKVector<bad>z1(&zx1, 1), z2(&zx2, 1);
			 try {
				 cout << (z1 > z2) << endl;
			 }
			 catch (int& bug) {
				 if (bug == 0)cout << "���󳤶ȴ���\n";
				 if (bug == -1)cout << "�±�Խ��\n";
				 if (bug == -2)cout << "���������ݳ�Ա�޷��Ƚϴ�С\n";
				 if (bug == -3)cout << "���������ݳ�Ա�޷�����\n";
				 if (bug == -4)cout << "���������ݳ�Ա�޷����\n";
				 if (bug == -5)cout << "���������ݳ�Ա�޷�����\n";
				 if (bug == -6)cout << "���������ݳ�Ա�޷����\n";
			 }
			 try {
				 z1 += 5;
			 }
			 catch (int& bug) {
				 if (bug == 0)cout << "���󳤶ȴ���\n";
				 if (bug == -1)cout << "�±�Խ��\n";
				 if (bug == -2)cout << "���������ݳ�Ա�޷��Ƚϴ�С\n";
				 if (bug == -3)cout << "���������ݳ�Ա�޷�����\n";
				 if (bug == -4)cout << "���������ݳ�Ա�޷����\n";
				 if (bug == -5)cout << "���������ݳ�Ա�޷�����\n";
				 if (bug == -6)cout << "���������ݳ�Ա�޷����\n";
			 }
			 try {
				 z1 += z2;
			 }
			 catch (int& bug) {
				 if (bug == 0)cout << "���󳤶ȴ���\n";
				 if (bug == -1)cout << "�±�Խ��\n";
				 if (bug == -2)cout << "���������ݳ�Ա�޷��Ƚϴ�С\n";
				 if (bug == -3)cout << "���������ݳ�Ա�޷�����\n";
				 if (bug == -4)cout << "���������ݳ�Ա�޷����\n";
				 if (bug == -5)cout << "���������ݳ�Ա�޷�����\n";
				 if (bug == -6)cout << "���������ݳ�Ա�޷����\n";
			 }
			 try{
				 z1 *= 5;
		 }
		 catch (int& bug) {
			 if (bug == 0)cout << "���󳤶ȴ���\n";
			 if (bug == -1)cout << "�±�Խ��\n" ;
			 if (bug == -2)cout << "���������ݳ�Ա�޷��Ƚϴ�С\n" ;
			 if (bug == -3)cout << "���������ݳ�Ա�޷�����\n";
			 if (bug == -4)cout << "���������ݳ�Ա�޷����\n";
			 if (bug == -5)cout << "���������ݳ�Ա�޷�����\n";
			 if (bug == -6)cout << "���������ݳ�Ա�޷����\n";
		 }
		 try {
			 z1 *=z2;
		 }
		 catch (int& bug) {
			 if (bug == 0)cout << "���󳤶ȴ���\n";
			 if (bug == -1)cout << "�±�Խ��\n";
			 if (bug == -2)cout << "���������ݳ�Ա�޷��Ƚϴ�С\n";
			 if (bug == -3)cout << "���������ݳ�Ա�޷�����\n";
			 if (bug == -4)cout << "���������ݳ�Ա�޷����\n";
			 if (bug == -5)cout << "���������ݳ�Ա�޷�����\n";
			 if (bug == -6)cout << "���������ݳ�Ա�޷����\n";
		 }
	return 0;
}


