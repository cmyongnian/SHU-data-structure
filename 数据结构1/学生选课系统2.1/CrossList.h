#ifndef __CROSS_LIST_H__
#define __CROSS_LIST_H__
#define _CRT_SECURE_NO_WARNINGS
#include "Assistance.h"				// 辅助软件包
#include "crossnode.h"				// 十字链表三元组结点类
#include "triple.h"					// 三元组类
#include"Course.h"
#include"Student.h"

// 稀疏矩阵十字链表类
template<class ElemType>
class CrossList
{
protected:
//  稀疏矩阵十字链的数据成员:
	Student<ElemType>* rowHead;
	Course<ElemType>* colHead;  // 行列链表数组
	int RowMax=1000, ColMax=200;         // 课程和学生的最大容量
	int rows, cols, num;			// 稀疏矩阵的行数,列数及非零元个数


public:
// 稀疏矩阵十字链的方法声明:
	CrossList(int rs = DEFAULT_SIZE, int cs = DEFAULT_SIZE);
		// 构造一个rs行cs列的空稀疏矩阵
	~CrossList();				// 析构函数
	void Clear();					// 清空稀疏矩阵
	int GetRows() const { return rows; };			// 返回稀疏矩阵行数
    int GetCols() const { return cols; };			// 返回稀疏矩阵列数
    int GetNum() const { return num; };			// 返回稀疏矩阵非零元个数
	Status SetElem(int r, int c, const ElemType &v);	// 设置指定位置的元素值
	CrossList(const CrossList<ElemType> &b);	// 复制构造函数
	CrossList<ElemType> &operator =(const CrossList<ElemType> &b);    // 重载赋值运算符 

	//查询某个学生的选课情况（输出所选课程及学分）
	Status seek_student(Student<ElemType> &e);
	//查询某门课程的被选情况（包括剩余名额及选课学生信息）
	Status seek_course(Course<ElemType>& e);

	//修改某个学生的选课情况，包括选课和退选
	Status set_student_choose(Student<ElemType>& e, Course<ElemType> &c);
	Status set_student_delete(Student<ElemType>& e, Course<ElemType>& c);
	//增加和删除某名学生
	Status add_student(Student<ElemType>& e);
	Status delete_students(Student<ElemType>& e);
	
	//增加和删除某门课程
	Status add_courses(Course<ElemType>& e);
	Status delete_courses(Course<ElemType>& e);
	//修改某门课程的选课容量
	Status set_course_capacity(Course<ElemType>& e,int Capacity);
	Status save();
	//辅助函数
	friend void setj(Course<ElemType>& e);
	friend void seti(Student<ElemType>& e);
};

template<class ElemType>
void setj(Course<ElemType>& e)   //删除课程时调用的辅助函数
{
	CrossNode<ElemType>* ps = e.down;
	while (ps != NULL)
	{
		ps->triElem.col--;
		ps = ps->down;
	}
}



template<class ElemType>
void seti(Student<ElemType>& e) //删除学生时调用的辅助函数
{
	CrossNode<ElemType>* ps = e.right;
	while (ps != NULL)
	{
		ps->triElem.row--;
		ps = ps->right;
	}
}

// 稀疏矩阵十字链表类的实现部分
template <class ElemType>
Status CrossList<ElemType>::seek_student(Student<ElemType>& e)  //输出该学生所选的所有课程
{
	int s_row=0, i = 0;
	CrossNode<ElemType>* ps = nullptr;
	while (e != rowHead[i] && i < rows) {
		i++;
	}

	if (e == rowHead[i])
	{

		cout << rowHead[i] << endl;
		if (rowHead[i].right != NULL)
		{
			ps = rowHead[i].right;

			cout << "***已选课程***" << endl;
			while (ps != NULL && s_row<cols)
			{
				s_row = ps->triElem.col;
				cout << colHead[s_row] << endl;  //输出课程信息
				ps = ps->right;
			}

		}
		else {
			cout << "未选课" << endl;

		}


		return SUCCESS;
	}
	else {
		cout << "未找到该学生！" << endl;
		return FAIL;
	}
}

