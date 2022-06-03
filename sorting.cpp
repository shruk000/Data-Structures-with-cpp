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




void swap(int &ele,int &ele2){
    int temp=ele;
    ele=ele2;
    ele2=temp;
}


void mergeTwoArray(int *arr, int low,int mid, int high){
    int copyarray[high-low+1]={0};
    int i=low,j=mid+1,k=0;
    // cout<<"-----------------"<<endl ; 
    // cout<<"low  "<<low<<"  mid "<<mid<<"  high"<<high<<endl ; 
    // printArray(arr,8);
    while(i<=mid&&j<=high)
    {   
        if(arr[i]<arr[j]){
            copyarray[k++]=arr[i++];
        }else {
            copyarray[k++]=arr[j++];
        }
    }
    for(;i<=mid;i++){
        copyarray[k++]=arr[i];
    }
    for(;j<=high;j++){
        copyarray[k++]=arr[j];
    }
    for(int a=0;a<=high-low;a++){
        arr[low+a]=copyarray[a];
    }
    // printArray(arr,8);
    // cout<<"-----------------"<<endl ; 

}

void mergeSort(int *arr, int low, int high){
        if(low<high){
            mergeSort(arr,low,(low+high)/2);
            mergeSort(arr,(low+high)/2 +1,high);
            mergeTwoArray(arr,low,(low+high)/2,high);

        }

}



void selectionSort(int *arr,int length){
        for(int i=0;i<length;i++){
            // for every i position find minimum in the rest of the array
            int minPosition=i;
            for(int j=i;j<length;j++){
                if(arr[minPosition]>arr[j]){
                    minPosition=j;
                }
            }
            swap(arr[i],arr[minPosition]);
        }



}
void insertionSort(int *arr,int length){
    for(int i=0;i<length;i++){
        int temp=arr[i];
        for(int j=i-1;j>=0;j--){
            if(temp<arr[j]){
                arr[j+1]=arr[j];
                arr[j]=temp;
            }else{
                // next(dec J) element is smaller then temp
                break;
            }

        }
    }

}

// void performQuickSort(int *arr,int low,int high){
//     int i,j,piviot=low;
//         i=low+1;j=high;
//         if(high<low) return;
   
//     cout<<"-----------------"<<endl ; 
//     cout<<"i= "<<i<<"  j= "<<j<<"  pivot="<<piviot<<endl ; 
//      printArray(arr,high);
//         while(i<j){
//             if(arr[j]<=arr[piviot]){
//                 swap(arr[j],arr[i]);
//             }
//             if(arr[i]>arr[piviot]){
//                 swap(arr[j],arr[i]);
//             }
//             if(arr[j]>=arr[piviot]){
//                 j--;
//             }        
//             if(arr[i]<arr[piviot]){
//                 i++;
//             }
            
//         }
        
     
//     swap(arr[piviot],arr[j]);
//     printArray(arr,high);
//     cout<<"-----------------"<<endl ; 
//     performQuickSort(arr,low,j-1);
//     performQuickSort(arr,j+1,high);
// }

// void quickSort(int *arr,int length){
//     performQuickSort(arr,0,length-1);
// }

int partition(int *arr,int low,int high){
    int i=low-1;
    int piviot=arr[high];
    for(int j=low;j<=high-1;j++){
        
        if(arr[j]<piviot){
            // pushing smaller backward.. by not incrementing j
            i++;
            swap(arr[j],arr[i]);
        }

    }
    swap(arr[high],arr[i+1]);
    return i+1;
}

void quickSort(int *arr,int low,int high){
    if(high<=low)return;
    int i=partition(arr,low,high);
    quickSort(arr,low,i-1);
    quickSort(arr,i+1,high);
}










int main(){
    int arr[] = {0,1,2,3,8,9,5,6, 86, 195, 15, 63, 72, 95, 71, 14, 10, 124, 33, 45};
    int size = sizeof(arr) / sizeof(arr[0]);
    int arr2[] = {95, 71, 14, 10, 124, 33, 45,1};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    
    
    // printArray(arr2,size2);
    // mergeSort(arr2,0,size2-1);
    // printArray(arr2,size2);
    // printArray(arr,size);
    // mergeSort(arr,0,size-1);
    // printArray(arr,size);
    // printArray(arr2,size2);
    // quickSort(arr2,0,size2-1);
    // printArray(arr2,size2);
    printArray(arr,size);
    quickSort(arr,0,size);
    printArray(arr,size);
    // printArray(arr,size);
    // selectionSort(arr,size);
    // printArray(arr,size);

    return 0;
}




