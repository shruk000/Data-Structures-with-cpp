#include <iostream>
using namespace std;



void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

// (i,2i,2i+1);
// [1,2,3,4,5,67,7];
// 0,1,2,3,4,5,6,7;


class heap
{
    int array[50];
    // leaving index 0 for simplicity
    int pos = 0;
    int arrayLength = 50;

public:
    heap()
    {
    }
    void swap(int &temp1, int &temp2)
    {
        int k = temp1;
        temp1 = temp2;
        temp2 = k;
    }
    int insert(int ele)
    {
        if (arrayLength < (pos + 1))
        {
            // array is full;;
            return -1;
        }
        pos++;
        array[pos] = ele;
        int start = pos;
        shiftinHeap(array, start);
    }


// this method shiftinHeap goes from top to the bottom of the tree.
    void shiftinHeap(int *arr, int start)
    {
        while (start/2 >= 1)
        {
            if (arr[start] > arr[start / 2])
            {
                swap(arr[start], arr[start / 2]);
                start = start / 2;
            }
            else
                // break because from start , not from some middle position. hence
                break;
        }
    }

    void createHeap(int *arr, int length)
    {
        for (int i = 2; i < length; i++)
        {
            shiftinHeap(arr, i);
        }
    }



    void deleteAll(int *arr, int length)
    {
        for (int i = 1; i < length-2; i++)
        {
            int limit = length -i;
            swap(arr[1], arr[limit]);
            for (int j = 1;;)
            {

                if ((limit) >= (2 * (j) + 1 + 1))
                {
                    if (arr[2 * j] > arr[2 * j + 1])
                    {
                        // left is bigger
                        if (arr[j] < arr[j * 2])
                        {

                            swap(arr[j], arr[j * 2]);
                            j = j * 2;
                        }
                        else
                        {
                            break;
                        }
                    }
                    else 
                    {   // right is bigger..
                        if (arr[j] < arr[2 * j + 1])
                        {
                            swap(arr[j], arr[j * 2 + 1]);
                            j = j * 2 + 1;
                        }
                        else
                            break;
                    }
                }
                else
                    break;
            }
        }
    }






// this method heapify goes from bottom of the tree to the top.
    void heapify(int *arr, int length){
        int len=length;
        for(int i=len/2;i>0;i--){
                for(int j=i;j<len/2;){
                    if(arr[2*j]>arr[2*j+1]){
                        if(arr[2*j]>arr[j]){
                            swap(arr[2*j],arr[j]);
                            j=2*j;
                        }else break;
                       
                    }else  {
                           if(arr[2*j+1]>arr[j]){
                            swap(arr[2*j+1],arr[j]);
                            j=2*j+1;
                        }else break;

                        
                    }
            
               
                }
        }
    }

} h1;


int main()
{
    // note zeroth element is not considered..
    int arr[] = {0,1,2,3,8,9,5,6, 86, 195, 15, 63, 72, 95, 71, 14, 10, 124, 33, 45};
    int ar2[] = {0,1,2,3,8,9,5,6, 86, 195, 15, 63, 72, 95, 71, 14, 10, 124, 33, 45};
    int size = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, size);
    h1.heapify(arr,size);
    printArray(arr, size);
    h1.createHeap(ar2,size);
    printArray(ar2, size);
    
    cout<<"------------till here--------"<<endl;
    
    // h1.createHeap(arr, size);
    // printArray(arr, size);
        h1.deleteAll(arr, size);
        printArray(arr, size);
        h1.deleteAll(ar2, size);
        printArray(ar2, size);

        

}
