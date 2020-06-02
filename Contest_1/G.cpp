#include <bits/stdc++.h>
 
int lowerIndex(const int arr[], int n, int x)
{
    int l = 0, h = n - 1;
    while (l <= h) {
        int mid = (l + h) / 2;
        if (arr[mid] >= x)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}
 
int upperIndex(const int arr[], int n, int y)
{
    int l = 0, h = n - 1;
    while (l <= h) {
        int mid = (l + h) / 2;
        if (arr[mid] <= y)
            l = mid + 1;
        else
            h = mid - 1;
    }
    return h;
}
 
int countInRange(int arr[], int n, int x, int y)
{
    int count = 0;
    count = upperIndex(arr, n, y) - lowerIndex(arr, n, x) + 1;
    return count;
}
 
 
int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int n = 0;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i){
        std::cin >> arr[i];
    }
 
    std::sort(arr, arr + n);
    int k = 0;
    std::cin >> k;
    int tmp1;
    int tmp2;
    for (int i = 0; i < k; ++i){
        std::cin >> tmp1 >> tmp2;
        std::cout << countInRange(arr, n, tmp1, tmp2) << " ";
    }
    return 0;
}