template <class ElemType>
Status CrossList<ElemType>::seek_course(Course<ElemType>& e)  //输出该课程下所有的学生
{
	int s_col=0, j = 0;
	CrossNode<ElemType>* pc;
	while (e != colHead[j] && j < cols) {
		j++;
	}

	if (e == colHead[j])
	{

		cout << colHead[j] << endl;
		if (colHead[j].down != NULL)
		{
			pc = colHead[j].down;
			cout << "***选择该课程的学生***" << endl;

			while (pc != NULL && s_col<rows)
			{
				s_col = pc->triElem.row;
				cout << rowHead[s_col] << endl;
				pc = pc->down;
			}

		}
		else {
			cout << "无人选课" << endl;

		}


		return SUCCESS;
	}
	else {
		cout << "未找到该课程！" << endl;
		return FAIL;
	}
}


//修改某个学生的选课情况，包括选课和退选

template <class ElemType>
Status CrossList<ElemType>::set_student_choose(Student<ElemType>& e, Course<ElemType> &c)
//选课函数
{
	if (e.coursecapacity == 5)      //该学生已选满课程
		return FAIL;        
	else
	{
		int i = 0, j = 0;
		
		CrossNode<ElemType>* pc = nullptr;
		CrossNode<ElemType>* ps = nullptr;
		CrossNode<ElemType>* pcr = nullptr;

		while (rowHead[i] != e && i < rows) {
			i++;
		}
		while (c != colHead[j] && j< cols)
		{
			j++;
		}
		if (colHead[j] != c)      //该课程不存在
			return FAIL2;
		if (colHead[j].capacity == colHead[j].Maxcapacity)     //课程已选满
			return RANGE_ERROR;

		ps = rowHead[i].right;
        pc = colHead[j].down;

		if (rowHead[i].right != NULL)  //排除该学生未选课的情况
		{
			while (ps->right != NULL && ps->triElem.col <= j) //将ps指针指向待添加节点的左一个节点
			{
				ps = ps->right;
			}
			while (pc->down != NULL && pc->triElem.row <= i) //将pc指针指向待添加节点的上一个节点
			{
				pc = pc->down;
			}
		}
		

		Triple<ElemType> NewTriple(i, j, 1);
		pcr = new CrossNode<ElemType>(NewTriple);
		
		//将新增节点添加到行链表中
		if (rowHead[i].right == NULL)
		{
			pcr->right = rowHead[i].right;
			rowHead[i].right = pcr;
		}
		else if (ps->triElem.col > j)
		{
			pcr->right = rowHead[i].right;
			rowHead[i].right = pcr;
		}
		else
		{
			pcr->right = ps->right;
			ps->right = pcr;
		}

		//将新增节点添加到列链表中
		if (pc->triElem.row > i)
		{
			pcr->down = colHead[j].down;
			colHead[j].down = pcr;
		}
		else
		{
			pcr->down = pc->down;
			pc->down = pcr;
		}

		e.coursecapacity++;
		colHead[j].capacity++;
		return SUCCESS;
	}
}
template <class ElemType>
Status CrossList<ElemType>::set_student_delete(Student<ElemType>& e,Course<ElemType> &c)
//退课函数
{
	int i = 0, j = 0;

	CrossNode<ElemType>* pc = nullptr;
	CrossNode<ElemType>* ps = nullptr;
	while (rowHead[i] != e && i < rows)
	{
		i++;
	}

	if (e == rowHead[i])   //找到学生所在处
	{
		while (c != colHead[j] && j < cols)
		{
			j++;
		}
		if (colHead[j] != c)
		{
			return FAIL;
		}
		else
		{
			ps = colHead[j].down;               //节点从纵向链表中脱链
			pc = ps;
			if (ps->triElem.row == i)            
			{
				colHead[j].down = ps->down;
			}
			else
			{
				while (ps->down->triElem.row != i)
					ps = ps->down;
				pc = ps->down;
				ps->down = pc->down;
			}

			ps = rowHead[i].right;               //节点从横向链表中脱链
			pc = ps;
			if (ps->triElem.col == j)
			{
				rowHead[i].right = ps->right;
				delete[] ps;
			}
			else
			{
				while (ps->right->triElem.col != j)
					ps = ps->right;
				pc = ps->right;
				ps->right = pc->right;
				delete[] pc;
			}
			e.coursecapacity--;
			colHead[j].capacity--;
			return SUCCESS;
		}
	}
	else 
	{
		return FAIL1;
	}
}

