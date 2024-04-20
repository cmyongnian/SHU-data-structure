#ifndef YYKBSTRING_H
#define YYKBSTRING_H
#include"YYKBase.h"
#include<iostream>
using namespace std;
class YYKBString:public YYKBase<char>{
	public:
		YYKBString(const char *x=NULL,const int n0=0)throw(int);
		YYKBString(const YYKBString &x);
		~YYKBString();
		void Show()throw(int);
		YYKBString slice(const int k=0,const int l= 1)const throw(int);
		YYKBString operator+(const double &x)const;
		friend YYKBString operator+(const double &x1,const YYKBString &x2);
		YYKBString &operator+=(const double &x);
		YYKBString operator+(const YYKBString &x)const;
		YYKBString &operator+=(const YYKBString &x);
		YYKBString operator*(const double &x)const;
		friend YYKBString operator*(const double &x1,const YYKBString &x);
		YYKBString &operator*=(const double &x);
		friend std::ostream &operator<<(std::ostream &out,const YYKBString &x);
};
YYKBString::YYKBString(const char*x,const int n0)throw(int):YYKBase(x,n0){}
YYKBString::YYKBString(const YYKBString &x):YYKBase(x){}
YYKBString::~YYKBString(){}
void YYKBString:: Show()throw(int){
	std::cout << '"';
	for (int i = 0;i<this->n; i++) cout << this->d[i];
	std::cout << '"';;
}
YYKBString YYKBString::slice(const int k,const int l)const throw(int){return YYKBString(cut(k,l),(l<n-k?l:n-k));}
YYKBString YYKBString::operator+(const double &x)const{
	YYKBString t=*this;
	for(int i=0;i<n;i++)t[i]=char(int(t[i])+int(x));
	return t;
}
YYKBString operator+(const double &x1,const YYKBString &x2){return x2+x1;}
YYKBString &YYKBString::operator+=(const double &x){
	*this=*this+x;
	return *this;
}
YYKBString YYKBString::operator+(const YYKBString &x)const{
	YYKBString t=*this;
	t.ins(x,n);
	return t;
}
YYKBString &YYKBString::operator+=(const YYKBString &x){
	*this=*this+x;
	return *this;
}
YYKBString YYKBString::operator*(const double &x)const{
	YYKBString t=*this;
	for(int i=1;i<x;i++)t.ins(*this,t.n);
	return t;
}
YYKBString operator*(const double &x1,const YYKBString &x2){return x2*x1;}
YYKBString &YYKBString::operator*=(const double &x){
	*this=*this*x;
	return *this;
}
std::ostream &operator<<(std::ostream &out,const YYKBString &x){
	out<<'"';
	for(int i=0;i<x.n;i++)out<<x[i];
	out<<'"';
	return out;
}
#endif
