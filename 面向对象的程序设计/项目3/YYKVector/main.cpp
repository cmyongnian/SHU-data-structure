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
		cout << "测试构造函数异常，传入n为负数" << endl;
		YYKVector<int> m(a0, -5);
	    }
	catch (int d) {
		if (d == 0) cout << "构造函数异常，传入n为负数" << endl;
	}

		cout << "正常构造，a=[1,2,3,4]，b=[5]" << endl;
		YYKVector<int> a(a0, 4);
		YYKVector<int> b(b0, 1);
		cout << "输出a的n的值" << endl;
		cout << a.N() << endl;
		try
		{
			cout << "测试插入函数异常，传入n为负数或越界" << endl;
			a.ins(b, -1);
		}
		catch (int d)
		{
			if (d == 2) cout << "插入函数异常，传入n为负数或越界" << endl;
		}
		try
		{
			a.ins(b, 5);
		}
		catch (int d)
		{
			if (d == 2) cout << "插入函数异常，传入n为负数或越界" << endl;
		}
		cout << "测试插入函数,插入位置为0（头插）" << endl;
		a.ins(b);
		cout << a << endl;
		try
		{
			cout << "测试删除函数异常，传入n为负数或越界" << endl;
			a.del(1, -1);
		}
		catch (int d)
		{
			if (d == 3) cout << "删除函数异常，传入n为负数或越界" << endl;
		}
		try
		{
			a.del(6, 1);
		}
		catch (int d)
		{
			if (d == 3) cout << "删除函数异常，传入n为负数或越界" << endl;
		}
		cout << "测试删除函数,删除位置为3" << endl;
		a.del(3, 100);
		cout << a << endl;
		cout << "测试替换函数,替换位置为1（第二项）" << endl;
		a.rep(b, 1);
		cout << a << endl;
		try {
			cout << "测试取子串函数异常，传入n为负数或越界" << endl;
			a.slice(-1, 3);
		}
		catch (int d)
		{
			if (d == 4) cout << "取子串函数异常，传入n为负数或越界" << endl;
		}
		try
		{
			cout << "测试取子串函数,取第二项到第三项" << endl;
			cout << "a=" << a << endl;
			e = a.slice(1, 2);
			cout << e  << endl;
		}
		catch (int d)
		{
			if (d == 4) cout << "取子串函数异常，传入n为负数或越界" << endl;
			if (d == 6) cout << "[ ]函数异常，传入负数或越界" << endl;
		}
		
		try {
			cout << "测试[ ]函数异常，传入负数或越界(传入值为a[-1],a[10])" << endl;
			a[-1];
		}
		catch (int d)
		{
			if (d == 6) cout << "[ ]函数异常，传入负数或越界" << endl;
		}
		try {
			a[10];
		}
		catch (int d)
		{
			if (d == 6) cout << "[ ]函数异常，传入负数或越界" << endl;
		}
		cout << "输出第2项a[1],正确结果为5，先输出a" << endl;
		cout << a << endl;
		cout << a[1] << endl;
		cout << "测试赋值函数c[4]={4,3,2,1}" << endl;
		a = c;
		cout << a << endl;
		cout << "测试向量比大小" << endl;
		cout << "测试维数不同向量(a>=b)" << endl;
		try
		{
			a >= b;
		}
		catch (int d)
		{
			if (d == -1)
				cout<<"维数不同"<<endl;
		}
		
		cout << "测试维数相同向量，a赋值{1,2,3,4}" << endl;
		a = f;
		
		cout << "a=" << a << endl;
		cout << "测试a==c,a>=c,a<=c,a>c,a<c,a!=c";
	
		cout << (a == c) << (a >= c) << (a <= c) << (a > c) << (a < c)<<(a != c) <<endl ;

		cout<<"测试a*b"<<endl;
		try {
			cout << (a * b);
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
		 

			 bad zx1, zx2;
			 YYKVector<bad>z1(&zx1, 1), z2(&zx2, 1);
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
	return 0;
}


