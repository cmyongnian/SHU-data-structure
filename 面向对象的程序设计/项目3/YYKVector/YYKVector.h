#ifndef YYKVECTOR_H
#define YYKVECTOR_H

#include<iostream>
#include<cmath>
template<typename T>class YYKVector{
       
	template<typename T1>friend std::ostream& operator<<(std::ostream& out, const YYKVector<T1>& x);
	template<typename T1>friend YYKVector<T1> operator*(const double& x1, const YYKVector<T1>& x)throw(int);
	template<typename T1>friend YYKVector<T1> operator+(const double& x1, const YYKVector<T1>& x2)throw(int);
public:
		YYKVector(const T *x=NULL,const int n0=0)throw(int);
		YYKVector(const YYKVector<T> &x);
		~YYKVector();
		int N()const;
		void ins(const YYKVector<T>& x, const int k = 0)throw(int);
		void del(const int k = 0, const int l = 1)throw(int);
		void rep(const YYKVector<T>& x, const int k = 0, const int l = 1)throw(int);
		T*  cut(const int k = 0, const int l = 1)const throw(int);
		T& operator[](const int& x)throw(int);
		T operator[](const int& x)const throw(int);
		YYKVector<T>& operator=(const YYKVector<T>& x);
		bool operator==(const YYKVector<T>& x)const;
		bool operator!=(const YYKVector<T>& x)const;
		bool operator>(const YYKVector<T> &x)const throw(int);
		bool operator>=(const YYKVector<T> &x)const throw(int);
		bool operator<(const YYKVector<T> &x)const throw(int);
		bool operator<=(const YYKVector<T> &x)const throw(int);
		YYKVector<T> slice(const int k=0,const int l=1)const throw(int);
		YYKVector<T> operator+(const double &x)const throw(int);
		
		YYKVector<T> &operator+=(const double &x)throw(int);
		YYKVector<T> operator+(const YYKVector<T> &x)const throw(int);
		YYKVector<T> &operator+=(const YYKVector<T> &x)throw(int);
		YYKVector<T> operator*(const double &x)const throw(int);
		
		YYKVector<T> &operator*=(const double &x)throw(int);
		YYKVector<T> operator*(const YYKVector<T> &x)const throw(int);
		YYKVector<T> &operator*=(const YYKVector<T> &x)throw(int);
		
    protected:
	T* d;
	int n;
};
template<typename T>YYKVector<T>::YYKVector(const T* x, const int n0)throw(int) :d(NULL), n(0) {
	if (n0 < 0)throw 0;
	d = new T[n0];
	for (int i = 0; i < n0; i++)d[i] = x[i];
	n = n0;
}

template<typename T>YYKVector<T>::YYKVector(const YYKVector<T>& x) :d(NULL), n(0) {
	d = new T[x.n];
	for (int i = 0; i < x.n; i++)d[i] = x[i];
	n = x.n;
}
template<typename T>YYKVector<T>::~YYKVector() { if (d != NULL)delete[]d; }
template<typename T>int YYKVector<T>::N()const { return n; }
template<typename T>void YYKVector<T>::ins(const YYKVector<T>& x, const int k)throw(int) {
	if (k<0 || k>n)throw  2;
	T* t = new T[n + x.n];
	for (int i = 0; i < k; i++)t[i] = d[i];
	for (int i = k; i < k + x.n; i++)t[i] = x[i - k];
	for (int i = k + x.n; i < n + x.n; i++)t[i] = d[i - x.n];
	if (d != NULL)delete[]d;
	d = t;
	n += x.n;
}
template<typename T>void YYKVector<T>::del(const int k, const int l)throw(int) {
	if (k<0 || k>n || l <= 0)throw 3;
	T* t = new T[n - (l < n - k ? l : n - k)];
	for (int i = 0; i < k; i++)t[i] = d[i];
	for (int i = k + l; i < n; i++)t[i - l] = d[i];
	if (d != NULL)delete[]d;
	d = t;
	n -= (l < n - k ? l : n - k);
}
template<typename T>void YYKVector<T>::rep(const YYKVector<T>& x, const int k, const int l)throw(int) {
	del(k, l);
	ins(x, k);
}
template<typename T>T* YYKVector<T>::cut(const int k, const int l)const throw(int) {
	if (k<0 || k>n|| l <= 0)throw 4;
	
	T* t = new T[(l < n - k ? l : n - k)];
	for (int i = k; i < (l + k < n ? l + k : n); i++)t[i - k] = d[i];
	return t;
}
template<typename T>T& YYKVector<T>::operator[](const int& x)throw(int) {
	if (x < 0 || x >= n)throw 6;
	return d[x];
}
template<typename T>T YYKVector<T>::operator[](const int& x)const throw(int) {
	if (x < 0 || x >= n)throw 6;
	return d[x];
}
template<typename T>YYKVector<T>& YYKVector<T>::operator=(const YYKVector<T>& x) {
	if (d != NULL)delete[]d;
	d = new T[x.n];
	for (int i = 0; i < x.n; i++)d[i] = x[i];
	n = x.n;
	return *this;
}
template<typename T>bool YYKVector<T>::operator==(const YYKVector<T>& x)const {
	if (n != x.n)return false;
	for (int i = 0; i < n; i++)if (d[i] != x[i])return false;
	return true;
}
template<typename T>bool YYKVector<T>::operator!=(const YYKVector<T>& x)const { return *this == x ? false : true; }

