//2.2.3课后习题

#include <iostream>
#include <cmath>
#include <vector>
typedef int DataType;
using namespace std;

struct SqList
{
    int *data;
    int length;
	int MaxSize;
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
    int left = 0, right = 1;
    while(right < L.length)
    {
        if(L.data[right] != L.data[left])
        {
            L.data[++left] = L.data[right];
        }
        right++;
    }
}

bool T6(SqList L1, SqList L2, SqList &L3)
{
    //将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表
    if (L1.length+L2.length > L3.MaxSize)
		return false;
	int i=0, j=0, k=0;
	while(i<L1.length && j<L2.length)
	{
		if(L1.data[i] <= L2.data[j])
			L3.data[k++] = L1.data[i++];
		else
			L3.data[k++] = L2.data[j++];
	}
	while(i<L1.length)
		L3.data[k++] = L1.data[i++];
	while(j<L2.length)
		L3.data[k++] = L2.data[j++];
	L3.length = k;
    return true;
}

void T7(SqList &L, int n, int m)
{
    //已知在一维数组A[m+n]中依次存放两个线性表(a1,a2,a3,...,am)和(b1,b2,b3,...,bn)。
    //编写一个函数，将数组中两个数序表的位置互换，即将(b1,b2,b3,...,bn)放到(a1,a2,a3,...,am)的前面
    for(int i=0;i<L.length/2;i++)
	{
		DataType tmp = L.data[i];
		L.data[i] = L.data[L.length-i-1];
		L.data[L.length-i-1] = tmp;
	}
	for(int i=0;i<n/2;i++)
	{
		DataType tmp = L.data[i];
		L.data[i] = L.data[n-i-1];
		L.data[n-i-1] = tmp;
	}
	for(int j=n;j<(n+m)/2;j++)
	{
		DataType tmp = L.data[j];
		L.data[j] = L.data[n+m-j-1];
		L.data[n+m-j-1] = tmp;
	}
}

void T8(SqList &L, DataType x)
{
    //线性表(a1,a2,a3,...,an)中的元素递增有序且按顺序存储于计算机内，要求设计一个算法
    //完成用最少时间在表中查找数值为x的元素，若找到，则将其与后继元素位置相交换
    //若找不到，则将其插入表中并使表中元素仍然递增有序
	int low = 0, high = L.length - 1, mid;
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(L.data[mid] == x)
			break;
		else if(L.data[mid] < x)
			low = mid+1;
		else
			high = mid-1;
	}
	if(L.data[mid] == x && mid != L.length - 1)
	{
		DataType tmp = L.data[mid];
		L.data[mid] = L.data[mid + 1];
		L.data[mid + 1] = tmp;
	}
	if(low > high)
	{
		for(int i=L.length;i>low;i--)
			L.data[i] = L.data[i-1];
		L.data[low] = x;
		L.length++;
		//1 3 5 7 9 10
	}
}

void T9(int a[], int b[], int c[], int n)
{
    /*给定三个序列A、B、C，长度均为n，且均为无重复元素的递增序列，请设计一个时间上尽可能高效的算法，逐行输出同时存在于这三个序列中的所有元素。
    例如，数组A为{1,2,3}，数组B为{2,3,4}，数组C为{-1,0,2}，则输出2。要求：
    1.给出算法的基本思想设计思路
    2.根据设计思想，采用C或C++语言描述算法，关键之处给出注释
    3.说明你的算法的时间复杂度和空间复杂度
    */
	/*
	1.使用三个下标变量同时遍历三个序列，当三个下标变量指向的元素相等时，输出并向前推进指针，否则仅移动小于最大元素的下标变量，
	  直到某个下标变量移除数组范围，即可停止。
	*/
	int i=0, j=0, k=0;
	while(i < n && j < n && k < n)
	{
		if(a[i] == b[j] && b[j] == c[k])
		{
			cout << a[i] << endl;
			i++;
			j++;
			k++;
		}
		else
		{
			int maxnum = max(a[i], max(b[j], c[k]));
			if(a[i] < maxnum)
				i++;
			if(b[j] < maxnum)
				j++;
			if(c[k] < maxnum)
				k++;
		}
	}
}

void reverse_r(int r[], int from, int to)
{
	for(int i = from; i < (from + to) / 2; i++)
	{
		int tmp = r[i];
		r[i] = r[to-i];
		r[to-i] = tmp;
	}
}

