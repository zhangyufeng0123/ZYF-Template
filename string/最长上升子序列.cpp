#include <iostream>

using namespace std;
const int maxn = 100;
int min_end[maxn]; //min_end[i]表示长度为i的子串的最小末端
int pre[maxn];//pre[i]表示第i个结点的前驱结点的索引
int index[maxn];  //当前找到的长度为i的递增子序列的最小末尾的索引
int search(int x, int low, int high) {
    //循环不变式保证每次循环后都有low左边小于等于x，high右边大于x
    while (low <= high) {
        int mid = (low + high) / 2;
        if (min_end[mid] > x)
            high = mid - 1;
        else if (min_end[mid] <= x)
            low = mid + 1;
    }
    return low;
}

void LIS(int A[], int n) {
    int k = 0;   //min_end[]数组的长度,数组从1开始, min_end[k]是末尾元素
    //对于min_end,index数组，下表是1到k有意义
    //对于pre数组，下标是0到n-1有意义
    min_end[0] = -999999;
    index[0] = -1;  //-1是结束标志
    pre[0] = -1;
    for (int i = 0; i < n; i++) {
        int pos = search(A[i], 1, k);
        min_end[pos] = A[i];
        index[pos] = i;
        pre[i] = index[pos - 1];
        if (pos > k) k++;
    }
    //打印最长递增子序列
    int result[maxn];
    int result_n = 0; //result数组的长度
    for (int i = index[k]; i != -1; i = pre[i])
        result[result_n++] = A[i];
    int sum = 0;

    //输出最长上升子序列的元素
    for (int i = result_n - 1; i >= 0; i--)
        cout << result[i] << " ";
    cout << endl;
}

int main() {

    int n;
    cin >> n;
    int A[maxn];
    for (int i = 0; i < n; i++)
        cin >> A[i];
    LIS(A, n);
    return 0;
}