#include <bits/stdc++.h>
#include<windows.h>
#include <time.h>



using namespace std;
void printArray(vector<int> &v)
{

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " | ";
    }
    cout << endl;
}


void printConnection(  vector<vector<int>> grph );
void bfs( vector<vector<int>> grph );
void dfs( vector<vector<int>> graph );
bool isCyclePresent(vector<vector<int>> graph);
bool recursive(vector<vector<int>> graph, vector<int> &arr,int current);
bool isCyclePresent1(vector<vector<int>> graph);
bool recursive1(vector<vector<int>> graph, vector<int> &arr,int current);
bool recursiveCycleUndirected(vector<vector<int>> graph, vector<int> arr,int current);
bool isCyclePresentUndirected(vector<vector<int>> graph);



void TopoSortDFS( vector<vector<int>> graph ){
    stack<int> st;
    vector<int> topSort;
    int current,N=graph.size();
    vector<int> visited(graph.size(),0);
    int startElement=3;
    st.push(startElement);
    visited[startElement]=1;
    while(!st.empty()){
        current=st.top();
        cout<<"-------------------------------------------------------------- "<<endl;
        cout<<"visiting : "<<current <<endl;
        for(int i=1;i<N;i++){
            if(graph[current][i]==1 && visited[i]!=1){
                visited[i]=1;
                st.push(i);
                cout<<" visitingNext : "<<i<<endl;
                break;
            }
            if(i==N-1){
                topSort.insert(topSort.begin(),st.top());
                st.pop();}
        }

    }

    cout<<"topsort!!-- ";
    printArray(topSort);




}





signed main(){
    // undirected Graph....
    vector<vector<int>> grph={{0,0,0,0,0,0,0}
                             ,{0,0,1,1,0,0,0}
                             ,{0,1,0,0,0,0,0}
                             ,{0,1,0,0,1,0,0}
                             ,{0,0,0,1,0,1,1}
                             ,{0,0,0,0,1,0,0}
                             ,{0,0,0,0,1,0,0}};
    // directed Graph....
    vector<vector<int>> grph2={{0,0,0,0,0,0,0}
                             ,{0,0,1,0,0,0,0}
                             ,{0,0,0,0,0,0,0}
                             ,{0,0,1,0,1,1,1}
                             ,{0,0,0,0,0,1,0}
                             ,{0,0,0,0,0,0,1}
                             ,{0,1,0,0,0,0,0}};
    // printConnection(grph);
    // bfs(grph);
    // dfs(grph);



    clock_t t;
    t = clock();

    cout<<"--topSort-- "<<endl;
    TopoSortDFS(grph2);
    cout<<endl<<"cycle present= "<< isCyclePresent(grph2)<<endl;
        t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; 
    cout<<time_taken<<endl;

    cout<<"cycle present= ";
     isCyclePresent1(grph2);
     cout<<endl;
        t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; 
    cout<<time_taken<<endl;

    cout<<"cycle present undirected= "<< isCyclePresentUndirected(grph)<<endl;
        t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; 
    cout<<time_taken<<endl;

}

bool recursiveCycleUndirected(vector<vector<int>> graph, vector<int> arr,int current){
    bool val;
    
    for(int i=1;i<graph.size();i++){
        if(graph[current][i]==1 && arr[i]==0){
            arr[i]=1;
            val=recursiveCycleUndirected(graph,arr,i);
            arr[i]=0;
        }else if(graph[current][i]==1 && arr[i]==1){
            arr[i]=2;
        }
        else if(graph[current][i]==1 && arr[i]==2){
            return true;
        }
        if(val==true){return true;}

    }
    return false;

}



bool isCyclePresentUndirected(vector<vector<int>> graph){
    int N=graph.size();
    bool val=false;
    for(int i=1;i<N;i++){
        int ele=i;
        vector<int> arr(N,0);
        arr[i]=1;
        val=recursiveCycleUndirected(graph, arr,i);
        if(val==true)return true;
    }
    return false;


}















