#define _CRT_SECURE_NO_WARNINGS
#ifndef __LK_LIST_H__
#define __LK_LIST_H__
#include "Assistance.h"		
template <class ElemType>
class LinkList
{
protected:
	int head;
	int maxLength;							//����� 
	int avail;                              //����ָ�����ͷ
	struct Data
	{
		ElemType data;
		int next;                           //��һ������λ��
	};
	Data* sll;                              //����

public:
	//  ��̬����ĺ�����Ա 
	LinkList(int maxLength = 10000);		
	virtual ~LinkList();				
	int GetLength() const;							 
	bool IsEmpty() const;	 			
	void Clear();						
	void Traverse(void (*Visit)(const ElemType&)) const; // ������̬����
	int LocateElem(const ElemType& e) const;	        
	Status GetElem(int position, ElemType& e) const;	 	
	Status SetElem(int position, const ElemType& e);	 // ����ָ��λ�õ�Ԫ��ֵ
	Status DeleteElem(int position, ElemType& e);		 	
	Status InsertElem(int position, const ElemType& e);	 // ��ָ��λ�ò���Ԫ��
	Status InsertElem(const ElemType& e);	             // �ڱ�β����Ԫ��
	LinkList(const LinkList<ElemType> &la);              // ���ƹ��캯��
	LinkList<ElemType> &operator =(const LinkList<ElemType> &la); // ���ظ�ֵ����
};

template <class ElemType>
LinkList<ElemType>::LinkList(int maxLen)
// �������������һ��������
{
	maxLength = maxLen;
	head = 0;                    //δʹ��ͷ���
	sll = new Data[maxLength];   //�½�������
	for (int i = 0;i < maxLen; i++)  //��������ÿ��Ԫ��ָ���¸�Ԫ��
		sll[i].next = i + 1;
	sll[maxLen - 1].next = -1;   //���һλָ��-1�������������
	avail = 1;                  //����δʹ��ʱavailָ��0
}
template <class ElemType>
LinkList<ElemType>::~LinkList()
// ������������پ�̬����
{
	delete[]sll;
}


template <class ElemType>
int LinkList<ElemType>::GetLength() const
// ������������ص�����ĳ��� 
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
// ����������羲̬����Ϊ�գ��򷵻�true�����򷵻�false
{
	return sll[head].next == -1;
}


template <class ElemType>
void LinkList<ElemType>::Clear()
// �����������յ�����,ɾ��������������Ԫ�ؽ�� 
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
// ������������ζԵ������ÿ��Ԫ�ص��ú���(*visit)����
{
	int j = head;
	while (sll[j].next != -1) {
		(*Visit)(sll[sll[j].next].data);	// �Ե�������ÿ��Ԫ�ص��ú���(*visit)���� 
		j = sll[j].next;
	}
}


template <class ElemType>
int LinkList<ElemType>::LocateElem(const ElemType& e) const
// Ԫ�ض�λ 
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
// �����������������ڵ�i��Ԫ��ʱ����e������ֵ����������ENTRY_FOUND,
//	����������NOT_PRESENT
{
	if (i < 1 || i > GetLength())
		return RANGE_ERROR;
	else {
		int j = head;
		int count;
		for (count = 1; count <= i; count++)
			j = sll[j].next;            // jָ���i�����
		e = sll[j].data;				// ��e���ص�i��Ԫ�ص�ֵ
		return ENTRY_FOUND;
	}
}


template <class ElemType>
Status LinkList<ElemType>::SetElem(int i, const ElemType& e)
// ���������������ĵ�i��λ�õ�Ԫ�ظ�ֵΪe,
//	i��ȡֵ��ΧΪ1��i��length,
//	i�Ϸ�ʱ��������SUCCESS,����������RANGE_ERROR
{
	if (i < 1 || i > GetLength())
		return RANGE_ERROR;
	else {
		int j = head;
		int count;
		for (count = 1; count <= i; count++)
			j = sll[j].next; 	           // ȡ��ָ���i������ָ��	
		sll[j].data = e;			   // �޸ĵ�i��Ԫ�ص�ֵΪe 
		return SUCCESS;
	}
}

template <class ElemType>
Status LinkList<ElemType>::DeleteElem(int i, ElemType& e)
// ���������ɾ������ĵ�i��λ�õ�Ԫ��, ����e������ֵ,
//	i��ȡֵ��ΧΪ1��i��length,
//	i�Ϸ�ʱ��������SUCCESS,����������RANGE_ERROR
{
	if (i < 1 || i > GetLength())
		return RANGE_ERROR;   // i��Χ��		 
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
		e = k;		  // ��e���ر�ɾ���Ԫ��ֵ	
		return SUCCESS;
	}
}


template <class ElemType>
Status LinkList<ElemType>::InsertElem(int i, const ElemType& e)
// ���������������ĵ�i��λ��ǰ����Ԫ��e
//	i��ȡֵ��ΧΪ1��i��length+1
//	i�Ϸ�ʱ����SUCCESS, ����������RANGE_ERROR
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
				j = sll[j].next; 		// pָ���i-1�����	
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
// ����������ھ�̬����ı�βλ�ò���Ԫ��e
{
	int j = head;
	int k = avail;
	avail = sll[avail].next;
	for (j = head;sll[j].next != -1; j = sll[j].next);	// ָ���β���	
	sll[j].next = k;				// ������ı�βλ�ò����½�� 
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
