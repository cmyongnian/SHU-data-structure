
#include "SeqStack.h"

#include <string>
//#include <utility>
using namespace std;
const int ROWS = 20;  // �µ�ͼ������
const int COLS = 20;  // �µ�ͼ������

// �µ�ͼ�����ݣ�0��ʾ��Ļ������-1��ʾδ��䣬����0��ʾ�����������˳��
int image[ROWS][COLS];

// �µ���������㷨
void AdvancedSeedFill(int x, int y, int& fillNumber)
{
    SeqStack<pair<int, int>> stack;

    // �����ӵ���ջ
    stack.Push(make_pair(x, y));

    while (!stack.IsEmpty())
    {
        // ��ջһ����
        pair<int, int> currentPoint;
        stack.Pop(currentPoint);

        x = currentPoint.first;
        y = currentPoint.second;

        // �ж��Ƿ���Ҫ��䵱ǰ��
        if (x >= 0 && x < ROWS && y >= 0 && y < COLS && image[x][y] == -1)
        {
            // ��䵱ǰ��
            image[x][y] = ++fillNumber;

            // �����ǰͼ��״̬
            cout << "Step " << fillNumber << ":" << endl;
            for (int i = 0; i < ROWS; ++i)
            {
                for (int j = 0; j < COLS; ++j)
                {
                    cout << std::setw(3) << (image[i][j] == 0 ? "0" : (image[i][j] == -1 ? "-1" : to_string(image[i][j]))) << " ";
                }
                cout << endl;
            }
            cout << "���س�����..." << endl;

            // �ȴ��û����س���
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            // ������δ���ĵ㰴���ϡ��¡����ҵ�˳����ջ
            stack.Push(make_pair(x, y + 1));  // ��
            stack.Push(make_pair(x, y - 1));  // ��
            stack.Push(make_pair(x + 1, y));  // ��
            stack.Push(make_pair(x - 1, y));  // ��
        }
    }
}

int main()
{
    int seedX, seedY;
    int flag;
    int a;

    // �û��������ӵ�λ�ã�ȷ���ڱ߽緶Χ��
    do
    {
        cout << "���������ӵ�ĺ����꣨0 �� " << ROWS - 1 << "��: ";
        cin >> seedX;

        cout << "���������ӵ�������꣨0 �� " << COLS - 1 << "��: ";
        cin >> seedY;

        if (seedX < 0 || seedX >= ROWS || seedY < 0 || seedY >= COLS)
        {
            cout << "������Ч���������������ӵ�����ꡣ" << endl;
          
        
        }
       
    } while (seedX < 0 || seedX >= ROWS || seedY < 0 || seedY >= COLS);

    cout << "���ӵ㣺 (" << seedX << ", " << seedY << ")" << std::endl;
    cout << "ѡ�����ģʽ,1ΪĬ�������Σ�2Ϊ�Զ������" << endl;
    cin >> flag;
    if (flag == 1) {
        // ��ʼ���µ�ͼ�����
        for (int i = 0; i < ROWS; ++i)
        {
            for (int j = 0; j < COLS; ++j)
            {
                // ���ñ߽�Ϊ��Ļ����
                if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1)
                {
                    image[i][j] = 0;
                }
                else
                {
                    // ��������Ϊδ���
                    image[i][j] = -1;
                }
            }
        }
    }
    else if (flag ==2)
    {
        cout << "���������" << endl;
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++) {
                cin >> image[i][j];
             
            }

        }
        
    }
    else {
        cout << "�����쳣�����������" << endl;
        cin >> flag;
    }
    int fillNumber = 0;

    cout << "���س���ʼ���..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // �����µ���������㷨
    AdvancedSeedFill(seedY, seedX, fillNumber);

    // ������������ͼ��
    cout << "����ͼ��" << endl;
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            cout << setw(3) << (image[i][j] == 0 ? "0" : (image[i][j] == -1 ? "-1" : to_string(image[i][j]))) << " ";
        }
        cout << endl;
    }

    return 0;
}