void T10(int r[], int n, int p)
{
    /*设将n(n>1)个整数存放到一维数组R中。设计一个在时间和空间两方面都尽可能高效的算法。将R中保存的序列循环左移p(0<p<n)个位置，
    即将R中的数据由(X0,X1,...,Xn-1)变换为(Xp,Xp+1,...,Xn-1,X0,...,Xp-1)。要求：
    1.给出算法的基本设计思想
    2.根据设计思想，采用C或C++或Java语言描述算法，关键之处给出注释
    3.说明你所设计算法的时间复杂度和空间复杂度
    */
	/*
	1.可将问题视为把数组ab转换成数组ba(a代表数组的前p个元素,b代表数组中余下的n-p个元素)，分别将a和b进行逆置，得到a^-1b^-1，
	然后再将整个数组逆置，得到ba
	例如p=3,n=5,r={1,2,3,4,5,6,7,8}则整个过程如下
	a的逆置得到{3,2,1,4,5,6,7,8}
	b的逆置得到{3,2,1,8,7,6,5,4}
	r的逆置得到{4,5,6,7,8,1,2,3}
	3.a和b进行单独转置的时间复杂度分别为O(p)和O(n-p)，整体进行转置的时间复杂度为O(n)，又因为p+n-p=n，所以整个算法的时间复杂度为O(n)，
	由于每个操作都只在原数组进行，无额外的辅助数组开销，故算法的空间复杂度为O(1)
	*/
	reverse_r(r, 0, p-1);
	reverse_r(r, p, n-1);
	reverse_r(r, 0, n-1);
}

int T11(int A[], int B[], int n)
{
    /*一个长度为L(L>=1)的升序序列S，处在第[L/2](向上取整)个位置的数称为S的中位数，例如，若序列S1=(11,13,15,17,19)，则S1的中位数是15，
    两个序列的中位数是含它们所有元素的升序序列的中位数，例如，若S2=(2,4,6,8,20)，则S1和S2的中位数是11。
    现在有两个等长升序序列A和B，试设计一个在时间和空间两方面都尽可能高效的算法，找出两个序列A和B的中位数，要求：
    1.给出算法的基本设计思想
    2.根据设计思想，采用C或C++或Java语言描述算法，关键之处给出注释
    3.说明你所设计算法的时间复杂度和空间复杂度
    */
   	/*
	1.分别求两个升序序列A、B的中位数，设为a和b，求序列A、B的中位数过程如下：
		01：若a=b，则a或b为所求中位数，算法结束
		02：若a<b，则舍弃序列A中较小的一半，同时舍弃序列B中较大的一半，要求两次舍弃的长度相等
		03：若a>b，则舍弃序列A中较大的一半，同时舍弃序列B中较小的一半，要求两次舍弃的长度相等
		在保留的两个升序序列中，重复过程1,2,3，直到两个序列中均只含一个元素时为止，较小者为所求的中位数
	3.时间复杂度为O(log2 n)，空间复杂度为O(1)
   	*/
	int s1, d1, m1, s2, d2, m2;
	s1 = 0; d1 = n-1;
	s2 = 0; d2 = n-1;
	while(s1 != d1 || s2 != d2)
	{
		m1 = (s1+d1) / 2;
		m2 = (s2+d2) / 2;
		if(A[m1] == B[m2]) // 满足条件1
			return A[m1];
		if(A[m1] < B[m2]) // 满足条件2
		{
			if((s1+d1)%2 == 0) // 若元素个数为奇数
			{
				s1 = m1; // 舍弃A中间点以前的部分，且保留中间点
				d2 = m2; // 舍弃B中间点以后的部分，且保留中间点
			}
			else // 元素个数为偶数
			{
				s1 = m1 + 1; // 舍弃A的前半部分
				d2 = m2; // 舍弃B的后半部分
			}
		}
		else // 满足条件3
		{
			if((s1+d1)%2 == 0) // 若元素个数为奇数
			{
				d1 = m1; // 舍弃A中间点以后的部分，且保留中间点
				s2 = m2; // 舍弃B中间点以前的部分，且保留中间点
			}
			else //元素个数为偶数
			{
				d1 = m1; // 舍弃A的后半部分
				s2 = m2+1; // 舍弃B的前半部分
			}
		}
	}
	return A[s1]<B[s2] ? A[s1]:B[s2];
}

int T12(int a[], int n)
{
    /*已知一个整数序列A=(a0,a1,...,an-1)，其中0<=ai<n(0<=i<n)。若存在ap1=ap2=...=apm=x且m>n/2(0<=pk<n,1<=k<=m),则称x为A的主元素。
	例如A=(0,5,5,3,5,7,5,5)，则5为主元素；又如A=(0,5,5,3,5,1,5,7)，则A中没有主元素。假设A中的n个元素保存在一个一维数组中，
	请设计一个尽可能高效的算法，找出A的主元素，若存在主元素，则输出该元素；否则输出-1。要求：
	1.给出算法的基本设计思想。
	2.根据设计思想，采用C或C++或Java语言描述算法，关键之处给出注释
	3.说明你所设计算法的时间复杂度和空间复杂度。
    */
    /*
	1.
	3.
	*/
	int cnt=1, ans=a[0];
	for(int i=1;i<n;i++)
	{
		if(a[i] == ans)
		{
			cnt++;
		}
		else if(cnt > 0)
		{
			cnt--;
		}
		else
		{
			ans = a[i];
		}
	}
	cnt = 0;
	for(int i=0;i<n;i++)
	{
		if(a[i] == ans)
		{
			cnt++;
		}
	}
	if(cnt > n/2)
		return ans;
	return -1;
}

