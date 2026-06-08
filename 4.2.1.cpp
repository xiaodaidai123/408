// 串的模式匹配

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define MAXLEN 50

typedef struct{ // 定长顺序存储表示
    char ch[MAXLEN];
    int length;
}SString;

typedef struct{ // 堆分配存储表示
    char *ch;
    int length;
}HString;

int Index(SString S, SString T){ // 简单的模式匹配算法
    int i=1, j=1;
    while(i<=S.length && j<=T.length)
    {
        if(S.ch[i] == T.ch[j])
            i++, j++;
        else
            i = i-j+2, j=1;
    }
    if(j>T.length)
        return i-T.length;
    else
        return 0;
}

void get_next(SString T, int next[]){ // 求next数组
    int i=1, j=0;
    next[1] = 0;
    while(i<T.length)
    {
        if(j==0 || T.ch[i] == T.ch[j])
        {
            i++, j++;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}

int Index_KMP(SString S, SString T, int next[]){ // kmp算法实现
    int i=1, j=1;
    while(i<=S.length && j<=T.length)
    {
        if(j == 0 || S.ch[i] == T.ch[j])
            i++, j++;
        else
            j = next[j];
    }
    if(j>T.length)
        return i-T.length;
    else
        return 0;
}

void get_nextval(SString T, vector<int> &nextval){ // 求nextval数组
    int i=1, j=0;
    nextval[1] = 0;
    while(i<T.length)
    {
        if(j == 0 || T.ch[i] == T.ch[j])
        {
            i++, j++;
            if(T.ch[i] != T.ch[j])
                nextval[i] = j;
            else
                nextval[i] = nextval[j];
        }
        else
        {
            j = nextval[j];
        }
    }
}

int kmpCount(const SString &S, const SString &T){ // 允许重叠的匹配子串 123页
    if(T.length == 0)
        return 0;
    vector<int> nextval(T.length + 1);
    get_nextval(T, nextval);
    int count = 0, j = 0;
    for(int i=1; i<=S.length; i++)
    {
        while(j > 0 && S.ch[i] != T.ch[j+1])
        {
            j = nextval[j];
        }
        if(S.ch[i] == T.ch[j+1])
        {
            j++;
        }
        if(j == T.length)
        {
            count++;
            j = nextval[j-1];
        }
    }
    return count;
}

int main()
{
    SString S, T;
    strcpy(S.ch+1, "ABABCABA");
    S.length = strlen("ABABCABA");
    cout << S.length << endl;
    strcpy(T.ch+1, "ABA");
    T.length = strlen("ABA");
    cout << kmpCount(S, T) << endl;
    return 0;
}