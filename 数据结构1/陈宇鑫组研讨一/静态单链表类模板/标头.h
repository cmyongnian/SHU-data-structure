#ifndef StaticList_h
#define StaticList_h 
const int maxSize = 100;// ��̬�����С
template <class T>
struct SLinkNode{
	T data;// �������
    int link;// �������ָ��
};
template <class T>
class StaticList {
public:
	void InitList();// ��ʼ��
	int Length();// ���㾲̬����ĳ���
	int Search(T x);// �ھ�̬�����в��Ҿ��и���ֵ�Ľ��
	int Locate(int i);// �ھ�̬�����в��ҵ�i�����
	bool Insert(int i, T x);// �ھ�̬�����i����������½��
	bool Remove(int i);// �ھ�̬�������ͷŵ�i�����
	bool isEmpty(); // ������շ� ?
private:
	SLinkNode<T> elem[maxSize];
	int avil;// ��ǰ�ɷ���ռ��׵�ַ
};

template <class T>
void StaticList<T>::InitList() {
    for (int i = 0; i < maxSize - 1; i++) {
        elem[i].link = i + 1; // ��ʼ��ÿ����������ָ��
    }
    elem[maxSize - 1].link = 0; // ���һ����������ָ��ָ��0����ʾ�������
    avil = 1; // ���õ�ǰ�ɷ���ռ��׵�ַ
}

template <class T>
int StaticList<T>::Length() {
    int count = 0;
    int p = elem[0].link; // �ӵ�һ����㿪ʼ����
    while (p) {
        count++;
        p = elem[p].link;
    }
    return count;
}

template <class T>
int StaticList<T>::Search(T x) {
    int p = elem[0].link; // �ӵ�һ����㿪ʼ����
    int count = 1;
    while (p && elem[p].data != x) {
        p = elem[p].link;
        count++;
    }
    if (p) {
        return count;
    }
    else {
        return 0; // δ�ҵ�
    }
}

template <class T>
int StaticList<T>::Locate(int i) {
    if (i < 1 || i > Length()) {
        return 0; // λ�ò��Ϸ�
    }
    int p = elem[0].link; // �ӵ�һ����㿪ʼ����
    for (int count = 1; count < i; count++) {
        p = elem[p].link;
    }
    return p;
}

template <class T>
bool StaticList<T>::Insert(int i, T x) {
    if (i < 1 || i > Length() + 1 || avil == 0) {
        return false; // λ�ò��Ϸ���û�пɷ���ռ�
    }
    int p = avil; // ȡһ���ɷ���ռ�
    avil = elem[avil].link; // ���¿ɷ���ռ��׵�ַ
    elem[p].data = x; // �����½��
    int pre = Locate(i - 1); // �ҵ���i-1�����
    elem[p].link = elem[pre].link; // �½������ָ��ԭ��i�����
    elem[pre].link = p; // ԭ��i-1���������ָ���½��
    return true;
}

template <class T>
bool StaticList<T>::Remove(int i) {
    if (i < 1 || i > Length()) {
        return false; // λ�ò��Ϸ�
    }
    int pre = Locate(i - 1); // �ҵ���i-1�����
    int p = elem[pre].link; // �ҵ���i�����
    elem[pre].link = elem[p].link; // ɾ����i����㣬��������ָ��
    elem[p].link = avil; // ��ɾ���Ľ������ָ��ָ��ǰ�ɷ���ռ��׵�ַ
    avil = p; // ���µ�ǰ�ɷ���ռ��׵�ַ
    return true;
}

template <class T>
bool StaticList<T>::isEmpty() {
    return elem[0].link == 0; // �׽�������ָ��Ϊ0��ʾ����Ϊ��
}

#endif