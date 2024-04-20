#ifndef __CROSS_LIST_H__
#define __CROSS_LIST_H__
#define _CRT_SECURE_NO_WARNINGS
#include "Assistance.h"				// ���������
#include "crossnode.h"				// ʮ��������Ԫ������
#include "triple.h"					// ��Ԫ����
#include"Course.h"
#include"Student.h"

// ϡ�����ʮ��������
template<class ElemType>
class CrossList
{
protected:
//  ϡ�����ʮ���������ݳ�Ա:
	Student<ElemType>* rowHead;
	Course<ElemType>* colHead;  // ������������
	int RowMax=1000, ColMax=200;         // �γ̺�ѧ�����������
	int rows, cols, num;			// ϡ����������,����������Ԫ����


public:
// ϡ�����ʮ�����ķ�������:
	CrossList(int rs = DEFAULT_SIZE, int cs = DEFAULT_SIZE);
		// ����һ��rs��cs�еĿ�ϡ�����
	~CrossList();				// ��������
	void Clear();					// ���ϡ�����
	int GetRows() const { return rows; };			// ����ϡ���������
    int GetCols() const { return cols; };			// ����ϡ���������
    int GetNum() const { return num; };			// ����ϡ��������Ԫ����
	Status SetElem(int r, int c, const ElemType &v);	// ����ָ��λ�õ�Ԫ��ֵ
	CrossList(const CrossList<ElemType> &b);	// ���ƹ��캯��
	CrossList<ElemType> &operator =(const CrossList<ElemType> &b);    // ���ظ�ֵ����� 

	//��ѯĳ��ѧ����ѡ������������ѡ�γ̼�ѧ�֣�
	Status seek_student(Student<ElemType> &e);
	//��ѯĳ�ſγ̵ı�ѡ���������ʣ�����ѡ��ѧ����Ϣ��
	Status seek_course(Course<ElemType>& e);

	//�޸�ĳ��ѧ����ѡ�����������ѡ�κ���ѡ
	Status set_student_choose(Student<ElemType>& e, Course<ElemType> &c);
	Status set_student_delete(Student<ElemType>& e, Course<ElemType>& c);
	//���Ӻ�ɾ��ĳ��ѧ��
	Status add_student(Student<ElemType>& e);
	Status delete_students(Student<ElemType>& e);
	
	//���Ӻ�ɾ��ĳ�ſγ�
	Status add_courses(Course<ElemType>& e);
	Status delete_courses(Course<ElemType>& e);
	//�޸�ĳ�ſγ̵�ѡ������
	Status set_course_capacity(Course<ElemType>& e,int Capacity);
	Status save();
	//��������
	friend void setj(Course<ElemType>& e);
	friend void seti(Student<ElemType>& e);
};

template<class ElemType>
void setj(Course<ElemType>& e)   //ɾ���γ�ʱ���õĸ�������
{
	CrossNode<ElemType>* ps = e.down;
	while (ps != NULL)
	{
		ps->triElem.col--;
		ps = ps->down;
	}
}



template<class ElemType>
void seti(Student<ElemType>& e) //ɾ��ѧ��ʱ���õĸ�������
{
	CrossNode<ElemType>* ps = e.right;
	while (ps != NULL)
	{
		ps->triElem.row--;
		ps = ps->right;
	}
}

// ϡ�����ʮ���������ʵ�ֲ���
template <class ElemType>
Status CrossList<ElemType>::seek_student(Student<ElemType>& e)  //�����ѧ����ѡ�����пγ�
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

			cout << "***��ѡ�γ�***" << endl;
			while (ps != NULL && s_row<cols)
			{
				s_row = ps->triElem.col;
				cout << colHead[s_row] << endl;  //����γ���Ϣ
				ps = ps->right;
			}

		}
		else {
			cout << "δѡ��" << endl;

		}


		return SUCCESS;
	}
	else {
		cout << "δ�ҵ���ѧ����" << endl;
		return FAIL;
	}
}

template <class ElemType>
Status CrossList<ElemType>::seek_course(Course<ElemType>& e)  //����ÿγ������е�ѧ��
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
			cout << "***ѡ��ÿγ̵�ѧ��***" << endl;

			while (pc != NULL && s_col<rows)
			{
				s_col = pc->triElem.row;
				cout << rowHead[s_col] << endl;
				pc = pc->down;
			}

		}
		else {
			cout << "����ѡ��" << endl;

		}


		return SUCCESS;
	}
	else {
		cout << "δ�ҵ��ÿγ̣�" << endl;
		return FAIL;
	}
}


