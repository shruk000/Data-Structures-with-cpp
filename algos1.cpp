#include <iostream>
using namespace std;

int binarySearch(int *arr, int length, int ele)
{
    int start = 0, end = length - 1;
    int currentPos;
    // cout<<"current pos = "<<currentPos<<endl;
    if (ele > arr[end])
    {
        return -1;
    }
    while (true)
    {
        if (currentPos != (start + end) / 2)
        {
            cout << "start = " << start << endl;
            cout << "end = " << end << endl;
            cout << "current pos = " << currentPos << endl;
        }
        currentPos = (start + end) / 2;
        if (arr[currentPos] == ele)
        {
            return currentPos;
        }
        else
        {
            if (arr[currentPos] < ele)
            {
                start = currentPos + 1;
            }
            else if (arr[currentPos] > ele)
            {
                end = currentPos;
            }
        }

        if (end - start < 1)
        {
            break;
        }
    }
    return -1;
}



int main()
{
    int ar[] = {10, 10, 20, 4, 57, 2, 1, 58, 943, 2, 73, 78, 2, 32, 55, 8, 36, 89, 324, 75, 2, 1, 58, 71, 18, 39, 16, 72, 94};
    int arr[] = {2, 3, 4, 5, 6, 8, 9, 10, 11, 24, 56, 89, 99, 100, 221, 334, 545, 657, 878};
    cout << "value should be 8" << endl;
    int posi = binarySearch(arr, sizeof(arr) / sizeof(arr[0]), arr[0]);
    cout << "value should be 19" << endl;
    cout << posi;
}







