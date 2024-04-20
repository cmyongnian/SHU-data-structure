#pragma once
#ifndef  __NODE_H__
#define  __NODE_H__
#include <iostream>
// �����
template <class ElemType>
struct Node
{
	// ���ݳ�Ա:
	ElemType data;				// �����г�Ա�����
	Node<ElemType>* next;		// ָ����

	// ���캯��:
	Node();						// �޲����Ĺ��캯��
	Node(ElemType n, Node<ElemType>* link = NULL);	// ��֪������Ԫ��ֵ��ָ�뽨���ṹ
};

// ������ʵ�ֲ���
template<class ElemType>
Node<ElemType>::Node()
// �������������ָ����Ϊ�յĽ��
{
	next = NULL;
}

template<class ElemType>
Node<ElemType>::Node(ElemType n, Node<ElemType>* link)
// �������������һ��������Ϊitem��ָ����Ϊlink�Ľ��
{
	data = n;
	next = link;
}

#endif