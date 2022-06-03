#include <iostream>
using namespace std;

int main(){
    int arr[22]={1,2,3,4,5,6,7,10,12,12,23};
    void *p;
    p=arr;
    char *k=(char*)p;
    char (*k2)[4]=(char(*)[4])p;
   

//  int is represented differently on different compilers..
    cout<<*(k);
    cout<<*(k2);
    
    cout<<*(k+4);
    cout<<*(k2+1);

    cout<<*(k+8);
    cout<<*(k2+2);

    cout<<*(k+12);
    cout<<*(k2+3);





    return 0;
}