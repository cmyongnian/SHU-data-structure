#include "CrossList.h"		// 稀疏矩阵的三元组顺序表
#define _CRT_SECURE_NO_WARNINGS
#include "CrossList.h"

int main()
{
	CrossList<int> C(1000, 200);

	//在下面进行数据读入
	// 读学生
	string filePath = "stu.txt";
	ifstream inputFile(filePath);
	if (!inputFile.is_open()) {
		cerr << "无法打开文件: " << filePath << endl;
		return 1;
	}
	// 读取学生学号和姓名信息
	int studentID;
	string studentName;
	while (inputFile >> studentID >> studentName) {
		// 在这里可以处理读取到的学生学号和姓名，例如输出到控制台
		Student<int> s(studentID, studentName);
		C.add_student(s);
	}
	inputFile.close();


	//读课程
	string filePath_2 = "course.txt";
	ifstream inputFile_2(filePath_2);
	if (!inputFile_2.is_open()) {
		cerr << "无法打开文件: " << filePath_2 << endl;
		return 1;
	}
	// 读取课程信息
	string num;
	string name;
	int credit;
	int capacity;
	while (inputFile_2 >> num >> name >> credit >> capacity) {
		// 在这里可以处理读取到的课程信息，例如输出到控制台
		Course<int> c(num, name, credit, capacity);
		C.add_courses(c);
	}
	inputFile_2.close();

	//读稀疏矩阵
	int i = 0, j = 0;
	int value;
	string filePath_3 = "selection.txt";
	ifstream inputFile_3(filePath_3);
	if (!inputFile_3.is_open()) {
		cerr << "无法打开文件: " << filePath_3 << endl;
		return 1;
	}
	else {
		cout << "读取成功" << endl;
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
		cout << "╔════════════════════════════════════╗" << endl;
		cout << "║          学生选课系统              ║" << endl;
		cout << "╠════════════════════════════════════╣" << endl;
		cout << "║  1. 输入学号姓名登录选课系统       ║" << endl;
		cout << "║  2. 增加或删除学生信息             ║" << endl;
		cout << "║  3. 查询课程被选情况               ║" << endl;
		cout << "║  4. 修改课程学生容量               ║" << endl;
		cout << "║  5. 增加或删除课程                 ║" << endl;
		cout << "║  6. 保存数据                       ║" << endl;
		cout << "║  0. 退出                           ║" << endl;
		cout << "╚════════════════════════════════════╝" << endl;
		cout << "请从0~5中选择你要进行的操作：";
		cin >> a;

		switch (a)
		{
		case'1':
		{
			Student<int> s;
			cout << "请输入你的学号和姓名：" << endl;
			cin >> s;

			//查询课程
			if (C.seek_student(s) == SUCCESS) {
				cout << "登录成功！" << endl;
			}
			else {
				cout << "错误，未找到学生信息!" << endl;
				continue;
			}

			//继续下一步操作
			cout << endl;

			int temp = 2;
			while (temp != 0)
			{
				cout << endl;
				cout << "请选择你要进行的操作" << endl;
				cout << "1.选课" << endl
					<< "2.退课" << endl
					<< "3.课表查询" << endl
					<< "0.退出" << endl;
				cin >> temp;

				if (temp == 1)  //选课
				{
					Course<int> c;
					Status sta;
					cin >> c;
					sta = C.set_student_choose(s, c);
					if (sta == SUCCESS) {
						cout << "选课成功！" << endl;
					}
					else if (sta == FAIL2) {
						cout << "所选课程不存在！" << endl;
					}
					else if (sta == RANGE_ERROR) {
						cout << "所选课程人数已满！" << endl;
					}
					else if (sta == FAIL) {
						cout << "选课数已达上限！" << endl;
					}

					else if (sta == DUPLICATE_ERROR) {
						cout << "重复选课" << endl;

					}
				}
				else if (temp == 2)  //退课
				{
					Course<int> c;
					Status sta;
					cin >> c;

					sta = C.set_student_delete(s, c);
					if (sta == SUCCESS)

						cout << "退课成功！" << endl;
					else if (sta == FAIL1) {
						cout << "未找到该学生！" << endl;
					}

					else if (sta == FAIL) {
						cout << "未选择该课程。" << endl;
					}

				}
				else if (temp == 3) {
					C.seek_student(s);
				}
				else if (temp == 0) {
					cout << "退出成功！";

				}
				else { cout << "操作失败！" << endl; }
			}
			break;
		}

		case'2':
		{
			int temp = 2;
			while (temp != 0)
			{
				cout << endl;
				cout << "请选择你要进行的操作" << endl
					<< "1.增加学生信息" << endl
					<< "2.删除学生信息" << endl
					<< "0.退出" << endl;
				cin >> temp;
				if (temp == 0) break;
				Student<int> s;
				cout << "请输入学生信息：" << endl;
				cin >> s;
				if ((temp == 1 && C.add_student(s) == SUCCESS) || (temp == 2 && C.delete_students(s) == SUCCESS))
				{
					cout << "操作成功！" << endl;
				}
				else {
					cout << "操作失败！！" << endl;
				}
			}
			break;
		}

		case'3':
		{
			Course<int> c;
			cout << "请输入你想查询的课程." << endl;
			cin >> c;
			if (C.seek_course(c) == SUCCESS) {
				cout << "查询成功！" << endl;
			}
			else {
				cout << "查询失败！!" << endl;
			}
			break;
		}

		case'4':
		{
			int capacity;
			Course<int> d;
			cout << "请输入你想修改容量的课程：" << endl;
			cin >> d;
			cout << "请输入新容量：" << endl;
			cin >> capacity;
			if (C.set_course_capacity(d, capacity) == SUCCESS) {
				cout << "操作成功！" << endl;
			}
			else {
				cout << "操作失败！！" << endl;
			}
			break;
		}

		case'5':
		{
			int temp = 2;
			while (temp != 0) {
				cout << endl;
				cout << "请选择你要进行的操作" << endl
					<< "1.增加课程" << endl
					<< "2.删除课程" << endl
					<< "0.退出" << endl;
				cin >> temp;
				if (temp == 0) break;
				Course<int> c;

				cout << "请输入课程号和课程名称：" << endl;
				cin >> c;
				if ((temp == 1 && C.add_courses(c) == SUCCESS) || (temp == 2 && C.delete_courses(c) == SUCCESS))
				{
					cout << "操作成功！" << endl;
				}
				else {
					cout << "操作失败！！" << endl;
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







	system("PAUSE");        // 调用库函数system()
	return 0;               // 返回值0, 返回操作系统
}