template <class ElemType>
Status CrossList<ElemType>::add_student(Student<ElemType>& e)
{
	if (rows <= RowMax) {
		rowHead[++rows] = e;
		return SUCCESS;
	}
	else
	{
		return FAIL;
	}
}

template <class ElemType>
Status CrossList<ElemType>::delete_students(Student<ElemType>& e)
{
	int i = 0, j = 0;
	CrossNode<ElemType>* ps=NULL, * pc=NULL, * pcr=NULL;
	while (e != rowHead[i] && i <= rows)
	{
		i++;
	}
	if (e == rowHead[i])
	{
		while (rowHead[i].right != NULL)
		{
			j = rowHead[i].right->triElem.col;
			pc = colHead[j].down;
			if (pc == rowHead[i].right)
			{
				colHead[j].down = pc->down;
				pcr = pc;
			}
			else {
				while (pc->down != NULL && pc->down->triElem.row < i)
				{
					pc = pc->down;
				}
				if (pc->down == rowHead[i].right) {
					pcr = pc->down;
					pc->down = pcr->down;
				}
				
			}
			rowHead[i].right = rowHead[i].right->right;
			delete[] pcr;
		}
	}
	else return FAIL;

	for (; i < rows; i++) {
		rowHead[i] = rowHead[i + 1];
		seti(rowHead[i]);
	}
	rows--;
	return SUCCESS;
}

template <class ElemType>
Status CrossList<ElemType>::add_courses(Course<ElemType>& e)
{
	if (cols <= ColMax) {
		colHead[++cols] = e;
		return SUCCESS;
	}
	else
	{
		return FAIL;
	}
}

template <class ElemType>
Status CrossList<ElemType>::delete_courses(Course<ElemType>& e)
{
	int i = 0, j = 0;
	CrossNode<ElemType>* ps = NULL, * pc = NULL, * pcr = NULL;
	while (e != colHead[j] && j <= cols)
	{
		j++;
	}
	if (e == colHead[j])
	{
		while (colHead[j].down != NULL)
		{
			i = colHead[j].down->triElem.row;
			pc = rowHead[i].right;
			if (pc == colHead[j].down) {
				rowHead[i].right = pc->right;
				pcr = pc;
			}
			else {
				while (pc->right != NULL && pc->right->triElem.col < j)
				{
					pc = pc->right;
				}
				if (pc->right == colHead[j].down) {
					pcr = pc->right;
					pc->right = pcr->right;
				}
			}
			
			colHead[j].down = colHead[j].down->down;

			delete[] pcr;
		}
	}
	else return FAIL;

	for (; j < cols; j++)
	{
		colHead[j] = colHead[j + 1];
		setj(colHead[j]);
	}


	cols--;
	return SUCCESS;
}

template <class ElemType>
Status CrossList<ElemType>::set_course_capacity(Course<ElemType>& e, int Capacity)
{
	int i = 0;
	while (colHead[i] != e)
	{
		i++;
	}
	if (e == colHead[i])
	{
		colHead[i].Maxcapacity = Capacity;
		return SUCCESS;
	}
	else
		return FAIL;
}


