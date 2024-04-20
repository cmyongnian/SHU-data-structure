#ifndef YYKBVECTOR_H
#define YYKBVECTOR_H
#include"YYKBase.h"
#include<iostream>
#include<cmath>
using namespace std;
template<typename T>class YYKBVector:public YYKBase<T>{
	public:
		YYKBVector(const T *x=NULL,const int n0=0)throw(int);
		YYKBVector(const YYKBVector<T> &x);
		~YYKBVector();
		void Show() throw(int);
		double M()const;
		YYKBVector<T> slice(const int k=0,const int l=1)const throw(int);
		YYKBVector<T> operator+(const double &x)const throw(int);
		template<typename T1>friend YYKBVector<T1> operator+(const double &x1,const YYKBVector<T1> &x2)throw(int);
		YYKBVector<T> &operator+=(const double &x)throw(int);
		YYKBVector<T> operator+(const YYKBVector<T> &x)const throw(int);
		YYKBVector<T> &operator+=(const YYKBVector<T> &x)throw(int);
		YYKBVector<T> operator*(const double &x)const throw(int);
		template<typename T1>friend YYKBVector<T1> operator*(const double &x1,const YYKBVector<T1> &x)throw(int);
		YYKBVector<T> &operator*=(const double &x)throw(int);
		YYKBVector<T> operator*(const YYKBVector<T> &x)const throw(int);
		YYKBVector<T> &operator*=(const YYKBVector<T> &x)throw(int);
		template<typename T1>friend std::ostream &operator<<(std::ostream &out,const YYKBVector<T1> &x);
};
template<typename T>YYKBVector<T>::YYKBVector(const T*x,const int n0)throw(int):YYKBase<T>(x,n0){}
template<typename T>YYKBVector<T>::YYKBVector(const YYKBVector<T> &x):YYKBase<T>(x){}
template<typename T>YYKBVector<T>::~YYKBVector(){}
template<typename T>void YYKBVector<T>::Show()throw(int){
	try{
		cout <<'(';
		for (int i = 0; i <this->n ; i++)cout<<this->d[i];
		cout <<')';
	}
	catch(...){throw -7;}
}
template<typename T>YYKBVector<T> YYKBVector<T>::slice(const int k,const int l)const throw(int){return YYKBVector(this->cut(k,l),(l<this->n-k?l:this->n-k));}
template<typename T>YYKBVector<T> YYKBVector<T>::operator+(const double &x)const throw(int){
	YYKBVector<T> t=*this;
	try{
		for(int i=0;i<this->n;i++)t[i]+=x;
		return t;
	}
	catch(...){throw -3;}
}
template<typename T>YYKBVector<T> operator+(const double &x1,const YYKBVector<T> &x2)throw(int){return x2+x1;}
template<typename T>YYKBVector<T> &YYKBVector<T>::operator+=(const double &x)throw(int){
	*this=*this+x;
	return *this;
}
template<typename T>YYKBVector<T> YYKBVector<T>::operator+(const YYKBVector<T> &x)const throw(int){
	if(this->n!=x.n)throw -1;
	YYKBVector<T> t=*this;
	try{
		for(int i=0;i<this->n;i++)t[i]+=x[i];
		return t;
	}
	catch(...){throw -4;}
}
template<typename T>YYKBVector<T> &YYKBVector<T>::operator+=(const YYKBVector<T> &x)throw(int){
	if(this->n!=x.n)throw -1;
	*this=*this+x;
	return *this;
}
template<typename T>YYKBVector<T> YYKBVector<T>::operator*(const double &x)const throw(int){
	YYKBVector<T> t=*this;
	try{
		for(int i=0;i<this->n;i++)t[i]*=x;
		return t;
	}
	catch(...){throw -5;}
}
template<typename T>YYKBVector<T> operator*(const double &x1,const YYKBVector<T> &x2)throw(int){return x2*x1;}
template<typename T>YYKBVector<T> &YYKBVector<T>::operator*=(const double &x)throw(int){
	*this=*this*x;
	return *this;
}
template<typename T>YYKBVector<T> YYKBVector<T>::operator*(const YYKBVector<T> &x)const throw(int){
	if(this->n!=x.n)throw -1;
	YYKBVector<T> t=*this;
	try{
		for(int i=0;i<this->n;i++)t[i]*=x[i];
		return t;
	}
	catch(...){throw -6;}
}
template<typename T>YYKBVector<T> &YYKBVector<T>::operator*=(const YYKBVector<T> &x)throw(int){
	if(this->n!=x.n)throw(int)-1;
	*this=*this*x;
	return *this;
}
template<typename T>std::ostream &operator<<(std::ostream &out,const YYKBVector<T> &x){
	out<<'('<<x[0];
	for(int i=1;i<x.n;i++)out<<','<<x[i];
	out<<')';
	return out;
}

#endif
