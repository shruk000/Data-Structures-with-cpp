#include <bits/stdc++.h>
#include<windows.h>



using namespace std;
void printArray(vector<int> &v)
{

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " | ";
    }
    cout << endl;
}

void printSubArrayWithSum(vector<int> &arr, int sum)
{

    int i = 0, j = 0, N = arr.size();
    int totaltill = 0;
    while (j < N)
    {

        for (;; j++)
        {
            int subArraySum = accumulate(arr.begin() + i, arr.begin() + j + 1, 0);
            if (subArraySum > sum)
            {
                break;
            }
            if (subArraySum == sum)
            {
                cout << "i= " << i << "  j=" << j << endl;

                j++;
                break;
            }
        }

        for (;; i++)
        {
            int subArraySum = accumulate(arr.begin() + i, arr.begin() + j + 1, 0);
            if (subArraySum < sum)
            {
                break;
            }
            if (subArraySum == sum)
            {
                cout << "i= " << i << "  j=" << j << endl;
                j++;
                break;
            }
        }
    }
}

void printSubArrayWithSum2(vector<int> &arr, int sum)
{

    int i = 0, j = 0, N = arr.size();
    int totaltill = arr[j];
    while (j < N)
    {
        while (totaltill < sum)
        {
            j++;
            totaltill += arr[j];
        }
        if (totaltill == sum)
        {
            cout << "i= " << i << "  j=" << j << endl;
            j++;
            totaltill += arr[j];
        }
        while (totaltill > sum)
        {
            totaltill -= arr[i];
            i++;
        }
    }
}



// substrings with no repeating chars..
void printSubstring(string bigS)
{
    unordered_map<char, int> windowsChars;
    int i = 0, j = 0, largestSize = 0, N = bigS.size();
    int iLargest, jLargest;
    // cout<<bigS[2];
    cout << bigS.size() << endl;
    cout << "originalString = " << bigS << endl;
    while (j < N)
    {
        for (;; j++)
        {

            if (windowsChars.count(bigS[j]) > 0 || j == N)
            {
                if((j-i+1)>largestSize){
                    largestSize=j-i;
                    iLargest=i;
                    jLargest=j-1;
                }
                cout << "i= " << i << "  j=" << j - 1 << endl;
                break;
            }
            windowsChars.insert({bigS[j], j});
        }
        if (j == N)
        {
            break;
        }
        int tempLo = windowsChars.find(bigS[j])->second;
        for (; i <= tempLo; i++)
        {
            windowsChars.erase(bigS[i]);
        }
    }
    cout <<"Largest - ||  "<< "i= " << iLargest << "  j=" << jLargest <<" ||"<< endl;
}


// substrings which contains Atleast all char of smallString 

void printSmallestSubString(string big, string small){
    int i=0,j=0,count=0,numS=small.size(),numB=big.size();
    unordered_map<char,int> smallStringCharsMap;
    for (char ch : small)
    {   count++;
        smallStringCharsMap[ch]++;
    }
    cout<<"Big String =| "<<big<<" |"<<endl;
    cout<<"small String =| "<<small<<" |"<<endl;
    while(j<numB){
        for(;j<numB;j++){
            if(count==0){
                break;
            }
            if(smallStringCharsMap.count(big[j])>0){
                if(smallStringCharsMap[big[j]]>0){ 
                    count--;
                }  
                
                smallStringCharsMap[big[j]]--; 
            }
            
        }
        if(j==numB)break;
        
        for(;;i++){
            if(smallStringCharsMap.count(big[i])>0){
                smallStringCharsMap[big[i]]++;
                if(smallStringCharsMap[big[i]]>0){
                    count++;
                    cout << "i= " << i << "  j=" << j-1 << endl;
                    i++;
                    break;
                } 

                
            }


        }



        
    }








    
    



}


// minimum flips allowed for max 1s
void flipsAllowed(vector<int> arr,int flips){
    int i=0,j=0,lastZero=0,N=arr.size(),precedingOnes=0;
    int iLargest,jLargest,sizeLargest=0;
    

    cout<<"flips allowed = "<<flips<<endl;
    printArray(arr);

    while(j<N){
        for(;j<N;j++){
            if(arr[j]==0){
                if(flips>0){
                    flips--;
                }else{
                    cout << "i= " << i << "  j=" << j-1 << endl;
                    if((j-i)>sizeLargest){
                        iLargest=i;
                        jLargest=j-1;
                        sizeLargest=j-i;
                    }


                    break;
                }
            }

        }
        if(j==N){
            cout << "i= " << i << "  j=" << j-1 << endl;
            if((j-i)>sizeLargest){
                        iLargest=i;
                        jLargest=j-1;
                        sizeLargest=j-i;
                    }
            break;
        }
        for(;;i++){
            if(arr[i]==0){
                flips++;
                i++;
                break;
            }

        }




    }
   cout <<"Largest - ||  "<< "i= " << iLargest << "  j=" << jLargest <<" ||"<< endl;

    vector<int> ret;
    for(int i=iLargest;i<=jLargest;i++){
        ret.push_back(i);
    }
    printArray(ret);


}


