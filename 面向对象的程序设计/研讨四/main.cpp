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
	cout << "              A.测试字符串操作函数" << endl;
	YYKBString s("123789",6), s1("456",3), s2("789",3), s3("147",3), s4("258",3), s5("123456123456",12), s6("112233",6);
	cout << "-------------------------------------------" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "长度：leng()" << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s1.leng() = " << s1.N() << endl;
	cout << "-------------------------------------------" << endl;
	cout << "增insert()" << endl;
	cout << "s2 = " << s2 << '\t' << "s1=" << s1 << endl;
	s2.ins(s1, 2);
	cout << "s2.ins(s1,2) = " << s2 << endl;
	cout << "s3=" << s3 << endl;
	s3.ins(YYKBString("789",3), 2);
	cout << "s.ins('789',2)" << s3 << endl;
	cout << "-------------------------------------------" << endl;
	cout << "改replace()" << endl;
	cout << "s4 = " << s4 << '\t' << "s=" << s << '\t' << "s1=" << s1 << endl;
	s4.rep(s, 1, 2);
	cout << "s4.replace(s,1,2) = " << s4 << endl;
	s.rep(s1, 4, 3);
	cout << "s.replace(s1,4,3)=" << s << endl;
	cout << endl;
	cout << "-------------------------------------------" << endl;
	cout << "删delete()" << endl;
	cout << "s6 = " << s6 << endl;
	s6.del(2, 3);
	cout << "s6.del(2,3) = " << s6 << endl;
	cout << endl;
	cout << "-------------------------------------------" << endl;
	cout << "取字串cut()" << endl;
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
	cout << "                  B.测试基本运算符" << endl;
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
	cout << "测试+运算符：" << endl;
	cout << "str + str2 = " << str1 << " + " << str2 << " = " << str1 + str2 << endl;
	cout << endl;
	cout << "-------------------------------------------" << endl;
	cout << "operator+=()" << endl;
	cout << "测试+=运算符：" << endl;
	str4 += str1;
	cout << "str4 += str1" << '\t' << "str4=" << str4 << endl;
	cout << endl;
	cout << "-------------------------------------------" << endl;
	cout << "operator[]()" << endl;
	cout << "测试operator[]运算符：" << endl;
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
	cout << "                 C.测试比较运算符重载" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "operator==()  operator!=()" << endl;
	cout << " s2：" << s2 << " s3：" << s3 << endl;
	cout << "比较s2 s3是否相等，测试==运算符重载：1是，0否" << endl;
	cout << "结果：" << (s2 == s3) << endl;
	cout << "比较s2 s3是否不等，测试!=运算符重载：1是，0否" << endl;
	cout << "结果：" << (s2 != s3) << endl;
	cout << endl;

	cout << " s：" << s << " s4：" << s4 << endl;
	cout << "比较s s4是否相等，测试==运算符重载：1是，0否" << endl;
	cout << "结果：" << (s == s4) << endl;
	cout << endl;
	cout << "比较s s4是否不等，测试!=运算符重载：1是，0否" << endl;
	cout << "结果：" << (s != s4) << endl;
	cout << endl;

	cout << "-------------------------------------------" << endl;
	cout << "operator<()  operator>()" << endl;
	cout << " s2：" << s2 << " s3：" << s3 << endl;
	cout << "比较s2是否<s3，测试<运算符重载：1是，0否" << endl;
	cout << "结果：" << (s2 < s3) << endl;
	cout << endl;

	cout << "比较s2是否>s3，测试>运算符重载：1是，0否" << endl;
	cout << "结果：" << (s2 > s3) << endl;
	cout << endl;

	cout << " s1：" << s1 << " s2：" << s2 << endl;
	cout << "比较s1是否<s2，测试<运算符重载：1是，0否" << endl;
	cout << "结果：" << (s1 < s2) << endl;
	cout << endl;

	cout << "比较s1是否>s2，测试>运算符重载：1是，0否" << endl;
	cout << "结果：" << (s1 > s2) << endl;
	cout << endl;

	cout << "-------------------------------------------" << endl;
	cout << "operator<=()   operator>=()" << endl;
	cout << " s2：" << s2 << " s3：" << s3 << endl;
	cout << "比较s2是否<=s3，测试<=运算符重载：1是，0否" << endl;
	cout << "结果：" << (s2 <= s3) << endl;
	cout << endl;
	cout << "比较s2是否>=s3，测试>=运算符重载：1是，0否" << endl;
	cout << "结果：" << (s2 >= s3) << endl;
	cout << endl;
	cout << " s1：" << s1 << " s2：" << s2 << endl;
	cout << "比较s1是否<=s2，测试<=运算符重载：1是，0否" << endl;
	cout << "结果：" << (s1 <= s2) << endl;
	cout << endl;
	cout << "比较s1是否>=s2，测试>=运算符重载：1是，0否" << endl;
	cout << "结果：" << (s1 >= s2) << endl;
	cout << endl;
	cout << " s：" << s << " s4：" << s4 << endl;
	cout << "比较s是否<=s4，测试<=运算符重载：1是，0否" << endl;
	cout << "结果：" << (s <= s4) << endl;
	cout << endl;
	cout << "比较s是否>=s4，测试>=运算符重载：1是，0否" << endl;
	cout << "结果：" << (s >= s4) << endl;
	cout << endl;
	system("pause");
}
void test_error()
{
	cout << "-------------------------------------------" << endl;
	cout << "            D.异常处理" << endl;
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
		cout << "输入下标错误" << endl;
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
		cout << "输入下标错误" << endl;
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
		cout << "输入下标错误" << endl;
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
		cout << "输入下标错误" << endl;
	}
	cout << endl;
	system("pause");
}
void test5()
{
	cout << "-------------------------------------------" << endl;
	cout << "            E.测试*以及*=运算符" << endl;
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
		cout << "测试构造函数异常，传入n为负数" << endl;
		cout << "构造m，传入n为-5" << endl;
		YYKBVector<int> m(a0, -5);
	    }
	catch (int d) {
		if (d == 0) cout << "构造函数异常，传入n为负数" << endl;
	}

		
	  cout << "\n正常构造，a=[1,2,3,4]，b=[5]" << endl;
		YYKBVector<int> a(a0, 4);
		YYKBVector<int> b(b0, 1);
		cout << "a=" << a << "b=" << b << endl;
		cout << "\n输出a的n的值" << endl;
		cout << a.N() <<endl<< endl;
		try
		{
			cout << "测试插入函数异常，传入n为负数或越界" << endl;
			cout << "n=-1" << endl;
			a.ins(b, -1);
		}
		catch (int d)
		{
			if (d == -1) cout << "插入函数异常，传入n为负数或越界" << endl;
		}
		try
		{
			cout << "n越界，n=5时" << endl;
			a.ins(b, 5);
		}
		catch (int d)
		{
			if (d == -1) cout << "插入函数异常，传入n为负数或越界" << endl;
		}
		cout << "测试插入函数,插入位置为0（头插）,插入b" << endl;
		a.ins(b);
		cout << a << endl;
		try
		{
			cout << "\n测试删除函数异常，传入n为负数或越界" << endl;
			cout << "n=-1" << endl;
			a.del(1, -1);
		}
		catch (int d)
		{
			if (d == -1) cout << "删除函数异常，传入n为负数或越界" << endl;
		}
		try
		{
			cout << "测试删除位置越界，（k=6）" << endl;
			a.del(6, 1);
		}
		catch (int d)
		{
			if (d == -1) cout << "删除函数异常，传入n为负数或越界" << endl;
		}
		cout << "测试正确使用删除函数,删除位置为3，n=100（删除至尾部）" << endl;
		a.del(3, 100);
		cout << a << endl;
		cout << "\n测试替换函数,替换位置为1（第二项）" << endl;
		a.rep(b, 1);
		cout << a << endl;
		try {
			cout << "\n测试取子串函数异常，传入n为负数或越界,n=-1" << endl;
			a.slice(-1, 3);
		}
		catch (int d)
		{
			if (d ==-1) cout << "取子串函数异常，传入n为负数或越界" << endl;
		} 
		try
		{
			cout << "测试正确取子串函数,取第二项到第三项" << endl;
			cout << "a=" << a << endl;
			e = a.slice(1, 2);
			cout << e  << endl;
		}
		catch (int d)
		{
			if (d == -1) cout << "取子串函数异常，传入n为负数或越界" << endl;
			if (d == 6) cout << "[ ]函数异常，传入负数或越界" << endl;
		}
		
		try {
			cout << "\n测试[ ]函数异常，传入负数或越界(传入值为a[-1],a[10])" << endl;
			a[-1];
		}
		catch (int d)
		{
			if (d == -1) cout << "[ ]函数异常，传入负数或越界" << endl;
		}
		try {
			a[10];
		}
		catch (int d)
		{
			if (d == -1) cout << "[ ]函数异常，传入负数或越界" << endl;
		}
		cout << "输出第2项a[1],正确结果为5，先输出a" << endl;
		cout << a << endl;
		cout << a[1] << endl;
		cout << "\n测试赋值函数c[4]={4,3,2,1}" << endl;
		a = c;
		cout << a << endl;
		cout << "\n测试向量比大小" << endl;
		cout << "a=" << a << "b=" << b << endl;
		cout << "测试维数不同向量(a>=b)" << endl;
		try
		{
			cout<<(a >= b);
		}
		catch (int d)
		{
			if (d == -1)
				cout<<"维数不同"<<endl;
		}
		
		cout << "测试维数相同向量，a赋值{1,2,3,4}" << endl;
		a = f;
		
		cout << "a=" << a << endl;
		cout << "c=" << c << endl;
		cout << "测试a==c,a>=c,a<=c,a>c,a<c,a!=c";
	
		cout << (a == c) << (a >= c) << (a <= c) << (a > c) << (a < c)<<(a != c) <<endl ;

		cout<<"\n测试a*b"<<endl;
		try {
			cout << "a*b="<<(a * b);
		    }
		catch (int d)
		{
			if (d == -1)
				cout << "维数不同" << endl;
		}
		cout << "测试a*c(点乘，结果为向量（4,6,6,4）,输出为(a * c))" << endl;
		try {
			cout << (a * c);
		}
		catch (int d)
		{
			if (d == -1)
				cout << "维数不同" << endl;
		}
		cout << "测试a*=c(输出为a)" << endl;
		 (a *= c);
		 cout << a<<endl;
		 
		 cout << "测试bad类做向量模板内容（不能执行比大小，相加等操作）" << endl;

			 bad zx1, zx2;
			 YYKBVector<bad>z1(&zx1, 1), z2(&zx2, 1);
			 try {
				 cout << (z1 > z2) << endl;
			 }
			 catch (int& bug) {
				 if (bug == 0)cout << "对象长度错误\n";
				 if (bug == -1)cout << "下标越界\n";
				 if (bug == -2)cout << "该类型数据成员无法比较大小\n";
				 if (bug == -3)cout << "该类型数据成员无法数加\n";
				 if (bug == -4)cout << "该类型数据成员无法相加\n";
				 if (bug == -5)cout << "该类型数据成员无法数乘\n";
				 if (bug == -6)cout << "该类型数据成员无法点乘\n";
			 }
			 try {
				 z1 += 5;
			 }
			 catch (int& bug) {
				 if (bug == 0)cout << "对象长度错误\n";
				 if (bug == -1)cout << "下标越界\n";
				 if (bug == -2)cout << "该类型数据成员无法比较大小\n";
				 if (bug == -3)cout << "该类型数据成员无法数加\n";
				 if (bug == -4)cout << "该类型数据成员无法相加\n";
				 if (bug == -5)cout << "该类型数据成员无法数乘\n";
				 if (bug == -6)cout << "该类型数据成员无法点乘\n";
			 }
			 try {
				 z1 += z2;
			 }
			 catch (int& bug) {
				 if (bug == 0)cout << "对象长度错误\n";
				 if (bug == -1)cout << "下标越界\n";
				 if (bug == -2)cout << "该类型数据成员无法比较大小\n";
				 if (bug == -3)cout << "该类型数据成员无法数加\n";
				 if (bug == -4)cout << "该类型数据成员无法相加\n";
				 if (bug == -5)cout << "该类型数据成员无法数乘\n";
				 if (bug == -6)cout << "该类型数据成员无法点乘\n";
			 }
			 try{
				 z1 *= 5;
		 }
		 catch (int& bug) {
			 if (bug == 0)cout << "对象长度错误\n";
			 if (bug == -1)cout << "下标越界\n" ;
			 if (bug == -2)cout << "该类型数据成员无法比较大小\n" ;
			 if (bug == -3)cout << "该类型数据成员无法数加\n";
			 if (bug == -4)cout << "该类型数据成员无法相加\n";
			 if (bug == -5)cout << "该类型数据成员无法数乘\n";
			 if (bug == -6)cout << "该类型数据成员无法点乘\n";
		 }
		 try {
			 z1 *=z2;
		 }
		 catch (int& bug) {
			 if (bug == 0)cout << "对象长度错误\n";
			 if (bug == -1)cout << "下标越界\n";
			 if (bug == -2)cout << "该类型数据成员无法比较大小\n";
			 if (bug == -3)cout << "该类型数据成员无法数加\n";
			 if (bug == -4)cout << "该类型数据成员无法相加\n";
			 if (bug == -5)cout << "该类型数据成员无法数乘\n";
			 if (bug == -6)cout << "该类型数据成员无法点乘\n";
		 }


		 cout << "测试多态性，show函数多态输出" << endl;
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

