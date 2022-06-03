#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " | ";
    }
    cout << endl;
}

void printSum(vector<int> numbers,int currentNumber,int totalSum){
    if(accumulate(numbers.begin(),numbers.end(),0)==totalSum){
        printArray(numbers);
    }else{

        for(int i=currentNumber;(i+accumulate(numbers.begin(),numbers.end(),0))<=totalSum ;i++){
            numbers.push_back(i);
            printSum(numbers,i,totalSum);
            numbers.pop_back();
        }



    }





}

void printSum(vector<int> numbers,int currentNumber,int totalSum,int digits){
    if(accumulate(numbers.begin(),numbers.end(),0)==totalSum){
        if(numbers.size()!=digits){
            return;
        }else 
        printArray(numbers);
    }else{

        for(int i=currentNumber;
        ((i+accumulate(numbers.begin(),numbers.end(),0))<=totalSum)&&(numbers.size()<digits)
         ;i++){
            numbers.push_back(i);
            printSum(numbers,i,totalSum,digits);
            numbers.pop_back();
        }



    }





}


signed main(){

    vector<int> v;
    cout<<"printing"<<endl;
    printSum(v,1,11,4); // digits based 4 only digits ..
    printSum(v,1,10);// non digits based

    cout<<"printed"<<endl;




    return 0;
}



