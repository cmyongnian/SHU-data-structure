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
	    CPPString(const char *x); //���� 
	    CPPString(const CPPString &x);//ת������ 
	    ~CPPString();//���� 
	    int leng()const;//�����ַ������� 
	    void ins(const CPPString &x,int k=0);//��x�ӵ�kλǰ����     //d ����kԽ���쳣
	    void ins(const char *x,int k=0);                 
	    void del(int k,int len=1);//��kλ(����)��ɾ��len���ַ�     //d����k��lenԽ��
	    void rep(const CPPString &x,int k=0,int len=1);//��x�滻����kλ(����)���len���ַ� 
	    void rep(const char *x,int k=0,int len=1);
	    int loc(const CPPString &x,int k=1);//���ص�k��x�����ַ��±꣬û���򷵻�-1 
		int loc(const char* x, int k = 1);  //d����
	    CPPString cut(int h=0,int len=1);//�����Ե�hλ(����)���len���ַ����ɵ��ַ��� 
	    //CPPString MaxUp()const;//���ر��ַ�������������� 
	    //CPPString MAXDown()const;//���ر��ַ������������ 
	    char &operator[](const int &x);
	    CPPString operator+(const CPPString &x);
	    CPPString &operator+=(const CPPString &x);
	    CPPString operator*(int y);
	    friend CPPString operator*(int y,const CPPString &x);
	    CPPString &operator*=(int y);
	    CPPString &operator=(const CPPString &x);
	    friend std::ostream &operator<<(std::ostream &out,const CPPString &x);
	    friend std::istream &operator>>(std::istream &in,  CPPString &x); //d.ȥ�����뺯��const
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