bool testForK(vector<int> &A,int k){

    unordered_multiset<int> st;
    int i=0,j=0,N=A.size(),prev=-1;
    bool valid=true;// 
    int a=0;
   

    for(a=0;a+k<N;a++){
        st.clear();
        int b;
        for(b=0;b<=a;b++){
            if(st.count(A[b])>1){
                valid=false;
                break;
            }
            st.insert(A[b]);
        }
        if(b<a){valid=false; continue;}

        for(b=a+k;b<N;b++){
            if(st.count(A[b])>1){
                valid=false;
                break;
            }
            st.insert(A[b]);
        }
        if(b<N){
            valid=false;
            continue;;
        }
        
        
        if(b==N){valid=true;break;}





    }
    return valid;
}


int solve(vector<int> &A) {

    
    int i=0,j=0,N=A.size(),prev=-1;
    int low=0,high=N-1,k;
    while(low<high){
        // Sleep(1000);
        cout<<k<<"| low"<<low <<" | high"<<high<<endl ;
        k=(low+high)/2 ;
        if(testForK(A,k)){
            high=k;
        }else{
            low=k+1;
        }
    }
    // cout<<k;
    return k;
    



    


}

int findCountMax(vector<int> arr){

    int i=0,N=arr.size();
    int max=arr[0];
    int count=1;
    if(N==0){
        return 0;
    }

    for(i=0;i<N;i++){
        if(arr[i]>max){
            count++;
            max=arr[i];
        }


    }
    return count;
}










int binarySearch(vector<int> A,int ele){

    int start=0,end=A.size()-1,mid=0;


    while(start<=end){
        mid=(start+end)/2;
        cout<<mid<<"| low"<<start <<" | high"<<end<<endl ;
        if(A[mid]==ele)return mid;
        if(A[mid]>ele)end=mid-1;
        if(A[mid]<ele)start=mid+1;
    }
    cout<<mid<<"| low"<<start <<" | high"<<end<<endl ;



    return -1;




}

int removeSubArraySort(vector<int> arr){
    int i=0,j=0,N=arr.size();
    j=N-1;
    while(j>i){
        for(;;i++){
            if(arr[i]>arr[j])
            break;
        }



    }




}




signed main()
{
    vector<int> arr = {1, 3, 2, 1, 4, 1, 3, 2, 1, 1, 1, 2};
    vector<int> proArray = {1, -3, 2, 1, 4, -1, -5, 2, 1, 1, 1, 2};
    vector<int> flip = {1,1,0,1,1,0,0,1,1,1}; 
    vector<int> sortedArray={1,2,34,56,78,90,211,213,242,251,256,257,345};
    vector<int> at={ 58, 38, 60, 24, 42, 30, 79, 17, 36, 91, 43, 89, 7, 41, 43, 65, 49, 47, 6, 91, 30, 71, 51, 7, 2, 94, 49, 30, 24, 85, 55, 57, 41, 67, 77, 32, 9, 45, 40, 27, 24, 38, 39, 19, 83, 30, 42, 34, 16, 40, 59, 5, 31, 78, 7, 74, 87, 22, 46, 25, 73, 71, 30, 78, 74, 98, 13, 87, 91, 62, 37, 56 };
    vector<int> at2={ 1, 2, 1,2,4, 2,1,3,4,6 };
    vector<int> mx={1,2,3,4};
    vector<int> mx2={1,1,2,2};

    string big = "pratteekbhaiya";
    string big1 = "aabcb";
    // string BIG = "helllol_world";
    string BIG = "fizzbuzz";
    string small = "fuzz";
    // string small="aabcb";

    int sum = 5;


    // printArray(arr);
    // printSubArrayWithSum2(proArray, sum);

    // printSubstring(big1);
    // printSmallestSubString(BIG,small);


    // flipsAllowed(flip,1);
    // cout<<solve(at);
    cout<<findCountMax(mx2);
    // cout<<binarySearch(sortedArray,90);





    

}