//�޸�ĳ��ѧ����ѡ�����������ѡ�κ���ѡ

template <class ElemType>
Status CrossList<ElemType>::set_student_choose(Student<ElemType>& e, Course<ElemType> &c)
//ѡ�κ���
{
	if (e.coursecapacity == 5)      //��ѧ����ѡ���γ�
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
		if (colHead[j] != c)      //�ÿγ̲�����
			return FAIL2;
		if (colHead[j].capacity == colHead[j].Maxcapacity)     //�γ���ѡ��
			return RANGE_ERROR;

		ps = rowHead[i].right;
        pc = colHead[j].down;

		if (rowHead[i].right != NULL)  //�ų���ѧ��δѡ�ε����
		{
			while (ps->right != NULL && ps->triElem.col <= j) //��psָ��ָ�����ӽڵ����һ���ڵ�
			{
				ps = ps->right;
			}
			while (pc->down != NULL && pc->triElem.row <= i) //��pcָ��ָ�����ӽڵ����һ���ڵ�
			{
				pc = pc->down;
			}
		}
		

		Triple<ElemType> NewTriple(i, j, 1);
		pcr = new CrossNode<ElemType>(NewTriple);
		
		//�������ڵ���ӵ���������
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

		//�������ڵ���ӵ���������
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
//�˿κ���
{
	int i = 0, j = 0;

	CrossNode<ElemType>* pc = nullptr;
	CrossNode<ElemType>* ps = nullptr;
	while (rowHead[i] != e && i < rows)
	{
		i++;
	}

	if (e == rowHead[i])   //�ҵ�ѧ�����ڴ�
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
			ps = colHead[j].down;               //�ڵ����������������
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

			ps = rowHead[i].right;               //�ڵ�Ӻ�������������
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
// �������������һ��rs��cs�еĿ�ϡ�����
{
	if (rs < 1 || cs < 1||rs>RowMax||cs>ColMax)							
		throw Error("������������Ч!");	// �׳��쳣
	RowMax = rs;							// ����
	ColMax = cs;							// ����
	rows = -1;
	cols = -1;
	num = 0;							// ����Ԫ����
	rowHead = new Student<ElemType> [RowMax];	// �����������ͷ����洢�ռ�
	colHead = new Course<ElemType> [ColMax];	// �����������ͷ����洢�ռ�
	for (int row = 0; row < RowMax; row++)
		rowHead[row].right = NULL;			// ��ʼ���������ͷ����
	for (int col = 0; col < ColMax; col++)
		colHead[col].down = NULL;			// ��ʼ���������ͷ����
}


template <class ElemType>
CrossList<ElemType>::~CrossList()
// ���������ϡ�������ռ�ÿռ�
{
	Clear();
	delete []rowHead;					// �ͷ��������ͷ����
	delete []colHead;					// �ͷ��������ͷ����
}


template <class ElemType>
Status CrossList<ElemType>::SetElem(int r, int c, const ElemType& v)
// �������������±귶Χ��,�򷵻�RANGE_ERROR,���򷵻�SUCCESS
{
	if (r >= RowMax || c >= ColMax || r < 0 || c < 0)
		return RANGE_ERROR;				// �±귶Χ��
	CrossNode<ElemType>* pre, * p;
	if (v == 0) {  // �ѵ�r�С���c�е�ֵ�޸�Ϊ�� 
		pre = NULL; p = rowHead[r].right;	// pָ����Ӧ��㣬preΪp��ǰ����� 
		while (p != NULL && p->triElem.col < c) {
			pre = p;
			p = p->right;
		}

		if (p != NULL && p->triElem.col == c) {// ԭԪ��Ϊ����Ԫ�أ���ɾ��p���
			//  �޸���Ӧ���н���ָ��    
			if (rowHead[r].right == p)
				rowHead[r].right = p->right;
			else
				pre->right = p->right;

			//  �޸���Ӧ���н���ָ��    
			if (colHead[c].down == p)
				colHead[c].down = p->down;
			else {
				pre = colHead[c].down;
				while (pre->down != p)
					pre = pre->down;
				pre->down = p->down;
			}
			delete p;
			num--;				// ɾ�����,����Ԫ�ظ�����1
		}
	}
	else {  // �ѵ�r�С���c�е�ֵ�޸�Ϊ����Ԫ�� 
		pre = NULL; p = rowHead[r].right;	// pָ����Ӧ��㣬preΪp��ǰ����� 
		while (p != NULL && p->triElem.col < c) {
			pre = p;	p = p->right;
		}

		if (p != NULL && p->triElem.col == c)  	// ԭ���Ϊ����Ԫ�أ���ֱ���޸���ֵ 
			p->triElem.value == v;
		else { 	// ԭ���Ϊ0Ԫ�أ�����Ҫ������
			Triple<ElemType> e(r, c, v);		// ��Ԫ��
			CrossNode<ElemType>* ePtr = new CrossNode<ElemType>(e);//���ɽ��
			// �ѽ����뵽��Ӧ����    	    
			if (rowHead[r].right == p)
				rowHead[r].right = ePtr;
			else
				pre->right = ePtr;
			ePtr->right = p;
			// �ѽ����뵽��Ӧ����    	    
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
			num++;							// ��ɲ���������Ԫ�ظ�����һ 
		}
	}
	return SUCCESS;							// �����޸ĳɹ�
}

template <class ElemType>
void CrossList<ElemType>::Clear()
// ������������ϡ�����
{
    CrossNode<ElemType> *p;
	for (int i = 0; i < RowMax; i++)
		while (rowHead[i].right!= NULL)	{   // �ͷŵ�row�еĽ�������ÿռ�
			p =  rowHead[i].right;		
			rowHead[i].right = p->right;	
			delete p;
		}
	for (int j = 0; j < ColMax; j++)
		colHead[j].down = NULL;			// ��ʼ���������ͷ����
    num = 0;
}

template <class ElemType>
CrossList<ElemType>::CrossList(const CrossList<ElemType> &b)
// �����������ϡ�����b������ϡ����󡪡����ƹ��캯��
{
    CrossNode<ElemType> *p;
	rows = b.rows;					// ��������
	cols = b.cols;	// ��������
	RowMax = b.RowMax;
	ColMax = b.ColMax;
	num = 0;						// ��ʼ������Ԫ����
	rowHead = new Student<ElemType> *[RowMax];	// �����������ͷ����洢�ռ�
	colHead = new Course<ElemType> *[ColMax];	// �����������ͷ����洢�ռ�
	for (int i = 0; i < RowMax; i++)
		rowHead[i].right = NULL;			// ��ʼ���������ͷ����
	for (int i = 0; i < ColMax; i++)
		colHead[i].down = NULL;			// ��ʼ���������ͷ����
	
	for (int i = 0; i < RowMax; i++)
		for (p = b.rowHead[i].right; p != NULL; p = p->right)
			SetElem(p->triElem.row, p->triElem.col, p->triElem.value);
}

template <class ElemType>
CrossList<ElemType> &CrossList<ElemType>::operator =(const CrossList<ElemType> &b)
// �����������ϡ�����b��ֵ����ǰϡ����󡪡���ֵ�������
{
    if (RowMax != b.RowMax || ColMax != b.ColMax)
        throw Error("���������������!");	// �׳��쳣

	if (&b != this) {
	    CrossNode<ElemType> *p;
		Clear();						// ���ϡ�����
		num = b.num;					// ��ʼ������Ԫ����
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
		std::cerr << "�޷����ļ�: " << saveFilePath << std::endl;
		return FAIL;
	}
	else {
		cout << "new_std.txt�򿪳ɹ�" << endl;
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
	cout << "����ɹ�" << endl;

	saveFilePath = "new_course.txt";

	ofs.open(saveFilePath, ios::out);

	if (!ofs.is_open()) {
		std::cerr << "�޷����ļ�: " << saveFilePath << std::endl;
		return FAIL;
	}
	else {
		cout << "new_course.txt�򿪳ɹ�" << endl;
	}
	string numb;
	nam;
	int cred;
	int cap;      //��ǰѡ������
	int Maxca;   //�������
	for (int i = 0; i <= cols; i++) {
		numb = colHead[i].num;
		nam = colHead[i].name;
		cred = colHead[i].credit;
		Maxca = colHead[i].Maxcapacity;
		ofs << numb << '\t' << nam << '\t' << cred << '\t' << Maxca << endl;
	}

	ofs.close();
	cout << "����ɹ�" << endl;
	///////////////////////////////////////////////////////
	CrossNode<ElemType>* ps = NULL, * pc = NULL, * pcr = NULL;
	saveFilePath = "new_selection.txt";

	ofs.open(saveFilePath, ios::out);

	if (!ofs.is_open()) {
		std::cerr << "�޷����ļ�: " << saveFilePath << std::endl;
		return FAIL;
	}
	else {
		cout << "new_selection.txt�򿪳ɹ�" << endl;
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
	cout << "����ɹ�" << endl;


}
#endif
