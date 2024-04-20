#ifndef StaticList_h
#define StaticList_h 
const int maxSize = 100;// 静态链表大小
template <class T>
struct SLinkNode{
	T data;// 结点数据
    int link;// 结点链接指针
};
template <class T>
class StaticList {
public:
	void InitList();// 初始化
	int Length();// 计算静态链表的长度
	int Search(T x);// 在静态链表中查找具有给定值的结点
	int Locate(int i);// 在静态链表中查找第i个结点
	bool Insert(int i, T x);// 在静态链表第i个结点后插入新结点
	bool Remove(int i);// 在静态链表中释放第i个结点
	bool isEmpty(); // 判链表空否 ?
private:
	SLinkNode<T> elem[maxSize];
	int avil;// 当前可分配空间首地址
};

template <class T>
void StaticList<T>::InitList() {
    for (int i = 0; i < maxSize - 1; i++) {
        elem[i].link = i + 1; // 初始化每个结点的链接指针
    }
    elem[maxSize - 1].link = 0; // 最后一个结点的链接指针指向0，表示链表结束
    avil = 1; // 设置当前可分配空间首地址
}

template <class T>
int StaticList<T>::Length() {
    int count = 0;
    int p = elem[0].link; // 从第一个结点开始遍历
    while (p) {
        count++;
        p = elem[p].link;
    }
    return count;
}

template <class T>
int StaticList<T>::Search(T x) {
    int p = elem[0].link; // 从第一个结点开始遍历
    int count = 1;
    while (p && elem[p].data != x) {
        p = elem[p].link;
        count++;
    }
    if (p) {
        return count;
    }
    else {
        return 0; // 未找到
    }
}

template <class T>
int StaticList<T>::Locate(int i) {
    if (i < 1 || i > Length()) {
        return 0; // 位置不合法
    }
    int p = elem[0].link; // 从第一个结点开始遍历
    for (int count = 1; count < i; count++) {
        p = elem[p].link;
    }
    return p;
}

template <class T>
bool StaticList<T>::Insert(int i, T x) {
    if (i < 1 || i > Length() + 1 || avil == 0) {
        return false; // 位置不合法或没有可分配空间
    }
    int p = avil; // 取一个可分配空间
    avil = elem[avil].link; // 更新可分配空间首地址
    elem[p].data = x; // 插入新结点
    int pre = Locate(i - 1); // 找到第i-1个结点
    elem[p].link = elem[pre].link; // 新结点链接指向原第i个结点
    elem[pre].link = p; // 原第i-1个结点链接指向新结点
    return true;
}

template <class T>
bool StaticList<T>::Remove(int i) {
    if (i < 1 || i > Length()) {
        return false; // 位置不合法
    }
    int pre = Locate(i - 1); // 找到第i-1个结点
    int p = elem[pre].link; // 找到第i个结点
    elem[pre].link = elem[p].link; // 删除第i个结点，更新链接指针
    elem[p].link = avil; // 将删除的结点链接指针指向当前可分配空间首地址
    avil = p; // 更新当前可分配空间首地址
    return true;
}

template <class T>
bool StaticList<T>::isEmpty() {
    return elem[0].link == 0; // 首结点的链接指针为0表示链表为空
}

#endif