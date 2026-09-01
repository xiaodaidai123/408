#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> arr(20, vector<int>(20));
int n, m, max_a=-INFINITY, max_row, cnt;

int main()
{
    cout << 123 << endl;
    cin >> n >> m;
    cout << n << m << endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] > max_a)
            {
                max_a = arr[i][j];
                max_row = i;
            }
        }
    }
    for(int j=0;j<m;j++)
    {
        cnt += arr[max_row][j];
    }
    cout << max_a << " " << cnt;
    return 0;
}