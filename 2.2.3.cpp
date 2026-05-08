//2.2.3课后习题

#include <iostream>
using namespace std;

struct SqList
{
    int *data;
    int length;
};

bool T1(SqList &L, int &value)
{
    //从顺序表中删除具有最小值的元素(假设唯一)并由函数返回被删除元素的值。空出的位置由最后一个元素填补，若顺序表为空，则显示出错信息并退出运行。
    if(L.length == 0)
        return false;
    value = L.data[0];
    int pos = 0;
    for(int i=1;i<L.length;i++)
    {
        if(L.data[i] < value)
        {
            value = L.data[i];
            pos = i;
        }
    }
    L.data[pos] = L.data[L.length - 1];
    L.length--;
    return true;
}

void T2(SqList &L)
{
    //设计一个高效算法，将顺序表L的所有元素逆置，要求算法的空间复杂度为O(1)
    if(L.length == 0)
        return ;
    for(int i=0;i<L.length/2;i++)
    {
        int tmp = L.data[i];
        L.data[i] = L.data[L.length-1-i];
        L.data[L.length-1-i] = tmp;
    }
}

void T3(SqList &L, int x)
{
    //对长度为n的顺序表L，编写一个时间复杂度为O(n)，空间复杂度为O(1)的算法，该算法删除顺序表中所有值为x的数据元素
    if(L.length == 0)
        return ;
    int left = 0, right = 0;
    while(right < L.length)
    {
        if(L.data[right] != x)
        {
            L.data[left] = L.data[right];
            left++;
        }
        right++;
    }
    L.length = left;
}

bool T4(SqList &L, int s, int t)
{
    //从顺序表中删除其值在给定值s和t之间(包含s和t，要求s<t)的所有元素，若s或t不合理或顺序表为空，则显示出错信息并退出执行。
    if(s >= t || L.length == 0)
        return false;
    int left = 0, right = 0;
    while(right < L.length)
    {
        if(L.data[right] < s || L.data[right] > t)
        {
            L.data[left] = L.data[right];
            left++;
        }
        right++;
    }
    L.length = left;
    return true;
}

void T5(SqList &L)
{
    //从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同。
    if(L.length == 0)
        return ;
    
}

void T6(SqList &L)
{
    //将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表
}

void T7(SqList &L)
{
    //已知在一维数组A[m+n]中依次存放两个线性表(a1,a2,a3,...,am)和(b1,b2,b3,...,bn)。
    //编写一个函数，将数组中两个数序表的位置互换，即将(b1,b2,b3,...,bn)放到(a1,a2,a3,...,am)的前面
    
}

int main()
{
    cout << 1283 << endl;
    cout << 123;
    return 0;
}