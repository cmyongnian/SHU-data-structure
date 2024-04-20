#include "CrossList.h"		// ϡ��������Ԫ��˳���
#define _CRT_SECURE_NO_WARNINGS
#include "CrossList.h"

int main()
{
	CrossList<int> C(1000, 200);

	//������������ݶ���
	// ��ѧ��
	string filePath = "stu.txt";
	ifstream inputFile(filePath);
	if (!inputFile.is_open()) {
		cerr << "�޷����ļ�: " << filePath << endl;
		return 1;
	}
	// ��ȡѧ��ѧ�ź�������Ϣ
	int studentID;
	string studentName;
	while (inputFile >> studentID >> studentName) {
		// ��������Դ����ȡ����ѧ��ѧ�ź��������������������̨
		Student<int> s(studentID, studentName);
		C.add_student(s);
	}
	inputFile.close();


	//���γ�
	string filePath_2 = "course.txt";
	ifstream inputFile_2(filePath_2);
	if (!inputFile_2.is_open()) {
		cerr << "�޷����ļ�: " << filePath_2 << endl;
		return 1;
	}
	// ��ȡ�γ���Ϣ
	string num;
	string name;
	int credit;
	int capacity;
	while (inputFile_2 >> num >> name >> credit >> capacity) {
		// ��������Դ����ȡ���Ŀγ���Ϣ���������������̨
		Course<int> c(num, name, credit, capacity);
		C.add_courses(c);
	}
	inputFile_2.close();

	//��ϡ�����
	int i = 0, j = 0;
	int value;
	string filePath_3 = "selection.txt";
	ifstream inputFile_3(filePath_3);
	if (!inputFile_3.is_open()) {
		cerr << "�޷����ļ�: " << filePath_3 << endl;
		return 1;
	}
	else {
		cout << "��ȡ�ɹ�" << endl;
	}
	for (i = 0;i < 900;i++) {
		for (j = 0;j < 100;j++) {
			inputFile_3 >> value;
			C.SetElem(i, j, value);
		}
	}
	inputFile_3.close();

	char a = '*';
	while (a != '0')
	{
		cout << endl;
		cout << "�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[" << endl;
		cout << "�U          ѧ��ѡ��ϵͳ              �U" << endl;
		cout << "�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g" << endl;
		cout << "�U  1. ����ѧ��������¼ѡ��ϵͳ       �U" << endl;
		cout << "�U  2. ���ӻ�ɾ��ѧ����Ϣ             �U" << endl;
		cout << "�U  3. ��ѯ�γ̱�ѡ���               �U" << endl;
		cout << "�U  4. �޸Ŀγ�ѧ������               �U" << endl;
		cout << "�U  5. ���ӻ�ɾ���γ�                 �U" << endl;
		cout << "�U  6. ��������                       �U" << endl;
		cout << "�U  0. �˳�                           �U" << endl;
		cout << "�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a" << endl;
		cout << "���0~5��ѡ����Ҫ���еĲ�����";
		cin >> a;

		switch (a)
		{
		case'1':
		{
			Student<int> s;
			cout << "���������ѧ�ź�������" << endl;
			cin >> s;

			//��ѯ�γ�
			if (C.seek_student(s) == SUCCESS) {
				cout << "��¼�ɹ���" << endl;
			}
			else {
				cout << "����δ�ҵ�ѧ����Ϣ!" << endl;
				continue;
			}

			//������һ������
			cout << endl;

			int temp = 2;
			while (temp != 0)
			{
				cout << endl;
				cout << "��ѡ����Ҫ���еĲ���" << endl;
				cout << "1.ѡ��" << endl
					<< "2.�˿�" << endl
					<< "3.�α��ѯ" << endl
					<< "0.�˳�" << endl;
				cin >> temp;

				if (temp == 1)  //ѡ��
				{
					Course<int> c;
					Status sta;
					cin >> c;
					sta = C.set_student_choose(s, c);
					if (sta == SUCCESS) {
						cout << "ѡ�γɹ���" << endl;
					}
					else if (sta == FAIL2) {
						cout << "��ѡ�γ̲����ڣ�" << endl;
					}
					else if (sta == RANGE_ERROR) {
						cout << "��ѡ�γ�����������" << endl;
					}
					else if (sta == FAIL) {
						cout << "ѡ�����Ѵ����ޣ�" << endl;
					}

					else if (sta == DUPLICATE_ERROR) {
						cout << "�ظ�ѡ��" << endl;

					}
				}
				else if (temp == 2)  //�˿�
				{
					Course<int> c;
					Status sta;
					cin >> c;

					sta = C.set_student_delete(s, c);
					if (sta == SUCCESS)

						cout << "�˿γɹ���" << endl;
					else if (sta == FAIL1) {
						cout << "δ�ҵ���ѧ����" << endl;
					}

					else if (sta == FAIL) {
						cout << "δѡ��ÿγ̡�" << endl;
					}

				}
				else if (temp == 3) {
					C.seek_student(s);
				}
				else if (temp == 0) {
					cout << "�˳��ɹ���";

				}
				else { cout << "����ʧ�ܣ�" << endl; }
			}
			break;
		}

		case'2':
		{
			int temp = 2;
			while (temp != 0)
			{
				cout << endl;
				cout << "��ѡ����Ҫ���еĲ���" << endl
					<< "1.����ѧ����Ϣ" << endl
					<< "2.ɾ��ѧ����Ϣ" << endl
					<< "0.�˳�" << endl;
				cin >> temp;
				if (temp == 0) break;
				Student<int> s;
				cout << "������ѧ����Ϣ��" << endl;
				cin >> s;
				if ((temp == 1 && C.add_student(s) == SUCCESS) || (temp == 2 && C.delete_students(s) == SUCCESS))
				{
					cout << "�����ɹ���" << endl;
				}
				else {
					cout << "����ʧ�ܣ���" << endl;
				}
			}
			break;
		}

		case'3':
		{
			Course<int> c;
			cout << "�����������ѯ�Ŀγ�." << endl;
			cin >> c;
			if (C.seek_course(c) == SUCCESS) {
				cout << "��ѯ�ɹ���" << endl;
			}
			else {
				cout << "��ѯʧ�ܣ�!" << endl;
			}
			break;
		}

		case'4':
		{
			int capacity;
			Course<int> d;
			cout << "�����������޸������Ŀγ̣�" << endl;
			cin >> d;
			cout << "��������������" << endl;
			cin >> capacity;
			if (C.set_course_capacity(d, capacity) == SUCCESS) {
				cout << "�����ɹ���" << endl;
			}
			else {
				cout << "����ʧ�ܣ���" << endl;
			}
			break;
		}

		case'5':
		{
			int temp = 2;
			while (temp != 0) {
				cout << endl;
				cout << "��ѡ����Ҫ���еĲ���" << endl
					<< "1.���ӿγ�" << endl
					<< "2.ɾ���γ�" << endl
					<< "0.�˳�" << endl;
				cin >> temp;
				if (temp == 0) break;
				Course<int> c;

				cout << "������γ̺źͿγ����ƣ�" << endl;
				cin >> c;
				if ((temp == 1 && C.add_courses(c) == SUCCESS) || (temp == 2 && C.delete_courses(c) == SUCCESS))
				{
					cout << "�����ɹ���" << endl;
				}
				else {
					cout << "����ʧ�ܣ���" << endl;
				}
			}
			break;
		}
		case'6':
		{
			C.save();
			break;
		}

		}
	}







	system("PAUSE");        // ���ÿ⺯��system()
	return 0;               // ����ֵ0, ���ز���ϵͳ
}