int T13(int a[], int n)
{
	/*给定一个含n(n>=1)个整数的数组，请设计一个在时间上尽可能高效的算法，找出数组中未出现的最小正整数。例如，数组{-5,3,2,3}中未出现的
	最小正整数是1;数组{1,2,3}中未出现的最小正整数是4。要求
	1.给出算法的基本设计思想
	2.根据设计思想，采用C或C++语言描述算法，关键之处给出注释
	3.说明你所设计算法的时间复杂度和空间复杂度
	*/
	/*
	1.针对在时间上尽可能高效的算法，我采用用空间换时间的思路，利用桶排序进行求解，开辟一个bool类型的桶，遍历数组，如果值在[1,n]之间，
	则进行记录，最后从下标1开始遍历桶的值，如果下标这个数未被标记，即为false，则这就是未出现的最小正整数，如果都出现了，则返回n+1
	3.时间复杂度为O(n)，因为只需要遍历一次数组，再加一次flag数组即可；空间复杂度为O(n)，因为需要开辟长度为n的标记数组
	*/
	//bool flag[n+1] = {};
	vector<bool> flag(n+1, false);
	for(int i=0;i<n;i++)
	{
		if(a[i] > 0 && a[i] <= n)
			flag[a[i]] = true;
	}
	for(int i=1;i<=n;i++)
	{
		if(!flag[i])
			return i;
	}
	return n+1;
}

int T14(int s1[], int s2[], int s3[], int n1, int n2, int n3)
{
	/*定义三元组(a,b,c)(a,b,c均为整数)的距离D=|a-b|+|b-c|+|c-a|。给定3个非空整数集合S1、S2和S3，按升序分别存储在3个数组中，请设计一个
	尽可能高效的算法，计算并输出所有可能的三元组(a,b,c)(a属于S1，b属于S2，c属于S3)中的最小距离。例如S1={-1,0,9},S2={-25,10,10,11},
	S3={2,9,17,30,41}，则最小距离为2，相应的三元组为(9,10,9)。要求：
	1.给出算法的基本设计思想
	2.根据设计思想，采用C语言或C++语言描述算法，关键之处给出注释
	3.说明你所设计算法的时间复杂度和空间复杂度
	*/
	/*
	1.设置三个下标指针，每次移动对应值最小的下标指针，如果这个指针无法移动，则不再移动，每次移动前，都求出距离D，并记录下最小值
	3.因为需要利用指针遍历三个数组，时间复杂度为O(n)，n为S1、S2、S3的长度和，空间复杂度为O(1)，不需要额外开辟长度为n的数组
	*/
	int i=0, j=0, k=0, D = abs(s1[0]-s2[0]) + abs(s2[0]-s3[0]) + abs(s1[0]-s3[0]);
	while(i < n1 && j < n2 && k < n3)
	{
		int d = abs(s1[i]-s2[j]) + abs(s2[j]-s3[k]) + abs(s1[i]-s3[k]);
		if(s1[i] <= s2[j] && s1[i] <= s3[k])
		{
			i++;
		}
		else if(s2[j] <= s1[i] && s2[j] <= s3[k])
		{
			j++;
		}
		else
		{
			k++;
		}
		D = min(D, d);
	}
	return D;
}

void T15(int A[],int res[],int n)
{
	/*有两个长度均为n的一维整型数组A和res，对数组A中的每个元素A[i]，计算A[i]与A[j](0<=i<=j<=n-1)乘积的最大值，并将其保存到res[i]中，例如，
	当A[]={1,4,-9,6}时，得到res[]={6,24,81,36}。现给定数组A，设计一个时间和空间上尽可能高效的算法calMulMax，求res中各元素的值。
	函数原型为void calMulMax(int A[],int res[],int n)。要求如下：
	1.给出算法的基本设计思想
	2.根据设计思想，采用C或C++语言描述算法，关键之处给出注释
	3.说明你所设计算法的时间复杂度和空间复杂度
	*/
	/*
	1.从后向前遍历数组，遍历的过程中记录最大值和最小值，同时计算res，如果当前数值是负数，则乘以这个数组最小的负数，如果是正数，
	则乘以数组中最大的正数，并保存到res中
	3.算法总共需要遍历两次数组A，时间复杂度为O(n)，空间复杂度为O(1)，无额外数组辅助计算
	*/
	int min_a=A[n-1], max_a=A[n-1];
	for(int i=n-1;i>=0;i--)
	{
		min_a = min(min_a, A[i]);
		max_a = max(max_a, A[i]);
		if(A[i] > 0)
		{
			res[i] = A[i] * max_a;
		}
		else
		{
			res[i] = A[i] * min_a;
		}
	}
}

int main()
{
	int aa, bb;
	cin >> aa;
	cout << aa << endl;
    cout << "测试输出1" << endl;
    cout << "测试输出2" << endl;
	int a[] = {11,13,15,17,19}, b[] = {2,4,6,8,20};
	cout << T11(a, b, 5);
    return 0;
}