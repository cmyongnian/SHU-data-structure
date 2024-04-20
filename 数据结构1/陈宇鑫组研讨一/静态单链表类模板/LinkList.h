#define _CRT_SECURE_NO_WARNINGS
#ifndef __LK_LIST_H__
#define __LK_LIST_H__
#include "Assistance.h"		
template <class ElemType>
class LinkList
{
protected:
	int head;
	int maxLength;							//最长长度 
	int avail;                              //备用指链表表头
	struct Data
	{
		ElemType data;
		int next;                           //下一个结点的位置
	};
	Data* sll;                              //数组

public:
	//  静态链表的函数成员 
	LinkList(int maxLength = 10000);		
	virtual ~LinkList();				
	int GetLength() const;							 
	bool IsEmpty() const;	 			
	void Clear();						
	void Traverse(void (*Visit)(const ElemType&)) const; // 遍历静态链表
	int LocateElem(const ElemType& e) const;	        
	Status GetElem(int position, ElemType& e) const;	 	
	Status SetElem(int position, const ElemType& e);	 // 设置指定位置的元素值
	Status DeleteElem(int position, ElemType& e);		 	
	Status InsertElem(int position, const ElemType& e);	 // 在指定位置插入元素
	Status InsertElem(const ElemType& e);	             // 在表尾插入元素
	LinkList(const LinkList<ElemType> &la);              // 复制构造函数
	LinkList<ElemType> &operator =(const LinkList<ElemType> &la); // 重载赋值运算
};

template <class ElemType>
LinkList<ElemType>::LinkList(int maxLen)
// 操作结果：构造一个空链表
{
	maxLength = maxLen;
	head = 0;                    //未使用头结点
	sll = new Data[maxLength];   //新建空数组
	for (int i = 0;i < maxLen; i++)  //将数组中每个元素指向下个元素
		sll[i].next = i + 1;
	sll[maxLen - 1].next = -1;   //最后一位指向-1，代表数组结束
	avail = 1;                  //链表未使用时avail指向0
}
template <class ElemType>
LinkList<ElemType>::~LinkList()
// 操作结果：销毁静态链表
{
	delete[]sll;
}


template <class ElemType>
int LinkList<ElemType>::GetLength() const
// 操作结果：返回单链表的长度 
{
	int length = 0;
	int j = head;
	while (sll[j].next != -1) {
		length++;
		j = sll[j].next;
	}
	return length;
}



template <class ElemType>
bool LinkList<ElemType>::IsEmpty() const
// 操作结果：如静态链表为空，则返回true，否则返回false
{
	return sll[head].next == -1;
}


template <class ElemType>
void LinkList<ElemType>::Clear()
// 操作结果：清空单链表,删除单链表中所有元素结点 
{
	int j = head;
	int k = 1;
	for (j = head;sll[j].next != -1;j = sll[j].next) {
		sll[j].data = '0';
		sll[j].next = k;
		k++;
	}
	sll[j].next = k;
	sll[head].next = -1;
	avail = 1;
}


template <class ElemType>
void LinkList<ElemType>::Traverse(void (*Visit)(const ElemType&)) const
// 操作结果：依次对单链表的每个元素调用函数(*visit)访问
{
	int j = head;
	while (sll[j].next != -1) {
		(*Visit)(sll[sll[j].next].data);	// 对单链表中每个元素调用函数(*visit)访问 
		j = sll[j].next;
	}
}


template <class ElemType>
int LinkList<ElemType>::LocateElem(const ElemType& e) const
// 元素定位 
{
	int j = head;
	int count = 1;
	while (sll[j].next != -1 && sll[j].data != e) {
		count++;
		j = sll[j].next;
	}
	if (count - 1 > GetLength())
	{
		if (sll[count - 1].data == e || sll[count - 2].data == e)
			return count - 1;
		else
			return RANGE_ERROR;
	}
	else
		return  count - 1;
}


