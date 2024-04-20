#include"CPPString.h"
using namespace std;
CPPString::CPPString(const char *x):s(NULL),l(0)
{  
	int k=0;
	while(x[k]!='\0')k++;
	s=new char[k];
	for(int i=0;i<k;i++)s[i]=x[i];
	l=k;
}
CPPString::CPPString(const CPPString &x):s(NULL),l(0)
{
	s=new char[x.l];
	for(int i=0;i<x.l;i++)s[i]=x.s[i];
	l=x.l;
}
CPPString::~CPPString()
{
	if(s!=NULL)
		delete []s;
	l = 0;
}
int CPPString::leng()const{return l;}
void CPPString::ins(const CPPString &x,int k)
{
	if (k < 0 || k > l)
		throw(int)k;
	char *t=new char[l+x.l];
	for(int i=0;i<k;i++)
		t[i]=s[i];
	for(int i=k;i<=k+x.l;i++)
		t[i]=x.s[i-k];
	for(int i=k+x.l;i<=l+x.l;i++)
		t[i]=s[i-x.l];
	delete []s;
	s=t;
	l+=x.l;
}
void CPPString::ins(const char *x,int k)
{
	if (k < 0 || k > l)
		throw(int)k;
	ins(CPPString(x),k);
}
void CPPString::del(int k,int len){

	if (k > l||k<0) 
		throw (int)1;
	if (l < len + k)
		len = l - k ;
	char *t = new char[l - len];
	for(int i=0;i<k;i++)t[i]=s[i];
	for(int i=k+len;i<l;i++)t[i-len]=s[i];
	delete []s;
	s = t;
	l = l - len;
}
void CPPString::rep(const CPPString &x,int k,int len)
{
	if (k < 0 || k > l)
		throw(int)1;
	if (len + k > l)
		len = l - k ;
	del(k,len);
	ins(x,k);
}
void CPPString::rep(const char *x,int k,int len)
{
	if (k < 0 || k > l)
		throw(int)1;
	if (len + k >=l)
		len = l - k ;
	del(k,len);
	ins(x,k);
}
int CPPString::loc(const CPPString &x,int k)
{
	int r = -1;
	for (int i = 0; i < l && k>0; i++) {
		if (s[i] == x.s[0]) {
			k--;
		}
		if (k == 0)
			r = i;
	}
	std::cout << r << endl;
	if (r == -1)
		return -1;
	else
		return r;
}

int CPPString::loc(const char* x, int k)
{
	return loc(CPPString(x), k);
}
CPPString CPPString::cut(int h,int len)
{
	CPPString temp;
	if (h > l || h <0) 
		throw (int) 1;
	if (l <h + len)
	{
		len = l - h ;
		cout << "输出长度越界，自动取到最后一位" << endl;
	}
	temp.s = new char[len];
	for (int i = 0; i <len; i++)
		temp.s[i] = s[i+h];
	temp.l = len;
	return temp;
}
char &CPPString::operator[](const int &x)
{
	if (x > l)
		throw (int)1;
	return s[x];
}
CPPString CPPString::operator+(const CPPString &x)
{
	CPPString t=*this;
	t.ins(x,l);
	return t;
}
CPPString &CPPString::operator+=(const CPPString &x)
{
	ins(x,l);
	return *this;
}
CPPString CPPString::operator*(int y){
	CPPString t = *this;
	for(int i=1;i<y;i++)t.ins(*this,t.l);
	return t;
}
CPPString operator*(int y,const CPPString &x){
	CPPString t=x;
	for(int i=1;i<y;i++)t.ins(x,t.l);
	return t;
}
CPPString &CPPString::operator*=(int y){
	CPPString t=*this;
	for(int i=1;i<y;i++)*this+=t;
	return *this;
}
CPPString &CPPString::operator=(const CPPString &x){
	if(s!=NULL)delete []s;
	s=new char[x.l];
	for(int i=0;i<x.l;i++)s[i]=x.s[i];
	l=x.l;
	return *this;
}

ostream &operator<<(ostream &out,const CPPString &x){
	for(int i=0;i<x.l;i++)out<<x.s[i];
	return out;
}
istream &operator>>(istream &in, CPPString &x){
	char* t = new char[100];
	in.getline(t, 100, '\n');
	x = CPPString(t);
	delete[]t;
	return in;
}
bool CPPString::operator==(const CPPString &x)const{
	if(l!=x.l)
		return false;
	for (int i = 0; i < l; i++)
	{
		if (s[i] != x.s[i])
			return false;
	}
	return true;
}
bool CPPString::operator!=(const CPPString &x)const{
	if(l!=x.l)return true;
	for(int i=0;i<l;i++)if(s[i]!=x.s[i])return true;
	return false;
}
bool CPPString::operator>(const CPPString &x)const{
	int n=min(l,x.l);
	for(int i=0;i<n;i++){
		if(s[i]>x.s[i])return true;
		if(s[i]<x.s[i])return false;
	}
	if(l<x.l||x==*this)return false;
	return true;
}
bool CPPString::operator<(const CPPString &x)const{
int n=min(l,x.l);
	for(int i=0;i<n;i++){
		if(s[i]>x.s[i])return false;
		if(s[i]<x.s[i])return true;
	}
	if(l<x.l)return true;
	return false;
}
bool CPPString::operator>=(const CPPString &x)const{
int n=min(l,x.l);
	for(int i=0;i<n;i++){
		if(s[i]>x.s[i])return true;
		if(s[i]<x.s[i])return false;
	}
	if(l<x.l)return false;
	return true;
}
bool CPPString::operator<=(const CPPString &x)const{
	int n=min(l,x.l);
	for(int i=0;i<n;i++){
		if(s[i]>x.s[i])return false;
		if(s[i]<x.s[i])return true;
	}
	if(l<x.l||x==*this)return true;
	return false;
}
