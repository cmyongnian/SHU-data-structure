#ifndef YYKBASE_H
#define YYKBASE_H
#include<iostream>
template<typename T>class YYKBase{
	public:
		YYKBase(const T *x=NULL,const int n0=0)throw(int);
		YYKBase(const YYKBase<T> &x);
		virtual ~YYKBase();
		int N()const;
		void ins(const YYKBase<T> &x,const int k=0)throw(int);
		void del(const int k=0,const int l=1)throw(int);
		void rep(const YYKBase<T> &x,const int k=0,const int l=1)throw(int);
		virtual void Show()throw(int)=0;
		T* cut(const int k=0,const int l=1)const throw(int);
		T &operator[](const int &x)throw(int);
		T operator[](const int &x)const throw(int);
		YYKBase<T> &operator=(const YYKBase<T> &x);
		bool operator==(const YYKBase<T> &x)const;
		bool operator!=(const YYKBase<T> &x)const;
		bool operator>(const YYKBase<T> &x)const throw(int);
		bool operator>=(const YYKBase<T> &x)const throw(int);
		bool operator<(const YYKBase<T> &x)const throw(int);
		bool operator<=(const YYKBase<T> &x)const throw(int);
	protected:
		T *d;
		int n;
};
template<typename T>YYKBase<T>::YYKBase(const T *x,const int n0)throw(int):d(NULL),n(0){
	if(n0<0)throw 0;
	d=new T[n0];
	for(int i=0;i<n0;i++)d[i]=x[i];
	n=n0;
}
template<typename T>YYKBase<T>::YYKBase(const YYKBase<T> &x):d(NULL),n(0){
	d=new T[x.n];
	for(int i=0;i<x.n;i++)d[i]=x[i];
	n=x.n;
}
template<typename T>YYKBase<T>::~YYKBase(){if(d!=NULL)delete []d;}
template<typename T>int YYKBase<T>::N()const{return n;}
template<typename T>void YYKBase<T>::ins(const YYKBase<T> &x,const int k)throw(int){
	if(k<0||k>n)throw -1;
	T *t=new T[n+x.n];
	for(int i=0;i<k;i++)t[i]=d[i];
	for(int i=k;i<k+x.n;i++)t[i]=x[i-k];
	for(int i=k+x.n;i<n+x.n;i++)t[i]=d[i-x.n];
	if(d!=NULL)delete []d;
	d=t;
	n+=x.n;
}
template<typename T>void YYKBase<T>::del(const int k,const int l)throw(int){
	if(k<0||k>n||l<=0)throw -1;
	T *t=new T[n-(l<n-k?l:n-k)];
	for(int i=0;i<k;i++)t[i]=d[i];
	for(int i=k+l;i<n;i++)t[i-l]=d[i];
	if(d!=NULL)delete []d;
	d=t;
	n-=(l<n-k?l:n-k);
}
template<typename T>void YYKBase<T>::rep(const YYKBase<T> &x,const int k,const int l)throw(int){
	del(k,l);
	ins(x,k);
}
template<typename T>T* YYKBase<T>::cut(const int k,const int l)const throw(int){
	if(k<0||k>n)throw -1;
	T *t=new T[(l<n-k?l:n-k)];
	for(int i=k;i<(l+k<n?l+k:n);i++)t[i-k]=d[i];
	return t;
}
template<typename T>T &YYKBase<T>::operator[](const int &x)throw(int){
	if(x<0||x>=n)throw -1;
	return d[x];
}
template<typename T>T YYKBase<T>::operator[](const int &x)const throw(int){
	if(x<0||x>=n)throw -1;
	return d[x];
}
template<typename T>YYKBase<T> &YYKBase<T>::operator=(const YYKBase<T> &x){
	if(d!=NULL)delete []d;
	d=new T[x.n];
	for(int i=0;i<x.n;i++)d[i]=x[i];
	n=x.n;
	return *this;
}
template<typename T>bool YYKBase<T>::operator==(const YYKBase<T> &x)const{
	if(n!=x.n)return false;
	for(int i=0;i<n;i++)if(d[i]!=x[i])return false;
	return true;
}
template<typename T>bool YYKBase<T>::operator!=(const YYKBase<T> &x)const{return *this==x?false:true;}
template<typename T>bool YYKBase<T>::operator>(const YYKBase<T>& x)const throw(int) {
	try {
		for (int i = 0; i < (this->n < x.N() ? this->n : x.N()); i++) {
			if (this->d[i] > x[i])return true;
			if (this->d[i] < x[i])return false;
		}
		if (this->n > x.N())return true;
		return false;
	}
	catch (...) { throw - 2; }
}
template<typename T>bool YYKBase<T>::operator>=(const YYKBase<T>& x)const throw(int) { return (*this > x || *this == x) ? true : false; }
template<typename T>bool YYKBase<T>::operator<(const YYKBase<T>& x)const throw(int) { return *this >= x ? false : true; }
template<typename T>bool YYKBase<T>::operator<=(const YYKBase<T>& x)const throw(int) { return *this > x ? false : true; }
#endif
