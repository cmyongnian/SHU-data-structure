#pragma once
#ifndef  __NODE_H__
#define  __NODE_H__
#include <iostream>
// 结点类
template <class ElemType>
struct Node
{
	// 数据成员:
	ElemType data;				// 家族中成员的序号
	Node<ElemType>* next;		// 指针域

	// 构造函数:
	Node();						// 无参数的构造函数
	Node(ElemType n, Node<ElemType>* link = NULL);	// 已知数数据元素值和指针建立结构
};

// 结点类的实现部分
template<class ElemType>
Node<ElemType>::Node()
// 操作结果：构造指针域为空的结点
{
	next = NULL;
}

template<class ElemType>
Node<ElemType>::Node(ElemType n, Node<ElemType>* link)
// 操作结果：构造一个数据域为item和指针域为link的结点
{
	data = n;
	next = link;
}

#endif