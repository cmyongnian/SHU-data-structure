
#include "SeqStack.h"

#include <string>
//#include <utility>
using namespace std;
const int ROWS = 20;  // 新的图像行数
const int COLS = 20;  // 新的图像列数

// 新的图像数据，0表示屏幕背景，-1表示未填充，大于0表示已填充且填充的顺序
int image[ROWS][COLS];

// 新的种子填充算法
void AdvancedSeedFill(int x, int y, int& fillNumber)
{
    SeqStack<pair<int, int>> stack;

    // 将种子点入栈
    stack.Push(make_pair(x, y));

    while (!stack.IsEmpty())
    {
        // 出栈一个点
        pair<int, int> currentPoint;
        stack.Pop(currentPoint);

        x = currentPoint.first;
        y = currentPoint.second;

        // 判断是否需要填充当前点
        if (x >= 0 && x < ROWS && y >= 0 && y < COLS && image[x][y] == -1)
        {
            // 填充当前点
            image[x][y] = ++fillNumber;

            // 输出当前图像状态
            cout << "Step " << fillNumber << ":" << endl;
            for (int i = 0; i < ROWS; ++i)
            {
                for (int j = 0; j < COLS; ++j)
                {
                    cout << std::setw(3) << (image[i][j] == 0 ? "0" : (image[i][j] == -1 ? "-1" : to_string(image[i][j]))) << " ";
                }
                cout << endl;
            }
            cout << "按回车继续..." << endl;

            // 等待用户按回车键
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            // 将相邻未填充的点按照上、下、左、右的顺序入栈
            stack.Push(make_pair(x, y + 1));  // 右
            stack.Push(make_pair(x, y - 1));  // 左
            stack.Push(make_pair(x + 1, y));  // 下
            stack.Push(make_pair(x - 1, y));  // 上
        }
    }
}

int main()
{
    int seedX, seedY;
    int flag;
    int a;

    // 用户输入种子点位置，确保在边界范围内
    do
    {
        cout << "请输入种子点的横坐标（0 到 " << ROWS - 1 << "）: ";
        cin >> seedX;

        cout << "请输入种子点的纵坐标（0 到 " << COLS - 1 << "）: ";
        cin >> seedY;

        if (seedX < 0 || seedX >= ROWS || seedY < 0 || seedY >= COLS)
        {
            cout << "输入无效，请重新输入种子点的坐标。" << endl;
          
        
        }
       
    } while (seedX < 0 || seedX >= ROWS || seedY < 0 || seedY >= COLS);

    cout << "种子点： (" << seedX << ", " << seedY << ")" << std::endl;
    cout << "选择填充模式,1为默认填充矩形，2为自定义填充" << endl;
    cin >> flag;
    if (flag == 1) {
        // 初始化新的图像矩阵
        for (int i = 0; i < ROWS; ++i)
        {
            for (int j = 0; j < COLS; ++j)
            {
                // 设置边界为屏幕背景
                if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1)
                {
                    image[i][j] = 0;
                }
                else
                {
                    // 其余区域为未填充
                    image[i][j] = -1;
                }
            }
        }
    }
    else if (flag ==2)
    {
        cout << "请输入矩阵" << endl;
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++) {
                cin >> image[i][j];
             
            }

        }
        
    }
    else {
        cout << "输入异常，请重新填充" << endl;
        cin >> flag;
    }
    int fillNumber = 0;

    cout << "按回车开始填充..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // 调用新的种子填充算法
    AdvancedSeedFill(seedY, seedX, fillNumber);

    // 输出最终填充后的图像
    cout << "最终图像：" << endl;
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
