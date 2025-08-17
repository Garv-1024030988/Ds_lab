#include <iostream>
using namespace std;
int main()
{
    int nums[100];
    int n;
    cout << "enter the number of elements on array :";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int l = 0;
    int r = n - 1;
    int mid = 0;
    while (mid <= r)
    {
        if (nums[mid] == 0)
        {
            swap(nums[l], nums[mid]);
            l++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[r]);
            r--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << ' ';
    }

    return 0;
}
