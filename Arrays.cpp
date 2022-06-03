#include <iostream>
using namespace std;


int minMax(int *arr,int size,int *min, int *max){
            cout<<arr[0];
            *max=arr[0];
            *min=arr[0];
            cout<<"running";
            // cout<<";
            for(int i=0;i<size;i++){
                // cout<<arr[i];
                if(*max<arr[i]){
                    *max=arr[i];
                }
                if(*min>arr[i]){
                    *min=arr[i];
                }


            }

return 0;
}


void mergeSorteDArrays(int *m1,int*m2,int size1,int size2){

    int *temparray=(int *)malloc(size1+size2);
    int i=0,j=0;
    for(int a=0;a<size1+size2;a++){

        if(i>=size1){
            temparray[a]=m2[j++];
            continue;
        }
        if(j>=size2){
            temparray[a]=m1[i++];
            continue;
        }

        if(m1[i]>m2[j]){
            temparray[a]=m2[j];
            j++;
        }else if(m1[i]<m2[j]){
            temparray[a]=m1[i];
            i++;
        }


    }

    for(i=0;i<size1+size2;i++){
        cout<<" "<<temparray[i];
        

    }
        // int sizeofArr=(sizeof(m1)/sizeof(m1[0]));
    // cout<<sizeofArr;    
    // building a empty arrya to store both...


}


int main(){
    int arr[]{10,12,1,4,6,24,-5,21,23,5,78,674,32,3,8,9,2};
    int sizeofArr=(sizeof(arr)/sizeof(arr[0]));
    int *p,q,r,min,max;
    p=arr;
    // for()
    // minMax(arr,sizeofArr,&min,&max);
    // cout<<"min"<<min<<endl;
    // cout<<"max"<<max<<endl;
// 
    int m1[]={3,8,16,20,35,200,300,500};
    int m2[]={2,6,19,55};

    // this will replace m1, with a new array.. whose lenght will be sum of both the arrays
    mergeSorteDArrays(m1,m2,(sizeof(m1)/sizeof(m1[0])),(sizeof(m2)/sizeof(m2[0])));
    


    // cout<<p[1];
    




    return 0;
}