template <class ElemType>
Status LinkList<ElemType>::GetElem(int i, ElemType& e) const
// 操作结果：当链表存在第i个元素时，用e返回其值，函数返回ENTRY_FOUND,
//	否则函数返回NOT_PRESENT
{
	if (i < 1 || i > GetLength())
		return RANGE_ERROR;
	else {
		int j = head;
		int count;
		for (count = 1; count <= i; count++)
			j = sll[j].next;            // j指向第i个结点
		e = sll[j].data;				// 用e返回第i个元素的值
		return ENTRY_FOUND;
	}
}


template <class ElemType>
Status LinkList<ElemType>::SetElem(int i, const ElemType& e)
// 操作结果：将链表的第i个位置的元素赋值为e,
//	i的取值范围为1≤i≤length,
//	i合法时函数返回SUCCESS,否则函数返回RANGE_ERROR
{
	if (i < 1 || i > GetLength())
		return RANGE_ERROR;
	else {
		int j = head;
		int count;
		for (count = 1; count <= i; count++)
			j = sll[j].next; 	           // 取出指向第i个结点的指针	
		sll[j].data = e;			   // 修改第i个元素的值为e 
		return SUCCESS;
	}
}

template <class ElemType>
Status LinkList<ElemType>::DeleteElem(int i, ElemType& e)
// 操作结果：删除链表的第i个位置的元素, 并用e返回其值,
//	i的取值范围为1≤i≤length,
//	i合法时函数返回SUCCESS,否则函数返回RANGE_ERROR
{
	if (i < 1 || i > GetLength())
		return RANGE_ERROR;   // i范围错		 
	else {
		int j = head, k, l;
		for (int count = 1; count < i; count++)
			j = sll[j].next;
		k = sll[sll[j].next].data;
		l = sll[sll[j].next].next;
		sll[sll[j].next].data = '0';
		sll[sll[j].next].next = avail;
		int temp = sll[j].next;
		sll[j].next = l;
		avail = temp;
		e = k;		  // 用e返回被删结点元素值	
		return SUCCESS;
	}
}


template <class ElemType>
Status LinkList<ElemType>::InsertElem(int i, const ElemType& e)
// 操作结果：在链表的第i个位置前插入元素e
//	i的取值范围为1≤i≤length+1
//	i合法时返回SUCCESS, 否则函数返回RANGE_ERROR
{
	if (i < 1 || i > GetLength() + 1 || GetLength() + 1 > maxLength)
		return RANGE_ERROR;
	else {
		int j = head;
		int k = avail;

		int count;
		if (i == GetLength() + 1)
			InsertElem(e);
		else if (i == 1) {
			avail = sll[k].next;
			int temp = sll[head].next;
			sll[k].data = e;
			sll[head].next = k;
			sll[k].next = temp;

		}
		else {
			avail = sll[k].next;
			for (count = 1; count < i; count++)
				j = sll[j].next; 		// p指向第i-1个结点	
			int temp = sll[j].next;
			sll[j].next = k;
			sll[k].data = e;
			sll[k].next = temp;
		}
		return SUCCESS;
	}
}

template <class ElemType>
Status LinkList<ElemType>::InsertElem(const ElemType& e)
// 操作结果：在静态链表的表尾位置插入元素e
{
	int j = head;
	int k = avail;
	avail = sll[avail].next;
	for (j = head;sll[j].next != -1; j = sll[j].next);	// 指向表尾结点	
	sll[j].next = k;				// 在链表的表尾位置插入新结点 
	sll[k].data = e;
	sll[k].next = -1;
	return SUCCESS;
}

template <class ElemType>
LinkList<ElemType>::LinkList(const LinkList<ElemType>& la)
{
	maxLength = la.maxLength;
	head = la.head;
	avail = la.avail;

	sll = new Data[maxLength];
	for (int i = 0; i < maxLength; i++) {
		sll[i] = la.sll[i];
	}
}

template <class ElemType>
LinkList<ElemType>& LinkList<ElemType>::operator =(const LinkList<ElemType>& la)
{
	if (this == &la) {
		return *this;
	}

	delete[] sll;
	maxLength = la.maxLength;
	head = la.head;
	avail = la.avail;
	sll = new Data[maxLength];
	for (int i = 0; i < maxLength; i++) {
		sll[i] = la.sll[i];
	}

	return *this;
}

#endif
