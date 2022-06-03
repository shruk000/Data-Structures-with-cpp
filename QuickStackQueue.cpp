#include <iostream>
using namespace std;

/***
 * only push function has been made different in these two implementation
 * 
 * 
*/




// LIFO
template <class T>
class stack{
    class node{
        public :
        T value;
        node *next;
    };

    node *head;
    int length=0;

    public:
    
    stack(T data){
        head=(node*)malloc(sizeof(node));
        head->value=data;
        head->next=nullptr;
        length++;
    }

    push(T data){
        node* temp=(node*)malloc(sizeof(node));
        temp->value=data;
        temp->next=head;
        head=temp;
        length++;
    }
    T pop(){
        if(length==0)return 0;
        node* temp=head;
        head=head->next;
        T data=temp->value;
        free(temp);
        length--;
        return data;
    }

};



//FIFO first in first out
template <class T>
class queue{
    class node{
        public :
        T value;
        node *next;
    };

    node *head;
    int length=0;

    public:
    
    queue(T data){
        head=(node*)malloc(sizeof(node));
        head->value=data;
        head->next=nullptr;
        length++;
    }

    push(T data){
        node* temp=(node*)malloc(sizeof(node));
        temp->value=data;
        temp->next=nullptr;
        node *temphead=head;
        while(temphead->next!=nullptr){
            temphead=temphead->next;
        }
        temphead->next=temp;
        length++;
    }


    T pop(){
        if(length==0)return NULL;
        node* temp=head;
        head=head->next;
        T data=temp->value;
        free(temp);
        length--;
        return data;
    }

};




int main(){
    queue<char> st('5');
    st.push('a');
    st.push('b'); 
    cout<<endl<<st.pop();
    cout<<endl<<st.pop();
    cout<<endl<<st.pop(); 
    cout<<endl<<st.pop(); 
    cout<<endl<<st.pop(); 



return 0;
}