bool recursiveCycle(vector<vector<int>> graph, vector<int> &arr,int current){
    bool val;
    
    for(int i=1;i<graph.size();i++){
        if(graph[current][i]==1 && arr[i]==false){
            arr[i]=true;
            val=recursiveCycle(graph,arr,i);
            arr[i]=false;
        }else if(graph[current][i]==1 && arr[i]==true){
            return true;
        }
        if(val==true){
            cout<<" - "<<i;
            return true;}

    }
    return false;

}


bool isCyclePresent(vector<vector<int>> graph){
    int N=graph.size();
    bool val=false;
    for(int i=1;i<N;i++){
        int ele=i;
        vector<int> arr(N,false);
        arr[i]=true;
        val=recursiveCycle(graph, arr,i);
        if(val==true){
            
             cout<<" - "<<i;
             return true;}
    }
    return false;

}




bool recursiveCycle1(vector<vector<int>> graph, vector<int> &arr,int current){
    bool val;
    for(int i=1;i<graph.size();i++){
        
        if(graph[current][i]==1 && arr[i]==2){
            // return false;  returning will cause other vertices unchecked..
        //    skip it..
        }else
        if(graph[current][i]==1 && arr[i]==0){
            arr[i]=1;
            val=recursiveCycle1(graph,arr,i);
            arr[i]=2;
        }else
        if(graph[current][i]==1 && (arr[i]==1)){
            return true;
        }
        if(val==true){
            cout<<" - "<<i;
            return true;}

    }
    return false;

}


bool isCyclePresent1(vector<vector<int>> graph){
    int N=graph.size();
    bool val=false;
    vector<int> arr(N,0);
     cout<<" cycle=>  ";
    for(int i=1;i<N;i++){
        int ele=i;
        arr[i]=1;
        val=recursiveCycle1(graph, arr,i);
        arr[i]=2;
        if(val==true){
             cout<<" - "<<i;
            return true;}
    }
    // cout<<endl;
    return false;

}



void dfs( vector<vector<int>> graph ){
    stack<int> st;
    int current,N=graph.size();
    vector<int> visited(graph.size(),0);
    int startElement=1;
    st.push(startElement);
    visited[startElement]=1;
    
    while(!st.empty()){
        current=st.top();
        cout<<"-------------------------------------------------------------- "<<endl;
        cout<<"visiting : "<<current <<endl;
        for(int i=1;i<N;i++){
            if(graph[current][i]==1 && visited[i]!=1){
                visited[i]=1;
                st.push(i);
                cout<<" visitingNext : "<<i<<endl;
                break;
            }
            if(i==N-1)st.pop();
        }
    }




}







void bfs( vector<vector<int>> graph ){
    queue<int> q;
    int current,N=graph.size();
    vector<int> visited(graph.size(),0);
    int startElement=4;
    q.push(startElement);
    visited[startElement]=1;

    while(!q.empty()){
        current=q.front();
        cout<<"-------------------------------------------------------------- "<<endl;
        cout<<"visiting : "<<current <<endl;
        
        for(int i=1;i<N;i++){
            if(graph[current][i]==1 && visited[i]!=1){
                visited[i]=1;
                q.push(i);
                cout<<" Appending : "<<i<<endl;
            }
        }
        q.pop();
        cout<<"-------------------------------------------------------------- "<<endl;

    }




}











void printConnection(  vector<vector<int>> grph ){


    int a;
    cout<<"type number you want connection from  ";
    cin>>a;
    if(a>grph.size()-1)return;
     cout<<"connection going out are ";
    for(int i=1;i<grph.size();i++){
        
        if(grph[a][i]==1){
            cout<<" | "<<i<<" "; 
         }
    }
     cout<<endl<<"connection coming in are ";
    for(int i=1;i<grph.size();i++){
         if(grph[i][a]==1){
            cout<<" | "<<i<<" "; 
         }
    }

}

