#include<iostream>
#include <vector>
using namespace std;

void printVector(vector<string> ve){
        cout<<"{";
    for(string a:ve){
        cout<<a<<" ,";
    }
        cout<<"}"<<endl;

}




void printSubset(vector<string> v){
    
    




}

void permutation(int digits,vector<string> &v){
    // cout<<"digits = "<<digits<<" vectorString= ";
    // printVector(v); 

    if(digits==0){
        printVector(v);
    }else{
        v.push_back("0");
        permutation(digits-1,v);
        v.pop_back();
        v.push_back("1");
        permutation(digits-1,v);
        v.pop_back();
    }
}

void doPermutation(int digits){
    vector<string> vc;
    permutation(digits,vc);
}


void permutationString(vector<string> strings,vector<string> &vc){
    if(vc.size()==strings.size()){
        printVector(vc);
    }else{
        for(int i=0;i<strings.size();i++){
                vc.push_back(strings[i]);
                permutationString(strings,vc);
                vc.pop_back();

        }


    }

    
}


void doPermutationString(vector<string> st){
    vector<string> vc;
    permutationString(st,vc);
}




void powerSet(vector<string> strings,vector<string> &vc){
  
  if(vc.size()==strings.size()){
       cout<<"{";
    for(int i=0;i<vc.size();i++){
        if(vc[i]=="1"){
            cout<<strings[i]<<",";
        }
    }
       cout<<"}"<<endl;
    }else{
       vc.push_back("0");
       powerSet(strings,vc);
       vc.pop_back();
       vc.push_back("1");
       powerSet(strings,vc);
       vc.pop_back();




    }



}

void doPowerSet(vector<string> st){
    vector<string> vc;
    powerSet(st,vc);
}






int main(){
    vector<string> ve={"janny","susan","mike"};
    // printVector(ve);
    // ve.pop_back();
    // printVector(ve);


    doPermutation(3);
    
    doPermutationString(ve);
    // same as permuation of digits just that any zero will replace other numbers
    doPowerSet(ve);

    return 0;
}




