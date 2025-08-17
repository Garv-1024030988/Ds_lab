#include <iostream>
using namespace std;
int main()
{
    int arr[100];
    int n;
    cout << "enter the number of elements in array :";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            for (int j = n - 1; j > i; j--)
            {
                arr[j] = arr[j - 1];
            }
            i++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