template <class ElemType>
CrossList<ElemType>::CrossList(int rs, int cs)
// 操作结果：构造一个rs行cs列的空稀疏矩阵
{
	if (rs < 1 || cs < 1||rs>RowMax||cs>ColMax)							
		throw Error("行数或列数无效!");	// 抛出异常
	RowMax = rs;							// 行数
	ColMax = cs;							// 列数
	rows = -1;
	cols = -1;
	num = 0;							// 非零元个数
	rowHead = new Student<ElemType> [RowMax];	// 分配行链表表头数组存储空间
	colHead = new Course<ElemType> [ColMax];	// 分配行链表表头数组存储空间
	for (int row = 0; row < RowMax; row++)
		rowHead[row].right = NULL;			// 初始化行链表表头数组
	for (int col = 0; col < ColMax; col++)
		colHead[col].down = NULL;			// 初始化行链表表头数组
}


template <class ElemType>
CrossList<ElemType>::~CrossList()
// 操作结果：稀疏矩阵所占用空间
{
	Clear();
	delete []rowHead;					// 释放行链表表头数组
	delete []colHead;					// 释放列链表表头数组
}


template <class ElemType>
Status CrossList<ElemType>::SetElem(int r, int c, const ElemType& v)
// 操作结果：如果下标范围错,则返回RANGE_ERROR,否则返回SUCCESS
{
	if (r >= RowMax || c >= ColMax || r < 0 || c < 0)
		return RANGE_ERROR;				// 下标范围错
	CrossNode<ElemType>* pre, * p;
	if (v == 0) {  // 把第r行、第c列的值修改为零 
		pre = NULL; p = rowHead[r].right;	// p指向相应结点，pre为p的前驱结点 
		while (p != NULL && p->triElem.col < c) {
			pre = p;
			p = p->right;
		}

		if (p != NULL && p->triElem.col == c) {// 原元素为非零元素，则删除p结点
			//  修改相应行中结点的指针    
			if (rowHead[r].right == p)
				rowHead[r].right = p->right;
			else
				pre->right = p->right;

			//  修改相应列中结点的指针    
			if (colHead[c].down == p)
				colHead[c].down = p->down;
			else {
				pre = colHead[c].down;
				while (pre->down != p)
					pre = pre->down;
				pre->down = p->down;
			}
			delete p;
			num--;				// 删除结点,非零元素个数减1
		}
	}
	else {  // 把第r行、第c列的值修改为非零元素 
		pre = NULL; p = rowHead[r].right;	// p指向相应结点，pre为p的前驱结点 
		while (p != NULL && p->triElem.col < c) {
			pre = p;	p = p->right;
		}

		if (p != NULL && p->triElem.col == c)  	// 原结点为非零元素，则直接修改其值 
			p->triElem.value == v;
		else { 	// 原结点为0元素，则需要插入结点
			Triple<ElemType> e(r, c, v);		// 三元组
			CrossNode<ElemType>* ePtr = new CrossNode<ElemType>(e);//生成结点
			// 把结点插入到相应行中    	    
			if (rowHead[r].right == p)
				rowHead[r].right = ePtr;
			else
				pre->right = ePtr;
			ePtr->right = p;
			// 把结点插入到相应列中    	    
			pre = NULL; p = colHead[c].down;
			while (p != NULL && p->triElem.row < r) {
				pre = p;
				p = p->down;
			}
			if (colHead[c].down == p)
				colHead[c].down = ePtr;
			else
				pre->down = ePtr;
			ePtr->down = p;
			num++;							// 完成插入结点后非零元素个数加一 
		}
	}
	return SUCCESS;							// 返回修改成功
}

template <class ElemType>
void CrossList<ElemType>::Clear()
// 操作结果：清空稀疏矩阵
{
    CrossNode<ElemType> *p;
	for (int i = 0; i < RowMax; i++)
		while (rowHead[i].right!= NULL)	{   // 释放第row行的结点所点用空间
			p =  rowHead[i].right;		
			rowHead[i].right = p->right;	
			delete p;
		}
	for (int j = 0; j < ColMax; j++)
		colHead[j].down = NULL;			// 初始化行链表表头数组
    num = 0;
}

