#ifndef CPPSTRING_H
#define CPPSTRING_H
#include<iostream>
class CPPString{
	public:
		CPPString()
		{
			s = NULL;
			l = 0;
		}
	    CPPString(const char *x); //构造 
	    CPPString(const CPPString &x);//转换构造 
	    ~CPPString();//析构 
	    int leng()const;//返回字符串长度 
	    void ins(const CPPString &x,int k=0);//将x从第k位前插入     //d 增加k越界异常
	    void ins(const char *x,int k=0);                 
	    void del(int k,int len=1);//从k位(包含)起删除len个字符     //d增加k，len越界
	    void rep(const CPPString &x,int k=0,int len=1);//用x替换掉从k位(包含)起的len个字符 
	    void rep(const char *x,int k=0,int len=1);
	    int loc(const CPPString &x,int k=1);//返回第k个x的首字符下标，没有则返回-1 
		int loc(const char* x, int k = 1);  //d增加
	    CPPString cut(int h=0,int len=1);//返回自第h位(包含)起的len个字符构成的字符串 
	    //CPPString MaxUp()const;//返回本字符串的最大升序列 
	    //CPPString MAXDown()const;//返回本字符串的最大降序列 
	    char &operator[](const int &x);
	    CPPString operator+(const CPPString &x);
	    CPPString &operator+=(const CPPString &x);
	    CPPString operator*(int y);
	    friend CPPString operator*(int y,const CPPString &x);
	    CPPString &operator*=(int y);
	    CPPString &operator=(const CPPString &x);
	    friend std::ostream &operator<<(std::ostream &out,const CPPString &x);
	    friend std::istream &operator>>(std::istream &in,  CPPString &x); //d.去除输入函数const
	    bool operator==(const CPPString &x)const;
	    bool operator!=(const CPPString &x)const;
	    bool operator>(const CPPString &x)const;
	    bool operator<(const CPPString &x)const;
		bool operator>=(const CPPString &x)const;
	    bool operator<=(const CPPString &x)const;
	private:
	    char *s;
		int l;
};
CPPString operator*(int y,const CPPString &x);
std::ostream &operator<<(std::ostream &out,const CPPString &x);
std::istream &operator>>(std::istream &in,  CPPString &x);
#endif
