#include"CPPString.h"
using namespace std;

void test1()
{
	cout << "-------------------------------------------" << endl;
	cout << "              A.�����ַ�����������" << endl;
	CPPString s("123789"), s1("456"), s2("789"), s3("147"), s4("258"), s5("123456123456"), s6("112233");
	cout << "-------------------------------------------" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "���ȣ�leng()" << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s1.leng() = " << s1 .leng()<< endl;
	cout << "-------------------------------------------" << endl;
	cout << "��insert()" << endl;
	cout << "s2 = " << s2 <<'\t'<<"s1="<<s1<< endl;
	s2.ins(s1,2);
	cout << "s2.ins(s1,2) = " << s2 << endl;
	cout << "s3=" << s3 << endl;
	s3.ins("789", 2);
	cout<< "s.ins('789',2)" << s3 << endl;
	cout << "-------------------------------------------" << endl;
	cout << "��replace()" << endl;
	cout << "s4 = " << s4 << '\t'<<"s="<<s<< '\t' << "s1=" << s1 << endl;
	s4.rep(s,1,2);
	cout << "s4.replace(s,1,2) = " << s4 << endl;
	s.rep(s1, 4, 3);
	cout << "s.replace(s1,4,3)=" << s << endl;
	cout << endl;
	cout << "-------------------------------------------" << endl;
	cout << "��find()" << endl;
	cout << "s5 = " << s5 << '\t' << "s=" << s << endl;
	cout << "s5.loc(s,1) = " << s5.loc(s, 1) << endl;
	cout << "s5.loc('456',2)=" << s5.loc("456", 2) << endl;
	cout << endl;
	cout << "-------------------------------------------" << endl;
	cout << "ɾdelete()" << endl;
	cout << "s6 = " << s6 << endl;
	s6.del(2, 3);
	cout << "s6.del(2,3) = " <<s6<< endl;
	cout << endl;
	cout << "-------------------------------------------" << endl;
	cout << "ȡ�ִ�cut()" << endl;
	cout << "s5="<<s5 << endl;
	cout << "s5.cut(3,5)=" << s5.cut(3, 5) << endl;
	CPPString ns = CPPString(s5.cut(8, 6));
	cout << "s5.cut(8,6)=" << ns << endl;
	cout << endl;
	system("pause");
}
void test2()
{
	cout << "-------------------------------------------" << endl;
	cout << "                  B.���Ի��������" << endl;
	cout << "-------------------------------------------" << endl;
	CPPString str1("00000"), str2("11111"), str3("22222"), str4("33333"), str5("12345");
	cout << "str1=" << str1<< endl;
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
	cout << "str4 += str1" << '\t'<<"str4=" <<str4<< endl;
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
	system("pause");
}
void test3()
{
	CPPString s("123"), s1("456"), s2("789"), s3("147"), s4("123"), s5("369");
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
	CPPString str1 = "abcd", str2 = "abcd", str3 = "abcd", str4 = "abcd", str5 = "abcd", str6 = "abcd";
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
		str2.del(5,4);
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
		str4.rep(str1, 5,4);
		cout<<"str4="<<str4 << endl;
		cout << endl;
		cout << "str5=" << str5 << endl;
		cout << "str5.rep('efg', 5, 3) " << endl;
		str5.rep("efg",5,3);
		cout<< "str5="<<str5 << endl;
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
		cout<< str6[5] << endl;
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
	CPPString s1 = "abcd", s2 = "1234";
	cout << "s1=" << s1 << '\t' << "s2=" << s2 << endl;
	s1 *= 2;
	cout <<"s1*=2"<<'\t' <<"s1=" << s1 << endl;
	cout <<"s2*2="<< s2 * 2 << endl;
	cout <<"2*s2="<< 2 * s2 << endl;
	cout << endl;
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
	return 0;
}