template <class ElemType>
CrossList<ElemType>::CrossList(const CrossList<ElemType> &b)
// 操作结果：由稀疏矩阵b构造新稀疏矩阵——复制构造函数
{
    CrossNode<ElemType> *p;
	rows = b.rows;					// 复制行数
	cols = b.cols;	// 复制列数
	RowMax = b.RowMax;
	ColMax = b.ColMax;
	num = 0;						// 初始化非零元个数
	rowHead = new Student<ElemType> *[RowMax];	// 分配行链表表头数组存储空间
	colHead = new Course<ElemType> *[ColMax];	// 分配行链表表头数组存储空间
	for (int i = 0; i < RowMax; i++)
		rowHead[i].right = NULL;			// 初始化行链表表头数组
	for (int i = 0; i < ColMax; i++)
		colHead[i].down = NULL;			// 初始化行链表表头数组
	
	for (int i = 0; i < RowMax; i++)
		for (p = b.rowHead[i].right; p != NULL; p = p->right)
			SetElem(p->triElem.row, p->triElem.col, p->triElem.value);
}

template <class ElemType>
CrossList<ElemType> &CrossList<ElemType>::operator =(const CrossList<ElemType> &b)
// 操作结果：将稀疏矩阵b赋值给当前稀疏矩阵——赋值语句重载
{
    if (RowMax != b.RowMax || ColMax != b.ColMax)
        throw Error("行数或列数不相等!");	// 抛出异常

	if (&b != this) {
	    CrossNode<ElemType> *p;
		Clear();						// 清空稀疏矩阵
		num = b.num;					// 初始化非零元个数
		for (int i = 0; i < rows; i++)
			for (p = b.rowHead[i].right; p != NULL; p = p->right)
			   SetElem(p->triElem.row, p->triElem.col, p->triElem.value);
	}
	return *this;

}


template <class ElemType>
Status CrossList<ElemType>::save() {
	string saveFilePath = "new_stu.txt";
	ofstream ofs;
	ofs.open(saveFilePath, ios::out);

	if (!ofs.is_open()) {
		std::cerr << "无法打开文件: " << saveFilePath << std::endl;
		return FAIL;
	}
	else {
		cout << "new_std.txt打开成功" << endl;
	}
	int num;
	string nam;
	for (int i = 0; i <= rows; i++) {
		num = rowHead[i].stunumber;
		nam = rowHead[i].name;
		ofs << num << '\t' << nam << endl;
	}

	ofs.close();
	///////////////////////////////////////////////////////
	cout << "保存成功" << endl;

	saveFilePath = "new_course.txt";

	ofs.open(saveFilePath, ios::out);

	if (!ofs.is_open()) {
		std::cerr << "无法打开文件: " << saveFilePath << std::endl;
		return FAIL;
	}
	else {
		cout << "new_course.txt打开成功" << endl;
	}
	string numb;
	nam;
	int cred;
	int cap;      //当前选课人数
	int Maxca;   //最大人数
	for (int i = 0; i <= cols; i++) {
		numb = colHead[i].num;
		nam = colHead[i].name;
		cred = colHead[i].credit;
		Maxca = colHead[i].Maxcapacity;
		ofs << numb << '\t' << nam << '\t' << cred << '\t' << Maxca << endl;
	}

	ofs.close();
	cout << "保存成功" << endl;
	///////////////////////////////////////////////////////
	CrossNode<ElemType>* ps = NULL, * pc = NULL, * pcr = NULL;
	saveFilePath = "new_selection.txt";

	ofs.open(saveFilePath, ios::out);

	if (!ofs.is_open()) {
		std::cerr << "无法打开文件: " << saveFilePath << std::endl;
		return FAIL;
	}
	else {
		cout << "new_selection.txt打开成功" << endl;
	}


	for (int i = 0; i <= rows; i++) {
		ps = rowHead[i].right;
		for (int j = 0; j <= cols; j++) {
			if (ps == NULL)
			{
				ofs << "0 ";
			}
			else {
				if (j != ps->triElem.col) {
					ofs << "0 ";
				}
				else {
					ofs << "1 ";
					ps = ps->right;
				}
			}
		}
		ofs << endl;
	}



	ofs.close();
	cout << "保存成功" << endl;


}
#endif