template<typename T>bool YYKVector<T>::operator>(const YYKVector<T> &x)const throw(int){
	if (n != x.n) throw - 1;
	try{
		for(int i=0;i<(this->n<x.N()?this->n:x.N());i++){
			if(this->d[i]>x[i])return true;
			if(this->d[i]<x[i])return false;
		}
		if(this->n>x.N())return true;
		return false;
	}
	catch(...){throw -2;}
}
template<typename T>bool YYKVector<T>::operator>=(const YYKVector<T> &x)const throw(int){return (*this>x||*this==x)?true:false;}
template<typename T>bool YYKVector<T>::operator<(const YYKVector<T> &x)const throw(int){return *this>=x?false:true;}
template<typename T>bool YYKVector<T>::operator<=(const YYKVector<T> &x)const throw(int){return *this>x?false:true;}
template<typename T>YYKVector<T> YYKVector<T>::slice(const int k,const int l)const throw(int){return YYKVector(this->cut(k,l),(l<this->n-k?l:this->n-k));}
template<typename T>YYKVector<T> YYKVector<T>::operator+(const double &x)const throw(int){
	YYKVector<T> t=*this;
	try{
		for(int i=0;i<this->n;i++)t[i]+=x;
		return t;
	}
	catch(...){throw -3;}
}
template<typename T>YYKVector<T> operator+(const double &x1,const YYKVector<T> &x2)throw(int){return x2+x1;}
template<typename T>YYKVector<T> &YYKVector<T>::operator+=(const double &x)throw(int){
	*this=*this+x;
	return *this;
}
template<typename T>YYKVector<T> YYKVector<T>::operator+(const YYKVector<T> &x)const throw(int){
	if(this->n!=x.n)throw -1;
	YYKVector<T> t=*this;
	try{
		for(int i=0;i<this->n;i++)t[i]+=x[i];
		return t;
	}
	catch(...){throw -4;}
}
template<typename T>YYKVector<T> &YYKVector<T>::operator+=(const YYKVector<T> &x)throw(int){
	if(this->n!=x.n)throw -1;
	*this=*this+x;
	return *this;
}
template<typename T>YYKVector<T> YYKVector<T>::operator*(const double &x)const throw(int){
	YYKVector<T> t=*this;
	try{
		for(int i=0;i<this->n;i++)t[i]*=x;
		return t;
	}
	catch(...){throw -5;}
}
template<typename T>YYKVector<T> operator*(const double &x1,const YYKVector<T> &x2)throw(int){return x2*x1;}
template<typename T>YYKVector<T> &YYKVector<T>::operator*=(const double &x)throw(int){
	*this=*this*x;
	return *this;
}
template<typename T>YYKVector<T> YYKVector<T>::operator*(const YYKVector<T> &x)const throw(int){
	if(this->n!=x.n)throw -1;
	YYKVector<T> t=*this;
	try{
		for(int i=0;i<this->n;i++)t[i]*=x[i];
		return t;
	}
	catch(...){throw -6;}
}
template<typename T>YYKVector<T> &YYKVector<T>::operator*=(const YYKVector<T> &x)throw(int){
	if(this->n!=x.n)throw(int)-1;
	*this=*this*x;
	return *this;
}
template<typename T>std::ostream &operator<<(std::ostream &out,const YYKVector<T> &x){
	out<<'('<<x[0];
	for(int i=1;i<x.n;i++)out<<','<<x[i];
	out<<')';
	return out;
}
#endif
