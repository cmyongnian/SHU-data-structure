#include"YYKBVector.h"
#include"YYKBString.h"
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
		 friend std::ostream &operator<<(std::ostream &out,const bad& x)throw(int);
	 };
std::ostream &operator<<(std::ostream &out,const bad& x)throw(int){throw -1;}	
void test1()
{
	cout << "-------------------------------------------" << endl;
	cout << "              A.�����ַ�����������" << endl;
	YYKBString s("123789",6), s1("456",3), s2("789",3), s3("147",3), s4("258",3), s5("123456123456",12), s6("112233",6);
	cout << "-------------------------------------------" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "���ȣ�leng()" << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s1.leng() = " << s1.N() << endl;
	cout << "-------------------------------------------" << endl;
	cout << "��insert()" << endl;
	cout << "s2 = " << s2 << '\t' << "s1=" << s1 << endl;
	s2.ins(s1, 2);
	cout << "s2.ins(s1,2) = " << s2 << endl;
	cout << "s3=" << s3 << endl;
	s3.ins(YYKBString("789",3), 2);
	cout << "s.ins('789',2)" << s3 << endl;
	cout << "-------------------------------------------" << endl;
	cout << "��replace()" << endl;
	cout << "s4 = " << s4 << '\t' << "s=" << s << '\t' << "s1=" << s1 << endl;
	s4.rep(s, 1, 2);
	cout << "s4.replace(s,1,2) = " << s4 << endl;
	s.rep(s1, 4, 3);
	cout << "s.replace(s1,4,3)=" << s << endl;
	cout << endl;
	cout << "-------------------------------------------" << endl;
	cout << "ɾdelete()" << endl;
	cout << "s6 = " << s6 << endl;
	s6.del(2, 3);
	cout << "s6.del(2,3) = " << s6 << endl;
	cout << endl;
	cout << "-------------------------------------------" << endl;
	cout << "ȡ�ִ�cut()" << endl;
	cout << "s5=" << s5 << endl;
	cout << "s5.slice(3,5)=" << s5.slice(3, 5) << endl;
	YYKBString ns = YYKBString(s5.slice(8, 6));
	cout << "s5.cut(8,6)=" << ns << endl;
	cout << endl;
	system("pause");
}
void test2()
{
	cout << "-------------------------------------------" << endl;
	cout << "                  B.���Ի��������" << endl;
	cout << "-------------------------------------------" << endl;
	YYKBString str1("00000",5), str2("11111",5), str3("22222",5), str4("33333",5), str5("12345",5);
	cout << "str1=" << str1 << endl;
	cout << "str2=" << str2 << endl;
	cout << "str3=" << str3 << endl;
	cout << "str4=" << str4 << endl;
	cout << "str5=" << str5 << endl;
	cout << endl;
	cout << "-------------------------------------------" << endl;
	cout << "operator+()" << endl;
	cout << "����+�������" << endl;
	cout << "str + str2 = " << str1 << " + " << str2 << " = " << str1 + str2 << endl;
	cout << endl;
	cout << "-------------------------------------------" << endl;
	cout << "operator+=()" << endl;
	cout << "����+=�������" << endl;
	str4 += str1;
	cout << "str4 += str1" << '\t' << "str4=" << str4 << endl;
	cout << endl;
	cout << "-------------------------------------------" << endl;
	cout << "operator[]()" << endl;
	cout << "����operator[]�������" << endl;
	cout << "str5[0]=" << str5[0] << endl;
	cout << "str5[1]=" << str5[1] << endl;
	cout << "str5[2]=" << str5[2] << endl;
	cout << "str5[3]=" << str5[3] << endl;
	cout << "str5[4]=" << str5[4] << endl;
	cout << endl;
	cout << "str5+10="<<str5 + 10<<endl;
	system("pause");
}
void test3()
{
	YYKBString s("123",3), s1("456",3), s2("789",3), s3("147",3), s4("123",3), s5("369",3);
	cout << "-------------------------------------------" << endl;
	cout << "                 C.���ԱȽ����������" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "operator==()  operator!=()" << endl;
	cout << " s2��" << s2 << " s3��" << s3 << endl;
	cout << "�Ƚ�s2 s3�Ƿ���ȣ�����==��������أ�1�ǣ�0��" << endl;
	cout << "�����" << (s2 == s3) << endl;
	cout << "�Ƚ�s2 s3�Ƿ񲻵ȣ�����!=��������أ�1�ǣ�0��" << endl;
	cout << "�����" << (s2 != s3) << endl;
	cout << endl;

	cout << " s��" << s << " s4��" << s4 << endl;
	cout << "�Ƚ�s s4�Ƿ���ȣ�����==��������أ�1�ǣ�0��" << endl;
	cout << "�����" << (s == s4) << endl;
	cout << endl;
	cout << "�Ƚ�s s4�Ƿ񲻵ȣ�����!=��������أ�1�ǣ�0��" << endl;
	cout << "�����" << (s != s4) << endl;
	cout << endl;

	cout << "-------------------------------------------" << endl;
	cout << "operator<()  operator>()" << endl;
	cout << " s2��" << s2 << " s3��" << s3 << endl;
	cout << "�Ƚ�s2�Ƿ�<s3������<��������أ�1�ǣ�0��" << endl;
	cout << "�����" << (s2 < s3) << endl;
	cout << endl;

	cout << "�Ƚ�s2�Ƿ�>s3������>��������أ�1�ǣ�0��" << endl;
	cout << "�����" << (s2 > s3) << endl;
	cout << endl;

	cout << " s1��" << s1 << " s2��" << s2 << endl;
	cout << "�Ƚ�s1�Ƿ�<s2������<��������أ�1�ǣ�0��" << endl;
	cout << "�����" << (s1 < s2) << endl;
	cout << endl;

	cout << "�Ƚ�s1�Ƿ�>s2������>��������أ�1�ǣ�0��" << endl;
	cout << "�����" << (s1 > s2) << endl;
	cout << endl;

	cout << "-------------------------------------------" << endl;
	cout << "operator<=()   operator>=()" << endl;
	cout << " s2��" << s2 << " s3��" << s3 << endl;
	cout << "�Ƚ�s2�Ƿ�<=s3������<=��������أ�1�ǣ�0��" << endl;
	cout << "�����" << (s2 <= s3) << endl;
	cout << endl;
	cout << "�Ƚ�s2�Ƿ�>=s3������>=��������أ�1�ǣ�0��" << endl;
	cout << "�����" << (s2 >= s3) << endl;
	cout << endl;
	cout << " s1��" << s1 << " s2��" << s2 << endl;
	cout << "�Ƚ�s1�Ƿ�<=s2������<=��������أ�1�ǣ�0��" << endl;
	cout << "�����" << (s1 <= s2) << endl;
	cout << endl;
	cout << "�Ƚ�s1�Ƿ�>=s2������>=��������أ�1�ǣ�0��" << endl;
	cout << "�����" << (s1 >= s2) << endl;
	cout << endl;
	cout << " s��" << s << " s4��" << s4 << endl;
	cout << "�Ƚ�s�Ƿ�<=s4������<=��������أ�1�ǣ�0��" << endl;
	cout << "�����" << (s <= s4) << endl;
	cout << endl;
	cout << "�Ƚ�s�Ƿ�>=s4������>=��������أ�1�ǣ�0��" << endl;
	cout << "�����" << (s >= s4) << endl;
	cout << endl;
	system("pause");
}
void test_error()
{
	cout << "-------------------------------------------" << endl;
	cout << "            D.�쳣����" << endl;
	cout << "-------------------------------------------" << endl;
	YYKBString str1 = "abcd", str2 = "abcd", str3 = "abcd", str4 = "abcd", str5 = "abcd", str6 = "abcd";
	cout << endl;
	cout << "str1 = str2 = str3 = str4 = str5 = str6 = abcd" << endl;
	cout << endl;
	cout << "-------------------------------------------" << endl;
	cout << "insert()" << endl;
	try
	{
		cout << "str1=" << str1 << endl;
		cout << "str1.ins(str2,9)" << endl;
		str1.ins(str2, 9);
	}
	catch (int)
	{
		cout << "�����±����" << endl;
	}
	cout << endl;

	cout << "-------------------------------------------" << endl;
	cout << "delete()" << endl;
	try
	{
		cout << "str2=" << str2 << endl;
		cout << "str2.del(5,4) " << endl;
		str2.del(5, 4);
	}
	catch (int)
	{
		cout << "�����±����" << endl;
	}
	cout << endl;

	cout << "-------------------------------------------" << endl;
	cout << "replace()" << endl;
	try
	{
		cout << "str4=" << str4 << endl;
		cout << "str4.rep(str1, 5,4)  " << endl;
		str4.rep(str1, 5, 4);
		cout << "str4=" << str4 << endl;
		cout << endl;
		cout << "str5=" << str5 << endl;
		cout << "str5.rep('efg', 5, 3) " << endl;
		str5.rep(YYKBString("efg",3), 5, 3);
		cout << "str5=" << str5 << endl;
	}
	catch (int)
	{
		cout << "�����±����" << endl;
	}
	cout << endl;

	cout << "-------------------------------------------" << endl;
	cout << "operator[]" << endl;
	try
	{
		cout << "str6[5]=" << endl;
		cout << str6[5] << endl;
	}
	catch (int)
	{
		cout << "�����±����" << endl;
	}
	cout << endl;
	system("pause");
}
void test5()
{
	cout << "-------------------------------------------" << endl;
	cout << "            E.����*�Լ�*=�����" << endl;
	cout << "-------------------------------------------" << endl;
	YYKBString s1 ( "abcd",4), s2 ("1234",4);
	cout << "s1=" << s1 << '\t' << "s2=" << s2 << endl;
	s1 *= 2;
	cout << "s1*=2" << '\t' << "s1=" << s1 << endl;
	cout << "s2*2=" << s2 * 2 << endl;
	cout << "2*s2=" << 2 * s2 << endl;
	cout << endl;
	system("pause");
}
int main()
{
	test1();
	system("cls");
	test2();
	system("cls");
	test3();
	system("cls");
	test_error();
	system("cls");
	test5();
	system("cls");

	int a0[4] = { 1,2,3,4 };
	int b0[1] = { 5 };
	int c0[4] = { 4,3,2,1 };
	
	YYKBVector<int> c(c0, 4),e;
	YYKBVector<int> f(a0, 4);
	
	try {
		cout << "���Թ��캯���쳣������nΪ����" << endl;
		cout << "����m������nΪ-5" << endl;
		YYKBVector<int> m(a0, -5);
	    }
	catch (int d) {
		if (d == 0) cout << "���캯���쳣������nΪ����" << endl;
	}

		
	  cout << "\n�������죬a=[1,2,3,4]��b=[5]" << endl;
		YYKBVector<int> a(a0, 4);
		YYKBVector<int> b(b0, 1);
		cout << "a=" << a << "b=" << b << endl;
		cout << "\n���a��n��ֵ" << endl;
		cout << a.N() <<endl<< endl;
		try
		{
			cout << "���Բ��뺯���쳣������nΪ������Խ��" << endl;
			cout << "n=-1" << endl;
			a.ins(b, -1);
		}
		catch (int d)
		{
			if (d == -1) cout << "���뺯���쳣������nΪ������Խ��" << endl;
		}
		try
		{
			cout << "nԽ�磬n=5ʱ" << endl;
			a.ins(b, 5);
		}
		catch (int d)
		{
			if (d == -1) cout << "���뺯���쳣������nΪ������Խ��" << endl;
		}
		cout << "���Բ��뺯��,����λ��Ϊ0��ͷ�壩,����b" << endl;
		a.ins(b);
		cout << a << endl;
		try
		{
			cout << "\n����ɾ�������쳣������nΪ������Խ��" << endl;
			cout << "n=-1" << endl;
			a.del(1, -1);
		}
		catch (int d)
		{
			if (d == -1) cout << "ɾ�������쳣������nΪ������Խ��" << endl;
		}
		try
		{
			cout << "����ɾ��λ��Խ�磬��k=6��" << endl;
			a.del(6, 1);
		}
		catch (int d)
		{
			if (d == -1) cout << "ɾ�������쳣������nΪ������Խ��" << endl;
		}
		cout << "������ȷʹ��ɾ������,ɾ��λ��Ϊ3��n=100��ɾ����β����" << endl;
		a.del(3, 100);
		cout << a << endl;
		cout << "\n�����滻����,�滻λ��Ϊ1���ڶ��" << endl;
		a.rep(b, 1);
		cout << a << endl;
		try {
			cout << "\n����ȡ�Ӵ������쳣������nΪ������Խ��,n=-1" << endl;
			a.slice(-1, 3);
		}
		catch (int d)
		{
			if (d ==-1) cout << "ȡ�Ӵ������쳣������nΪ������Խ��" << endl;
		} 
		try
		{
			cout << "������ȷȡ�Ӵ�����,ȡ�ڶ��������" << endl;
			cout << "a=" << a << endl;
			e = a.slice(1, 2);
			cout << e  << endl;
		}
		catch (int d)
		{
			if (d == -1) cout << "ȡ�Ӵ������쳣������nΪ������Խ��" << endl;
			if (d == 6) cout << "[ ]�����쳣�����븺����Խ��" << endl;
		}
		
		try {
			cout << "\n����[ ]�����쳣�����븺����Խ��(����ֵΪa[-1],a[10])" << endl;
			a[-1];
		}
		catch (int d)
		{
			if (d == -1) cout << "[ ]�����쳣�����븺����Խ��" << endl;
		}
		try {
			a[10];
		}
		catch (int d)
		{
			if (d == -1) cout << "[ ]�����쳣�����븺����Խ��" << endl;
		}
		cout << "�����2��a[1],��ȷ���Ϊ5�������a" << endl;
		cout << a << endl;
		cout << a[1] << endl;
		cout << "\n���Ը�ֵ����c[4]={4,3,2,1}" << endl;
		a = c;
		cout << a << endl;
		cout << "\n���������ȴ�С" << endl;
		cout << "a=" << a << "b=" << b << endl;
		cout << "����ά����ͬ����(a>=b)" << endl;
		try
		{
			cout<<(a >= b);
		}
		catch (int d)
		{
			if (d == -1)
				cout<<"ά����ͬ"<<endl;
		}
		
		cout << "����ά����ͬ������a��ֵ{1,2,3,4}" << endl;
		a = f;
		
		cout << "a=" << a << endl;
		cout << "c=" << c << endl;
		cout << "����a==c,a>=c,a<=c,a>c,a<c,a!=c";
	
		cout << (a == c) << (a >= c) << (a <= c) << (a > c) << (a < c)<<(a != c) <<endl ;

		cout<<"\n����a*b"<<endl;
		try {
			cout << "a*b="<<(a * b);
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
		 
		 cout << "����bad��������ģ�����ݣ�����ִ�бȴ�С����ӵȲ�����" << endl;

			 bad zx1, zx2;
			 YYKBVector<bad>z1(&zx1, 1), z2(&zx2, 1);
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


		 cout << "���Զ�̬�ԣ�show������̬���" << endl;
		 cout << "a=" <<a<< endl;

		 YYKBase<int> * p1 = &a;
		 p1->Show();
		 a.Show();
		 cout << endl;
		 YYKBString s("abcd", 4);
		 cout << "s=" << s << endl;
		 YYKBase<char>* p2 = &s;
		 p2->Show();
		 s.Show();
		 system("pause");
	return 0;
}

