#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

void printArray(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " | ";
    }
    cout << endl;
}

void outputLeft(int lower,int higher,vector<int>& glob,vector<int>& nums){
           
            if((higher-lower)==1){
                 glob.push_back(nums[(lower)]);
                return;}
            if((higher-lower)==0){
                return;}

            cout<<"lower= "<<lower<<" higher="<<higher<<" mid="<<(higher+lower)/2<<endl;
            glob.push_back(nums[(higher+lower)/2]);
            outputLeft(lower,(higher+lower)/2,glob,nums);
            outputLeft(((higher+lower)/2)+1,higher,glob,nums);
 }


int firstRepeated(int *arr, int n) {
    
    unordered_map<int,int> mp;
    
    for(int i=0;i<n;i++){
        if(mp.count(arr[i])>0){
            return mp.find(arr[i])->second;
        }else{
            mp.insert({arr[i],i});
        }
        
        
        
    }
    return -1;
    
    
    
    
    // code here
}
 long long int inversionCount(long long arr[], long long N)
    {
   
        
        map<long long,long long> elements;
        for(long long i=0;i<N;i++){
            elements.insert({arr[i],i});
        }
        long long max=0;
        auto it=elements.begin();
        for(long long i=0;i<N;i++){
            cout<<max<<endl;
            auto ele=std::next(it,i);
            if(ele->second > i){
            max=max +(ele->second - i);
                
            } 
        }
        cout<<max;
        return max;
        
    }

int main(){
    
        vector<int> nums={-10,-8 ,-4 ,-3 ,-1 ,1 ,6, 6, 7, 10};
        vector<int> glob;    
         
       
      
        // outputLeft(0,nums.size()-1,glob,nums);
        

        // printArray(nums);  
        // printArray(glob);
        long long size=42;
        long long arr[]={468,335,1, 170, 225 ,479, 359, 463, 465, 206, 146, 282, 328, 462, 492, 496, 443, 328, 437, 392, 105, 403, 154, 293, 383, 422, 217, 219, 396, 448, 227, 272, 39, 370, 413, 168, 300, 36, 395, 204, 312, 323};
        cout<<inversionCount(arr,size);

        



return 0;
}






